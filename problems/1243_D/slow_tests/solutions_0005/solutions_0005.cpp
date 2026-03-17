#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(const T niz[], const int siz) {
  for (int i = 0; i < siz; i++) cout << niz[i] << " ";
  cout << endl;
}
int n, m;
vector<int> graf[100005];
int dsu[100005];
int sajz[100005];
int findpar(int x) {
  if (x == dsu[x]) return x;
  return dsu[x] = findpar(dsu[x]);
}
void unite(int x, int y) {
  int a = findpar(x);
  int b = findpar(y);
  if (a == b) return;
  if (sajz[a] > sajz[b]) {
    dsu[a] = b;
    sajz[b] += sajz[a];
  } else {
    dsu[b] = a;
    sajz[a] += sajz[b];
  }
}
void init() {
  for (int(i) = (1); (i) <= (n); ++(i)) {
    dsu[i] = i;
    sajz[i] = 1;
  }
}
int deg[100005];
vector<pair<int, int> > v;
map<pair<int, int>, bool> poj;
bool bad[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  init();
  for (int(i) = (0); (i) <= (m - 1); ++(i)) {
    int a, b;
    cin >> a >> b;
    graf[a].push_back(b);
    graf[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
  for (int(i) = (1); (i) <= (n); ++(i)) v.push_back({-deg[i], i});
  sort(v.begin(), v.end());
  int ops = 0;
  int sol = 0;
  for (auto c : v) {
    for (int i = 1; i <= n; i++) bad[i] = 0;
    for (auto k : graf[c.second]) bad[k] = 1;
    for (int i = 1; i <= n; i++) {
      if (i == c.second || bad[i]) continue;
      unite(i, c.second);
    }
    ops += n;
    if (ops > 20000000) break;
  }
  for (int(i) = (1); (i) <= (n); ++(i))
    if (findpar(i) == i) sol++;
  cout << sol - 1 << endl;
  return 0;
}
