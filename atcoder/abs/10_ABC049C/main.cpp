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
  // noflush;

  string S;
  cin >> S;
  reverse(S.begin(), S.end());

  string T1 = "dream", T2 = "dreamer", T3 = "erase", T4 = "eraser";
  reverse(T1.begin(), T1.end());
  reverse(T2.begin(), T2.end());
  reverse(T3.begin(), T3.end());
  reverse(T4.begin(), T4.end());

  auto T1_ = T1.c_str();
  auto T2_ = T2.c_str();
  auto T3_ = T3.c_str();
  auto T4_ = T4.c_str();

  auto start = 0;

  while (1) {
    // cout << "TXT " << S.substr(start, 5) << endl;
    if (start > S.size()) {
      put("NO");
      return 0;
    }
    if (start == S.size()) {
      put("YES");
      return 0;
    }
    if (S.find(T1_, start, T1.size()) == start) {
      // put(T1);
      start += T1.size();
    } else if (S.find(T2_, start, T2.size()) == start) {
      // put(T2);
      start += T2.size();
    } else if (S.find(T3_, start, T3.size()) == start) {
      // put(T3);
      start += T3.size();
    } else if (S.find(T4_, start, T4.size()) == start) {
      // put(T4);
      start += T4.size();
    } else {
      put("NO");
      return 0;
    }
  }
}
