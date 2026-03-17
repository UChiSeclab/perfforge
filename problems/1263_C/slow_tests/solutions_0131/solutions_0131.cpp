#include <bits/stdc++.h>
using namespace std;
void search(int n) {
  int i = sqrt(n);
  set<int> s = {0};
  int mid;
  while (i >= 1) {
    if (s.count(n / i) == 0) {
      s.insert(n / i);
    }
    if (s.count(i) == 0) {
      s.insert(i);
    }
    mid = i / 2;
    if (mid == 0) break;
    if (n / mid == n / i + 1) {
      i = mid - 1;
      if (s.count(n / mid) == 0) {
        s.insert(n / mid);
      }
    } else
      i--;
  }
  cout << s.size() << "\n";
  for (auto it = s.begin(); it != s.end(); ++it) cout << *it << " ";
  cout << "\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    search(n);
  }
  return 0;
}
