#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
using namespace std;

using TokenType = string;

// TT_*
// Token.typeにおいて、各種キーワードを表す
const TokenType TT_PINT = "print_int";
const TokenType TT_PVEC = "print_vec";
const TokenType TT_LBRAC = "[";
const TokenType TT_RBRAC = "]";
const TokenType TT_PLUS = "+";
const TokenType TT_MINUS = "-";
const TokenType TT_ASTERISK = "*";
const TokenType TT_EQ = "=";
const TokenType TT_COMMA = ",";
const TokenType TT_SEMICOLON = ";";
// TT_INT
// Token.typeにおいて、キーワード`int`を表す
// Node.typeにおいて、NodeがNode.int_valueにintを格納することを表す
const TokenType TT_INT = "int";
// TT_VEC
// Token.typeにおいて、キーワード`vec`を表す
// Node.typeにおいて、NodeがNode.vec_valueにVector<Node>を格納することを表す
const TokenType TT_VEC = "vec";
// TT_VAR
// Token.typeにおいて、変数名を表す
// Token.literalに変数名を格納する
const TokenType TT_VAR = "VAR";
// TT_NUM
// Token.typeにおいて、整数値を表す
// Token.literalに値を格納する
const TokenType TT_NUM = "NUM";
// TT_ERR
// エラーを表す
// Token、Node、ExpressionのデフォルトコンストラクタはTT_ERR
const TokenType TT_ERR = "ERR";
// TT_INTERNAL_NODE
// Expressionにおいて、自身がNodeであること(left==NULL && right==NULL && node!=NULL)を表す
const TokenType TT_INTERNAL_NODE = "NODE";
// TT_INTERNAL_VEC_CONTAINER
// パーサーでvecをまとめて1個のTokenにする(入れ子は対応しない)
// Token.literalにvecのリテラルを格納する
const TokenType TT_INTERNAL_VEC_CONTAINER = "VECC";

struct Token
{
    TokenType type;
    string literal;

    Token(TokenType t, string l)
    {
        type = t;
        literal = l;
    }
    // err
    Token()
    {
        type = TT_ERR;
        literal = TT_ERR;
    }
    string to_string()
    {
        return literal + "(" + type + ")" + " ";
    }
};

string printTokenVec(vector<Token> &vt, bool simple)
{
    string s = "";
    for (auto t : vt)
    {
        if (simple)
            s += t.literal + " ";
        else
            s += t.to_string();
    }
    return s;
}
string describeTokenVec(vector<Token> &vt) { return printTokenVec(vt, false); }
string printTokenVec(vector<Token> &vt) { return printTokenVec(vt, true); }

vector<Token> tokenize(string line)
{
    vector<Token> t;
    istringstream iss(line);
    string s;
    while (true)
    {
        iss >> s;
        cerr << "[tokenize] " << s << endl;
        if (s == TT_SEMICOLON)
        {
            t.push_back(Token(TT_SEMICOLON, s));
            break;
        }
        else if (s == TT_INT)
            t.push_back(Token(TT_INT, s));
        else if (s == TT_VEC)
            t.push_back(Token(TT_VEC, s));
        else if (s == TT_PINT)
            t.push_back(Token(TT_PINT, s));
        else if (s == TT_PVEC)
            t.push_back(Token(TT_PVEC, s));
        else if (s == TT_PVEC)
            t.push_back(Token(TT_PVEC, s));
        else if (s == TT_LBRAC)
            t.push_back(Token(TT_LBRAC, s));
        else if (s == TT_RBRAC)
            t.push_back(Token(TT_RBRAC, s));
        else if (s == TT_PLUS)
            t.push_back(Token(TT_PLUS, s));
        else if (s == TT_MINUS)
            t.push_back(Token(TT_MINUS, s));
        else if (s == TT_EQ)
            t.push_back(Token(TT_EQ, s));
        else if (s == TT_COMMA)
            t.push_back(Token(TT_COMMA, s));
        else if (s == TT_SEMICOLON)
            t.push_back(Token(TT_SEMICOLON, s));
        else if (isalpha(s[0]))
            t.push_back(Token(TT_VAR, s));
        else
            t.push_back(Token(TT_NUM, s));
    }
    return t;
}

// AST Node
struct Node
{
    TokenType type;
    int int_value;
    string var_value;
    vector<Node> vec_value;

    Node() { type = TT_ERR; }
    // Node (INT)
    Node(int v)
    {
        type = TT_INT;
        int_value = v;
    }
    // Node (VAR)
    Node(string s)
    {
        type = TT_VAR;
        var_value = s;
    }
    // Node (VECC)
    Node(Token t)
    {
        type = TT_VEC;
        vector<Node> v;
        istringstream iss(t.literal);
        cerr << "[Node (VECC)] START | " << t.literal << endl;
        string s;
        while (true)
        {
            iss >> s;
            if (s == TT_RBRAC)
                break;
            if (s == TT_LBRAC)
                continue;
            if (isalpha(s[0]))
                v.push_back(Node(s));
            else
                v.push_back(Node(stoi(s)));
        }
        vec_value = v;
        cerr << "[Node (VECC)] FINISHED | " << to_string() << endl;
    }
    // another way to initialize Node (VECC)
    // used in evalExpr and tests
    Node(vector<Node> v)
    {
        type = TT_VEC;
        vec_value = v;
    }
    string to_string()
    {
        if (type == TT_INT)
            return std::to_string(int_value);
        if (type == TT_VAR)
            return var_value;
        if (type == TT_VEC)
        {
            string s = "[ ";
            for (auto v : vec_value)
                s += v.to_string() + " ";
            s += "]";
            return s;
        }
        return TT_ERR;
    }
};

using Variables = map<string, Node>;

