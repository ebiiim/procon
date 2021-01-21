// clang-format off
using namespace std;
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,s,n) for (int i=(s); i<(int)(n); ++i)
#define PI 3.14159265358979323846264338327950L
#define noflush ios::sync_with_stdio(false);cin.tie(nullptr);constexpr char endl='\n'
#define put(expr) cout<<expr<<'\n'
__int128 parse(string &s) { __int128 ret = 0; for (int i = 0; i < s.length(); i++) if ('0' <= s[i] && s[i] <= '9') ret = 10 * ret + s[i] - '0'; return ret; }
istream &operator>>(istream &is, __int128_t &v) { string s; is >> s; v = parse(s); return is; }
ostream &operator<<(ostream &os, const __int128_t &v) { if (v == 0) return (os << "0"); __int128_t num = v; if (v < 0) { os << '-'; num = -num; } string s; for (; num > 0; num /= 10) s.push_back('0' + (char)(num % 10)); reverse(s.begin(), s.end()); return (os << s); }
typedef __int128 i128;
typedef int8_t i8; typedef int16_t i16; typedef int32_t i32; typedef int64_t i64;
typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef uint64_t u64;
typedef float f32; typedef double f64; typedef long double f80;
template <typename T> bool chmax(T &now, const T &cand) { if (now < cand) { now = cand; return true; } return false; }
template <typename T> bool chmin(T &now, const T &cand) { if (now > cand) { now = cand; return true; } return false; }
const int INF = 1<<30; /* INF > 10^9 */ const i64 INFLL = 1LL<<60; /* INFLL > 10^18 */
// clang-format on

#include <numeric>

int gcd3(const int &a, const int &b, const int &c) {
  return __gcd(__gcd(a, b), c);
}

int main() {
  noflush;

  int K;
  cin >> K;

  i64 sum = 0;

  rep2(i, 1, K + 1) {
    rep2(j, 1, K + 1) {
      rep2(k, 1, K + 1) { sum += gcd3(i, j, k); }
    }
  }

  put(sum);
}
