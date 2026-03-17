#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> field;
vector<vector<int>> points;
int is_wall(int i, int j) { return field[i][j] == '*' ? 1 : 0; }
int forward(int i, int j) {
  if (field[i][j] == '*') return 1;
  if (points[i][j] == -1) return 0;
  points[i][j] = -1;
  int pts = forward(i - 1, j) + forward(i + 1, j) + forward(i, j - 1) +
            forward(i, j + 1);
  return pts;
}
void back(int i, int j, int pts) {
  if (field[i][j] == '*') return;
  if (points[i][j] > 0) return;
  points[i][j] = pts;
  back(i - 1, j, pts);
  back(i + 1, j, pts);
  back(i, j - 1, pts);
  back(i, j + 1, pts);
}
int calc_cell_points(int i, int j) {
  if (points[i][j] > 0) {
    return points[i][j];
  }
  int pts = forward(i, j);
  back(i, j, pts);
  return pts;
}
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  field = vector<vector<char>>(n, vector<char>(m));
  points = vector<vector<int>>(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> field[i][j];
    }
  }
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    cout << calc_cell_points(x - 1, y - 1) << endl;
  }
  return 0;
}
