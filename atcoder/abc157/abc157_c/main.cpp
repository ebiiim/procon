// clang-format off
using namespace std;
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define PI 3.14159265358979323846264338327950L
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,s,n) for (int i=(s); i<(int)(n); ++i)
#define noflush ios::sync_with_stdio(false);cin.tie(nullptr);constexpr char endl='\n'
#define prec(i) fixed << setprecision(i)
#define put(expr) cout<<expr<<'\n'
#define putV(A) cout << '['; rep(i, A.size()) { cout << A[i]; if (i != A.size() - 1) cout << ' '; else cout << "]\n"; }
typedef int8_t i8; typedef int16_t i16; typedef int32_t i32; typedef int64_t i64; typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef uint64_t u64; typedef float f32; typedef double f64; typedef long double f80;
typedef vector<int> vi; typedef vector<vector<int>> vvi; typedef map<int, int> mii;
typedef __int128_t i128; i128 parse(string &s) { i128 ret = 0; for (int i = 0; i < s.length(); i++) if ('0' <= s[i] && s[i] <= '9') ret = 10 * ret + s[i] - '0'; return ret; } istream &operator>>(istream &is, i128 &v) { string s; is >> s; v = parse(s); return is; } ostream &operator<<(ostream &os, const i128 &v) { if (v == 0) return (os << "0"); i128 num = v; if (v < 0) { os << '-'; num = -num; } string s; for (; num > 0; num /= 10) s.push_back('0' + (char)(num % 10)); reverse(s.begin(), s.end()); return (os << s); }
template <typename T> bool chmax(T &now, const T &cand) { if (now < cand) { now = cand; return true; } return false; } template <typename T> bool chmin(T &now, const T &cand) { if (now > cand) { now = cand; return true; } return false; }
template <typename T> T gcd(const T &a, const T &b) { if (a % b == 0) return b; return gcd(b, a % b); } template <typename T> T lcm(const T &a, const T &b) { return a * b / gcd(a, b); }
template <typename T> T nCr(const T &n, T k) { if (k > n) return 0; if (k * 2 > n) k = n - k; if (k == 0) return 1; int result = n; for (int i = 2; i <= k; ++i) { result *= (n - i + 1); result /= i; } return result; }
const int INF = 1<<30; /* INF > 10^9 */ const i64 INFLL = 1LL<<60; /* INFLL > 10^18 */ const string YES = "Yes", NO = "No";
// clang-format on

int main() {
  // noflush;

  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> A(M, {0, 0});
  rep(i, M) {
    int p0, p1;
    cin >> p0 >> p1;
    A[i].first = p0;
    A[i].second = p1;
    // put("A[i] " << A[i].first << ' ' << A[i].second);
  };

  vi ans(N, -1);
  string ANS = "";

  rep(i, M) {
    int keta = A[i].first - 1;
    int atai = A[i].second;
    if (ans[keta] != -1 && atai != ans[keta]) goto L_NO;
    ans[keta] = atai;
    // put("keta,atai " << keta << ',' << atai);
  }

  if (ans[0] == 0 && N != 1) goto L_NO;
  if (ans[0] == -1) ans[0] = 1;
  rep(i, N) {
    if (ans[i] == -1) ans[i] = 0;
  }

  if (M == 0) {
    if (N == 1)
      ans[0] = 0;
    else {
      ans[0] = 1;
      for (int i = 1; i < N; ++i) ans[i] = 0;
    }
  }

  rep(i, N) { ANS += to_string(ans[i]); }

  put(ANS);

  return 0;

L_NO:
  put(-1);
  return 0;
}
