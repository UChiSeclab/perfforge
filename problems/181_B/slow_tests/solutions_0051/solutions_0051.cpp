#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, m, i, s = 0, d = 0, h, j;
  cin >> n;
  vector<vector<double>> b(n, vector<double>(2));
  set<pair<double, double>> a;
  for (i = 0; i < n; i++) {
    cin >> b[i][0] >> b[i][1];
    a.insert(make_pair(b[i][0], b[i][1]));
  }
  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++) {
      d = b[i][0] + b[j][0];
      d /= 2;
      h = b[i][1] + b[j][1];
      h /= 2;
      if (a.find(make_pair(d, h)) != a.end()) s++;
    }
  cout << s << endl;
}
