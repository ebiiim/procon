// clang-format off
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,s,n) for (int i=(s); i<(int)(n); ++i)
#define noflush ios::sync_with_stdio(false);cin.tie(nullptr);constexpr char endl='\n'
#define put(expr) cout<<expr<<'\n'
typedef int8_t i8; typedef int16_t i16; typedef int32_t i32; typedef int64_t i64;
typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef uint64_t u64;
template <typename T> bool chmax(T &now, const T &cand) { if (now < cand) { now = cand; return true; } return false; }
template <typename T> bool chmin(T &now, const T &cand) { if (now > cand) { now = cand; return true; } return false; }
using namespace std;
const int inf = 1<<30; /* inf > 10^9 */ const i64 infLL = 1LL<<60; /* infLL > 10^18*/
// clang-format on

const string YES = "Yes", NO = "No";
int D(int x1, int y1, int x2, int y2) { return abs(x2 - x1) + abs(y2 - y1); }
int main() {
  noflush;

  int N;
  cin >> N;

  vector<int> t(N), x(N), y(N);
  rep(i, N) cin >> t[i] >> x[i] >> y[i];

  int now = 0;
  int prevX = 0, prevY = 0;
  rep(i, N) {
    int restTime = t[i] - now;
    int nextD = D(prevX, prevY, x[i], y[i]);
    if (restTime - nextD < 0) {
      put(NO);  // 時間切れ
      return 0;
    }
    if ((restTime - nextD) % 2 != 0) {
      put(NO);  // いけない
      return 0;
    }

    now = t[i];
    prevX = x[i];
    prevY = y[i];
  }
  put(YES);
}
