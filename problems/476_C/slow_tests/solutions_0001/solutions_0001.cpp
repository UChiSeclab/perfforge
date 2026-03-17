#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  long long int ans = 0;
  for (int i = 1; i < b; i++) {
    int n = a;
    long long int temp;
    if (n % 2 == 0) {
      temp = n + 1;
      temp = (temp * (n / 2)) % mod;
      temp = (temp * i) % mod;
    } else {
      temp = n;
      temp = (temp * ((n + 1) / 2)) % mod;
      temp = (temp * i) % mod;
    }
    temp = (temp * b) % mod;
    ans = (ans + temp) % mod;
    temp = ((long long int)i * n) % mod;
    ans = (ans + temp) % mod;
  }
  cout << ans;
}
