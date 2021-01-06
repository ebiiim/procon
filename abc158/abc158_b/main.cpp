#include <iostream>
#include <string>
#include <vector>
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++(i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++(i))
#define REP_R(i, n) for (int i = (int)(n)-1; (i) >= 0; --(i))
#define REP3R(i, m, n) for (int i = (int)(n)-1; (i) >= (int)(m); --(i))
#define ALL(x) ::std::begin(x), ::std::end(x)
using namespace std;

int64_t solve(int64_t N, int64_t A, int64_t B)
{
    // TLE
    int i = 0;
    int c = 0;
    while (true)
    {
        i += A;
        if (i >= N)
            return c + i - N - 1;
        c += A;
        i += B;
        if (i >= N)
            return c;
    }
    return c;
}

// generated by online-judge-template-generator v4.7.1 (https://github.com/online-judge-tools/template-generator)
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    constexpr char endl = '\n';
    int64_t N, A, B;
    cin >> N >> A >> B;
    auto ans = solve(N, A, B);
    cout << ans << endl;
    return 0;
}