// Expression
// {Token, Expression, Expression, Node}
// {{"+", "+"}, {"int", 5}, {"int", 8}, NULL}
// {{"NODE", "NODE"}, NULL, NULL, {"int", 5, []}}
struct Expression
{
    Token *op = NULL;
    Expression *left = NULL;
    Expression *right = NULL;
    Node *node = NULL;

    Expression(Token *oper, Expression *leftExpr, Expression *rightExpr)
    {
        op = oper;
        left = leftExpr;
        right = rightExpr;
        cerr << "[INIT Expression Node Op] " << op->literal << endl;
    }
    // Node Expression (INT)
    Expression(int i)
    {
        op = new Token(TT_INTERNAL_NODE, TT_INTERNAL_NODE);
        node = new Node(i);
        cerr << "[INIT Expression Node INT] " << node->to_string() << endl;
    }
    // Node Expression (VAR)
    Expression(string s)
    {
        op = new Token(TT_INTERNAL_NODE, TT_INTERNAL_NODE);
        node = new Node(s);
        cerr << "[INIT Expression Node VAR] " << node->to_string() << endl;
    }
    // Node Expression (VECC)
    Expression(Token t)
    {
        // err
        if (t.type != TT_INTERNAL_VEC_CONTAINER)
        {
            op = new Token();
            node = new Node();
            return;
        }
        op = new Token(TT_INTERNAL_NODE, TT_INTERNAL_NODE);
        node = new Node(t);
        cerr << "[INIT Expression Node VECC] " << node->to_string() << endl;
    }
    // another way to initialize Expression Node (VECC)
    // used in evalExpr and tests
    Expression(vector<Node> vn)
    {
        op = new Token(TT_INTERNAL_NODE, TT_INTERNAL_NODE);
        node = new Node(vn);
        cerr << "[INIT Expression Node VEC] " << node->to_string() << endl;
    }

    // err
    Expression()
    {
        op = new Token();
    }
    string to_string()
    {
        string s = "expr(";
        if (op->type == TT_INTERNAL_NODE)
            s += node->to_string();
        else
            s += left->to_string() + op->literal + right->to_string();
        s += ")";
        return s;
    }
    ~Expression()
    {
        // string s = to_string();
        // cerr << "[DELETE] " << s << endl;
        // cerr << "[DELETE] " << s << " op" << endl;
        // delete op;
        // cerr << "[DELETE] " << s << " op"
        //      << " OK " << endl;
        // cerr << "[DELETE] " << s << " node" << endl;
        // delete node;
        // cerr << "[DELETE] " << s << " node"
        //      << " OK " << endl;
        // cerr << "[DELETE] " << s << " left" << endl;
        // delete left;
        // cerr << "[DELETE] " << s << " left"
        //      << " OK " << endl;
        // cerr << "[DELETE] " << s << " right" << endl;
        // delete right;
        // cerr << "[DELETE] " << s << " right"
        //      << " OK " << endl;
    }
};

// Statement
// {Token, Expression}
// {{"print_int", "print_int"}, {"+", "12345", "54321"}
// {{"int", "i"}, {"+", "5", "5"}}
struct Statement
{
    Token *var;
    Expression *expr;

    Statement(Token *variable, Expression *expression)
    {
        var = variable;
        expr = expression;
    }
    string to_string()
    {
        string s = "stmt(";
        if (var->type == TT_INT || var->type == TT_VEC)
            s += var->type + " " + var->literal + " = " + expr->to_string();
        else
            s += var->type + " " + expr->to_string();
        s += ")";
        return s;
    }
    ~Statement()
    {
        // delete var;
        // delete expr;
    }
};

// tokenizeVector
// 前から読んでいく
// 8 tokens -> 4 tokens | a + [ 1 2 3 ] ; -> a + ([ 1 2 3 ]) ;
// 9 tokens -> 3 tokens | [ 1 a ] + [ 2 b ] -> ([ 1 a ]) + ([ 2 b ])
// 3 tokens -> 3 tokens | a + b -> a + b
vector<Token> tokenizeVector(vector<Token> &vt)
{
    vector<Token> vt2;
    string vs;
    bool isAdding = false;
    for (auto t : vt)
    {
        if (t.type == TT_LBRAC)
        {
            vs = "[ "; // initialize
            isAdding = true;
            continue;
        }
        else if (t.type == TT_RBRAC)
        {
            vs += "]";
            vt2.push_back(Token(TT_INTERNAL_VEC_CONTAINER, vs));
            isAdding = false;
            continue;
        }

        if (isAdding)
        {
            if (t.type == TT_NUM)
                vs += t.literal + " ";
            else if (t.type == TT_VAR)
                vs += t.literal + " ";
            // ignore TT_COMMA
        }
        else
            vt2.push_back(t);
    }
    return vt2;
}

