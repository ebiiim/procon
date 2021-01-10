// なぜか一部WA...
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
using namespace std;

int main()
{
    int n;
    cin >> n;
    int len = int(pow(n, 2));
    vector<int> a(len);
    rep(i, len) cin >> a[i];

    auto mid = a.begin() + a.size() / 2;
    vector<int>::iterator il = max_element(a.begin(), mid);
    vector<int>::iterator ir = max_element(mid, a.end());
    size_t l = distance(a.begin(), il);
    size_t r = distance(a.begin(), ir);
    int ans = (a[l] < a[r]) ? (++l) : (++r);
    cout << ans << endl;
}
