#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int arr[n];
  int max1 = -1;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    max1 = max(max1, arr[i]);
  }
  long long freq[max1 + 1], subsequence[max1 + 1];
  for (int i = 0; i <= max1; i++) {
    freq[i] = 0;
    subsequence[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    freq[arr[i]]++;
  }
  for (int i = max1; i > 0; i--) {
    for (int j = i; j <= max1; j += i) {
      subsequence[i] += freq[j];
    }
  }
  long long ans = 0;
  for (int i = max1; i > 0; i--) {
    long long sub = 0;
    for (int j = 2 * i; j <= max1; j += i) {
      sub += subsequence[j];
      sub %= mod;
    }
    subsequence[i] = (power(2, subsequence[i]) - 1 + mod) % mod;
    subsequence[i] -= sub;
    subsequence[i] += mod;
    subsequence[i] %= mod;
  }
  cout << subsequence[1] << "\n";
}