// parseExpr
// 後ろから読んでいく
// start_atは再帰で後から何文字飛ばすかを指定する、外から呼ぶときは0
// **必ず最後にセミコロンがある想定**
// **vtはtokenizeVectorに通してある想定**
// `int a = 5 ;`のうち
//     `int a =`はparseStmtで処理
//     `5 ;`はparseExlprで処理
//     (実際の処理はtokenize後なので、↑の表現においてwhitespaceは無視して良い)
Expression *parseExpr(vector<Token> &vt, int start_at)
{
    string s = printTokenVec(vt);
    cerr << "[parseExpr] " << std::to_string(start_at) << " | " << s << endl;

    // Nodeとセミコロンだけの場合
    // Nodeを返すだけ
    // e.g. "5;", "-100;", "a;"
    // sizeで見るのでvecは対応できない
    if (vt.size() == 2)
    {
        if (vt[0].type == TT_NUM)
            return new Expression(stoi(vt[0].literal));
        if (vt[0].type == TT_VAR)
            return new Expression(vt[0].literal);
        if (vt[0].type == TT_INTERNAL_VEC_CONTAINER)
            return new Expression(vt[0]);
    }

    // 演算子がある場合
    // 末尾開始、再帰的にExpressionを作る
    // 演算子の右をrightに、演算子の左をleftに入れる
    // 末尾開始なので、演算子の左はその左にさらに何かあるかもしれない
    // なので、演算子より左のToken列をparseする(再帰)
    // a + b + c + d
    // [a + b + c] (+) (d)
    //         a + b + c
    //         {a + b} (+) (c)
    //                 a + b
    //                 (a) (+) (b)
    //         {(a) (+) (b)} (+) (c)
    // [{(a) (+) (b)} (+) (c)] (+) (d)
    auto expr = new Expression();
    bool nextIsRight = true;
    auto pos = int(vt.size()) - start_at - 1; // off-by-one

    while (true)
    {
        if (pos < 0)
            return expr;

        if (expr->right != NULL)
            nextIsRight = false;

        if (vt[pos].type == TT_SEMICOLON)
        {
            cerr << "[parseExpr] " << start_at << " | " << pos << " | "
                 << "SEMICOLON" << endl;
            // ignore semicolons;
        }
        else if (vt[pos].type == TT_PLUS)
        {
            cerr << "[parseExpr] " << start_at << " | " << pos << " | "
                 << "PLUS" << endl;
            expr->op = new Token(TT_PLUS, TT_PLUS);
        }
        else if (vt[pos].type == TT_MINUS)
        {
            cerr << "[parseExpr] " << start_at << " | " << pos << " | "
                 << "MINUS" << endl;
            expr->op = new Token(TT_MINUS, TT_MINUS);
        }
        else if (vt[pos].type == TT_NUM || vt[pos].type == TT_INTERNAL_VEC_CONTAINER || vt[pos].type == TT_VAR)
        {
            // INTかVARかVECCかわからないので、全部用意しておく
            int val;
            string var;
            Token vecc;

            auto typ = vt[pos].type;
            if (typ == TT_VAR)
                var = vt[pos].literal;
            else if (typ == TT_NUM)
                val = stoi(vt[pos].literal);
            else if (typ == TT_INTERNAL_VEC_CONTAINER)
                vecc = vt[pos];

            if (nextIsRight)
            {
                cerr << "[parseExpr] " << start_at << " | " << pos << " | "
                     << "RIGHT " << vt[pos].literal << endl;
                if (typ == TT_VAR)
                    expr->right = new Expression(var);
                else if (typ == TT_NUM)
                    expr->right = new Expression(val);
                else if (typ == TT_INTERNAL_VEC_CONTAINER)
                    expr->right = new Expression(vecc);
            }
            else
            {
                if (pos == 0)
                {
                    cerr << "[parseExpr] " << start_at << " | " << pos << " | "
                         << "LEFT " << vt[pos].literal << endl;
                    if (typ == TT_VAR)
                        expr->left = new Expression(var);
                    else if (typ == TT_NUM)
                        expr->left = new Expression(val);
                    else if (typ == TT_INTERNAL_VEC_CONTAINER)
                        expr->left = new Expression(vecc);
                    cerr << "[parseExpr] " << start_at << " | " << pos << " | "
                         << "RETURN " << expr->to_string() << endl;
                    return expr;
                }
                else if (start_at == 0) // first loop; take care of the semicolon
                {
                    cerr << "[parseExpr] " << start_at << " | " << pos << " | "
                         << "LEFT_EXPR(1st) " << endl;
                    expr->left = parseExpr(vt, start_at + 3);
                    cerr << "[parseExpr] " << start_at << " | " << pos << " | "
                         << "GOT LEFT_EXPR(1st)" << endl;
                    return expr;
                }
                else
                {
                    cerr << "[parseExpr] " << start_at << " | " << pos << " | "
                         << "LEFT_EXPR " << endl;
                    expr->left = parseExpr(vt, start_at + 2);
                    cerr << "[parseExpr] " << start_at << " | " << pos << " | "
                         << "GOT LEFT_EXPR" << endl;
                    return expr;
                }
            }
        }
        --pos;
    }
    return expr;
}

Statement *parseStmt(vector<Token> &vt)
{
    // 代入は=より右側をparseExprに渡す
    if (vt.at(0).type == TT_INT || vt.at(0).type == TT_VEC)
    {
        auto t = new Token(vt.at(0).type, vt.at(1).literal);
        cerr << "[parseStmt] size" << int(vt.size()) << " " << printTokenVec(vt) << endl;
        vector<Token> vt2(int(vt.size()) - 3);
        for (int i = 0; i < int(vt.size() - 3); ++i)
            vt2[i] = vt[i + 3];
        auto vt3 = tokenizeVector(vt2);
        cerr << "[parseStmt] tokenizeVector " << printTokenVec(vt2) << " -> " << printTokenVec(vt3) << endl;
        auto expr = parseExpr(vt3, 0);
        cerr << "[parseStmt] Return: " << expr->to_string() << endl;
        return new Statement(t, expr);
    }
    // printはprint_*より右側をparseExprに渡す
    else if (vt.at(0).type == TT_PINT || vt.at(0).type == TT_PVEC)
    {
        auto t = new Token(vt.at(0).type, vt.at(0).literal);
        cerr << "[parseStmt] size" << int(vt.size()) << " " << printTokenVec(vt) << endl;
        vector<Token> vt2(int(vt.size()) - 1);
        for (int i = 0; i < int(vt.size() - 1); ++i)
            vt2[i] = vt[i + 1];
        auto vt3 = tokenizeVector(vt2);
        cerr << "[parseStmt] tokenizeVector " << printTokenVec(vt2) << " -> " << printTokenVec(vt3) << endl;
        auto expr = parseExpr(vt3, 0);
        cerr << "[parseStmt] Return" << endl;
        return new Statement(t, expr);
    }
    // err
    auto t = new Token();
    cerr << "[parseStmt] " << t->literal << endl;
    auto expr = new Expression();
    return new Statement(t, expr);
};

