#include <bits/stdc++.h>
using namespace std;
long long n, i, temp, b[1000001], mx, ans, lel;
long long r[1000001];
pair<long long, long long> a[100001];
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first > b.first or a.first == b.first and a.second > b.second;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> temp;
    b[temp]++;
    mx = max(temp, mx);
  }
  for (i = mx; i >= 1; i--) {
    if ((b[i] + r[i]) % 2 == 1 and b[i]) {
      b[i]--, r[i - 1]++;
    }
  }
  vector<long long> kek;
  for (i = mx; i >= 1; i--) {
    b[i] = b[i] + r[i];
    for (int j = 0; j < b[i] - b[i] % 2; j++) kek.push_back(i);
  }
  for (int i = 0; i < kek.size(); i += 4) {
    if (i + 3 < kek.size()) {
      ans += kek[i] * kek[i + 2];
    }
  }
  cout << ans << "\n";
  return 0;
}
