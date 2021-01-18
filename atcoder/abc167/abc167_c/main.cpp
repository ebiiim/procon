// clang-format off
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,s,n) for (int i=(s); i<(int)(n); ++i)
#define PI 3.14159265358979323846264338327950L
#define noflush ios::sync_with_stdio(false);cin.tie(nullptr);constexpr char endl='\n'
#define put(expr) cout<<expr<<'\n'
typedef int8_t i8; typedef int16_t i16; typedef int32_t i32; typedef int64_t i64;
typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef uint64_t u64;
typedef float f32; typedef double f64; typedef long double f80;
template <typename T> bool chmax(T &now, const T &cand) { if (now < cand) { now = cand; return true; } return false; }
template <typename T> bool chmin(T &now, const T &cand) { if (now > cand) { now = cand; return true; } return false; }
using namespace std;
const int INF = 1<<30; /* INF > 10^9 */ const i64 INFLL = 1LL<<60; /* INFLL > 10^18*/
// clang-format on

int main() {
  noflush;

  int N, M, X;
  cin >> N >> M >> X;

  vector<int> C(N);
  vector<vector<int>> A(N);
  rep(i, N) {
    cin >> C[i];
    A[i] = vector<int>(M);
    rep(j, M) { cin >> A[i][j]; }
  }

  // rep(i, N) cout << C[i] << ' ';
  // put("");

  // rep(i, N) {
  //   rep(j, M) cout << A[i][j] << ' ';
  //   put("");
  // }

  // 1<=N<=12冊の本を買うor買わない
  // 2^12は間に合うので全探索
  vector<i64> costs(1 << N, INFLL);
  for (int bit = 0; bit < (1 << N); ++bit) {
    i64 cost = 0;
    vector<int> algo(M);
    for (int i = 0; i < N; ++i) {
      if (bit & (1 << i)) {
        cost += C[i];
        rep(m, M) algo[m] += A[i][m];
      }
    }
    bool ok = true;
    rep(m, M) if (algo[m] < X) ok = false;
    if (ok) {
      costs[bit] = cost;
    }
  }

  // i64 min_cost = INFLL;
  // rep(i, 1 << N) chmin(min_cost, costs[i]);
  auto min_cost = *min_element(costs.begin(), costs.end());

  if (min_cost == INFLL)
    put(-1);
  else
    put(min_cost);
}
