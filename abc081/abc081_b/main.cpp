// clang-format off
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define noflush ios::sync_with_stdio(false);cin.tie(nullptr);constexpr char endl = '\n';
#define put(expr) cout << expr << '\n'
typedef int8_t i8; typedef int16_t i16; typedef int32_t i32; typedef int64_t i64;
typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef uint64_t u64;
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
using namespace std;
// clang-format on

int count0(bitset<32> &bs) {
  rep(i, 32) {
    if (bs.test(i)) return i;
  }
  return 0;
}

int main() {
  noflush;

  int N;
  cin >> N;

  int ans_min = INT_MAX;
  int tmp;
  rep(i, N) {
    cin >> tmp;
    auto bs = bitset<32>(tmp);
    chmin(ans_min, count0(bs));
  }
  put(ans_min);
}
