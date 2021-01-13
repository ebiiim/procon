#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int calc(int A, string op, int B)
{
    if (op == "+")
        A += B;
    else if (op == "-")
        A -= B;
    else if (op == "*")
        A *= B;
    else if (op == "/" && B != 0)
        A /= B;
    else
        A = INT_MAX;
    return A;
}

int main()
{
    int N, A;
    cin >> N >> A;

    string op;
    int B;

    rep(i, N)
    {
        cin >> op >> B;
        if (A != INT_MAX)
        {
            A = calc(A, op, B);
            if (A == INT_MAX)
                cout << "error" << endl;
            else
                cout << i + 1 << ":" << A << endl;
        }
    }
}
