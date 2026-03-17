#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, d;
    cin >> n >> k >> d;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int temp[101] = {0};
    int max_day = INT_MAX, count = 0;
    for (int i = 0; i + d <= n; i++) {
      for (int j = i; j < d + i; j++) {
        temp[arr[j]]++;
      }
      for (int k = 0; k <= 100; k++) {
        if (temp[k] != 0) {
          count++;
          temp[k] = 0;
        }
      }
      max_day = min(max_day, count);
      count = 0;
    }
    cout << max_day << endl;
  }
  return 0;
}
