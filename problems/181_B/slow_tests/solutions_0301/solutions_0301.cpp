#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n][2], br = 0;
  for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
  int p[2];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (a[j][0] < a[i][0]) {
        p[0] = a[i][0];
        p[1] = a[i][1];
        a[i][0] = a[j][0];
        a[i][1] = a[j][1];
        a[j][0] = p[0];
        a[j][1] = p[1];
      } else if ((a[j][0] == a[i][0]) && (a[j][1] < a[i][1])) {
        p[0] = a[i][0];
        p[1] = a[i][1];
        a[i][0] = a[j][0];
        a[i][1] = a[j][1];
        a[j][0] = p[0];
        a[j][1] = p[1];
      }
    }
  int donjagranica = 0, gornjagranica = n - 1, sredina;
  int donjagranica2, gornjagranica2, sredina2;
  double g[2];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      g[0] = (a[i][0] + a[j][0]) / 2.0;
      g[1] = (a[i][1] + a[j][1]) / 2.0;
      while (a[donjagranica][0] != a[gornjagranica][0]) {
        sredina = (donjagranica + gornjagranica) / 2;
        if (a[sredina][0] >= g[0])
          gornjagranica = sredina;
        else
          donjagranica = sredina + 1;
      }
      while (a[gornjagranica][0] == a[gornjagranica + 1][0]) {
        gornjagranica++;
      }
      while (a[donjagranica][0] == a[donjagranica - 1][0]) {
        donjagranica--;
      }
      donjagranica2 = donjagranica;
      gornjagranica2 = gornjagranica;
      while (donjagranica2 < gornjagranica2) {
        sredina2 = (donjagranica2 + gornjagranica2) / 2;
        if (a[sredina2][1] >= g[1])
          gornjagranica2 = sredina2;
        else
          donjagranica2 = sredina2 + 1;
      }
      if ((a[donjagranica2][0] == g[0]) && (a[donjagranica2][1] == g[1])) br++;
      gornjagranica = n - 1;
      donjagranica = 0;
    }
  cout << br;
  return 0;
}
