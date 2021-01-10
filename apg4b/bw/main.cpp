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
};

vector<Token> tokenize(string line)
{
    vector<Token> t;
    istringstream iss(line);
    string s;
    while (true)
    {
        iss >> s;
        // cout << "[tokenize] " << s << endl;
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
        else
            t.push_back(Token(TT_VAR, s));
    }
    return t;
}

// AST Node
struct Node
{
    TokenType type;
    int int_value;
    vector<int> vec_value;

    Node() { type = TT_ERR; }
    Node(int v)
    {
        type = TT_INT;
        int_value = v;
    }
    Node(vector<int> v)
    {
        type = TT_VEC;
        vec_value = v;
    }
    string to_string()
    {
        // TT_INT
        if (type == TT_INT)
            return std::to_string(int_value);
        // TT_VEC
        string s = "[ ";
        for (auto v : vec_value)
            s += std::to_string(v) + " ";
        s += "]";
        return s;
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
        // cout << "[INIT Expression Node Op] " << op->literal << endl;
    }
    Expression(int i)
    {
        op = new Token(TT_INTERNAL_NODE, TT_INTERNAL_NODE);
        node = new Node(i);
        // cout << "[INIT Expression Node INT] " << node->to_string() << endl;
    }
    Expression(vector<int> vi)
    {
        op = new Token(TT_INTERNAL_NODE, TT_INTERNAL_NODE);
        node = new Node(vi);
        // cout << "[INIT Expression Node VEC] " << node->to_string() << endl;
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
        // cout << "[DELETE] " << s << endl;
        // cout << "[DELETE] " << s << " op" << endl;
        // delete op;
        // cout << "[DELETE] " << s << " op"
        //      << " OK " << endl;
        // cout << "[DELETE] " << s << " node" << endl;
        // delete node;
        // cout << "[DELETE] " << s << " node"
        //      << " OK " << endl;
        // cout << "[DELETE] " << s << " left" << endl;
        // delete left;
        // cout << "[DELETE] " << s << " left"
        //      << " OK " << endl;
        // cout << "[DELETE] " << s << " right" << endl;
        // delete right;
        // cout << "[DELETE] " << s << " right"
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
        // cout << "[Statement.to_string]" << endl;
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

vector<int> parseVec(string s)
{
}

Expression *parseExpr(vector<Token> &vt, int start_at)
{
    string s = "";
    for (auto t : vt)
        s += t.literal + " ";
    cout << "[parseExpr] " << std::to_string(start_at) << " | " << s << endl;

    // 必ず最後にセミコロンがある想定
    if (vt.size() == 2)
    {
        if (vt[0].type == TT_INT)
            return new Expression(stoi(vt[0].literal));
        return new Expression(parseVec(vt[0].literal));
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
            cout << "[parseExpr] " << start_at << " | " << pos << " | "
                 << "SEMICOLON" << endl;
            // ignore semicolons;
        }
        else if (vt[pos].type == TT_PLUS)
        {
            cout << "[parseExpr] " << start_at << " | " << pos << " | "
                 << "PLUS" << endl;
            expr->op = new Token(TT_PLUS, TT_PLUS);
        }
        else if (vt[pos].type == TT_MINUS)
        {
            cout << "[parseExpr] " << start_at << " | " << pos << " | "
                 << "MINUS" << endl;
            expr->op = new Token(TT_MINUS, TT_MINUS);
        }
        else if (vt[pos].type == TT_INT)
        {
            int val = stoi(vt[pos].literal);
            if (nextIsRight)
            {
                cout << "[parseExpr] " << start_at << " | " << pos << " | "
                     << "RIGHT " << val << endl;
                expr->right = new Expression(val);
            }
            else
            {
                if (pos == 0)
                {
                    cout << "[parseExpr] " << start_at << " | " << pos << " | "
                         << "LEFT " << val << endl;
                    expr->left = new Expression(val);
                    cout << "[parseExpr] " << start_at << " | " << pos << " | "
                         << "RETURN " << expr->to_string() << endl;
                    return expr;
                }
                else if (start_at == 0) // first loop; take care of the semicolon
                {
                    cout << "[parseExpr] " << start_at << " | " << pos << " | "
                         << "LEFT_EXPR(1st) " << endl;
                    expr->left = parseExpr(vt, start_at + 3);
                    cout << "[parseExpr] " << start_at << " | " << pos << " | "
                         << "GOT LEFT_EXPR(1st)" << endl;
                    return expr;
                }
                else
                {
                    cout << "[parseExpr] " << start_at << " | " << pos << " | "
                         << "LEFT_EXPR " << endl;
                    expr->left = parseExpr(vt, start_at + 2);
                    cout << "[parseExpr] " << start_at << " | " << pos << " | "
                         << "GOT LEFT_EXPR" << endl;
                    return expr;
                }
            }
        }
        else if (vt[pos].type == TT_VEC)
        {
            vector<int> val = parseVec(vt[pos].literal);
            if (nextIsRight)
                expr->right = new Expression(val);
            else
            {
                if (pos == 0)
                {
                    expr->left = new Expression(val);
                    return expr;
                }
                else if (start_at == 0) // first loop; take care of the semicolon
                    expr->left = parseExpr(vt, start_at + 3);
                else
                {
                    expr->left = parseExpr(vt, start_at + 2);
                }
            }
        }
        --pos;
        // cout << "[parseExpr] " << start_at << " | " << pos << " | "
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
        cout << "[parseStmt] size" << int(vt.size()) << " " << s << endl;
        vector<Token> vt2(int(vt.size()) - 3);
        for (int i = 0; i < int(vt.size() - 3); i++)
            vt2[i] = vt[i + 3];
        auto expr = parseExpr(vt2, 0);
        cout << "[parseStmt] Return" << endl;
        return new Statement(t, expr);
    }
    else if (vt.at(0).type == TT_VEC)
    {
        auto t = new Token(vt.at(0).type, vt.at(1).literal);
        cout << "[parseStmt] " << t->literal << endl;
        auto expr = parseExpr(vt, 0);
        return new Statement(t, expr);
    }
    else if (vt.at(0).type == TT_PINT)
    {
        auto t = new Token(vt.at(0).type, vt.at(0).literal);
        string s = "";
        for (auto t : vt)
            s += t.literal + " ";
        cout << "[parseStmt] size" << int(vt.size()) << " " << s << endl;
        vector<Token> vt2(int(vt.size()) - 1);
        for (int i = 0; i < int(vt.size() - 1); i++)
            vt2[i] = vt[i + 1];
        auto expr = parseExpr(vt2, 0);
        cout << "[parseStmt] Return" << endl;
        return new Statement(t, expr);
    }
    else if (vt.at(0).type == TT_PVEC)
    {
        auto t = new Token(vt.at(0).type, vt.at(0).literal);
        cout << "[parseStmt] " << t->literal << endl;
        auto expr = parseExpr(vt, 1);
        return new Statement(t, expr);
    }
    // err
    auto t = new Token();
    cout << "[parseStmt] " << t->literal << endl;
    auto expr = new Expression();
    return new Statement(t, expr);
};

void evalExpr(Expression *expr)
{
    cout << "[evalExpr] START | " << expr->to_string() << endl;
    // cout << "CHECK NULL" << endl;
    // if (expr->op == NULL)
    //     cout << "expr->op == NULL" << endl;
    // if (expr->node == NULL)
    //     cout << "expr->node == NULL" << endl;
    // if (expr->left == NULL)
    //     cout << "expr->left == NULL" << endl;
    // if (expr->right == NULL)
    //     cout << "expr->right == NULL" << endl;
    // cout << "CHECKED NULL" << endl;
    // cout << expr->op->type << endl;

    // recursion
    if (expr->op->type == TT_INTERNAL_NODE)
    {
        cout << "[evalExpr] NODE | " << expr->to_string() << endl;
        return;
    }
    if (expr->left->op->type != TT_INTERNAL_NODE)
    {
        cout << "[evalExpr] RECURSION | " << expr->left->to_string() << endl;
        evalExpr(expr->left);
    }
    // err check
    if (expr->left->op->type != TT_INTERNAL_NODE || expr->right->op->type != TT_INTERNAL_NODE)
        cout << "[evalExpr] ERR | not TT_INTERNAL_NODE";
    if (expr->left->node->type != expr->right->node->type)
        cout << "[evalExpr] ERR | Node.type unmatch";

    cout << "[evalExpr] CALC | " << expr->to_string() << endl;

    if (expr->op->type == TT_PLUS && expr->left->node->type == TT_INT)
    {
        auto val = expr->left->node->int_value + expr->right->node->int_value;
        auto expr2 = new Expression(val);
        cout << "[evalExpr] PLUS | " << expr2->to_string() << endl;
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
        cout << "[evalExpr] MINUS | " << expr2->to_string() << endl;
        expr->left = NULL;
        expr->right = NULL;
        expr->op = new Token(TT_INTERNAL_NODE, TT_INTERNAL_NODE);
        expr->node = new Node(val);
    }
    else if (expr->op->type == TT_PLUS && expr->left->node->type == TT_VEC)
    {
    }
    else if (expr->op->type == TT_MINUS && expr->left->node->type == TT_VEC)
    {
    }
}

// evaluate
// StatementのTokenが
//     int|vecならExpressionの評価結果を代入し""を返す
//     print_*ならExpressionの評価結果をstringで返す
//     どこかでエラーがあれば"ERR"を返す
string evaluate(Statement *stmt, Variables *vars)
{
    cout << "[evaluate] " << stmt->to_string() << endl;
    if (stmt->var->type == TT_INT)
    {
        evalExpr(stmt->expr);
        if (stmt->expr->op->type == TT_ERR)
            return TT_ERR;
        cout << "[evaluate] SET VALUE " << stmt->expr->node->to_string() << " TO KEY " << stmt->var->literal << endl;
        (*vars)[stmt->var->literal] = *stmt->expr->node;
        cout << "[evaluate] SET" << endl;
        return "";
    }
    else if (stmt->var->type == TT_VEC)
    {
        evalExpr(stmt->expr);
        if (stmt->expr->op->type == TT_ERR)
            return TT_ERR;
        (*vars)[stmt->var->literal] = *stmt->expr->node;
        return "";
    }
    else if (stmt->var->type == TT_PINT)
    {
        evalExpr(stmt->expr);
        if (stmt->expr->op->type == TT_ERR || stmt->expr->node->type == TT_ERR)
            return TT_ERR;
        return stmt->expr->node->to_string();
    }
    else if (stmt->var->type == TT_PVEC)
    {
        evalExpr(stmt->expr);
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
        // cout << "[getline] " << s << endl;
        tokens.push_back(tokenize(s));
    };
    // print tokens
    // for (auto tt : tokens)
    // {
    //     for (auto t : tt)
    //     {
    //         cout << t.literal << "(" << t.type << ")"
    //              << " ";
    //     }
    //     cout << endl;
    // }
    Variables *pvars;
    rep(i, N)
    {
        auto stmt = parseStmt(tokens[i]);
        auto result = evaluate(stmt, pvars);
        if (result != "")
            cout << result << endl;
    }

    return 0;
}

// #define testS(expr, result) cout << (((expr) == (result)) ? "OK" : "NG") << ": " << (expr) << endl;

bool testS(string got, string want)
{
    bool result = got == want;
    cout << (result ? "OK" : "NG") << ": " << got << endl;
    return result;
}

bool testNode()
{
    auto n1 = Node(5);
    auto n2 = Node(vector<int>{1, 2, -3, 4, 5});
    return testS(n1.to_string(), "5") && testS(n2.to_string(), "[ 1 2 -3 4 5 ]");
}

bool testExpr()
{
    bool result = true;

    auto e1 = Expression(5);
    auto e2 = Expression(vector<int>{1, 2, -3, 4, 5});
    result &= testS(e1.to_string(), "expr(5)") && testS(e2.to_string(), "expr([ 1 2 -3 4 5 ])");

    auto e3 = Expression(10);
    auto e4 = Expression(new Token(TT_PLUS, TT_PLUS), &e1, &e2);
    result &= testS(e4.to_string(), "expr(expr(5)+expr([ 1 2 -3 4 5 ]))");
    return result;
}

int testStmt()
{
    bool result = true;

    auto s1t = Token(TT_INT, "a");
    auto s1e = Expression(5);
    auto s1 = Statement(&s1t, &s1e);
    result &= testS(s1.to_string(), "stmt(int a = expr(5))");

    auto s2t = Token(TT_PVEC, TT_PVEC);
    auto s2e = Expression(vector<int>{1, 2, -3, 4, 5});
    auto s2 = Statement(&s2t, &s2e);
    result &= testS(s2.to_string(), "stmt(print_vec expr([ 1 2 -3 4 5 ]))");
    return result;
}

bool testParseExpr()
{
    bool result = true;

    vector<Token> t0{Token(TT_INT, "123"), Token(TT_SEMICOLON, ";")};
    auto e0 = parseExpr(t0, 0);
    result &= testS(e0->to_string(), "expr(123)");

    vector<Token> t1{Token(TT_INT, "1"), Token(TT_PLUS, TT_PLUS), Token(TT_INT, "10"), Token(TT_SEMICOLON, ";")};
    auto e1 = parseExpr(t1, 0);
    result &= testS(e1->to_string(), "expr(expr(1)+expr(10))");

    vector<Token> t2{Token(TT_INT, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_INT, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "500"), Token(TT_SEMICOLON, ";")};
    auto e2 = parseExpr(t2, 0);
    result &= testS(e2->to_string(), "expr(expr(expr(5)+expr(50))-expr(500))");

    vector<Token> t3{Token(TT_INT, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_INT, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "5000"), Token(TT_SEMICOLON, ";")};
    auto e3 = parseExpr(t3, 0);
    result &= testS(e3->to_string(), "expr(expr(expr(expr(5)+expr(50))-expr(500))-expr(5000))");
    // vector<Token> t3{Token(TT_VEC, "[ 1 , 2 , -3 , 4 , 5 ]"), Token(TT_PLUS, TT_PLUS), Token(TT_VEC, "[ 5 , 4 , -3 , 2 , 1 ]")};
    // auto e3 = parseExpr(t1, 0);
    // result &= testS(e3->to_string(), "expr(expr(1)+expr(10))");

    return result;
}

bool testParseStmt()
{
    bool result = true;

    vector<Token> t0{Token(TT_INT, TT_INT), Token(TT_VAR, "a"), Token(TT_EQ, TT_EQ), Token(TT_INT, "123"), Token(TT_SEMICOLON, ";")};
    auto s0 = parseStmt(t0);
    result &= testS(s0->to_string(), "stmt(int a = expr(123))");

    vector<Token> t1{Token(TT_INT, TT_INT), Token(TT_VAR, "b"), Token(TT_EQ, TT_EQ), Token(TT_INT, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_INT, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "5000"), Token(TT_SEMICOLON, ";")};
    auto s1 = parseStmt(t1);
    result &= testS(s1->to_string(), "stmt(int b = expr(expr(expr(expr(5)+expr(50))-expr(500))-expr(5000)))");

    vector<Token> t2{Token(TT_PINT, TT_PINT), Token(TT_INT, "123"), Token(TT_SEMICOLON, ";")};
    auto s2 = parseStmt(t2);
    result &= testS(s2->to_string(), "stmt(print_int expr(123))");

    vector<Token> t3{Token(TT_PINT, TT_PINT), Token(TT_INT, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_INT, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "5000"), Token(TT_SEMICOLON, ";")};
    auto s3 = parseStmt(t3);
    result &= testS(s3->to_string(), "stmt(print_int expr(expr(expr(expr(5)+expr(50))-expr(500))-expr(5000)))");

    return result;
}

bool testEvalExpr()
{
    bool result = true;

    vector<Token> t0{Token(TT_INT, "123"), Token(TT_SEMICOLON, ";")};
    auto e0 = parseExpr(t0, 0);
    evalExpr(e0);
    result &= testS(e0->to_string(), "expr(123)");

    vector<Token> t1{Token(TT_INT, "1"), Token(TT_PLUS, TT_PLUS), Token(TT_INT, "10"), Token(TT_SEMICOLON, ";")};
    auto e1 = parseExpr(t1, 0);
    evalExpr(e1);
    result &= testS(e1->to_string(), "expr(11)");

    vector<Token> t2{Token(TT_INT, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_INT, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "500"), Token(TT_SEMICOLON, ";")};
    auto e2 = parseExpr(t2, 0);
    evalExpr(e2);
    result &= testS(e2->to_string(), "expr(-445)");

    vector<Token> t3{Token(TT_INT, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_INT, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "5000"), Token(TT_SEMICOLON, ";")};
    auto e3 = parseExpr(t3, 0);
    evalExpr(e3);
    result &= testS(e3->to_string(), "expr(-5445)");

    return result;
}

bool testEval()
{
    bool result = true;

    Variables m;

    vector<Token> t0{Token(TT_INT, TT_INT), Token(TT_VAR, "a"), Token(TT_EQ, TT_EQ), Token(TT_INT, "123"), Token(TT_SEMICOLON, ";")};
    auto s0 = parseStmt(t0);
    auto r0 = evaluate(s0, &m);
    result &= testS(r0, "");
    result &= testS(m["a"].to_string(), Node(123).to_string());

    vector<Token> t1{Token(TT_INT, TT_INT), Token(TT_VAR, "b"), Token(TT_EQ, TT_EQ), Token(TT_INT, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_INT, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "5000"), Token(TT_SEMICOLON, ";")};
    auto s1 = parseStmt(t1);
    auto r1 = evaluate(s1, &m);
    result &= testS(r1, "");
    result &= testS(m["b"].to_string(), Node(-5445).to_string());

    vector<Token> t2{Token(TT_PINT, TT_PINT), Token(TT_INT, "123"), Token(TT_SEMICOLON, ";")};
    auto s2 = parseStmt(t2);
    auto r2 = evaluate(s2, &m);
    result &= testS(r2, "123");

    vector<Token> t3{Token(TT_PINT, TT_PINT), Token(TT_INT, "5"), Token(TT_PLUS, TT_PLUS), Token(TT_INT, "50"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "500"), Token(TT_MINUS, TT_MINUS), Token(TT_INT, "5000"), Token(TT_SEMICOLON, ";")};
    auto s3 = parseStmt(t3);
    auto r3 = evaluate(s3, &m);
    result &= testS(r3, "-5445");

    // TODO: 変数名解決
    return result;
}
bool test()
{
    return testNode() && testExpr() && testStmt() && testParseExpr() && testParseStmt() && testEvalExpr() && testEval();
}

int main()
{
    if (!test())
    {
        cerr << "failed" << endl;
        return 1;
    }
    // main1();
    return 0;
}