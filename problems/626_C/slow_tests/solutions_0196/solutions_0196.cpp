#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v1, v2;
int main() {
  cin >> n >> m;
  if (n == 0) {
    cout << m * 3;
    return 0;
  }
  if (m == 0) {
    cout << n * 2;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    v1.push_back(i * 2);
  }
  for (int i = 1; i <= m; i++) {
    v2.push_back(i * 3);
  }
  for (int i = 6; i <= min(v1[v1.size() - 1], v2[v2.size() - 1]); i += 6) {
    if (binary_search(v1.begin(), v1.end(), i) &&
        binary_search(v2.begin(), v2.end(), i)) {
      if (v1[v1.size() - 1] <= v2[v2.size() - 1]) {
        v1.push_back(v1[v1.size() - 1] + 2);
      } else {
        v2.push_back(v2[v2.size() - 1] + 3);
      }
    }
  }
  cout << max(v1[v1.size() - 1], v2[v2.size() - 1]);
  return 0;
}
