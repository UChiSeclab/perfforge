#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const double PI = 3.14159265358979323846;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int n;
const int dir[3][2][2] = {
    {{0, -1}, {1, 0}}, {{-1, 0}, {0, -1}}, {{0, 1}, {-1, 0}}};

// Checker functions for performance bottleneck conditions
void check_permutation_invariant(int permutationCount, int n) {
    if (permutationCount > 120 && n >= 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to excessive permutations!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int n) {
    if (n >= 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to large matrix operations in nested loops!" << endl;
        abort();
    }
}

void check_transformation_comparison_invariant(int transformationAttempts, int n) {
    if (transformationAttempts > 1000 && n >= 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to frequent transformations and comparisons!" << endl;
        abort();
    }
}

void vertical(vector<string>& src) {
  for (int i = 0; i < int(n); ++i) reverse(src[i].begin(), src[i].end());
}

void horizontal(vector<string>& src) {
  for (int i = 0; i < int(n / 2); ++i) swap(src[i], src[n - i - 1]);
}

pair<int, int> at(pair<int, int> cur) {
  cur.first *= 2, cur.second *= 2;
  cur.first -= n - 1, cur.second -= n - 1;
  return cur;
}

pair<int, int> rat(pair<int, int> cur) {
  cur.first += n - 1, cur.second += n - 1;
  cur.first /= 2, cur.second /= 2;
  return cur;
}

void ope(vector<string>& src, int t) {
  if (t == 3) {
    vertical(src);
    return;
  }
  if (t == 4) {
    horizontal(src);
    return;
  }
  vector<string> nsrc(src);
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(n); ++j) {
      pair<int, int> cur = at({i, j});
      pair<int, int> nxt;
      nxt.first = cur.first * dir[t][0][0] + cur.second * dir[t][0][1];
      nxt.second = cur.first * dir[t][1][0] + cur.second * dir[t][1][1];
      nxt = rat(nxt);
      nsrc[nxt.first][nxt.second] = src[i][j];
    }
  src = nsrc;
}

void solve() {
  cin >> n;
  vector<string> src, des;
  for (int i = 0; i < int(n); ++i) {
    string s;
    cin >> s;
    src.push_back(s);
  }
  for (int i = 0; i < int(n); ++i) {
    string s;
    cin >> s;
    des.push_back(s);
  }
  vector<int> num = {0, 1, 2, 3, 4};

  int permutationCount = 0;
  int transformationAttempts = 0;

  auto nextPermutation = [&](int l, int r) {
    int rg = r - 1;
    while (rg > l && num[rg - 1] > num[rg]) --rg;
    if (l == rg) return false;
    int lf = rg - 1;
    while (rg + 1 < r && num[rg + 1] > num[lf]) ++rg;
    swap(num[lf], num[rg]);
    reverse(num.begin() + lf + 1, num.begin() + r);
    return true;
  };

  auto cmp = [&](const vector<string>& s, const vector<string>& d) -> bool {
    transformationAttempts++;
    for (int i = 0; i < int(n); ++i)
      if (s[i] != d[i]) return false;
    return true;
  };

  // Check for large matrix operations
  check_nested_loop_invariant(n);

  do {
    vector<string> nsrc(src);
    permutationCount++;
    check_permutation_invariant(permutationCount, n); // Checks for excessive permutations

    for (int i = 0; i < int(5); ++i) {
      ope(nsrc, num[i]);
      if (cmp(nsrc, des)) {
        cout << "Yes" << endl;
        return;
      }
    }
  } while (nextPermutation(0, 5));

  // Check for frequent transformations and comparisons
  check_transformation_comparison_invariant(transformationAttempts, n);

  cout << "No" << endl;
}

int main() {
  solve();
  return 0;
}