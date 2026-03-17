#include <bits/stdc++.h>
using namespace std;
inline void print(vector<long long int>& a) {
  for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
  cout << "\n";
}
inline void inp(vector<int>& a, vector<int>& b) {
  for (int i = 0; i < a.size(); i++) {
    cin >> a[i] >> b[i];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n), b(n);
  inp(a, b);
  int ans = 0;
  for (int i = 0; i < 500000; i++) {
    int temp = 0;
    for (int j = 0; j < n; j++) {
      if (s[j] == '1') {
        temp++;
      }
    }
    ans = max(temp, ans);
    if (ans == n) break;
    for (int j = 0; j < n; j++) {
      if (i - b[j] >= 0 && (i - b[j]) % a[j] == 0) {
        if (s[j] == '1')
          s[j] = '0';
        else if (s[j] == '0')
          s[j] = '1';
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
