#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
long long h[1000010];
int main() {
  long long n, x, max = -1, min = 1e9;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > max) max = a[i];
    if (a[i] < min) min = a[i];
    h[a[i]]++;
  }
  for (long long i = max; i >= min; i--) {
    if (h[i] % 2) {
      if (h[i - 1]) {
        h[i - 1]++;
      }
      h[i]--;
    }
  }
  long long area = 0;
  long long flag = 0, temp;
  for (long long i = max; i >= min; i--) {
    if (h[i]) {
      if (flag) {
        area += i * temp;
        h[i] -= 2;
      }
      long long f = h[i] / 4;
      area += f * (i * i);
      h[i] %= 4;
      if (h[i] == 2) {
        flag = 1;
        temp = i;
      } else
        flag = 0;
    }
  }
  cout << area << endl;
  return 0;
}
