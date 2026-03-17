#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, i, j, x, y, cont, x2, y2, x3, y3;
  cin >> n;
  map<int, set<int> > mapa;
  map<int, set<int> >::iterator it, ita;
  set<int>::iterator sit, sita;
  cont = 0;
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    mapa[x].insert(y);
  }
  for (it = mapa.begin(); it != mapa.end(); ++it) {
    for (sit = it->second.begin(); sit != it->second.end(); ++sit) {
      ita = it;
      while (ita != mapa.end()) {
        if (ita == it) {
          sita = sit;
          sita++;
        } else {
          sita = ita->second.begin();
        }
        for (; sita != ita->second.end(); ++sita) {
          x = it->first;
          y = *sit;
          x2 = ita->first;
          y2 = *sita;
          if ((x != x2 || y != y2) && (x + x2) % 2 == 0 && (y + y2) % 2 == 0) {
            x3 = (x + x2) / 2;
            y3 = (y + y2) / 2;
            if (mapa[x3].find(y3) != mapa[x3].end()) {
              cont++;
            }
          }
        }
        ita++;
      }
    }
  }
  cout << cont << endl;
  return 0;
}