// resolveVar
// int a = b はbを解決したものをaにコピーする
// なので、Variablesに変数は入っていない
void resolveVar(Expression *expr, Variables *vars)
{
    if (expr->node->type == TT_VAR)
    {
        auto n = (*vars)[expr->node->var_value];
        cerr << "[evalExpr] NODE(RESOLVE) | " << (expr->node->var_value) << " -> " << n.to_string() << endl;
        // if (n.type == TT_INT)
        //     expr->node = new Node(n.int_value);
        // ポインタ代入でよさそう？(SEGVにならない)
        expr->node = &(*vars)[expr->node->var_value];
        cerr << "[evalExpr] NODE(RESOLVED) | " << expr->to_string() << endl;
    }
}

// resolveVarsInVec
// [ 1 2 x 4 ] 左から変数を解決しながら巡回する
void resolveVarsInVec(Node *vn, Variables *vars)
{
    if (vn->type == TT_VEC)
    {
        cerr << "[evalExpr] VEC(RESOLVE) | " << vn->to_string() << endl;
        for (int i = 0; i < vn->vec_value.size(); i++)
        {
            if (vn->vec_value[i].type == TT_VAR)
            {
                auto k = vn->vec_value[i].var_value;
                auto v = (*vars)[k];
                vn->vec_value[i] = Node(v.int_value);
            }
        }
        cerr << "[evalExpr] NODE(RESOLVED) | " << vn->to_string() << endl;
    }
}

void evalExpr(Expression *expr, Variables *vars)
{
    cerr << "[evalExpr] START | " << expr->to_string() << endl;
    // cerr << "CHECK NULL" << endl;
    // if (expr->op == NULL)
    //     cerr << "expr->op == NULL" << endl;
    // if (expr->node == NULL)
    //     cerr << "expr->node == NULL" << endl;
    // if (expr->left == NULL)
    //     cerr << "expr->left == NULL" << endl;
    // if (expr->right == NULL)
    //     cerr << "expr->right == NULL" << endl;
    // cerr << "CHECKED NULL" << endl;
    // cerr << expr->op->type << endl;

    // 自身がNodeなら終わり
    // `expr(a)`
    if (expr->op->type == TT_INTERNAL_NODE)
    {
        cerr << "[evalExpr] NODE | " << expr->to_string() << endl;
        resolveVar(expr, vars);
        return;
    }
    // leftがNodeじゃなければ再帰
    // `expr(expr(a)+expr(b))`は再帰しない
    // `expr(expr(expr(a)+expr(b))-expr(c))`は再帰する
    if (expr->left->op->type != TT_INTERNAL_NODE)
    {
        cerr << "[evalExpr] RECURSION | " << expr->left->to_string() << endl;
        evalExpr(expr->left, vars);
    }
    // 最後まで再帰したら`expr(expr(a)+expr(b))`のはず、opを評価していく
    // err check
    if (expr->left->op->type != TT_INTERNAL_NODE || expr->right->op->type != TT_INTERNAL_NODE)
        cerr << "[evalExpr] ERR | not TT_INTERNAL_NODE";
    cerr << "[evalExpr] EVAL | " << expr->to_string() << endl;
    // 計算する前に変数を解決する TT_VAR -> (TT_INT or TT_VEC)
    // leftとrightはともにTT_INT or TT_VECのどちらか(left.type==right.type)
    // vec内の変数はここでは解決しない
    resolveVar(expr->left, vars);
    resolveVar(expr->right, vars);
    if (expr->left->node->type == TT_INT)
    {
        int val;
        if (expr->op->type == TT_PLUS)
            val = expr->left->node->int_value + expr->right->node->int_value;
        else if (expr->op->type == TT_MINUS)
            val = expr->left->node->int_value - expr->right->node->int_value;
        auto expr2 = new Expression(val);
        cerr << "[evalExpr] " << ((expr->op->type == TT_PLUS) ? "PLUS" : "MINUS")
             << " | " << expr2->to_string() << endl;
        expr->left = NULL;
        expr->right = NULL;
        expr->op = new Token(TT_INTERNAL_NODE, TT_INTERNAL_NODE);
        expr->node = new Node(val);
    }
    else if (expr->left->node->type == TT_VEC)
    {
        vector<Node> val;
        // vec内の変数を解決する
        resolveVarsInVec(expr->left->node, vars);
        resolveVarsInVec(expr->right->node, vars);
        // 要素ごとに引き算して結果をvalに格納
        if (expr->op->type == TT_PLUS)
            for (int i = 0; i < expr->left->node->vec_value.size(); i++)
                val.push_back(Node(expr->left->node->vec_value[i].int_value + expr->right->node->vec_value[i].int_value));
        else if (expr->op->type == TT_MINUS)
            for (int i = 0; i < expr->left->node->vec_value.size(); i++)
                val.push_back(Node(expr->left->node->vec_value[i].int_value - expr->right->node->vec_value[i].int_value));

        auto expr2 = new Expression(val);
        cerr << "[evalExpr] " << ((expr->op->type == TT_PLUS) ? "PLUS" : "MINUS")
             << " | " << expr2->to_string() << endl;
        expr->left = NULL;
        expr->right = NULL;
        expr->op = new Token(TT_INTERNAL_NODE, TT_INTERNAL_NODE);
        expr->node = new Node(val);
    }
}

