#include <bits/stdc++.h>
using namespace std;
int dp[109][109][109][5], m, noatk, nodef, atkcard[109], card[109],
    defcard[109];
int memoize(int ceil, int atk, int def, int cardlef) {
  if (ceil == m && cardlef == 2 && (atk != noatk || def != nodef))
    return -1 * 10000000;
  if (ceil == m) return 0;
  if (dp[ceil][atk][def][cardlef] != -1) return dp[ceil][atk][def][cardlef];
  int ans = -1 * 10000000;
  if (cardlef != 0) ans = max(ans, card[ceil] + memoize(ceil + 1, atk, def, 2));
  if (atk < noatk && card[ceil] >= atkcard[atk])
    ans = max(ans, card[ceil] - atkcard[atk] +
                       memoize(ceil + 1, atk + 1, def, cardlef));
  if (def < nodef && card[ceil] > defcard[def])
    ans = max(ans, memoize(ceil + 1, atk, def + 1, cardlef));
  if (def < nodef && cardlef != 2)
    ans = max(ans, memoize(ceil, atk, def + 1, 0));
  if (atk < noatk && cardlef != 2)
    ans = max(ans, memoize(ceil, atk + 1, def, 0));
  ans = max(ans, memoize(ceil + 1, atk, def, cardlef));
  return dp[ceil][atk][def][cardlef] = ans;
}
int main() {
  memset(dp, -1, sizeof(dp));
  int n;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = int(0); i <= int(n - 1); i++) {
    string str;
    cin >> str;
    int val;
    scanf("%d", &val);
    if (str == "ATK")
      atkcard[noatk++] = val;
    else
      defcard[nodef++] = val;
  }
  sort(atkcard, atkcard + noatk);
  reverse(atkcard, atkcard + noatk);
  sort(defcard, defcard + nodef);
  reverse(defcard, defcard + nodef);
  for (int i = int(0); i <= int(m - 1); i++) scanf("%d", &card[i]);
  sort(card, card + m);
  reverse(card, card + m);
  int ans = memoize(0, 0, 0, 1);
  printf("%d\n", ans);
  return 0;
}
