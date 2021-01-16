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

bool is753(const string &s) {
  bool is7 = false, is5 = false, is3 = false;
  for (const auto &c : s) {
    if (c == '7') is7 = true;
    if (c == '5') is5 = true;
    if (c == '3') is3 = true;
    if (is7 && is5 && is3) return true;
  }
  return false;
}

int count753(string start, int N) {
  if (start != "" && stoi(start) > N) return 0;

  string s7, s5, s3;
  s7 = '7' + start;
  s5 = '5' + start;
  s3 = '3' + start;

  return is753(start) + count753(s7, N) + count753(s5, N) + count753(s3, N);
}

int main() {
  noflush;

  int N;
  cin >> N;

  // WA if N >~ 1000000000
  put(count753("", N));
}