// evaluate
// StatementのTokenが
//     int|vecならExpressionの評価結果を代入し""を返す
//     print_*ならExpressionの評価結果をstringで返す
//     どこかでエラーがあれば"ERR"を返す
string evaluate(Statement *stmt, Variables *vars)
{
    cerr << "[evaluate] " << stmt->to_string() << endl;
    // 代入
    if (stmt->var->type == TT_INT || stmt->var->type == TT_VEC)
    {
        evalExpr(stmt->expr, vars);
        if (stmt->expr->op->type == TT_ERR)
            return TT_ERR;
        cerr << "[evaluate] SET VALUE " << stmt->expr->node->to_string() << " TO KEY " << stmt->var->literal << endl;
        (*vars)[stmt->var->literal] = *stmt->expr->node;
        cerr << "[evaluate] SET" << endl;
        return "";
    }
    // print
    else if (stmt->var->type == TT_PINT || stmt->var->type == TT_PVEC)
    {
        evalExpr(stmt->expr, vars);
        if (stmt->expr->op->type == TT_ERR || stmt->expr->node->type == TT_ERR)
            return TT_ERR;
        return stmt->expr->node->to_string();
    }
    return TT_ERR;
}

int main1()
{
    int N;
    cin >> N;
    {
        // trush the first line
        string x;
        getline(cin, x);
    }

    vector<vector<Token>> tokens;
    rep(i, N)
    {
        string s;
        getline(cin, s);
        // cerr << "[getline] " << s << endl;
        tokens.push_back(tokenize(s));
    };
    Variables pvars;
    rep(i, N)
    {
        auto stmt = parseStmt(tokens[i]);
        auto result = evaluate(stmt, &pvars);
        if (result != "")
            cout << result << endl;
    }

    return 0;
}

// #define testS(expr, result) cerr << (((expr) == (result)) ? "OK" : "NG") << ": " << (expr) << endl;

bool testS(string got, string want)
{
    bool result = got == want;
    cout << (result ? "OK" : "NG") << ": " << got << endl;
    return result;
}

bool testTokenize()
{
    bool result = true;

    auto v0 = tokenize("int a = 123 ;");
    result &= testS(describeTokenVec(v0), "int(int) a(VAR) =(=) 123(NUM) ;(;) ");

    auto v2 = tokenize("int b = a + 1000 ;");
    result &= testS(describeTokenVec(v2), "int(int) b(VAR) =(=) a(VAR) +(+) 1000(NUM) ;(;) ");
    return result;
}

bool testNode()
{
    bool result = true;

    auto n0 = Node(5);
    result &= testS(n0.to_string(), "5");

    auto n1 = Node("a");
    result &= testS(n1.to_string(), "a");
    result &= testS(n1.type, TT_VAR);
    result &= testS(n1.var_value, "a");

    // auto n2 = Node(vector<int>{1, 2, -3, 4, 5});
    // result &= testS(n2.to_string(), "[ 1 2 -3 4 5 ]");

    return result;
}

bool testExpr()
{
    bool result = true;

    auto e1 = Expression(5);
    result &= testS(e1.to_string(), "expr(5)");

    auto e2 = Expression("a");
    result &= testS(e2.to_string(), "expr(a)");

    auto e21 = Expression(new Token(TT_PLUS, TT_PLUS), &e1, &e2);
    result &= testS(e21.to_string(), "expr(expr(5)+expr(a))");

    return result;
}

bool testStmt()
{
    bool result = true;

    auto s1t = Token(TT_INT, "a");
    auto s1e = Expression(5);
    auto s1 = Statement(&s1t, &s1e);
    result &= testS(s1.to_string(), "stmt(int a = expr(5))");

    auto s2t = Token(TT_PINT, TT_PINT);
    auto s2e = Expression(5);
    auto s2 = Statement(&s2t, &s2e);
    result &= testS(s2.to_string(), "stmt(print_int expr(5))");

    return result;
}

bool testParseExpr()
{
    bool result = true;

    vector<Token> t0{Token(TT_NUM, "123"), Token(TT_SEMICOLON, ";")};
    auto e0 = parseExpr(t0, 0);
    result &= testS(e0->to_string(), "expr(123)");

    vector<Token> t1{Token(TT_NUM, "1"), Token(TT_PLUS, TT_PLUS), Token(TT_NUM, "10"), Token(TT_SEMICOLON, ";")};
    auto e1 = parseExpr(t1, 0);
    result &= testS(e1->to_string(), "expr(expr(1)+expr(10))");

    vector<Token> t2{Token(TT_NUM, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_NUM, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "500"), Token(TT_SEMICOLON, ";")};
    auto e2 = parseExpr(t2, 0);
    result &= testS(e2->to_string(), "expr(expr(expr(5)+expr(50))-expr(500))");

    vector<Token> t3{Token(TT_NUM, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_NUM, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "5000"), Token(TT_SEMICOLON, ";")};
    auto e3 = parseExpr(t3, 0);
    result &= testS(e3->to_string(), "expr(expr(expr(expr(5)+expr(50))-expr(500))-expr(5000))");

    vector<Token> t4{Token(TT_NUM, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_VAR, "a"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "5000"), Token(TT_SEMICOLON, ";")};
    auto e4 = parseExpr(t4, 0);
    result &= testS(e4->to_string(), "expr(expr(expr(expr(5)+expr(a))-expr(500))-expr(5000))");

    return result;
}

