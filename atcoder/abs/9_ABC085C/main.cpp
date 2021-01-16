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

// 貪欲法ではうまくいかない...?
int main2() {
  noflush;

  int N, Y;
  cin >> N >> Y;

  int K1, K5, K10;
  K1 = Y / 1000;
  K5 = K10 = 0;
  while (1) {
    // put("> " << K10 << ' ' << K5 << ' ' << K1);
    if (K1 + K5 + K10 == N) {
      put(K10 << ' ' << K5 << ' ' << K1);
      return 0;
    }
    if (K5 - 2 >= 0) {
      K5 -= 2;
      K10 += 1;
    } else if (K1 - 5 >= 0) {
      K1 -= 5;
      K5 += 1;
    } else {
      // nothing to do
      break;
    }
  }
  put("-1 -1 -1");
  return 0;
}

// 鶴亀算
int main() {
  noflush;

  int N, Y;
  cin >> N >> Y;

  int K1 = Y / 1000, K5 = 0, K10 = 0;
  int diff = Y - N * 1000;
  // put("diff" << diff);
  if (diff < 0) {
    put("-1 -1 -1");
    return 0;
  }
  rep(i, N + 1) {
    rep(j, N + 1) {
      if (9000 * i + 4000 * j == diff && i + j <= N) {
        // put("i=" << i << " j=" << j);
        K10 = i;
        K5 = j;
        K1 = N - i - j;
        put(K10 << ' ' << K5 << ' ' << K1);
        return 0;
      }
    }
  }
  put("-1 -1 -1");
}
