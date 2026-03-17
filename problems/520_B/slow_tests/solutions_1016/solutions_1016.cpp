#include <bits/stdc++.h>
using namespace std;
int dist[60010];
int n, m, inf;
void bellman(int s) {
  int size = 2 * m;
  for (int i = 0; i < size; i++) dist[i] = inf;
  dist[s] = 0;
  for (int i = 0; i < size - 1; i++) {
    for (int j = 1; j < size; j++) {
      if (dist[j] + 1 < dist[j * 2]) dist[j * 2] = dist[j] + 1;
      if (dist[j] + 1 < dist[j - 1]) dist[j - 1] = dist[j] + 1;
    }
  }
}
int main() {
  cin >> n >> m;
  if (n > m) {
    cout << n - m << endl;
    return 0;
  }
  unsigned int t = -1;
  ;
  inf = 1 << 30;
  bellman(n);
  cout << dist[m] << endl;
  return 0;
}
