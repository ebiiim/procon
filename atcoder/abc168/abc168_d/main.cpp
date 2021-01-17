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

using Graph = vector<vector<int>>;

void BFS(const Graph &G, int s, vector<int> &D) {
  int N = (int)G.size();
  queue<int> que;
  D[s] = 0;
  que.push(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto x : G[v]) {
      if (D[x] != -1) continue;
      D[x] = D[v] + 1;
      que.push(x);
    }
  }
}

int main() {
  noflush;

  int N, M;
  cin >> N >> M;

  Graph G(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
  };
  vector<int> dist(N, -1);

  BFS(G, 0, dist);

  // 各頂点から自分の隣接の頂点->Goalの最短距離をみる
  // それが自分->Goalより1少なければ採用
  vector<int> ans(N);
  for (int i = 1; i < N; ++i) {
    // put("check " << i);
    int my_dist = dist[i];
    // put("my_dist " << my_dist);
    bool ok = false;
    for (auto v : G[i]) {
      // put("Adj " << v << " dist " << dist[v]);
      if (dist[v] == my_dist - 1) {
        // put("yes! mydist-1");
        ans[i] = v + 1;  // 問題文とのズレ
        ok = true;
        break;
      }
    }
    if (!ok) goto L_NO;
  }

  // 自分より距離が1少ない頂点 と 自分の隣の頂点 の積集合をとっている
  // TLE、多分O(N^2)
  //   vector<set<int>> eq_dist(N);
  //   rep(i, N) eq_dist[dist[i]].insert(i);
  //   rep(i, N) { put("dist_to_" << i << ": " << dist[i]); }
  //   rep(i, N) {
  //     cout << "dist=" << i << ": ";
  //     for (auto e : eq_dist[i]) {
  //       cout << e << ", ";
  //     }
  //     cout << endl;
  //   }
  //   vector<int> ans(N);
  //   for (int i = 1; i < N; ++i) {
  //     // put("Check " << i);
  //     int d2g = dist[i] - 1;  // next dist to goal
  //     // put("d2g " << dist[i]);
  //     set<int> gs(G[i].begin(), G[i].end());  // 隣接のvertex
  //     // for (auto x : gs) put("ad_v " << x);
  //     // for (auto x : eq_dist[d2g]) put("eqd_of_d2g " << x);
  //     set<int> prod;
  //     set_intersection(gs.begin(), gs.end(), eq_dist[d2g].begin(),
  //                      eq_dist[d2g].end(), inserter(prod, prod.begin()));
  //     // for (auto x : prod) put("prod " << x);
  //     if (prod.empty()) goto L_NO;
  //     ans[i] = (*prod.begin() + 1);
  //   }
  put("Yes");
  for (int i = 1; i < N; ++i) put(ans[i]);
  return 0;
L_NO:
  put("No");
  return 0;
}
