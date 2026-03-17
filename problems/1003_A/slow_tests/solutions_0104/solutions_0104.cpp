#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x;
  vector<int> v1;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v1.push_back(x);
  }
  int occ, count = 0;
  vector<int> v2;
  for (int i = 0; i < n; i++) {
    occ = v1[i];
    for (int j = 0; j < n; j++) {
      if (occ == v1[j]) count++;
    }
    v2.push_back(count);
    count = 0;
  }
  sort(v2.begin(), v2.end());
  int l;
  l = v2.size();
  cout << v2[l - 1];
  return 0;
}