bool testParseStmt()
{
    bool result = true;

    vector<Token> t0{Token(TT_INT, TT_INT), Token(TT_VAR, "a"), Token(TT_EQ, TT_EQ), Token(TT_NUM, "123"), Token(TT_SEMICOLON, ";")};
    auto s0 = parseStmt(t0);
    result &= testS(s0->to_string(), "stmt(int a = expr(123))");

    vector<Token> t1{Token(TT_INT, TT_INT), Token(TT_VAR, "b"), Token(TT_EQ, TT_EQ), Token(TT_NUM, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_NUM, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "5000"), Token(TT_SEMICOLON, ";")};
    auto s1 = parseStmt(t1);
    result &= testS(s1->to_string(), "stmt(int b = expr(expr(expr(expr(5)+expr(50))-expr(500))-expr(5000)))");

    vector<Token> t11{Token(TT_INT, TT_INT), Token(TT_VAR, "b"), Token(TT_EQ, TT_EQ), Token(TT_NUM, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_VAR, "a"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "5000"), Token(TT_SEMICOLON, ";")};
    auto s11 = parseStmt(t11);
    result &= testS(s11->to_string(), "stmt(int b = expr(expr(expr(expr(5)+expr(a))-expr(500))-expr(5000)))");

    vector<Token> t2{Token(TT_PINT, TT_PINT), Token(TT_NUM, "123"), Token(TT_SEMICOLON, ";")};
    auto s2 = parseStmt(t2);
    result &= testS(s2->to_string(), "stmt(print_int expr(123))");

    vector<Token> t3{Token(TT_PINT, TT_PINT), Token(TT_NUM, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_NUM, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "5000"), Token(TT_SEMICOLON, ";")};
    auto s3 = parseStmt(t3);
    result &= testS(s3->to_string(), "stmt(print_int expr(expr(expr(expr(5)+expr(50))-expr(500))-expr(5000)))");

    vector<Token> t31{Token(TT_PINT, TT_PINT), Token(TT_NUM, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_VAR, "a"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "5000"), Token(TT_SEMICOLON, ";")};
    auto s31 = parseStmt(t31);
    result &= testS(s31->to_string(), "stmt(print_int expr(expr(expr(expr(5)+expr(a))-expr(500))-expr(5000)))");

    return result;
}

bool testEvalExpr()
{
    bool result = true;

    Variables m;

    vector<Token> t0{Token(TT_NUM, "123"), Token(TT_SEMICOLON, ";")};
    auto e0 = parseExpr(t0, 0);
    evalExpr(e0, &m);
    result &= testS(e0->to_string(), "expr(123)");

    vector<Token> t1{Token(TT_NUM, "1"), Token(TT_PLUS, TT_PLUS), Token(TT_NUM, "10"), Token(TT_SEMICOLON, ";")};
    auto e1 = parseExpr(t1, 0);
    evalExpr(e1, &m);
    result &= testS(e1->to_string(), "expr(11)");

    vector<Token> t2{Token(TT_NUM, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_NUM, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "500"), Token(TT_SEMICOLON, ";")};
    auto e2 = parseExpr(t2, 0);
    evalExpr(e2, &m);
    result &= testS(e2->to_string(), "expr(-445)");

    vector<Token> t3{Token(TT_NUM, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_NUM, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "5000"), Token(TT_SEMICOLON, ";")};
    auto e3 = parseExpr(t3, 0);
    evalExpr(e3, &m);
    result &= testS(e3->to_string(), "expr(-5445)");

    // with var

    // test the map
    m["a"] = Node(321);
    result &= testS(m["a"].to_string(), "321");

    vector<Token> t4{Token(TT_VAR, "a"), Token(TT_SEMICOLON, ";")};
    auto e4 = parseExpr(t4, 0);
    evalExpr(e4, &m);
    result &= testS(e4->to_string(), "expr(321)");

    m["b"] = Node(100000);
    vector<Token> t5{Token(TT_VAR, "a"), Token(TT_PLUS, TT_PLUS), Token(TT_NUM, "-321"), Token(TT_MINUS, TT_MINUS), Token(TT_VAR, "b"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "5000"), Token(TT_SEMICOLON, ";")};
    auto e5 = parseExpr(t5, 0);
    evalExpr(e5, &m);
    result &= testS(e5->to_string(), "expr(-105000)");

    return result;
}

bool testEval()
{
    bool result = true;

    Variables m;

    // print_int 123 ;
    vector<Token> t01{Token(TT_PINT, TT_PINT), Token(TT_NUM, "123"), Token(TT_SEMICOLON, ";")};
    auto s01 = parseStmt(t01);
    result &= testS(evaluate(s01, &m), "123");

    // print_int a ;
    m["a"] = Node(321);
    vector<Token> t02{Token(TT_PINT, TT_PINT), Token(TT_VAR, "a"), Token(TT_SEMICOLON, ";")};
    auto s02 = parseStmt(t02);
    result &= testS(evaluate(s02, &m), "321");

    // int a = 123 ;
    vector<Token> t0{Token(TT_INT, TT_INT), Token(TT_VAR, "a"), Token(TT_EQ, TT_EQ), Token(TT_NUM, "123"), Token(TT_SEMICOLON, ";")};
    auto s0 = parseStmt(t0);
    auto r0 = evaluate(s0, &m);
    result &= testS(r0, "");
    result &= testS(m["a"].to_string(), Node(123).to_string());

    // int b = 5 + 50 - 500 - a ;
    vector<Token> t1{Token(TT_INT, TT_INT), Token(TT_VAR, "b"), Token(TT_EQ, TT_EQ), Token(TT_NUM, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_NUM, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_VAR, "a"), Token(TT_SEMICOLON, ";")};
    auto s1 = parseStmt(t1);
    auto r1 = evaluate(s1, &m);
    result &= testS(r1, "");
    result &= testS(m["b"].to_string(), Node(-568).to_string());

    vector<Token> t3{Token(TT_PINT, TT_PINT), Token(TT_NUM, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_NUM, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_NUM, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_VAR, "a"), Token(TT_SEMICOLON, ";")};
    auto s3 = parseStmt(t3);
    result &= testS(evaluate(s3, &m), "-568");

    return result;
}

