#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << max(max(A, B), C) - min(min(A, B), C) << endl;
}
