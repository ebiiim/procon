#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main()
{
    int A, B;
    cin >> A >> B;

    string a, b;
    rep(i, A)
        a += "]";
    rep(i, B)
        b += "]";
    cout << "A:" << a << endl;
    cout << "B:" << b << endl;
}
