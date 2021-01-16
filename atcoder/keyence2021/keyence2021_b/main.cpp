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

int main() {
  noflush;

  int N, K;
  cin >> N >> K;

  map<int, int> mii;
  int maxA = 0;

  {
    int A;
    rep(i, N) {
      cin >> A;
      chmax(maxA, A);
      mii[A]++;
    }
  }

  int sum = 0;
  int cur = -1;
  rep(j, K) {
    // put("J=" << j);
    rep(i, maxA + 2) {  // sentinel
      if (mii[i] > 0) {
        // put("GOT" << i);
        mii[i]--;
        // put("mii[" << i << "]=" << mii[i]);
        cur = i;
      } else {
        // put("+" << (cur + 1));
        sum += cur + 1;
        cur = -1;
        // put("set cur -1");
        break;
      }
    }
  }
  put(sum);
}
