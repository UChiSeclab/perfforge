#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int l = 0; l < t; l++) {
    int n, k, d;
    cin >> n >> k >> d;
    int *a = new int[n];
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]] = 0;
    }
    deque<int> q;
    int j = 0;
    for (int i = 0; i < d; i++) {
      if (m[a[i]] == 0) {
        q.push_back(a[i]);
        m[a[i]] = 1;
      } else {
        m[a[i]] = m[a[i]] + 1;
      }
      j = i;
    }
    int ans = q.size();
    int start = 0;
    int end1 = d;
    for (int i = end1; i < (n); i++) {
      m[a[start]] = m[a[start]] - 1;
      if (m[a[start]] == 0) {
        q.pop_front();
      }
      if (m[a[i]] == 0) {
        q.push_back(a[i]);
        m[a[i]] = 1;
      } else {
        m[a[i]] = m[a[i]] + 1;
      }
      int k = q.size();
      if (ans > k) {
        ans = k;
      }
      start = start + 1;
    }
    cout << ans << endl;
  }
}
