#include <bits/stdc++.h>
using namespace std;
long long solve(string s) {
  if (count(s.begin(), s.end(), '0') == s.size()) {
    if (s == "0")
      return 1990;
    else if (s == "00")
      return 2000;
    else if (s == "000")
      return 3000;
    else {
      long long v;
      s = '1' + s;
      sscanf(s.c_str(), "%lld", &v);
      return v;
    }
  }
  long long value;
  sscanf(s.c_str(), "%lld", &value);
  long long p10 = 1;
  for (int i = 0; i < (int)s.size(); ++i) p10 *= 10;
  long long m = 1989;
  for (string sub = s.substr(1, s.size() - 1); !sub.empty();
       sub = sub.substr(1, sub.size() - 1))
    m = max(m, 1 + solve(sub));
  if (m <= value) return value;
  long long k = (m - value + p10 - 1) / p10;
  return value + k * p10;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    string s;
    scanf(" IAO'");
    cin >> s;
    cout << solve(s) << "\n";
  }
  return 0;
}
