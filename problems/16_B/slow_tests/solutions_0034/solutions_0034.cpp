#include <bits/stdc++.h>
using namespace std;
long long sumofdigits(string s) {
  long long sum = 0;
  for (long long i = 0; i < s.size(); i++) {
    int digit = s[i] - '0';
    sum += digit;
  }
  return sum;
}
int main() {
  int n;
  vector<pair<int, int>> v;
  cin >> n;
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    pair<int, int> p(x, y);
    v.push_back(p);
  }
  int sum = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    for (int j = i + 1; j < v.size(); j++) {
      if (v[j].second > v[i].second) {
        pair<int, int> p = v[i];
        v[i] = v[j];
        v[j] = p;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    int counter = 0;
    if (sum == n) {
      break;
    }
    int t = n - sum;
    while (counter < v[i].first && t--) {
      counter++;
      sum++;
      ans += v[i].second;
    }
  }
  cout << ans << endl;
}
