#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long n;
  while (t--) {
    int a;
    map<int, int> mp;
    mp[0] = 1;
    map<int, int>::iterator it;
    cin >> n;
    int x = sqrt(n) + 1;
    for (int i = 1; i <= x; i++) {
      a = n / i;
      if (mp[a] == 0 && mp[i] == 0) {
        mp[a] = 1;
        mp[i] = 1;
      }
    }
    cout << mp.size() << endl;
    for (it = mp.begin(); it != mp.end(); it++) {
      cout << it->first << " ";
    }
    cout << endl;
  }
  return 0;
}
