#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

vector<int> divs(int x) {
  vector<int> res;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      res.push_back(i);
      if (x / i != i) res.push_back(x / i);
    }
  }
  reverse(res.begin(), res.end());
  return res;
}

// Checkers for performance-characterizing invariants
void check_large_divisors(int divisorCount) {
    if (divisorCount > 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of divisors!" << endl;
        abort();
    }
}

void check_large_dynamic_array(int arraySize) {
    if (arraySize > 500000) {
        cerr << "Warning: Performance bottleneck condition triggered - large dynamic array size!" << endl;
        abort();
    }
}

void check_accumulation_iterations(int iterations) {
    if (iterations > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive accumulation iterations!" << endl;
        abort();
    }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> d(*max_element(a.begin(), a.end()) + 1, 0);
  
  // Check for large dynamic array
  check_large_dynamic_array(d.size());
  
  d[0] = 1;
  for (int i = 0; i < n; i++) {
    vector<int> divisors = divs(a[i]);
    
    // Check for large number of divisors
    check_large_divisors(divisors.size());
    
    for (int j : divisors) {
      d[j] = (d[j] % MOD + d[j - 1] % MOD) % MOD;
    }
  }
  
  int ans = 0;
  int iterationCount = 0;
  for (int i = 1; i < d.size(); i++) {
    ans = (ans % MOD + d[i] % MOD) % MOD;
    iterationCount++;
  }
  
  // Check for excessive accumulation iterations
  check_accumulation_iterations(iterationCount);
  
  cout << ans;
}