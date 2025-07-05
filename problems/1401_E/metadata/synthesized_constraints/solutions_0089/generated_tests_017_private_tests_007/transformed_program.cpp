#include <bits/stdc++.h>
using namespace std;

int n, m;
long long ans = 1;

struct par {
  int h, l;
  par(int x = 0, int y = 0) : h(x), l(y) {}
};

vector<par> l, r, u, d;

struct SPLAY {
  struct node {
    int val, tot, size;
    node *zuo, *you, *fa;
    node(int x, node *Fa) : val(x), tot(1), size(1), zuo(NULL), you(NULL), fa(Fa) {}
    node *find(int x) {
      if (zuo && x < val) return zuo->find(x);
      if (you && x > val) return you->find(x);
      return this;
    }
    void check() {
      size = tot;
      if (zuo) size += zuo->size;
      if (you) size += you->size;
    }
  } *root;
  
  void rotate(node *x) {
    node *fa = x->fa, *gfa = fa->fa;
    if (fa->zuo == x) {
      fa->zuo = x->you;
      if (x->you) x->you->fa = fa;
      x->you = fa;
    } else {
      fa->you = x->zuo;
      if (x->zuo) x->zuo->fa = fa;
      x->zuo = fa;
    }
    fa->fa = x;
    x->fa = gfa;
    if (gfa && gfa->zuo == fa) gfa->zuo = x;
    if (gfa && gfa->you == fa) gfa->you = x;
    fa->check();
    x->check();
  }
  
  void splay(node *x, node *to = NULL) {
    while (x->fa != to) {
      if (x->fa->fa != to && (x->fa->zuo == x) == (x->fa->fa->zuo == x->fa))
        rotate(x->fa), rotate(x);
      else
        rotate(x);
    }
    if (!to) root = x;
  }
  
  void add(int x) {
    if (root == NULL) {
      root = new node(x, NULL);
      return;
    }
    node *p = root->find(x);
    if (x == p->val)
      p->tot++, p->size++, splay(p);
    else if (x < p->val)
      p->zuo = new node(x, p), splay(p->zuo);
    else
      p->you = new node(x, p), splay(p->you);
  }
  
  int findrk(int x) {
    node *p = root->find(x);
    splay(p);
    if (p->val < x) {
      if (!p->you) return p->size + 1;
      p = p->you;
      while (p->zuo) p = p->zuo;
      splay(p);
    }
    return (p->zuo ? p->zuo->size : 0) + 1;
  }
} U, D;

// Function to check for full range iteration bottleneck
void check_full_range_iteration(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to full range iteration!" << endl;
        abort();
    }
}

// Function to check for sparse segment usage bottleneck
void check_sparse_segment_usage(int n, int m) {
    if ((n > 0 && n < 10) || (m > 0 && m < 10)) {
        cerr << "Warning: Potential performance bottleneck due to sparse segment usage!" << endl;
        abort();
    }
}

// Function to check for unnecessary splay tree operations bottleneck
void check_splay_tree_operations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck due to unnecessary splay tree operations!" << endl;
        abort();
    }
}

bool cmp1(par x, par y) { return x.l < y.l; };
bool cmp2(par x, par y) { return x.l > y.l; };

int main() {
  scanf("%d %d", &n, &m);

  // Check for sparse segment usage
  check_sparse_segment_usage(n, m);

  l.clear();
  r.clear();
  for (int i = 1; i <= n; i++) {
    int y, lx, rx;
    scanf("%d %d %d", &y, &lx, &rx);
    if (lx == 0)
      l.push_back(par(y, rx));
    else
      r.push_back(par(y, lx));
  }
  
  sort(l.begin(), l.end(), cmp1);
  sort(r.begin(), r.end(), cmp2);
  
  d.clear();
  u.clear();
  for (int i = 1; i <= m; i++) {
    int x, ly, ry;
    scanf("%d %d %d", &x, &ly, &ry);
    if (ly == 0) {
      d.push_back(par(ry, x));
      if (ry == 1000000) ans++;
    } else
      u.push_back(par(1000000 - ly, x));
  }
  
  U.root = NULL;
  D.root = NULL;
  sort(d.begin(), d.end(), cmp1);
  sort(u.begin(), u.end(), cmp1);
  
  int now1 = 0, now2 = 0, now3 = 0;

  // Check for full range iteration bottleneck
  check_full_range_iteration((n > 0 || m > 0) && (l.size() > 0 || r.size() > 0 || u.size() > 0 || d.size() > 0));

  for (int i = 0; i <= 1000000; i++) {
    while (now1 < d.size() && d[now1].l == i) D.add(d[now1].h), now1++;
    while (now2 < u.size() && u[now2].l == i) U.add(u[now2].h), now2++;
    if (i == 1000000) now1++;
    while (now3 < l.size() && l[now3].l == i) {
      int st = ans;
      if (D.root)
        ans += now1 - (D.findrk(l[now3].h) - 1);
      else
        ans += now1;
      if (U.root)
        ans += now2 - (U.findrk(1000000 - l[now3].h) - 1);
      else
        ans += now2;
      now3++;
    }
  }
  
  D.root = NULL;
  U.root = NULL;
  reverse(d.begin(), d.end());
  reverse(u.begin(), u.end());
  
  now1 = now2 = now3 = 0;

  for (int i = 1000000; i >= 0; i--) {
    while (now1 < d.size() && d[now1].l == i) D.add(d[now1].h), now1++;
    while (now2 < u.size() && u[now2].l == i) U.add(u[now2].h), now2++;
    if (i == 0) now1++;
    while (now3 < r.size() && r[now3].l == i) {
      if (D.root)
        ans += now1 - (D.findrk(r[now3].h) - 1);
      else
        ans += now1;
      if (U.root)
        ans += now2 - (U.findrk(1000000 - r[now3].h) - 1);
      else
        ans += now2;
      now3++;
    }
  }

  // Check for unnecessary splay tree operations bottleneck
  check_splay_tree_operations((U.root != NULL && D.root != NULL) && (l.size() >= 10 || r.size() >= 10));

  printf("%lld", ans);
}