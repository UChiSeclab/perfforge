#include <bits/stdc++.h>
using namespace std;
struct debugger {
  static void call(string::iterator it, string::iterator ed) {}
  template <typename T, typename... aT>
  static void call(string::iterator it, string::iterator ed, T a, aT&... rest) {
    string b;
    for (; *it != ','; ++it)
      if (*it != ' ') b += *it;
    cout << b << "=" << a << " ";
    call(++it, ed, rest...);
  }
};
int main() {
  long long int a, b, c, d, i, j;
  cin >> a >> b >> c >> d;
  map<long long int, long long int> mp;
  for (i = 0; i <= 1000000; i++) {
    long long int ret = b + i * a;
    if (mp[ret] != 0) {
      cout << ret << endl;
      return 0;
    }
    mp[ret]++;
    ret = d + i * c;
    if (mp[ret] != 0) {
      cout << ret << endl;
      return 0;
    }
    mp[ret]++;
  }
  cout << -1 << endl;
  return 0;
}
