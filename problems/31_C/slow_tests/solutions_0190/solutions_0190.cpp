#include <bits/stdc++.h>
using namespace std;
int a, l[100009], r[100009], z[100009 * 10], b, c;
long long sm;
vector<int> v;
int main() {
  cin >> a;
  for (int i = 1; i <= a; i++) cin >> l[i] >> r[i], z[l[i]]++, z[r[i]]--;
  for (int i = 1; i <= 1000000; i++) z[i] += z[i - 1];
  for (int i = 1; i <= 1000000; i++) {
    if (z[i] > 2) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 1; i <= 1000000; i++) {
    if (z[i] == 2) {
      b = i;
      break;
    }
  }
  if (b == 0) {
    cout << a << endl;
    for (int i = 1; i <= a; i++) cout << i << ' ';
    return 0;
  }
  for (int i = 1000000; i >= 1; i--)
    if (z[i] == 2) {
      c = i;
      break;
    }
  c++;
  for (int i = 1; i <= a; i++)
    if (l[i] <= b and r[i] >= c) sm++, v.push_back(i);
  cout << sm << endl;
  for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
  return 0;
}
