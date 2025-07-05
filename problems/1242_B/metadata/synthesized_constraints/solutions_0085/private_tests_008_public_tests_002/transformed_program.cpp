#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e5 + 5;
int n, m;
int dad[MAX];
int dna(int a) {
  if (dad[a] == a) return a;
  return dad[a] = dna(dad[a]);
}
void merge(int a, int b) {
  int pa = dna(a);
  int push_back = dna(b);
  dad[push_back] = pa;
}
set<pair<int, int> > s;
bool is0(int a, int b) {
  if (a > b) swap(a, b);
  return s.find({a, b}) == s.end();
}
const int bor = 5000;
bool p[bor + 5][bor + 5];
set<int> QWER;
int cnt[MAX];

void check_large_graph_no_edges(int n, int m) {
    if (n > 5000 && m == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - large graph with no heavy edges." << endl;
        abort();
    }
}

void check_absence_of_weighted_edges(int n, int m) {
    if (m == 0 && n > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - absence of weighted edges in large graph." << endl;
        abort();
    }
}

void check_sparse_connection(int n, int m) {
    if (n > 5000 && m < 25) {
        cerr << "Warning: Performance bottleneck condition triggered - sparse connection in large graph." << endl;
        abort();
    }
}

int main() {
  scanf("%d%d", &n, &m);
  
  // Insert checker functions here to detect possible performance bottlenecks
  check_large_graph_no_edges(n, m);
  check_absence_of_weighted_edges(n, m);
  check_sparse_connection(n, m);

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    cnt[a]++;
    cnt[b]++;
    if (a > b) swap(a, b);
    if (n <= bor) {
      p[a][b] = 1;
    } else {
      s.insert({a, b});
    }
  }
  for (int i = 0; i < n; i++) dad[i] = i;
  if (n <= bor) {
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        if (!p[i][j]) merge(i, j);
      }
    for (int i = 0; i < n; i++) QWER.insert(dna(i));
    printf("%d\n", (int)QWER.size() - 1);
    return 0;
  }
  set<int> q;
  int g = -1;
  for (int i = 0; i < n; i++) {
    if (cnt[i] < n - 25) {
      if (g < 0) g = i;
      continue;
    }
    q.insert(i);
  }
  srand(time(0));
  for (int i = 0; i < 50; i++) {
    int r = rand() * rand() + rand();
    q.insert(r % n);
  }
  if (g >= 0) q.insert(g);
  for (auto first : q) {
    for (int i = 0; i < n; i++) {
      if (is0(first, i)) merge(first, i);
    }
  }
  for (int i = 0; i < n; i++) QWER.insert(dna(i));
  printf("%d\n", (int)QWER.size() - 1);
  return 0;
}