#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n, m;
int st, en;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<string> v;
int cell[1005][1005], visited[1005][1005];

// Checker functions
void check_high_connectivity_invariant(int contiguousEmptyCellsThreshold, int contiguousEmptyCells) {
    if (contiguousEmptyCells > contiguousEmptyCellsThreshold) {
        cerr << "Warning: High connectivity of empty cells detected!" << endl;
        abort();
    }
}

void check_repeated_exploration_invariant(int maxStartingPoints, int startingPointsExplored, int neighborsVisited) {
    if ((startingPointsExplored > maxStartingPoints) && (neighborsVisited > startingPointsExplored * 2)) {
        cerr << "Warning: Repeated exploration from multiple starting points detected!" << endl;
        abort();
    }
}

void check_bfs_overhead_invariant(int maxQSize, int currentQSize) {
    if (currentQSize > maxQSize) {
        cerr << "Warning: BFS overhead in complex grids detected!" << endl;
        abort();
    }
}

// Validity check for cell coordinates
bool valid(int xx, int yy) {
  if (xx >= 0 && yy >= 0 && xx < n && yy < m && v[xx][yy] != '*') return 1;
  return 0;
}

// BFS function to explore the grid
int bfs() {
  int wx, wy, ans = 0;
  vector<pair<int, int> > vaa;
  queue<pair<int, int> > Q;
  Q.push(make_pair(st, en));
  visited[st][en] = 1;

  // BFS overhead checker
  check_bfs_overhead_invariant(10000, Q.size());

  while (!Q.empty()) {
    st = Q.front().first;
    en = Q.front().second;
    vaa.push_back(make_pair(st, en));
    Q.pop();

    for (int i = 0; i < 4; i++) {
      wx = st + dx[i];
      wy = en + dy[i];
      if (!valid(wx, wy)) ans++;
      if (valid(wx, wy) && !visited[wx][wy]) {
        visited[wx][wy] = 1;
        Q.push(pair<int, int>(wx, wy));

        // Check BFS overhead again as the queue grows
        check_bfs_overhead_invariant(10000, Q.size());
      }
    }
  }

  // Cache results to reduce repeated exploration
  for (int i = 0; i < vaa.size(); i++) cell[vaa[i].first][vaa[i].second] = ans;
  return ans;
}

int main() {
  int k;
  string s;
  cin >> n >> m >> k;
  memset(cell, -1, sizeof(cell));
  memset(visited, 0, sizeof(visited));

  for (int i = 0; i < n; i++) {
    cin >> s;
    v.push_back(s);
  }

  // Check high connectivity invariant at the start
  int contiguousEmptyCells = 0;
  for (const auto& row : v) {
      contiguousEmptyCells += count(row.begin(), row.end(), '.');
  }
  check_high_connectivity_invariant(500, contiguousEmptyCells);

  while (k--) {
    cin >> st >> en;
    st--;
    en--;

    if (cell[st][en] != -1) {
      cout << cell[st][en] << '\n';
    } else {
      cout << bfs() << '\n';
    }
  }

  return 0;
}