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

int tribo(int N) {
  if (N == 0 || N == 1) return 0;
  if (N == 2) return 1;

  return tribo(N - 1) + tribo(N - 2) + tribo(N - 3);
}

int main() {
  noflush;

  int N;
  cin >> N;

  put(tribo(N));
}
