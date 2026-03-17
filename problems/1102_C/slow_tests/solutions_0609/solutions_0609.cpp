#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> v;
  int count = 0;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    v.push_back(p);
  }
  if (x > y) {
    cout << n;
    return 0;
  } else {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      v[0] -= x;
      if (v[0] <= 0) {
        count++;
        v.erase(v.begin() + 0);
      }
      v[0] = v[0] + y;
      sort(v.begin(), v.end());
      if (v[0] > x) {
        cout << count << endl;
        return 0;
      }
    }
    cout << count;
    return 0;
  }
}
