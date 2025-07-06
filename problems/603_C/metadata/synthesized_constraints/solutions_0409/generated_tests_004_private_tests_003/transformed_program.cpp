#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, k, a[N], flag[N], sg[N];

void Calc_SG() {
  memset(sg, 0, sizeof(sg));
  // Check for heavy loop operations
  check_large_loop_invariant(100000);
  for (register int i = 1; i <= 100000; i++) {
    if (i % 2)
      flag[sg[i - 1]] = 1;
    else {
      flag[sg[i - 1]] = 1;
      flag[sg[i / 2]] = 1;
    }
    for (register int j = 0; j <= 100000; j++)
      if (flag[j] == 0) {
        sg[i] = j;
        break;
      }
    if (i % 2)
      flag[sg[i - 1]] = 0;
    else {
      flag[sg[i - 1]] = 0;
      flag[sg[i / 2]] = 0;
    }
  }
}

int Cal(int x) {
  int rev = 0;
  while (x > 100000) {
    if (x % 2) {
      break;
    }
    rev++;
    x /= 2;
  }
  if (x <= 100000) {
    if (sg[x] == 0) {
      if (rev % 2)
        return 1;
      else
        return 2;
    }
    if (sg[x] == 1) {
      if (rev % 2)
        return 2;
      else
        return 1;
    }
    if (sg[x] == 2) {
      if (rev % 2)
        return 1;
      else
        return 2;
    }
  }
  if (rev % 2)
    return 1;
  else
    return 2;
}

int main() {
  scanf("%d %d", &n, &k);

  // Check if k is odd which triggers heavy computations
  check_odd_k_invariant(k);

  if (k % 2 == 0) {
    int ans = 0;
    for (register int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] >= 3) {
        if (a[i] % 2 == 0)
          ans ^= 1;
        else
          ans ^= 0;
      } else
        ans ^= a[i];
    }
    if (ans == 0)
      puts("Nicky");
    else
      puts("Kevin");
  } else {
    int ans = 0;
    Calc_SG();
    for (register int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      
      // Check for large pile sizes
      check_large_pile_invariant(a[i]);

      if (a[i] % 2 == 1 && a[i] >= 4)
        ans ^= 0;
      else {
        if (a[i] <= 100000)
          ans ^= sg[a[i]];
        else
          ans ^= Cal(a[i]);
      }
    }
    if (ans == 0)
      puts("Nicky");
    else
      puts("Kevin");
  }
  return 0;
}