#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  for (long long i = 0; i < s.length(); i++) {
    string t = s;
    for (long long j = 0; j < s.length(); j++) {
      if (j >= i && j < i + k && s[j] == '?') {
        t[j] = 'N';
      }
    }
    long long ans = 0, cnt = 0;
    for (long long j = 0; j < s.length(); j++) {
      if (t[j] == 'N') {
        cnt++;
      } else {
        cnt = 0;
      }
      ans = max(ans, cnt);
    }
    if (ans == k) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
