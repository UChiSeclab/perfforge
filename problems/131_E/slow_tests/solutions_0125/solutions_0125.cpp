#include <bits/stdc++.h>
using namespace std;
int **ac, **bd, **ad, **ab, **l, res[9];
int n, m;
int check(int num) {
  int c = 0;
  if (ab[l[num][0]][0] != -1 && ab[l[num][0]][0] != ab[l[num][0]][1]) {
    if (ab[l[num][0]][0] < l[num][1] && ab[l[num][0]][1] > l[num][1])
      c += 2;
    else
      c++;
  }
  if (ad[l[num][1]][0] != -1 && ad[l[num][1]][0] != ad[l[num][1]][1]) {
    if (ad[l[num][1]][0] < l[num][0] && ad[l[num][1]][1] > l[num][0])
      c += 2;
    else
      c++;
  }
  if (ac[l[num][1] + l[num][0]][0] != -1 &&
      ac[l[num][1] + l[num][0]][0] != ac[l[num][1] + l[num][0]][1]) {
    if (ac[l[num][1] + l[num][0]][0] < l[num][0] &&
        ac[l[num][1] + l[num][0]][1] > l[num][0])
      c += 2;
    else
      c++;
  }
  if (bd[l[num][1] - l[num][0] + n - 1][0] != -1 &&
      bd[l[num][1] - l[num][0] + n - 1][0] !=
          bd[l[num][1] - l[num][0] + n - 1][1]) {
    if (bd[l[num][1] - l[num][0] + n - 1][0] < l[num][0] &&
        bd[l[num][1] - l[num][0] + n - 1][1] > l[num][0])
      c += 2;
    else
      c++;
  }
  return c;
}
int main() {
  scanf("%d%d", &n, &m);
  ac = new int *[2 * n + 1];
  bd = new int *[2 * n + 1];
  ad = new int *[n];
  ab = new int *[n];
  l = new int *[m];
  for (int i = 0; i < n; i++) {
    ad[i] = new int[2];
    ad[i][0] = -1;
    ab[i] = new int[2];
    ab[i][0] = -1;
  }
  for (int i = 0; i < m; i++) l[i] = new int[2];
  for (int i = 0; i < 2 * n; i++) {
    ac[i] = new int[2];
    ac[i][0] = -1;
    bd[i] = new int[2];
    bd[i][0] = -1;
  }
  for (int i = 0; i < m; i++) {
    int t1, t2;
    scanf("%d%d", &t1, &t2);
    t1--;
    t2--;
    l[i][0] = t1;
    l[i][1] = t2;
    if (ab[t1][0] == -1) {
      ab[t1][0] = t2;
      ab[t1][1] = t2;
    } else {
      if (t2 > ab[t1][1]) ab[t1][1] = t2;
      if (t2 < ab[t1][0]) ab[t1][0] = t2;
    }
    if (ad[t2][0] == -1) {
      ad[t2][0] = t1;
      ad[t2][1] = t1;
    } else {
      if (t1 > ad[t2][1]) ad[t2][1] = t1;
      if (t1 < ad[t2][0]) ad[t2][0] = t1;
    }
    if (ac[t2 + t1][0] == -1) {
      ac[t2 + t1][0] = t1;
      ac[t2 + t1][1] = t1;
    } else {
      if (t1 > ac[t2 + t1][1]) ac[t2 + t1][1] = t1;
      if (t1 < ac[t2 + t1][0]) ac[t2 + t1][0] = t1;
    }
    if (bd[t2 - t1 + n - 1][0] == -1) {
      bd[t2 - t1 + n - 1][0] = t1;
      bd[t2 - t1 + n - 1][1] = t1;
    } else {
      if (t1 > bd[t2 - t1 + n - 1][1]) bd[t2 - t1 + n - 1][1] = t1;
      if (t1 < bd[t2 - t1 + n - 1][0]) bd[t2 - t1 + n - 1][0] = t1;
    }
  }
  for (int i = 0; i < m; i++) res[check(i)]++;
  for (int i = 0; i <= 8; i++) printf("%d ", res[i]);
}
