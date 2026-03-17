#include <bits/stdc++.h>
using namespace std;
int a[200000];
int main() {
  int n;
  cin >> n;
  int c[2];
  memset(c, 0, sizeof c);
  for (int i = 0; i < n; i++)
    cin >> a[i], c[(int)sqrt(a[i]) * (int)sqrt(a[i]) == a[i]]++;
  if (c[0] == c[1]) cout << 0 << endl, exit(0);
  long long val = 0;
  vector<int> v;
  v.clear();
  if (c[1] > c[0]) {
    for (int i = 0; i < n; i++)
      if (!((int)sqrt(a[i]) * (int)sqrt(a[i]) - a[i]))
        a[i] ? v.push_back(1) : v.push_back(2);
    sort(v.begin(), v.end());
    for (int i = 0; i < c[1] - (n >> 1); i++) val += v[i];
    cout << val << endl, exit(0);
  }
  val = 0;
  v.clear();
  if (c[0] > c[1]) {
    for (int i = 0; i < n; i++)
      if ((int)sqrt(a[i]) * (int)sqrt(a[i]) - a[i])
        v.push_back(
            min(abs((int)sqrt(a[i]) * (int)sqrt(a[i]) - a[i]),
                abs(((int)sqrt(a[i]) + 1) * ((int)sqrt(a[i]) + 1) - a[i])));
    sort(v.begin(), v.end());
    for (int i = 0; i < c[0] - (n >> 1); i++) val += v[i];
    cout << val << endl, exit(0);
  }
  return 0;
}
