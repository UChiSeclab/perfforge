#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void err(istream_iterator<string> it) { cout << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << " ";
  err(++it, args...);
}
long long pow(long long x, long long y) {
  if (y == 0) return 1;
  long long temp = pow(x, y / 2);
  temp = (temp * temp);
  if (y % 2 == 1) temp *= x;
  return temp;
}
map<int, set<int>> m;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    int y;
    cin >> a[i] >> y;
    vector<int> div;
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        div.push_back(j);
        if (a[i] / j != j) div.push_back(a[i] / j);
      }
    }
    int res = 0;
    for (int d : div) {
      if (m[d].lower_bound(i - y) == m[d].end()) res++;
    }
    cout << res << '\n';
    for (int d : div) m[d].insert(i);
  }
}
