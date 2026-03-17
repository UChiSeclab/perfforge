#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, sum(0), summ(0);
  cin >> n >> m;
  int c[m][2];
  for (int i = 0; i < m; i++) {
    cin >> c[i][0];
    cin >> c[i][1];
  }
  for (int i = 0; i < m; i++) {
    for (int j = i; j < m; j++) {
      if (c[j][1] > c[i][1]) {
        swap(c[j], c[i]);
      }
    }
    summ += c[i][0];
  }
  if (summ >= n) {
    int k(0);
    while (n) {
      while (c[k][0] && n) {
        sum += c[k][1];
        c[k][0] -= 1;
        n--;
      }
      k++;
    }
  } else {
    int k(0);
    while (summ) {
      while (c[k][0] && summ) {
        sum += c[k][1];
        c[k][0] -= 1;
        summ--;
      }
      k++;
    }
  }
  cout << sum;
  return 0;
}
