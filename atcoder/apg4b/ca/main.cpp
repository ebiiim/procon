#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> P(N);
    rep(i, N) cin >> P.at(i).second >> P.at(i).first;
    sort(P.begin(), P.end());
    rep(i, N) cout << P.at(i).second << ' ' << P.at(i).first << endl;
}
