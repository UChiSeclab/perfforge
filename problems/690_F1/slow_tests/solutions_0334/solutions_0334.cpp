#include <bits/stdc++.h>
using namespace std;
long long int maxx, l, k, minn, w, d, n, m, x, z, y, a[100001], b, np, nl, c, p;
queue<int> s;
vector<long long int> v[100001];
bool mark[100001], markk[100001];
void clean(queue<int> &s) {
  while (!s.empty()) s.pop();
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    fill(a, a + 100001, 0);
    fill(mark, mark + 100001, 0);
    a[i] = 0;
    s.push(i);
    l = 1;
    while (s.size() != 0 && l != 0) {
      k = s.front();
      s.pop();
      z = v[k].size();
      for (int j = 0; j < z; j++) {
        if (mark[v[k][j]] == 0) {
          s.push(v[k][j]);
          mark[v[k][j]] = 1;
          a[v[k][j]] = a[k] + 1;
          if (a[v[k][j]] == 2 && v[k][j] > i) p++;
          if (a[v[k][j]] == 4) {
            l = 0;
          }
        }
      }
    }
    clean(s);
  }
  cout << p;
  return 0;
}
