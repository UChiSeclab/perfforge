#include <bits/stdc++.h>
using namespace std;
bool cycle = false;
void DFS(int** matrix, int n, int sv, bool* visited) {
  visited[sv] = true;
  for (int i = 0; i < n; i++) {
    if (i == sv) continue;
    if (matrix[sv][i] == 1) {
      if (visited[i]) {
        continue;
      }
      DFS(matrix, n, i, visited);
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  int** matrix = new int*[n];
  int x, y;
  for (int i = 0; i < n; i++) {
    matrix[i] = new int[n];
    for (int j = 0; j < n; j++) {
      matrix[i][j] = 0;
    }
  }
  bool visited[n];
  for (int i = 0; i < n; i++) visited[i] = false;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    matrix[x - 1][y - 1] = 1;
    matrix[y - 1][x - 1] = 1;
  }
  if (m != n - 1) {
    cout << "no";
  } else {
    DFS(matrix, n, 0, visited);
    if (cycle == false) {
      for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
          cout << "no";
          return 0;
        }
      }
      cout << "yes";
    }
  }
  for (int i = 0; i < n; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
  return 0;
}
