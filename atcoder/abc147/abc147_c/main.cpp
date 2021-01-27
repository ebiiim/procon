#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// clang-format off
#define PI 3.14159265358979323846264338327950L
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,s,n) for (int i=(s); i<(int)(n); ++i)
#define prep_ios(do_flush) if(!do_flush){ ios::sync_with_stdio(false);cin.tie(nullptr);constexpr char endl='\n'; } cout<<fixed<<setprecision(20)
#define put(expr) cout<<expr<<'\n'
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "[ "; for (auto v: vec) os << v << " "; os << "]"; return os; }template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "< "; for (auto v: vec) os << v << " "; os << ">"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{ "; for (auto v: vec) os << v << " "; os << "}"; return os; }template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{ "; for (auto v: vec) os << v << " "; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{ "; for (auto v: mp) os << v.first << ": " << v.second << ", "; os << "}"; return os; }template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{ "; for (auto v: mp) os << v.first << ": " << v.second << ", "; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << ", " << pa.second << ")"; return os; }
typedef int8_t i8; typedef int16_t i16; typedef int32_t i32; typedef int64_t i64; typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef uint64_t u64; typedef float f32; typedef double f64; typedef long double f80;
typedef vector<int> vi; typedef vector<vector<int>> vvi; typedef map<int, int> mii;
typedef __int128_t i128; i128 parse(string &s) { i128 ret = 0; for (int i = 0; i < s.length(); i++) if ('0' <= s[i] && s[i] <= '9') ret = 10 * ret + s[i] - '0'; return ret; } istream &operator>>(istream &is, i128 &v) { string s; is >> s; v = parse(s); return is; } ostream &operator<<(ostream &os, const i128 &v) { if (v == 0) return (os << "0"); i128 num = v; if (v < 0) { os << '-'; num = -num; } string s; for (; num > 0; num /= 10) s.push_back('0' + (char)(num % 10)); reverse(s.begin(), s.end()); return (os << s); }
template <typename T> bool chmax(T &now, const T &cand) { if (now < cand) { now = cand; return true; } return false; } template <typename T> bool chmin(T &now, const T &cand) { if (now > cand) { now = cand; return true; } return false; }
template <typename T> T gcd(const T &a, const T &b) { if (a % b == 0) return b; return gcd(b, a % b); } template <typename T> T lcm(const T &a, const T &b) { return a * b / gcd(a, b); }
template <typename T> T nCr(const T &n, T k) { if (k > n) return 0; if (k * 2 > n) k = n - k; if (k == 0) return 1; int result = n; for (int i = 2; i <= k; ++i) { result *= (n - i + 1); result /= i; } return result; }
const int INF = 1<<30; /* INF > 10^9 */ const i64 INFLL = 1LL<<60; /* INFLL > 10^18 */ const string YES = "Yes", NO = "No";
// clang-format on

// WA
int main() {
  prep_ios(true);

  i64 N;
  cin >> N;

  vector<vector<pair<int, int>>> V;

  rep(i, N) {
    int A;
    cin >> A;
    vector<pair<int, int>> VV;
    rep(i, A) {
      int x, y;
      cin >> x >> y;
      VV.push_back({x, y});
    }
    V.push_back(VV);
  }
  // put(V);

  int cand = 0;

  for (int bit = 0; bit < (1 << N); ++bit) {
    vi checklist(20, -1); // 証言: {未使用, 発言=1, 発言=0} = {-1, 1, 0}
    vi checked(20, 0); // 証言した人: {未使用or発言しない, 発言} = {0, 1}
    int cnt = 0;
    put("---" << bit);
    for (int i = 0; i < N; ++i) {
      // bitmaskで指定したメンバーを正直者として、全員の証言に矛盾がないことを確認する
      if (bit & (1 << i)) {
        checked[i + 1] = 1; // 発言者を記録
        // put("check " << i << ": " << V[i]);
        for (auto p : V[i]) {
          if (checklist[p.first] == -1) {
            checklist[p.first] = p.second;
            ++cnt;
          } else if (checklist[p.first] != p.second) {
            cnt = -1;
            break;
          }
        }
      }
    }
    // さらに、証言と実際の発言者に矛盾がないことを確認する
    rep(x, 20) {
      // 証言で1なら必ず発言してなければならない
      if ((checklist[x] == 1 && checked[x] != 1) ||
          (checklist[x] == 0 && checked[x] != 0))
        cnt = -3;
    }
    put("checkls " << checklist);
    put("checked " << checked);
    put("cnt " << cnt);
    chmax(cand, cnt);
  }

  put(cand);
}
