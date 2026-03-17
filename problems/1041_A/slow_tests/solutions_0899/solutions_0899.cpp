#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  int t = 0, d = 0;
  for (int i = a[0]; i <= a[n - 1]; i++) {
    if (i == a[t])
      t++;
    else
      d++;
  }
  cout << d << endl;
}
