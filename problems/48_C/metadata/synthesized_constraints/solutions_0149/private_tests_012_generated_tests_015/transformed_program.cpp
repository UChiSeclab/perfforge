#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const int N = 5e3 + 10;
vector<double> vd;
int flag = 0;

void check_loop_invariant(int iterations, int threshold) {
    if (iterations > threshold) {
        cerr << "Warning: loop_invariant triggered - excessive iterations in check function!" << endl;
        abort();
    }
}

void check_binary_search_invariant(int iteration_count, int max_iterations) {
    if (iteration_count > max_iterations) {
        cerr << "Warning: binary_search_invariant triggered - slow convergence detected!" << endl;
        abort();
    }
}

void check_sequence_complexity_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: sequence_complexity_invariant triggered - ambiguous sequence detected!" << endl;
        abort();
    }
}

vector<int> check(double x, int sz) {
  vector<int> v;
  int cur = 0;
  double tot = x;
  int iterations = 0;  // Track the number of loop iterations
  while (v.size() < sz) {
    int o = tot / 10;
    cur += o;
    v.push_back(cur);
    tot -= o * 10;
    if (v.size() == sz) break;
    tot += x;
    iterations++;
  }
  check_loop_invariant(iterations, 1000);  // Check for excessive iterations
  if (flag) vd.push_back(tot);
  return v;
}

double solve(vector<int>& v1, int o = 0) {
  double l = 10 + 1e-10;
  double r = INF;
  int cnt = 200;
  int initial_cnt = cnt;  // Save initial count for comparison
  while (cnt--) {
    double mid = (l + r) / 2;
    auto v2 = check(mid, v1.size());
    for (int i = 0; i < v1.size(); i++) {
      if (v1[i] < v2[i]) {
        r = mid;
        break;
      }
      if (v1[i] > v2[i]) {
        l = mid;
        break;
      }
    }
    if (v1 != v2) continue;
    if (o == 0)
      l = mid;
    else
      r = mid;
  }
  check_binary_search_invariant(initial_cnt - cnt, 50);  // Check slow convergence
  return l;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto& x : v) cin >> x;

  bool ambiguous_sequence = (n > 1 && v[0] == 1 && v[1] == 2);  // Example condition
  check_sequence_complexity_invariant(ambiguous_sequence);  // Check for ambiguous sequence

  double key1 = solve(v, 0);
  double key2 = solve(v, 1);
  flag = 1;
  if (key1 > key2) swap(key1, key2);
  int ans1 = check(key1, n + 1).back();
  int ans2 = check(key2, n + 1).back();
  if (abs(vd[0] - 10) <= 1e-8) ans1++;
  if (ans1 == ans2)
    puts("unique"), printf("%d\n", ans1), exit(0);
  else
    puts("not unique");
  return 0;
}