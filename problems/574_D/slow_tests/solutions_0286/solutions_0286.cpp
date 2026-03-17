#include <bits/stdc++.h>
using namespace std;
long long int tree[100001 * 10];
long long int lazy[100001 * 10];
long long int arr[100001];
void build_tree(int node, int a, int b) {
  if (a > b) return;
  if (a == b) {
    tree[node] = arr[a] + a;
    return;
  }
  build_tree(node * 2, a, (a + b) / 2);
  build_tree(node * 2 + 1, 1 + (a + b) / 2, b);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
void update_tree(int node, int a, int b, int i, int j, int value) {
  if (lazy[node] != 0) {
    tree[node] += lazy[node];
    if (a != b) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (a > b || a > j || b < i) return;
  if (a >= i && b <= j) {
    tree[node] += value;
    if (a != b) {
      lazy[node * 2] += value;
      lazy[node * 2 + 1] += value;
    }
    return;
  }
  update_tree(node * 2, a, (a + b) / 2, i, j, value);
  update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value);
  tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int query_tree(int node, int a, int b, int i, int j) {
  if (a > b || a > j || b < i) return 1000000007;
  if (lazy[node] != 0) {
    tree[node] += lazy[node];
    if (a != b) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if (a >= i && b <= j) return tree[node];
  int q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
  int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);
  int res = min(q1, q2);
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
  arr[0] = arr[n + 1] = 0;
  build_tree(1, 0, n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    update_tree(1, 0, n + 1, 0, i - 1, 1);
    update_tree(1, 0, n + 1, i, n + 1, -1);
    ans = max(ans, query_tree(1, 0, n + 1, 0, n + 1));
  }
  printf("%d\n", ans);
  return 0;
}
