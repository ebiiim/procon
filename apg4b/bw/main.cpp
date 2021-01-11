#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
using namespace std;

using TokenType = string;

const TokenType TT_INT = "int";
const TokenType TT_VEC = "vec";
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
// 変数
const TokenType TT_VAR = "VAR";
// 数値
const TokenType TT_NUM = "NUM";
// エラーを示す。Tokenのデフォルトコンストラクタもこれになる。
const TokenType TT_ERR = "ERR";
// Expressionにおいて、自身がNodeであることを示す。{TT_INTERNAL_NODE, left, NULL}
const TokenType TT_INTERNAL_NODE = "NODE";

struct Token
{
    TokenType type;
    string literal;

    Token(TokenType t, string l)
    {
        type = t;
        literal = l;
    }
    Token() // err
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
        // cerr << "[tokenize] " << s << endl;
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
    Node(int v)
    {
        type = TT_INT;
        int_value = v;
    }
    Node(string s)
    {
        type = TT_VAR;
        var_value = s;
    }
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
    Expression(int i)
    {
        op = new Token(TT_INTERNAL_NODE, TT_INTERNAL_NODE);
        node = new Node(i);
        cerr << "[INIT Expression Node INT] " << node->to_string() << endl;
    }
    Expression(string s)
    {
        op = new Token(TT_INTERNAL_NODE, TT_INTERNAL_NODE);
        node = new Node(s);
        cerr << "[INIT Expression Node VAR] " << node->to_string() << endl;
    }
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
        // cerr << "[Statement.to_string]" << endl;
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

// parseExpr
// 必ず最後にセミコロンがある想定
Expression *parseExpr(vector<Token> &vt, int start_at)
{
    string s = printTokenVec(vt);
    cerr << "[parseExpr] " << std::to_string(start_at) << " | " << s << endl;

    // "5;"
    // "-100;"
    // "a;"
    if (vt.size() == 2)
    {
        if (vt[0].type == TT_NUM)
            return new Expression(stoi(vt[0].literal));
        if (vt[0].type == TT_VAR)
            return new Expression(vt[0].literal);
        // vec
        //return new Expression(parseVec(vt[0].literal));
    }

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
        else if (vt[pos].type == TT_NUM || vt[pos].type == TT_VAR)
        {
            bool isVar = (vt[pos].type == TT_VAR);
            // どちらか使う
            int val;
            string var;

            if (isVar)
                var = vt[pos].literal;
            else
                val = stoi(vt[pos].literal);

            if (nextIsRight)
            {
                cerr << "[parseExpr] " << start_at << " | " << pos << " | "
                     << "RIGHT " << (isVar ? var : std::to_string(val)) << endl;
                expr->right = isVar ? new Expression(var) : new Expression(val);
            }
            else
            {
                if (pos == 0)
                {
                    cerr << "[parseExpr] " << start_at << " | " << pos << " | "
                         << "LEFT " << (isVar ? var : std::to_string(val)) << endl;
                    expr->left = isVar ? new Expression(var) : new Expression(val);
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
        // else if (vt[pos].type == TT_VEC)
        // {
        //     vector<int> val;
        //     // vector<int> val = parseVec(vt[pos].literal);
        //     if (nextIsRight)
        //         expr->right = new Expression(val);
        //     else
        //     {
        //         if (pos == 0)
        //         {
        //             expr->left = new Expression(val);
        //             return expr;
        //         }
        //         else if (start_at == 0) // first loop; take care of the semicolon
        //             expr->left = parseExpr(vt, start_at + 3);
        //         else
        //         {
        //             expr->left = parseExpr(vt, start_at + 2);
        //         }
        //     }
        // }
        --pos;
        // cerr << "[parseExpr] " << start_at << " | " << pos << " | "
        //      << "POS-- | " << pos << endl;
    }
    return expr;
}

Statement *parseStmt(vector<Token> &vt)
{
    if (vt.at(0).type == TT_INT)
    {
        auto t = new Token(vt.at(0).type, vt.at(1).literal);
        string s = "";
        for (auto t : vt)
            s += t.literal + " ";
        cerr << "[parseStmt] size" << int(vt.size()) << " " << s << endl;
        vector<Token> vt2(int(vt.size()) - 3);
        for (int i = 0; i < int(vt.size() - 3); i++)
            vt2[i] = vt[i + 3];
        auto expr = parseExpr(vt2, 0);
        cerr << "[parseStmt] Return: " << expr->to_string() << endl;
        return new Statement(t, expr);
    }
    else if (vt.at(0).type == TT_VEC)
    {
        auto t = new Token(vt.at(0).type, vt.at(1).literal);
        cerr << "[parseStmt] " << t->literal << endl;
        auto expr = parseExpr(vt, 0);
        return new Statement(t, expr);
    }
    else if (vt.at(0).type == TT_PINT)
    {
        auto t = new Token(vt.at(0).type, vt.at(0).literal);
        string s = "";
        for (auto t : vt)
            s += t.literal + " ";
        cerr << "[parseStmt] size" << int(vt.size()) << " " << s << endl;
        vector<Token> vt2(int(vt.size()) - 1);
        for (int i = 0; i < int(vt.size() - 1); i++)
            vt2[i] = vt[i + 1];
        auto expr = parseExpr(vt2, 0);
        cerr << "[parseStmt] Return" << endl;
        return new Statement(t, expr);
    }
    else if (vt.at(0).type == TT_PVEC)
    {
        auto t = new Token(vt.at(0).type, vt.at(0).literal);
        cerr << "[parseStmt] " << t->literal << endl;
        auto expr = parseExpr(vt, 1);
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
    // (print_int a)のaとか
    if (expr->op->type == TT_INTERNAL_NODE)
    {
        cerr << "[evalExpr] NODE | " << expr->to_string() << endl;
        resolveVar(expr, vars);
        return;
    }
    // leftがNodeじゃなければ再帰
    // (a+b+c)のcとか
    if (expr->left->op->type != TT_INTERNAL_NODE)
    {
        cerr << "[evalExpr] RECURSION | " << expr->left->to_string() << endl;
        evalExpr(expr->left, vars);
    }
    // err check
    if (expr->left->op->type != TT_INTERNAL_NODE || expr->right->op->type != TT_INTERNAL_NODE)
        cerr << "[evalExpr] ERR | not TT_INTERNAL_NODE";

    cerr << "[evalExpr] CALC | " << expr->to_string() << endl;
    // 計算する前に変数を解決する
    resolveVar(expr->left, vars);
    resolveVar(expr->right, vars);
    if (expr->op->type == TT_PLUS && expr->left->node->type == TT_INT)
    {
        auto val = expr->left->node->int_value + expr->right->node->int_value;
        auto expr2 = new Expression(val);
        cerr << "[evalExpr] PLUS | " << expr2->to_string() << endl;
        // expr = expr2; // TODO: これなんでダメ？
        expr->left = NULL;
        expr->right = NULL;
        expr->op = new Token(TT_INTERNAL_NODE, TT_INTERNAL_NODE);
        expr->node = new Node(val);
    }
    else if (expr->op->type == TT_MINUS && expr->left->node->type == TT_INT)
    {
        auto val = expr->left->node->int_value - expr->right->node->int_value;
        auto expr2 = new Expression(val);
        cerr << "[evalExpr] MINUS | " << expr2->to_string() << endl;
        expr->left = NULL;
        expr->right = NULL;
        expr->op = new Token(TT_INTERNAL_NODE, TT_INTERNAL_NODE);
        expr->node = new Node(val);
    }
    // else if (expr->op->type == TT_PLUS && expr->left->node->type == TT_VEC)
    // {
    // }
    // else if (expr->op->type == TT_MINUS && expr->left->node->type == TT_VEC)
    // {
    // }
}

// evaluate
// StatementのTokenが
//     int|vecならExpressionの評価結果を代入し""を返す
//     print_*ならExpressionの評価結果をstringで返す
//     どこかでエラーがあれば"ERR"を返す
string evaluate(Statement *stmt, Variables *vars)
{
    cerr << "[evaluate] " << stmt->to_string() << endl;
    if (stmt->var->type == TT_INT)
    {
        evalExpr(stmt->expr, vars);
        if (stmt->expr->op->type == TT_ERR)
            return TT_ERR;
        cerr << "[evaluate] SET VALUE " << stmt->expr->node->to_string() << " TO KEY " << stmt->var->literal << endl;
        (*vars)[stmt->var->literal] = *stmt->expr->node;
        cerr << "[evaluate] SET" << endl;
        return "";
    }
    // else if (stmt->var->type == TT_VEC)
    // {
    //     evalExpr(stmt->expr);
    //     if (stmt->expr->op->type == TT_ERR)
    //         return TT_ERR;
    //     (*vars)[stmt->var->literal] = *stmt->expr->node;
    //     return "";
    // }
    else if (stmt->var->type == TT_PINT)
    {
        evalExpr(stmt->expr, vars);
        if (stmt->expr->op->type == TT_ERR || stmt->expr->node->type == TT_ERR)
            return TT_ERR;
        return stmt->expr->node->to_string();
    }
    // else if (stmt->var->type == TT_PVEC)
    // {
    //     evalExpr(stmt->expr);
    //     if (stmt->expr->op->type == TT_ERR || stmt->expr->node->type == TT_ERR)
    //         return TT_ERR;
    //     return stmt->expr->node->to_string();
    // }
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
    result &= testS((*(&m))["a"].to_string(), "321");

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

bool testParseExprV()
{
    bool result = true;

    auto t0 = tokenize("[ 1 , 2 , -3 ] ;");
    auto e0 = parseExpr(t0, 0);
    result &= testS(e0->to_string(), "expr([ 1 2 -3 ])");

    auto t1 = tokenize("[ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] ;");
    auto e1 = parseExpr(t1, 0);
    result &= testS(e1->to_string(), "expr([ 1 2 -3 ])+expr([ 9 8 13 ])");

    auto t2 = tokenize("[ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] - [ 10 , 10 , 10 ] ;");
    auto e2 = parseExpr(t2, 0);
    result &= testS(e2->to_string(), "expr(expr(expr([ 1 2 -3 ])+expr([ 9 8 13 ]))-expr([ 10 10 10 ]))");

    auto t3 = tokenize("[ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] - [ 10 , 10 , 10 ] - [ -100 , -200 , -300 ] ;");
    auto e3 = parseExpr(t3, 0);
    result &= testS(e3->to_string(), "expr(expr(expr(expr(expr([ 1 2 -3 ])+expr([ 9 8 13 ]))-expr([ 10 10 10 ])))-expr([ -100 -200 -300]))");

    auto t4 = tokenize("[ 1 , 2 , -3 ] + [ 9 , 8 , 13 ] - [ 10 , x , 10 ] + y ;");
    auto e4 = parseExpr(t4, 0);
    result &= testS(e4->to_string(), "expr(expr(expr(expr(expr([ 1 2 -3 ])+expr([ 9 8 13 ]))-expr([ 10 x 10 ])))+expr(y))");

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
    // r &= testParseExprV();
    // r &= testParseStmtV();
    // r &= testEvalExprV();
    // r &= testEvalV();
    // r &= testEvalTokenStrV();
    return r;
}

int main()
{
    // HACK: disable cerr
    // cerr.setstate(std::ios::failbit);
    if (!(testNum() && testVec()))
    {
        cout << "test failed" << endl;
        return 1;
    }
    main1();
    return 0;
}
