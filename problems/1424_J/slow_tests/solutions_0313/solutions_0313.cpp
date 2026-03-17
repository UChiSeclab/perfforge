#include <bits/stdc++.h>
inline long long read() {
  long long sign = 1;
  long long x = 0;
  char ch;
  while (!isdigit(ch = getchar()))
    if (ch == '-') sign = -1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * sign;
}
inline void wonl() { putchar('\n'); }
inline void ww(long long k) {
  if (k < 0) putchar('-'), k *= -1;
  char ch[20];
  int num = 0;
  while (k) ch[++num] = k % 10, k /= 10;
  if (num == 0) ch[++num] = 0;
  while (num) putchar(ch[num--] + '0');
}
using namespace std;
const int N = 1e6 + 4;
template <typename T, typename... V>
inline void wonl(T t, V... v) {
  ww(t);
  if (sizeof...(v)) putchar(' ');
  wonl(v...);
}
int main() {
  int t = 1;
  t = read();
  int arr[t], mx = 0;
  for (int i = 0; i < t; i++) {
    arr[i] = read();
    if (arr[i] > mx) mx = arr[i];
  }
  vector<bool> nos(mx + 1, 1);
  for (int i = 2; i * i <= mx; i++) {
    if (nos[i]) {
      for (int j = i * i; j <= mx; j += i) {
        if (nos[j]) nos[j] = 0;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i <= mx; i++) {
    if (nos[i]) primes.push_back(i);
  }
  for (int i = 0; i < t; i++) {
    vector<int>::iterator it;
    it = upper_bound(primes.begin(), primes.end(), arr[i]);
    int x = (int)sqrt(arr[i]);
    vector<int>::iterator it2;
    it2 = upper_bound(primes.begin(), primes.end(), x);
    int ans = it - it2;
    wonl(ans + 1);
  }
  return 0;
}
