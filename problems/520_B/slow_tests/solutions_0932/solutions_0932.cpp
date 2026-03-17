#include <bits/stdc++.h>
using namespace std;
int main() {
  list<int> a[10001];
  int n, m, val, maxi, visited[10001], dist[10001];
  list<int>::iterator it;
  cin >> n >> m;
  if (n == m)
    cout << "0";
  else {
    for (int i = 1; i <= 10000; ++i) {
      if (i - 1 <= 10000) a[i].push_back(i - 1);
      if (i * 2 <= 10000) a[i].push_back(i * 2);
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i <= 10000; ++i) dist[i] = INT_MAX;
    dist[n] = 0;
    for (int i = 0; i < 10000; ++i) {
      maxi = INT_MAX;
      for (int j = 0; j <= 10000; ++j) {
        if (!visited[j] && dist[j] < maxi) {
          val = j;
          maxi = dist[j];
        }
      }
      visited[val] = 1;
      if (val == m) break;
      for (it = a[val].begin(); it != a[val].end(); ++it) {
        if (!visited[*it] && dist[*it] > dist[val] + 1)
          dist[*it] = dist[val] + 1;
      }
    }
    cout << dist[m];
  }
}
