#include <bits/stdc++.h>
using namespace std;
double pi = 3.141592653589793238462;
string numkey = "0123456789";
string uni = "abcdefghijklmnopqrstuvwxyz";
signed main() {
  long long int n;
  cin >> n;
  n *= 2;
  long long int arr[n];
  long long int hash[1000 + 100] = {0};
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  long long int ans = INT_MAX;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      vector<long long int> v;
      for (long long int k = 0; k < n; k++) {
        if (k != i && k != j) v.push_back(arr[k]);
      }
      sort(v.begin(), v.end());
      long long int maxx = 0;
      for (long long int k = 0; k < v.size() - 1; k += 2) {
        maxx = maxx + abs(v[k] - v[k + 1]);
      }
      ans = min(ans, maxx);
    }
  }
  cout << ans;
  return 0;
}
