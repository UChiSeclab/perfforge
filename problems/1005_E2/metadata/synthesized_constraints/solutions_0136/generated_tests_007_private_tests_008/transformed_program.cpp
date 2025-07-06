#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[200003];

// Checkers for performance bottlenecks
void check_tree_operations_invariant(int operationCount) {
    if (operationCount > 10000) { // Threshold to identify excessive BIT operations
        cerr << "Warning: Performance bottleneck condition triggered - excessive BIT operations!" << endl;
        abort();
    }
}

void check_subarray_invariant(int equivalentMedianCount) {
    if (equivalentMedianCount > n / 2) { // Arbitrary threshold to identify high density of median-equivalent elements
        cerr << "Warning: Performance bottleneck condition triggered - excessive subarray evaluations around median!" << endl;
        abort();
    }
}

void check_input_pattern_invariant(const vector<int>& arr) {
    int patternCount = 0;
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] != arr[i - 1]) {
            patternCount++;
        }
    }
    if (patternCount > n / 2) { // Threshold indicating frequent changes in input pattern
        cerr << "Warning: Performance bottleneck condition triggered - frequent changes in input pattern!" << endl;
        abort();
    }
}

void read() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  // Check frequent changes in input pattern
  check_input_pattern_invariant(vector<int>(arr + 1, arr + n + 1));
}

class bit {
 public:
  unordered_map<int, unordered_map<int, int> > tr;
  int operationCount = 0;
  
  void add(int a, int b) {
    a += n + 2;
    b += n + 2;
    for (int i = a; i < 3 * 200003; i += i & (-i))
      for (int j = b; j < 3 * 200003; j += j & (-j)) {
          tr[i][j]++;
          operationCount++;
      }
    // Check excessive BIT operations
    check_tree_operations_invariant(operationCount);
  }
  
  int get_prefix(int a, int b) {
    a += n + 2;
    b += n + 2;
    int ans = 0;
    for (int i = a; i > 0; i -= i & (-i))
      if (tr.count(i))
        for (int j = b; j > 0; j -= j & (-j))
          if (tr[i].count(j)) {
              ans += tr[i][j];
              operationCount++;
          }
    // Check excessive BIT operations
    check_tree_operations_invariant(operationCount);
    return ans;
  }
  
  int get(int a, int b) {
    return get_prefix(a, 3 * 200003) - get_prefix(a, b - 1);
  }
};

bit even, odd;

void solve() {
  int equivalentMedianCount = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] < m)
      arr[i] = 0;
    else if (arr[i] == m) {
      arr[i] = 1;
      equivalentMedianCount++;
    }
    else
      arr[i] = 2;
  }
  // Check high density of median-equivalent elements
  check_subarray_invariant(equivalentMedianCount);
  
  int a = 0, b = 0, c = 0;
  even.add(0, 0);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 0)
      a++;
    else if (arr[i] == 1)
      b++;
    else
      c++;
    if (i % 2 == 0) {
      int first = a + b - c;
      int second = a - b - c + 1;
      ans += even.get(first, second);
      first--;
      ans += odd.get(first, second);
      even.add(a + b - c, a - b - c);
    } else {
      int first = a + b - c;
      int second = a - b - c + 1;
      ans += odd.get(first, second);
      first--;
      ans += even.get(first, second);
      odd.add(a + b - c, a - b - c);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  read();
  solve();
}