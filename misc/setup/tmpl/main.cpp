#define _GLIBCXX_DEBUG
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
// clang-format off
#define PI 3.14159265358979323846264338327950L
#define rep(i,n) for (int i=0; i<(int)(n); ++i)
#define prep_ios(do_flush) if(!do_flush){ ios::sync_with_stdio(false);cin.tie(nullptr);constexpr char endl='\n'; } cout<<fixed<<setprecision(20)
#define put(expr) cout<<expr<<'\n'
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "[ "; for (auto v: vec) os << v << " "; os << "]"; return os; }
typedef int64_t i64; typedef uint64_t u64; typedef double f64; typedef vector<i64> vi; typedef vector<vector<i64>> vvi; typedef map<i64, i64> mii;
template <typename T> bool chmax(T &now, const T &cand) { if (now < cand) { now = cand; return true; } return false; } template <typename T> bool chmin(T &now, const T &cand) { if (now > cand) { now = cand; return true; } return false; }
const string YES = "Yes", NO = "No";

// clang-format on?

int main() {
  prep_ios(true);

  i64 N;
  cin >> N;

  vi A(N);
  rep(i, N) cin >> A[i];

  put("tmpl");
}
