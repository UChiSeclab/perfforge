#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int n, i, j, c, c1;
  c1 = 0;
  vector<int>::iterator it, it2;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> j;
    v.push_back(j);
  }
  it = v.begin();
  it2 = v.end();
  for (i = 0; i < n; i++) {
    c = count(it, it2, v[i]);
    if (c > c1) c1 = c;
  }
  cout << c1;
}
