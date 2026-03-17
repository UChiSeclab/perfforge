#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, y;
  cin >> p >> y;
  map<int, int> a;
  for (int i = 2; i <= min((int)sqrt(y) + 1, p); i++) {
    if (y % i == 0 && i == 2) {
      a[i] = 1;
      a[y - (y % i)] = 1;
    } else if (i % 2 != 0) {
      a[i] = 1;
      a[y - (y % i)] = 1;
    }
  }
  vector<int> ans;
  for (auto it = a.begin(); it != a.end(); it++) {
    ans.push_back(it->first);
  }
  if (ans.empty() || ans[max((int)((ans).size()) - 1, 0)] != y) {
    cout << y;
    return 0;
  }
  for (int i = (int)((ans).size()) - 1; i > 0; i--) {
    if (ans[i] - 1 > p) {
      for (int j = ans[i] - 1; j > ans[i - 1]; j--) {
        int flag = 1;
        for (int k = 2; k <= min((int)sqrt(j), p); k++) {
          if (j % k == 0) {
            flag = 0;
            break;
          }
        }
        if (flag) {
          cout << j;
          return 0;
        }
      }
    }
  }
  cout << "-1";
}
