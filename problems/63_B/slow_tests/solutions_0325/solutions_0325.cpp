#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> freq;
  int n, k, res = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int soliderRank;
    cin >> soliderRank;
    freq.find(soliderRank) != freq.end() ? freq[soliderRank] += 1
                                         : freq[soliderRank] = 1;
  }
  while (freq[k] < n) {
    for (int i = k - 1; i > 0; i--) {
      if (freq.find(i) != freq.end() && freq[i] > 0) {
        freq[i] -= 1;
        freq.find(i + 1) != freq.end() ? freq[i + 1] += 1 : freq[i + 1] = 1;
      }
    }
    res++;
  }
  cout << res;
  return 0;
}
