#include <bits/stdc++.h>
using namespace std;
int main() {
  pair<double, double> p;
  set<pair<double, double>> s;
  set<pair<double, double>>::iterator it;
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p.first >> p.second;
    s.insert(p);
  }
  for (set<pair<double, double>>::iterator it1 = s.begin(); it1 != s.end();
       it1++) {
    for (set<pair<double, double>>::iterator it2 = next(it1, 1); it2 != s.end();
         it2++) {
      p.first = ((*it1).first + (*it2).first) / 2;
      p.second = ((*it1).second + (*it2).second) / 2;
      it = s.find(p);
      if (it != s.end() && it != it1 && it != it2) cnt++;
    }
  }
  cout << cnt;
  return 0;
}
