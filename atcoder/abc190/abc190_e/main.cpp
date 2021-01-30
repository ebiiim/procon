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

using Graph = vector<vector<int>>;

// input:
//   G: graph
//   s: start from
//   D: distance array
//      - set all elems -1 by `vector<int> D(N, -1);` for the first run
//      - set this array to do BFS for graph with multiple linked components
void BFS(const Graph &G, int s, vector<int> &D) {
  int N = (int)G.size(); // num of vertex
  // vector<int> dist(N, -1);  // -1 represents not seen
  queue<int> que;

  // start from s
  D[s] = 0;
  que.push(s);

  // do BFS
  while (!que.empty()) {
    int v = que.front(); // vertex to see
    que.pop();
    // see adjacencies of v
    for (auto x : G[v]) {
      if (D[x] != -1)
        continue; // seen
      // set dist and enqueue
      D[x] = D[v] + 1;
      que.push(x);
    }
  }
}

int main() {
  prep_ios(true);

  int N, M;
  cin >> N >> M;
  Graph G(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a].push_back(b);
    G[b].push_back(a);
  };
  int K;
  cin >> K;
  vi C(K);
  rep(i, K) {
    cin >> C[i];
    --C[i];
  };

  // 頂点Xから各頂点までの最短距離
  vvi D;
  rep(i, N) {
    vector<int> dist(N, -1);
    BFS(G, i, dist);
    D.push_back(dist);
  }

  // rep(i, N) { put("FROM " << i << ": " << D[i]); }

  // TLE
  // DPにすれば解けるはず

  i64 min_dist = INFLL;

  vector<int> PM(K);
  rep(i, K) PM[i] = i;
  do {
    // put(PM);
    i64 dist = 1;
    // put("---");
    rep(i, K - 1) {
      // PM[i]を参照すること
      // put(PM[i]);
      int now_stone = C[PM[i]];
      int next_stone = C[PM[i + 1]];
      // put(now_stone << "->" << next_stone);
      int now2next = D[now_stone][next_stone];
      if (now2next == -1) {
        dist = INFLL;
        break;
      }
      dist += now2next;
    }
    chmin(min_dist, dist);
  } while (next_permutation(PM.begin(), PM.end()));

  (min_dist == INFLL) ? put(-1) : put(min_dist);
}
