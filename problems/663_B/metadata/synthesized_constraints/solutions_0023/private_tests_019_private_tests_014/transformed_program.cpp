#include <bits/stdc++.h>
using namespace std;
const int N = 510000;
long long a[N], ten[N], ans[N];
struct node {
  long long x, y;
} b[N];
bool cmp(const node &a, const node &b) {
  return a.x < b.x || a.x == b.x && a.y < b.y;
}
char s[N];

// Checker functions
void check_nested_loop_invariant(int top, int up) {
    if (top > 7 || up > 3000) {
        cerr << "Warning: Performance bottleneck condition triggered in nested loops!" << endl;
        abort();
    }
}

void check_sort_invariant(int tp) {
    if (tp > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large sorting operation!" << endl;
        abort();
    }
}

void check_conditional_invariant(int tp, int up) {
    if ((tp > 5000) && (up > 300)) {
        cerr << "Warning: Performance bottleneck condition triggered in repeated conditionals!" << endl;
        abort();
    }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s + 1);
    long long n = 0;
    int len = 0;
    for (int i = 1; i <= strlen(s + 1); i++)
      if (s[i] >= '0' && s[i] <= '9') n = n * 10 + s[i] - '0', len++;
    int top = 0;
    for (int i = 1; i <= len; i++) {
      a[++top] = n % 10;
      n /= 10;
    }
    ten[0] = 1;
    for (int i = 1; i <= 20; i++) ten[i] = ten[i - 1] * 10;
    for (int i = 1; i <= top; i++) a[i] = a[i - 1] + ten[i - 1] * a[i];
    int tp = 0;
    for (int i = 1; i <= top; i++) {
      int up = 0;
      if (i == 1)
        up = 3000;
      else if (i == 2)
        up = 700;
      else
        up = 300;

      // Place check for nested loop permutations
      check_nested_loop_invariant(top, up);

      for (int j = 0; j <= up; j++) {
        if (a[i] + j * ten[i] < 1989) continue;
        b[++tp].x = a[i] + j * ten[i];
        b[tp].y = i;
      }
    }

    // Place check for sorting overhead before sorting
    check_sort_invariant(tp);

    sort(b + 1, b + 1 + tp, cmp);

    for (int i = 1; i <= top; i++) ans[i] = 0;
    for (int l = 1; l <= tp;) {
      int r = l;
      while (r < tp && b[r + 1].x == b[l].x) r++;

      // Place check for repeated conditionals
      check_conditional_invariant(tp, r - l);

      for (int i = l; i <= r; i++)
        if (ans[b[i].y] == 0) {
          ans[b[i].y] = b[i].x;
          break;
        }
      l = r + 1;
    }
    cout << ans[top];
    printf("\n");
  }
}