bool testEvalTokenStr()
{
    bool result = true;

    Variables m;
    auto v0 = tokenize("int a = 123 ;");
    result &= testS(describeTokenVec(v0), "int(int) a(VAR) =(=) 123(NUM) ;(;) ");
    auto s0 = parseStmt(v0);
    result &= testS(s0->to_string(), "stmt(int a = expr(123))");
    auto r0 = evaluate(s0, &m);
    result &= testS(r0, "");
    result &= testS(m["a"].to_string(), Node(123).to_string());

    return result;
}

bool testTokenizeV()
{
    bool result = true;

    auto v1 = tokenize("vec v = [ 1 , 2 , -3 ] ;");
    result &= testS(describeTokenVec(v1), "vec(vec) v(VAR) =(=) [([) 1(NUM) ,(,) 2(NUM) ,(,) -3(NUM) ](]) ;(;) ");

    auto v2 = tokenize("print_vec [ 1 , 2 , -3 ] + [ 9 , 8 , -13 ] ;");
    result &= testS(describeTokenVec(v2), "print_vec(print_vec) [([) 1(NUM) ,(,) 2(NUM) ,(,) -3(NUM) ](]) +(+) [([) 9(NUM) ,(,) 8(NUM) ,(,) -13(NUM) ](]) ;(;) ");

    auto v3 = tokenize("print_vec [ 1 , 2 , -3 ] + a ;");
    result &= testS(describeTokenVec(v3), "print_vec(print_vec) [([) 1(NUM) ,(,) 2(NUM) ,(,) -3(NUM) ](]) +(+) a(VAR) ;(;) ");

    return result;
}

bool testNodeV()
{
    bool result = true;

    auto n2 = Node(vector<Node>{Node(1), Node(2), Node(-3), Node(4), Node(5)});
    result &= testS(n2.to_string(), "[ 1 2 -3 4 5 ]");

    auto n3 = Node(vector<Node>{Node(1), Node(2), Node("a"), Node("b"), Node(5)});
    result &= testS(n3.to_string(), "[ 1 2 a b 5 ]");

    return result;
}

bool testExprV()
{
    bool result = true;

    auto e2 = Expression(vector<Node>{Node(1), Node(2), Node(-3), Node(4), Node(5)});
    result &= testS(e2.to_string(), "expr([ 1 2 -3 4 5 ])");

    auto e21 = Expression(vector<Node>{Node(1), Node(2), Node("a"), Node("b"), Node(5)});
    result &= testS(e21.to_string(), "expr([ 1 2 a b 5 ])");

    auto e4 = Expression(new Token(TT_PLUS, TT_PLUS), &e2, &e21);
    result &= testS(e4.to_string(), "expr(expr([ 1 2 -3 4 5 ])+expr([ 1 2 a b 5 ]))");

    auto e5 = Expression(new Token(TT_MINUS, TT_MINUS), &e4, &e2);
    result &= testS(e5.to_string(), "expr(expr(expr([ 1 2 -3 4 5 ])+expr([ 1 2 a b 5 ]))-expr([ 1 2 -3 4 5 ]))");

    auto e6 = Expression(new Token(TT_PLUS, TT_PLUS), &e4, new Expression("a"));
    result &= testS(e6.to_string(), "expr(expr(expr([ 1 2 -3 4 5 ])+expr([ 1 2 a b 5 ]))+expr(a))");

    return result;
}

bool testStmtV()
{
    bool result = true;

    auto s1t = Token(TT_VEC, "v");
    auto s1e = Expression(vector<Node>{Node(1), Node(2), Node("a"), Node("b"), Node(5)});
    auto s1 = Statement(&s1t, &s1e);
    result &= testS(s1.to_string(), "stmt(vec v = expr([ 1 2 a b 5 ]))");

    auto s2t = Token(TT_PVEC, TT_PVEC);
    auto s2e = Expression(vector<Node>{Node(1), Node(2), Node("a"), Node("b"), Node(5)});
    auto s2 = Statement(&s2t, &s2e);
    result &= testS(s2.to_string(), "stmt(print_vec expr([ 1 2 a b 5 ]))");

    auto s3t = Token(TT_PVEC, TT_PVEC);
    auto s3e = Expression(new Token(TT_PLUS, TT_PLUS), new Expression(vector<Node>{Node(1), Node(2), Node("a"), Node("b"), Node(5)}), new Expression("a"));
    auto s3 = Statement(&s3t, &s3e);
    result &= testS(s3.to_string(), "stmt(print_vec expr(expr([ 1 2 a b 5 ])+expr(a)))");

    return result;
}

bool testTokenizeVector()
{
    bool result = true;

    auto t1 = tokenize("[ 1 , x , -3 ] + [ 9 , 8 , 13 ] + c ;");
    result &= testS(describeTokenVec(t1), "[([) 1(NUM) ,(,) x(VAR) ,(,) -3(NUM) ](]) +(+) [([) 9(NUM) ,(,) 8(NUM) ,(,) 13(NUM) ](]) +(+) c(VAR) ;(;) ");
    result &= testS((t1.size() == 18) ? "Size=18" : "Size!=18", "Size=18");
    auto t2 = tokenizeVector(t1);
    result &= testS(describeTokenVec(t2), "[ 1 x -3 ](VECC) +(+) [ 9 8 13 ](VECC) +(+) c(VAR) ;(;) ");
    result &= testS((t2.size() == 6) ? "Size=6" : "Size!=6", "Size=6");

    auto t31 = tokenize("[ 1 , x , -3 ] ;");
    auto t32 = tokenizeVector(t31);
    result &= testS(describeTokenVec(t32), "[ 1 x -3 ](VECC) ;(;) ");
    result &= testS((t32.size() == 2) ? "Size=2" : "Size!=2", "Size=2");

    auto n33 = Node(t32[0]);
    result &= testS(n33.to_string(), "[ 1 x -3 ]");

    auto n34 = Expression(t32[0]);
    result &= testS(n34.to_string(), "expr([ 1 x -3 ])");

    return result;
}

