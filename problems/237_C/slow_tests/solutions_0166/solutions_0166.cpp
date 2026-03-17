#include <bits/stdc++.h>
using namespace std;
int isPrime(int n) {
  int md = (int)(pow((float)n, 0.5)) + 1;
  int i;
  if (n < 2) return 0;
  if (n == 2) return 1;
  for (i = 2; i <= md; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int cq[1000005];
int main() {
  int i;
  int a, b, k;
  cin >> a;
  cin >> b;
  cin >> k;
  int l = -1;
  cq[0] = a - 1;
  int ind = 1;
  for (i = a; i <= b; i++) {
    if (isPrime(i) == 1) {
      cq[ind % (k + 1)] = i;
      if (ind >= k) {
        int interv = cq[ind % (k + 1)] - cq[(ind - k) % (k + 1)];
        if (l < interv) {
          l = interv;
        }
      }
      ind++;
    }
  }
  if (ind >= k && b + 1 - cq[(ind - k) % (k + 1)] > l) {
    l = b + 1 - cq[(ind - k) % (k + 1)];
  }
  if (l > b - a + 1) {
    cout << "-1\n";
    return 0;
  }
  cout << l;
  return 0;
}
