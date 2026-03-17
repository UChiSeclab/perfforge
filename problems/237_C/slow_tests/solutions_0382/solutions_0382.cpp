#include <bits/stdc++.h>
using namespace std;
int a, b, k;
bool prime[1000001];
int main() {
  int i, j;
  cin >> a >> b >> k;
  int cnt = 0, leng = 0;
  for (i = a; i <= b; i++) {
    prime[i] = true;
    int s = (int)(sqrt((double)i));
    for (j = 2; j <= s; j++) {
      if (i % j == 0) {
        prime[i] = false;
        break;
      }
    }
    if (i == 1) prime[i] = false;
    if (prime[i]) cnt++;
  }
  if (cnt < k) {
    cout << -1;
    return 0;
  }
  int s = a, e = a, max = 0, cprime = 0;
  while (1) {
    if (e > b) break;
    if (prime[e] != true) {
      if (cprime == k) {
        if (prime[s] != true) {
          s++;
        } else {
          e++;
        }
      } else {
        e++;
      }
    } else if (prime[e] == true) {
      if (cprime < k) {
        cprime++;
        if (max < e - s + 1) max = e - s + 1;
        e++;
      } else if (cprime == k) {
        if (max < e - s) max = e - s;
        if (prime[s] != true) {
          s++;
        } else {
          if (s == e)
            e++;
          else {
            if (prime[s] == true) cprime--;
            s++;
          }
        }
      }
    }
  }
  if (max < e - s) max = e - s;
  cout << max;
  return 0;
}
