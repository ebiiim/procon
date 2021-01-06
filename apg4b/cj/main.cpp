#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    int sum = 0;
    rep(i, N)
    {
        sum += A[i];
    }
    int avg = sum / N;
    rep(i, N)
    {
        int diff = avg - A[i];
        if (diff < 0)
            diff *= -1;
        cout << diff << endl;
    }
}
