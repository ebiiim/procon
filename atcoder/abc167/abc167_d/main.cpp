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

int getStartPos(const vector<int> &v) {
  int a = 0, b = 0;
  while (true) {
    a += 2;
    ++b;
    if (a >= v.size()) return -1;
    if (v[a] == v[b]) break;
  }
  a = 0;
  while (true) {
    ++a;
    ++b;
    if (b >= v.size()) return -1;
    if (v[a] == v[b]) break;
  }
  return a;
}

int getCycleLen(const vector<int> &v, int startPos) {
  int cycle = 0;
  int a = startPos, b = startPos;
  while (true) {
    ++cycle;
    a += 2;
    ++b;
    if (a >= v.size()) {
      return -1;
    }
    if (v[a] == v[b]) {
      break;
    }
  }
  return cycle;
}

int main2() {
  noflush;

  int N;
  i64 K;
  cin >> N >> K;

  vector<int> A(N);
  rep(i, N) cin >> A[i];
  rep(i, N) A[i]--;

  int testSize = 2 * 10 * 10 * 10 * 10 * 10;
  vector<int> testV(testSize);
  int pos = 0;
  int nextPos = A[0];
  rep(i, testV.size()) {
    testV[i] = pos;
    pos = nextPos;
    nextPos = A[pos];
  }

  // フロイドの循環検出法
  bool hasLoop = true;
  int sp = getStartPos(testV);
  if (sp == -1) {
    hasLoop = false;
  }
  int cl = getCycleLen(testV, sp);
  if (cl == -1) {
    hasLoop = false;
  }

  if (!hasLoop) {
    vector<int> testV(K);
    int pos = 0;
    int nextPos = A[0];
    rep(i, testV.size()) {
      testV[i] = pos;
      pos = nextPos;
      nextPos = A[pos];
    }
    put(testV[K - 1] + 1);
    return 0;
  }

  // rep(i, 100) { cout << testV[i] << " "; }
  // put("\n");
  // put("sp, cl = " << sp << ", " << cl);

  i64 minRoute = sp + (K - sp) % cl;
  // put("minRoute = " << minRoute);

  put(testV[minRoute] + 1);
}

// ↑では循環の有無を調べていたが、K>Nなら必ず循環があるし、
// 既出の数字が出たらそこで循環になる
// 最悪なケースは循環なしだが、K<=Nなら間に合うので全探索すればいい
// WAが2個ある...
int main() {
  noflush;

  int N;
  i64 K;
  cin >> N >> K;

  vector<int> A(N);
  rep(i, N) cin >> A[i];
  rep(i, N) A[i]--;

  set<int> seen;
  int next_see = 0;
  int loop = 0;              // ループした回数
  int loop1 = 0, loop2 = 0;  // ループした時のindex
  int loop1v = 0;            // ループした時の値
  int X = (2 * 100000) > K ? K : 2 * 100000;
  // put("X " << X);
  rep(i, X) {
    auto prev_see = next_see;
    next_see = A[next_see];
    // put(prev_see << "->" << next_see);
    if (seen.count(next_see)) {
      ++loop;
      if (loop == 1) {
        loop1 = i;
        loop1v = next_see;
        // put("loop1");
      }
      if (loop > 1 && next_see == loop1v) {
        loop2 = i;
        // put("loopsize " << loop2 - loop1);
        break;
      }
    }
    seen.insert(prev_see);
  }

  if (loop > 1) {
    // ループあり
    // put("loop!");
    i64 loopsize = abs(loop2 - loop1);
    i64 n = loop1 + loopsize + ((K - loop1) % loopsize);
    // put("loop1 " << loop1);
    // put("loop2 " << loop2);
    // put("loopsize " << loopsize);
    // put("((K - loop1) % loopsize) " << ((K - loop1) % loopsize));
    // put("n " << n);
    int next_see = 0;
    rep(i, n) { next_see = A[next_see]; }
    put(++next_see);
    return 0;
  } else {
    // ループなし
    // put("no loop!");
    int next_see = 0;
    rep(i, K) {
      auto a = A[next_see];
      next_see = a;
    }
    put(++next_see);
    return 0;
  }
}
