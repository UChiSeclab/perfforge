#include <bits/stdc++.h>
using namespace std;
int N, K;
long long Ans;
int Vis[10];
int H[10];
std::vector<std::vector<int> > Edge(8);
long long PowMod(long long N, long long P) {
  if (P == 0) return 1;
  long long Res = PowMod(N, P / 2);
  Res = (Res * Res) % 1000000007;
  if (P & 1) return (Res * N) % 1000000007;
  return Res;
}
void dfs(int idx) {
  Vis[idx] = 1;
  for (int i = 0; i < Edge[idx].size(); i++) {
    if (Vis[Edge[idx][i]] == 0) dfs(Edge[idx][i]);
  }
}
int check() {
  memset(Vis, 0, sizeof(Vis));
  for (int i = 0; i < K; i++) Edge[i].clear();
  for (int i = 0; i < K; i++) {
    Edge[H[i]].push_back(i);
  }
  dfs(0);
  int Sum = 0;
  for (int i = 0; i < K; i++) Sum += Vis[i];
  return (Sum == K);
}
void rec(int idx) {
  if (idx == K) {
    Ans += check();
    return;
  }
  for (int i = 0; i < K; i++) {
    H[idx] = i;
    rec(idx + 1);
  }
}
int main() {
  cin >> N >> K;
  rec(0);
  cout << (Ans * PowMod(N - K, N - K)) % 1000000007 << endl;
}
