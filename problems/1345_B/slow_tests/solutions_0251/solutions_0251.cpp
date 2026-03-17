#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, i;
  cin >> n;
  long int arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  long int m = *max_element(arr, arr + n);
  vector<long long int> brr;
  brr.push_back(2);
  i = 1;
  while (1) {
    brr.push_back(brr[i - 1] + 3 * i + 2);
    if (brr[i] > m) break;
    i++;
  }
  for (i = 0; i < n; i++) {
    long int a = arr[i];
    long int c = 0;
    while (a) {
      auto it = upper_bound(brr.begin(), brr.end(), a);
      if (it == brr.begin()) break;
      c++;
      it--;
      a = a - *it;
    }
    cout << c << endl;
  }
}
