#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int *B = new int[n];
  int *G = new int[m];
  for (int i = 0; i < n; i++) B[i] = 0;
  for (int i = 0; i < m; i++) G[i] = 0;
  int b, g;
  cin >> b;
  for (int i = 0; i < b; i++) {
    int t;
    cin >> t;
    B[t] = 1;
  }
  cin >> g;
  for (int i = 0; i < g; i++) {
    int t;
    cin >> t;
    G[t] = 1;
  }
  int i = 0;
  int max = m * n;
  bool possible = false;
  do {
    int boy = i % n;
    int girl = i % m;
    if (B[boy])
      if (!G[girl]) G[girl] = 1;
    if (G[girl])
      if (!B[boy]) B[boy] = 1;
    i++;
    bool gF = true, bF = true;
    for (int i = 0; i < n; i++)
      if (B[i] == 0) {
        bF = false;
        break;
      }
    for (int i = 0; i < m; i++)
      if (G[i] == 0) {
        gF = false;
        break;
      }
    if (bF && gF) {
      possible = true;
      break;
    }
  } while (i < m * n * 10);
  if (possible)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
