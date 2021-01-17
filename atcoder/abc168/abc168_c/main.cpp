// clang-format off
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define rep2(i,s,n) for (int i=(s); i<(int)(n); ++i)
#define noflush ios::sync_with_stdio(false);cin.tie(nullptr);constexpr char endl='\n'
#define put(expr) cout<<expr<<'\n'
#define PI 3.14159265358979323846264338327950L
typedef int8_t i8; typedef int16_t i16; typedef int32_t i32; typedef int64_t i64;
typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef uint64_t u64;
template <typename T> bool chmax(T &now, const T &cand) { if (now < cand) { now = cand; return true; } return false; }
template <typename T> bool chmin(T &now, const T &cand) { if (now > cand) { now = cand; return true; } return false; }
using namespace std;
const int inf = 1<<30; /* inf > 10^9 */ const i64 infLL = 1LL<<60; /* infLL > 10^18*/
// clang-format on

// 一部WA
int main() {
  // noflush;

  int A, B, H, M;
  cin >> A >> B >> H >> M;

  // 余弦定理
  // c^2 = a^2 + b^2 - 2ab*cos(C)

  // 時計の進み方
  // 長針は1分で6度
  // 短針は1分で0.5度

  int minute = 60 * H + M;
  double degH = fmod(0.5 * minute, 360);
  double degM = fmod(6.0 * minute, 360);
  double degDiff = degH - degM;
  // double degDiff = (degH - degM < 0.0) ? degM - degH : degH - degM;
  degDiff = degDiff > 180.0 ? fmod(degDiff, 180) : degDiff;
  long double radDiff = cosl(PI / 180 * (long double)degDiff);
  // put("dHdM " << degH << ' ' << degM << " dD " << degDiff << " rD " << radDiff);
  long double c2 =
      ((long double)A * (long double)A) + ((long double)B * (long double)B) - 2.0 * (long double)(A) * (long double)(B) * radDiff;
  long double c = sqrt(c2);
  put(fixed << setprecision(20) << c);
}
