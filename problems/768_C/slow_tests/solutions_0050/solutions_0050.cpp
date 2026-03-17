#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x;
  cin >> n >> k >> x;
  int a[n];
  int freq[2001] = {0};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }
  int l = 0;
  int tmp[2001];
  for (int i = 0; i < k; i++) {
    l = 0;
    for (int i = 0; i < 2001; i++) tmp[i] = freq[i];
    for (int j = 0; j < 2001; j++) {
      if (l % 2 == 0 && freq[j] % 2 == 1) {
        tmp[j ^ x] += ceil(freq[j] / 2.0);
        tmp[j] -= ceil(freq[j] / 2.0);
        l++;
      } else if (l % 2 == 1 && freq[j] % 2 == 1) {
        tmp[j ^ x] += floor(freq[j] / 2.0);
        tmp[j] -= floor(freq[j] / 2.0);
        l++;
      } else {
        tmp[j ^ x] += freq[j] / 2;
        tmp[j] -= freq[j] / 2;
      }
    }
    for (int i = 0; i < 2001; i++) freq[i] = tmp[i];
  }
  int pq = 0;
  for (int i = 0; i < 2001; i++) {
    if (freq[i] != 0) {
      pq = i;
    }
  }
  cout << pq << " ";
  for (int i = 0; i < 2001; i++) {
    if (freq[i] != 0) {
      cout << i;
      break;
    }
  }
  return 0;
}