bool testParseExprV()
{
    bool result = true;

    auto t0 = tokenize("[ 1 , 2 , -3 ] ;");
    t0 = tokenizeVector(t0);
    auto e0 = parseExpr(t0, 0);
    result &= testS(e0->to_string(), "expr([ 1 2 -3 ])");

    auto t1 = tokenize("[ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] ;");
    t1 = tokenizeVector(t1);
    auto e1 = parseExpr(t1, 0);
    result &= testS(e1->to_string(), "expr(expr([ 1 2 -3 ])+expr([ 9 8 13 ]))");

    auto t2 = tokenize("[ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] - [ 10 , 10 , 10 ] ;");
    t2 = tokenizeVector(t2);
    auto e2 = parseExpr(t2, 0);
    result &= testS(e2->to_string(), "expr(expr(expr([ 1 2 -3 ])+expr([ 9 8 13 ]))-expr([ 10 10 10 ]))");

    auto t3 = tokenize("[ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] - [ 10 , 10 , 10 ] - [ -100 , -200 , -300 ] ;");
    t3 = tokenizeVector(t3);
    auto e3 = parseExpr(t3, 0);
    result &= testS(e3->to_string(), "expr(expr(expr(expr([ 1 2 -3 ])+expr([ 9 8 13 ]))-expr([ 10 10 10 ]))-expr([ -100 -200 -300 ]))");

    auto t4 = tokenize("[ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] - [ 10 , x , 10 ] + y ;");
    t4 = tokenizeVector(t4);
    auto e4 = parseExpr(t4, 0);
    result &= testS(e4->to_string(), "expr(expr(expr(expr([ 1 2 -3 ])+expr([ 9 8 13 ]))-expr([ 10 x 10 ]))+expr(y))");

    return result;
}

bool testParseStmtV()
{
    bool result = true;

    auto t0 = tokenize("vec a = [ 1 , 2 , -3 ] ;");
    auto s0 = parseStmt(t0);
    result &= testS(s0->to_string(), "stmt(vec a = expr([ 1 2 -3 ]))");

    auto t1 = tokenize("vec b = [ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] - [ 10 , x , 10 ] + y ;");
    auto s1 = parseStmt(t1);
    result &= testS(s1->to_string(), "stmt(vec b = expr(expr(expr(expr([ 1 2 -3 ])+expr([ 9 8 13 ]))-expr([ 10 x 10 ]))+expr(y)))");

    auto t2 = tokenize("print_vec [ 1 , 2 , -3 ] ;");
    auto s2 = parseStmt(t2);
    result &= testS(s2->to_string(), "stmt(print_vec expr([ 1 2 -3 ]))");

    auto t3 = tokenize("print_vec [ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] - [ 10 , x , 10 ] + y ;");
    auto s3 = parseStmt(t3);
    result &= testS(s3->to_string(), "stmt(print_vec expr(expr(expr(expr([ 1 2 -3 ])+expr([ 9 8 13 ]))-expr([ 10 x 10 ]))+expr(y)))");

    return result;
}

bool testEvalExprV()
{
    bool result = true;

    Variables m;

    auto t0 = tokenize("[ 1 , 2 , -3 ] ;");
    t0 = tokenizeVector(t0);
    auto e0 = parseExpr(t0, 0);
    evalExpr(e0, &m);
    result &= testS(e0->to_string(), "expr([ 1 2 -3 ])");

    auto t1 = tokenize("[ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] ;");
    t1 = tokenizeVector(t1);
    auto e1 = parseExpr(t1, 0);
    evalExpr(e1, &m);
    result &= testS(e1->to_string(), "expr([ 10 10 10 ])");

    auto t2 = tokenize("[ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] - [ 10 , 10 , 10 ] ;");
    t2 = tokenizeVector(t2);
    auto e2 = parseExpr(t2, 0);
    evalExpr(e2, &m);
    result &= testS(e2->to_string(), "expr([ 0 0 0 ])");

    auto t3 = tokenize("[ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] - [ 10 , 10 , 10 ] - [ -100 , -200 , -300 ] ;");
    t3 = tokenizeVector(t3);
    auto e3 = parseExpr(t3, 0);
    evalExpr(e3, &m);
    result &= testS(e3->to_string(), "expr([ 100 200 300 ])");

    m["x"] = Node(10);
    result &= testS(m["x"].to_string(), "10");
    m["y"] = Node(Token(TT_INTERNAL_VEC_CONTAINER, "[ 100 200 300 ]"));
    result &= testS(m["y"].to_string(), "[ 100 200 300 ]");

    auto t4 = tokenize("[ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] - [ 10 , x , 10 ] + y ;");
    t4 = tokenizeVector(t4);
    auto e4 = parseExpr(t4, 0);
    evalExpr(e4, &m);
    result &= testS(e4->to_string(), "expr([ 100 200 300 ])");

    return result;
}
bool testNum()
{
    bool r = true;
    r &= testTokenize();
    r &= testNode();
    r &= testExpr();
    r &= testStmt();
    r &= testParseExpr();
    r &= testParseStmt();
    r &= testEvalExpr();
    r &= testEval();
    r &= testEvalTokenStr();
    return r;
}

bool testVec()
{
    bool r = true;
    r &= testTokenizeV();
    r &= testNodeV();
    r &= testExprV();
    r &= testStmtV();
    r &= testTokenizeVector();
    r &= testParseExprV();
    r &= testParseStmtV();
    r &= testEvalExprV();
    // r &= testEvalV();
    // r &= testEvalTokenStrV();
    return r;
}

int main()
{
    // HACK: disable cerr (trace info)
    cerr.setstate(std::ios::failbit);
    if (!(testNum() && testVec()))
    {
        cout << "test failed" << endl;
        return 1;
    }
    main1();
    return 0;
}
