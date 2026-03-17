#include <bits/stdc++.h>
using namespace std;
bitset<502> b[502];
bool ok[502];
int n, k, c;
int main() {
  b[0][0] = ok[0] = 1;
  scanf("%d%d", &n, &k);
  while (n--) {
    scanf("%d", &c);
    for (int j = k; j >= c; j--)
      for (int i = 0; i <= k; i++)
        b[j][i] = (b[j][i] || b[j - c][i] || ((i >= c) ? b[j - c][i - c] : 0));
  }
  printf("%d\n", b[k].count());
  for (int i = 0; i <= k; i++)
    if (b[k][i]) printf("%d ", i);
  return 0;
}
