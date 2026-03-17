#include <bits/stdc++.h>
int n, m;
typedef struct {
  int a, b;
} punct;
punct r[2000], l[2000];
int rst[2000], rdr[2000];
bool cmp1(punct a, punct b) {
  if (a.a < b.a) return 1;
  if (a.a > b.a) return 0;
  if (a.b < b.b) return 1;
  return 0;
}
bool cmp(punct a, punct b) {
  if (a.a > b.a) return 1;
  if (a.a < b.a) return 0;
  if (a.b > b.b) return 1;
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  int i, j;
  for (i = 0; i < n; i++) {
    scanf("%d%d", &r[i].a, &r[i].b);
  }
  for (j = 0; j < m; j++) {
    scanf("%d%d", &l[j].a, &l[j].b);
  }
  std::sort(r, r + n, cmp1);
  std::sort(l, l + m, cmp);
  j = 1;
  for (i = 1; i < n; i++) {
    if (r[i].b < r[j - 1].b) r[j++] = r[i];
  }
  n = j;
  j = 1;
  for (i = 1; i < m; i++) {
    if (l[i].b > l[j - 1].b) l[j++] = l[i];
  }
  m = j;
  punct aux;
  i = 0;
  j = m - 1;
  while (i < j) {
    aux = l[i];
    l[i] = l[j];
    l[j] = aux;
    i++;
    j--;
  }
  int st, dr;
  std::multiset<int> mx;
  mx.insert(0);
  std::priority_queue<std::pair<int, int> > scot;
  for (i = 0; i < n; i++) {
    st = 0;
    while (st < m && l[st].a < r[i].a) st++;
    if (st == m || (st < m && l[st].b < r[i].b)) {
      for (j = i; j < n - 1; j++) {
        r[j] = r[j + 1];
      }
      i--;
      n--;
      continue;
    }
    dr = st;
    while (dr < m && l[dr].b >= r[i].b) dr++;
    rst[i] = st;
    rdr[i] = dr - 1;
    mx.insert(l[st].b - r[i].b + 1);
    scot.push(std::make_pair(-(l[st].a - r[i].a + 1), i));
  }
  if (n == 0) {
    printf("0\n");
    return 0;
  }
  int rr = *mx.rbegin();
  std::pair<int, int> x;
  for (i = 1; !scot.empty(); i++) {
    while (!scot.empty() && -i == scot.top().first) {
      x = scot.top();
      scot.pop();
      x.first = -x.first;
      std::multiset<int>::iterator it;
      it = mx.find(l[rst[x.second]].b - r[x.second].b + 1);
      mx.erase(it);
      rst[x.second]++;
      if (rst[x.second] <= rdr[x.second]) {
        scot.push(std::make_pair(-(l[rst[x.second]].a - r[x.second].a + 1),
                                 x.second));
        mx.insert(l[rst[x.second]].b - r[x.second].b + 1);
      }
    }
    rr = std::min(rr, i + (*mx.rbegin()));
  }
  printf("%d", rr);
  return 0;
}
