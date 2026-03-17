#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, w, v1, v2, cont1, cont2, q, total;
  bool flag = 0;
  cin >> n;
  cont1 = cont2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> w;
    if (w == 100)
      cont1++;
    else
      cont2++;
  }
  if (n == 1)
    cout << "NO";
  else {
    if ((cont1 * 100) == (cont2 * 200))
      cout << "YES";
    else {
      total = (cont1 * 100) + (cont2 * 200);
      q = total / 2;
      for (int i = 0; i <= cont1 and !flag; i++) {
        for (int j = 0; j <= cont2 and !flag; j++) {
          v1 = (i * 100) + (j * 200);
          v2 = total - v1;
          if (v1 == v2) flag = 1;
        }
      }
      if (flag)
        cout << "YES";
      else
        cout << "NO";
    }
  }
  cout << endl;
  return 0;
}
