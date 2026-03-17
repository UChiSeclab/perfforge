#include <bits/stdc++.h>
using namespace std;
long long int no_of_ones_on_right[1000010];
long long int minimum_destroyed[1000010];
long long int power[1000010] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  long long int n, a, b, max_right = 0, n_right, n_destroyed;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    power[a] = b;
    max_right = max(max_right, a);
  }
  n_right = 0;
  for (int i = max_right; i >= 0; i--) {
    no_of_ones_on_right[i] = n_right;
    if (power[i] > 0) n_right++;
  }
  minimum_destroyed[0] = 0;
  for (int i = 1; i <= max_right; i++) {
    if (power[i] > 0) {
      if (i - power[i] - 1 < 0) {
        minimum_destroyed[i] = n_right - no_of_ones_on_right[i] - 1;
      } else
        minimum_destroyed[i] =
            (no_of_ones_on_right[(i - power[i] - 1) < 0 ? 0
                                                        : (i - power[i] - 1)] -
             no_of_ones_on_right[i] - 1) +
            minimum_destroyed[(i - power[i] - 1) < 0 ? 0 : (i - power[i] - 1)];
    } else {
      minimum_destroyed[i] = minimum_destroyed[i - 1];
    }
  }
  long long int ans = LONG_MAX;
  for (int i = 0; i <= max_right; i++) {
    ans = min(ans, minimum_destroyed[i] + no_of_ones_on_right[i]);
  }
  cout << ans << '\n';
  return 0;
}
