#include <bits/stdc++.h>
using namespace std;
string binary(long long n) {
  string result;
  do result += '0' + (n & 1);
  while (n >>= 1);
  reverse(result.begin(), result.end());
  return result;
}
int countSubstr(const string& str, const string& sub) {
  if (sub.length() == 0) return 0;
  int count = 0;
  for (size_t offset = str.find(sub); offset != string::npos;
       offset = str.find(sub, offset + sub.length())) {
    ++count;
  }
  return count;
}
vector<bool> primes;
vector<int> primesCnt;
void seive(int a, int b) {
  primes = vector<bool>(b + 1, true);
  primesCnt = vector<int>(b, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i * i <= b; i++) {
    for (int j = i; j * i <= b; j++) {
      primes[i * j] = false;
    }
  }
  primesCnt[0] = 0;
  for (decltype(b + 1)(i) = (1); (i) < (b + 1); (i)++) {
    primesCnt[i] = primesCnt[i - 1] + primes[i];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, k, ans = -1;
  cin >> a >> b >> k;
  seive(a, b);
  if (primesCnt[b] - primesCnt[a - 1] < k) {
    cout << ans;
    return 0;
  }
  int left = 0, right = b - a + 1, med;
  while (right > left + 1) {
    med = (right + left) / 2;
    bool can = true;
    int j = a + med - 1;
    while (j <= b) {
      if (primesCnt[j] - primesCnt[j - med] < k) {
        can = false;
        break;
      }
      j++;
    }
    if (can)
      right = med;
    else
      left = med;
  }
  cout << right;
  return 0;
}
