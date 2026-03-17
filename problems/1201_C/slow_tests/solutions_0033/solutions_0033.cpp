#include <bits/stdc++.h>
using namespace std;
int bin_search(int *arr, int l, int r, int key) {
  int mid;
  int ans = l;
  while (l < r) {
    mid = ((l + r) / 2) + 1;
    if (arr[mid] == key) {
      l = mid;
      ans = l;
    } else if (arr[mid] > key) {
      r = mid - 1;
    }
  }
  return ans;
}
int main() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int el = arr[n / 2];
  int pos = 0;
  int left = n / 2;
  int size = 0;
  int maxmedian = el;
  while (k > 0) {
    pos = bin_search(arr, left, n - 1, el);
    if (pos == n - 1) {
      break;
    }
    size += pos - left + 1;
    while (el < arr[pos + 1]) {
      k -= size;
      if (k >= 0) {
        el++;
        maxmedian++;
      } else {
        break;
      }
    }
    left = pos + 1;
    el = arr[left];
  }
  if (k > 0) {
    maxmedian += k / ((n + 1) / 2);
  }
  cout << maxmedian;
}
