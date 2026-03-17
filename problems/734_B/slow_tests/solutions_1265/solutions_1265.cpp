#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int ara[4];
  for (int i = 0; i < 4; i++) cin >> ara[i];
  long long int sum = -1;
  long long minv = min(ara[0], ara[2]);
  minv = min(ara[3], minv);
  for (int i = 0; i <= minv; i++) {
    long long a = 256LL * i + 32LL * min(ara[0] - i, ara[1]);
    sum = max(sum, a);
  }
  cout << sum;
}
