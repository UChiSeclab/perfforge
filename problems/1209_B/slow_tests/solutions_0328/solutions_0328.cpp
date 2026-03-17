#include <bits/stdc++.h>
using namespace std;
const long double pie = 3.14159265358979;
const long long mod = 1e9 + 7;
string vow = "aeiou";
void solve(int test_case) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int N = 1e3;
  vector<vector<int> > v(n, vector<int>(N, 0));
  vector<pair<int, int> > p(n);
  for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
  for (int i = 0; i < n; i++) {
    if (s[i] - '0') v[i][0] = 1;
    for (int j = 1; j < p[i].second; j++) v[i][j] = v[i][j - 1];
    int temp = v[i][0] ^ 1;
    for (int j = p[i].second; j < N; j += p[i].first) {
      for (int k = 0; j + k < N; k++) v[i][j + k] = temp;
      temp ^= 1;
    }
  }
  int ans = 0;
  for (int j = 0; j < N; j++) {
    int temp = 0;
    for (int i = 0; i < n; i++) temp += v[i][j];
    ans = max(ans, temp);
  }
  cout << ans;
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 0; i < t; i++) solve(i);
  return 0;
}
