#include <bits/stdc++.h>
using namespace std;
int main() {
  int freq[4], n, sum = 0;
  for (int i = 0; i < 4; i++) {
    cin >> n;
    freq[i] = n;
  }
  while (freq[0] > 0 && freq[2] > 0 && freq[3] > 0) {
    sum += 256;
    freq[0]--;
    freq[2]--;
    freq[3]--;
  }
  while (freq[0] > 0 && freq[1] > 0) {
    sum += 32;
    freq[0]--;
    freq[1]--;
  }
  cout << sum;
  return 0;
}
