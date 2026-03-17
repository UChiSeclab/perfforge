#include <bits/stdc++.h>
const long long int INF = 1e18;
const long long int MOD = 1000000007;
const int MX = 100005;
using namespace std;
int main() {
  int test_c;
  cin >> test_c;
  while (test_c--) {
    long long int i, j;
    int n;
    cin >> n;
    int count = 0;
    vector<long long int> a(MX);
    for (i = 0; i < MX; i++) a[i] = ((i + 1) * (3 * i + 4)) / 2;
    while (n) {
      vector<long long int>::iterator it = upper_bound(a.begin(), a.end(), n);
      i = it - a.begin();
      i--;
      if (i >= 0) {
        n -= a[i];
        count++;
      } else
        break;
    }
    cout << count << endl;
  }
  return 0;
}
