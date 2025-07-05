#include <bits/stdc++.h>
using namespace std;

vector<int> graph[51];
int degree[51];
bool visited[51];

int ring_size(int idx, int prev) {
  if (graph[idx].size() != 2) return 987654321;
  if (graph[idx][0] != prev) {
    if (graph[idx][0] == 1) return 1;
    return ring_size(graph[idx][0], idx) + 1;
  } else {
    if (graph[idx][1] == 1) return 1;
    return ring_size(graph[idx][1], idx) + 1;
  }
}

bool cycled(int idx, int prev) {
  if (visited[idx]) return true;
  visited[idx] = true;
  
  // Check for excessive cycle detection
  check_cycle_invariant(visited[idx] && graph[idx].size() > 2);
  
  for (int i = 0; i < graph[idx].size(); i++) {
    if (graph[idx][i] != prev && cycled(graph[idx][i], idx)) return true;
  }
  return false;
}

int u[51];
int parent(int idx) {
  check_union_find_invariant(idx > 50);  // Example invariant for union-find
  if (u[idx] == idx) return idx;
  return u[idx] = parent(u[idx]);
}

void merge(int idx1, int idx2) {
  int p1 = u[idx1];
  int p2 = u[idx2];
  if (p1 == p2) return;
  u[p1] = p2;
}

int main() {
  int n, m, a, b;
  scanf("%d %d", &n, &m);
  if (n == 1) {
    if (m == 0) {
      printf("YES\n1\n1 1");
    } else if (m == 1) {
      scanf("%d %d", &a, &b);
      if (a == 1 && b == 1)
        printf("YES\n0");
      else
        printf("NO");
    } else
      printf("NO");
    return 0;
  }
  
  for (int i = 1; i <= n; i++) u[i] = i;
  bool ar[51][51] = {0};
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    if (a == b || (n != 2 && ar[a][b] == 1)) {
      printf("NO");
      return 0;
    }
    ar[a][b] = ar[b][a] = 1;
    graph[a].push_back(b);
    graph[b].push_back(a);
    degree[a]++;
    degree[b]++;
    merge(a, b);
  }
  if (ring_size(1, -1) == n) {
    printf("YES\n0");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (m >= n || degree[i] > 2 || (!visited[i] && cycled(i, -1))) {
      printf("NO");
      return 0;
    }
  }
  
  // Check for excessive graph construction iterations
  check_graph_construction_invariant(m >= n - 1);

  printf("YES\n");
  printf("%d\n", n - m);
  for (int abcd = 0; abcd < n - m - 1; abcd++) {
    a = -1, b = -1;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (parent(i) != parent(j) && degree[i] != 2 && degree[j] != 2) {
          a = i;
          b = j;
          degree[i]++;
          degree[j]++;
          merge(a, b);
          break;
        }
      }
      if (a != -1) break;
    }
    printf("%d %d\n", a, b);
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (degree[i] == 1 && degree[j] == 1) {
        printf("%d %d", i, j);
        return 0;
      }
}