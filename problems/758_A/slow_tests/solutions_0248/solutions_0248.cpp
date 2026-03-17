#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int temp;
  long long int c = 0;
  long long int n;
  long long int *a;
  cin >> n;
  a = (long long int *)malloc(sizeof(long long int) * n);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long int i = 0; i < n - 1; i++) {
    for (long long int j = i + 1; j < n; j++) {
      if (a[j] > a[i]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
  for (long long int i = 0; i < n; i++) {
    c += a[0] - a[i];
  }
  cout << c;
  return 0;
}
