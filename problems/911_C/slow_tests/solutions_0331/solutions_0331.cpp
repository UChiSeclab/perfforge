#include <bits/stdc++.h>
using namespace std;
int arr[3];
bool check() {
  bool freq[1005];
  memset(freq, 0, sizeof(freq));
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      for (int k = 1; k <= 100; k++) {
        for (int m = i; m <= 1000; m += arr[0]) freq[m] = 1;
        for (int m = j; m <= 1000; m += arr[1]) freq[m] = 1;
        for (int m = k; m <= 1000; m += arr[2]) freq[m] = 1;
        bool good = true;
        for (int m = max(i, max(j, k)); m <= 1000; m++) good &= freq[m];
        if (good) return true;
        for (int m = 1; m <= 1000; m++) freq[m] = false;
      }
    }
  }
  return false;
}
int main() {
  cin >> arr[0] >> arr[1] >> arr[2];
  sort(arr, arr + 3);
  if (check()) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
