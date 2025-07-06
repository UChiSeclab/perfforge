#include <bits/stdc++.h>
using namespace std;

typedef struct d3point {
  long double x;
  long double y;
  long double z;
  d3point(int arg1, int arg2, int arg3) {
    x = arg1;
    y = arg2;
    z = arg3;
  }
} d3point;

const double eps = 1e-15;
const int maxN = 1 * 10000 + 10, mod = (int)1e9 + 7;
long long chooseM(int, int);
void primeM(int);
long long powerM(int, int);
long double distanceM(d3point, d3point);
int gcdM(int, int);
int n, m;
vector<int> v[maxN];
bool mark[maxN];
bool color[maxN];
int cot[2];

void dfsm(int i, bool c) {
  mark[i] = 1;
  color[i] = c;
  ++cot[c];
  for (int j = 0; j < v[i].size(); ++j)
    if (!mark[v[i][j]]) dfsm(v[i][j], 1 - c);
}

void check_graph_construction_invariant(int n, int m) {
    if (n < 10 || m < 10) {
        cerr << "Warning: Performance bottleneck condition triggered - graph construction and DFS traversal!" << endl;
        abort();
    }
}

void check_grid_loop_invariant(int n, int m) {
    if ((n < 10 && m > 900) || (m < 10 && n > 900)) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive grid loop overhead!" << endl;
        abort();
    }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;

  // Performance checks
  check_graph_construction_invariant(n, m);
  check_grid_loop_invariant(n, m);

  int p = 0;
  if (m < 10 || n < 10) {
    for (int i = 0; i < n - 2; ++i)
      for (int j = 0; j < m - 1; ++j)
        v[i * m + j].push_back((i + 2) * m + j + 1),
            v[(i + 2) * m + j + 1].push_back(i * m + j);
    for (int i = 0; i < n - 1; ++i)
      for (int j = 0; j < m - 2; ++j)
        v[i * m + j].push_back((i + 1) * m + j + 2),
            v[(i + 1) * m + j + 2].push_back(i * m + j);
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < m - 2; ++j)
        v[i * m + j].push_back((i - 1) * m + j + 2),
            v[(i - 1) * m + j + 2].push_back(i * m + j);
    for (int i = 2; i < n; ++i)
      for (int j = 0; j < m - 1; ++j)
        v[i * m + j].push_back((i - 2) * m + j + 1),
            v[(i - 2) * m + j + 1].push_back(i * m + j);
    for (int i = 0; i < m * n; ++i) {
      if (!mark[i]) {
        cot[0] = 0;
        cot[1] = 0;
        dfsm(i, 0);
        p += max(cot[0], cot[1]);
      }
    }
  } else
    p = m * n / 2 + (m * n) % 2;
  cout << p;
  return 0;
}

long long chooseM(int arg1, int arg2) {
  long long tmp1 = 1, tmp2 = 1;
  if (arg2 > arg1 / 2) arg2 = arg1 - arg2;
  for (int i = 1; i <= arg2; ++i) {
    tmp1 = (tmp1 * i) % mod;
    tmp2 = (tmp2 * (arg1 - i + 1)) % mod;
  }
  return tmp2 * powerM(tmp1, mod - 2);
}

void primeM(int last) {
  bool isNotPrime[maxN] = {};
  int minPrime[maxN];
  vector<int> prime;
  for (int i = 2; i < last; ++i)
    if (!isNotPrime[i]) {
      prime.push_back(i);
      for (int j = 2; j < last / i + 1; ++j) {
        isNotPrime[j * i] = 1;
        minPrime[i * j] = i;
      }
    }
  prime.push_back(last);
}

long double distanceM(d3point d1, d3point d2) {
  return sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2) + pow(d1.z - d2.z, 2));
}

long long powerM(int arg1, int arg2) {
  if (arg2 == 0) return 1;
  long long pow = powerM(arg1, arg2 / 2);
  pow = (pow * pow) % mod;
  if (arg2 % 2 == 1) pow = (pow * arg1) % mod;
  return pow;
}

int gcdM(int arg1, int arg2) {
  if (arg1 < arg2) swap(arg1, arg2);
  while (0 < arg2) {
    arg1 -= (arg1 / arg2) * arg2;
    swap(arg1, arg2);
  }
  return arg1;
}