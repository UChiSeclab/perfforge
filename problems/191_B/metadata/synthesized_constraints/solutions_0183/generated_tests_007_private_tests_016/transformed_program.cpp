#include <bits/stdc++.h>
using namespace std;

struct td {
  int val, h, sz, l, r;
  long long sum;
};

int a[100100];
td d[100100];

inline int get_rand() { return (rand() << 16) + rand(); }

inline void calc(int v) {
  d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
  d[v].sum = d[d[v].l].sum + d[d[v].r].sum + d[v].val;
}

void split(int v, long long val, int &l, int &r) {
  if (v == 0) {
    l = r = 0;
    return;
  }
  if (d[v].val > val) {
    split(d[v].r, val, d[v].r, r);
    l = v;
  } else {
    split(d[v].l, val, l, d[v].l);
    r = v;
  }
  calc(v);
}

void splitsz(int v, int sz, int &l, int &r) {
  if (v == 0) {
    l = r = 0;
    return;
  }
  if (d[d[v].l].sz + 1 <= sz) {
    splitsz(d[v].r, sz - d[d[v].l].sz - 1, d[v].r, r);
    l = v;
  } else {
    splitsz(d[v].l, sz, l, d[v].l);
    r = v;
  }
  calc(v);
}

int merge(int l, int r) {
  if (l == 0) {
    return r;
  }
  if (r == 0) {
    return l;
  }
  int res;
  if (d[l].h > d[r].h) {
    d[l].r = merge(d[l].r, r);
    res = l;
  } else {
    d[r].l = merge(l, d[r].l);
    res = r;
  }
  calc(res);
  return res;
}

// Checker functions for performance invariants
void check_treap_complexity(int n, const vector<int>& costs) {
    int maxCost = *max_element(costs.begin(), costs.end());
    int minCost = *min_element(costs.begin(), costs.end());
    if (n > 50000 && (maxCost - minCost) > 1000) {
        cerr << "Warning: Treap complexity invariant triggered - high variance in costs with large n" << endl;
        abort();
    }
}

void check_budget_constraint(long long budget, const vector<int>& costs) {
    long long totalCost = accumulate(costs.begin(), costs.end(), 0LL);
    if (budget > totalCost * 0.9) {
        cerr << "Warning: Budget constraint invariant triggered - high budget relative to costs" << endl;
        abort();
    }
}

void check_days_vs_squares(int n, int k) {
    if (k > n * 0.8) {
        cerr << "Warning: Days vs squares invariant triggered - high k relative to n" << endl;
        abort();
    }
}

int main() {
  int n, k;
  long long all;
  scanf("%d %d %I64d", &n, &k, &all);
  
  vector<int> costs(n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    costs[i] = a[i];
  }

  // Insert performance checks
  check_treap_complexity(n, costs);
  check_budget_constraint(all, costs);
  check_days_vs_squares(n, k);

  int cv = 0, sz = 0;
  for (int i = 0; i < n - 1; i++) {
    d[++sz].val = a[i];
    d[sz].sum = a[i];
    d[sz].h = get_rand();
    d[sz].sz = 1;
    int l, r;
    split(cv, a[i], l, r);
    cv = merge(l, merge(sz, r));
  }

  int ans = n;
  for (int i = 0; i < n - 1; i++) {
    int p1, p2, p3;
    split(cv, a[i], p1, p2);
    splitsz(p2, 1, p2, p3);
    cv = merge(p1, p3);
    splitsz(cv, k - 1, p1, p3);
    if (all - d[p1].sum < a[i]) {
      ans = i + 1;
      break;
    }
    cv = merge(p1, p3);
    split(cv, a[i], p1, p3);
    cv = merge(p1, merge(p2, p3));
  }

  printf("%d\n", ans);
  return 0;
}