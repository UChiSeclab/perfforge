#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int x = arr[0];
  int last = arr[n - 1];
  int stolen = 0;
  int c = 0;
  for (int i = x; i <= last; i++) {
    if (arr[c] != i)
      stolen++;
    else
      c++;
  }
  cout << stolen;
  return 0;
}
