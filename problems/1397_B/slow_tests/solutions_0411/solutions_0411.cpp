#include <bits/stdc++.h>
const long long N = 300010;
long long arr[N];
using namespace std;
bool binasea(long long arr[], long long n, long long key) {
  long long hi = n - 1, lo = 0, mid;
  while (lo <= hi) {
    mid = lo + (hi - lo) / 2;
    if (arr[mid] == key)
      return true;
    else if (arr[mid] > key)
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  return 0;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) res *= a;
    b /= 2;
    a *= a;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
signed main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  long long t = 1, n;
  long long check = pow(10, 15);
  while (t--) {
    cin >> n;
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }
    sort(arr, arr + n);
    long long mini = abs(sum - n);
    long long upb = 1;
    if (n < 40) {
      while (power(upb, n - 1) <= check) upb++;
    }
    long long k = 0;
    for (long long i = 2; i < upb + 1; i++) {
      sum = 0;
      for (long long j = 0; j < n; j++) {
        sum += abs(power(i, j) - arr[j]);
      }
      mini = min(mini, sum);
    }
    cout << mini << "\n";
  }
  return 0;
}
