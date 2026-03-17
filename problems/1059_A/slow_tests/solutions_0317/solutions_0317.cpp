#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, L, s;
  cin >> n >> L >> s;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    int ini, d;
    cin >> ini >> d;
    a[i] = make_pair(ini, d);
  }
  int i = 0, k = 0, last = 0;
  for (int j = 0; j < L;) {
    if (i < a.size() && a[i].first == j) {
      j += a[i].second;
      i++;
      last = j;
    } else {
      j++;
      if (j - last == s) {
        last = j;
        k++;
      }
    }
  }
  cout << k;
}
