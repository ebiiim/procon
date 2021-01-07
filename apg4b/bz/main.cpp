#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
using namespace std;

int main()
{
    int N;
    cin >> N;

    map<int, int> cnt;
    register int tmp;
    rep(i, N)
    {
        cin >> tmp;
        if (cnt.count(tmp))
            ++cnt.at(tmp);
        else
            cnt[tmp] = 1;
    }

    int cnt_max = 0;
    pair<int, int> max_p;
    for (auto p : cnt)
    {
        if (p.second > cnt_max)
        {
            cnt_max = p.second;
            max_p = p;
        }
    }
    cout << max_p.first << ' ' << max_p.second << endl;
}
