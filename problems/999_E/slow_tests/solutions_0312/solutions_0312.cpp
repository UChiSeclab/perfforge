#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 5010;
vector<long long> L[MAXN];
bool ok[MAXN];
bool mk[MAXN];
long long arr[MAXN];
long long contg;
void precal(long long nodo) {
  mk[nodo] = true;
  contg++;
  for (auto v : L[nodo]) {
    if (!mk[v]) {
      precal(v);
    }
  }
}
void DFS(long long nodo) {
  ok[nodo] = true;
  mk[nodo] = true;
  for (auto v : L[nodo]) {
    if (!mk[v]) {
      DFS(v);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long N, M, S;
  cin >> N >> M >> S;
  for (long long i = 0; i < M; i++) {
    long long a, b;
    cin >> a >> b;
    L[a].push_back(b);
  }
  vector<pair<long long, long long>> vect;
  for (long long i = 1; i <= N; i++) {
    for (long long j = 0; j < MAXN; j++) mk[j] = false;
    contg = 0;
    precal(i);
    arr[i] = contg;
    vect.push_back({arr[i], i});
  }
  sort(vect.rbegin(), vect.rend());
  for (long long j = 0; j < MAXN; j++) mk[j] = false;
  DFS(S);
  long long res = 0;
  for (auto x : vect) {
    if (ok[x.second] == true) continue;
    bool flag = true;
    for (long long i = 1; i <= N; i++) {
      flag = flag & ok[i];
    }
    if (flag) break;
    res++;
    for (long long i = 0; i < MAXN; i++) {
      mk[i] = false;
    }
    DFS(x.second);
  }
  cout << res << '\n';
  return 0;
}
