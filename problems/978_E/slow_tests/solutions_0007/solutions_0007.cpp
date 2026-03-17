#include <bits/stdc++.h>
using namespace std;
int n, w;
int arr[1005];
int psum[1005];
int main() {
  cin >> n >> w;
  for (int i = 0; i < n; i++) cin >> arr[i];
  psum[0] = arr[0];
  for (int i = 1; i < n; i++) psum[i] = arr[i] + psum[i - 1];
  int hi = *max_element(psum, psum + n);
  int lo = *min_element(psum, psum + n);
  int cnt = 0;
  for (int i = 0; i <= w; i++)
    if (i + hi <= w && i + lo >= 0) cnt++;
  cout << cnt;
}
