#include <bits/stdc++.h>
using namespace std;
using LLI = long long int;
int n;
int as[214514];
LLI ans;

// Checker functions
void check_repetitive_loop_condition(const vector<int>& as) {
    int threshold = 50; // Arbitrary threshold for small numbers
    int frequency_threshold = 6; // Arbitrary threshold for frequency of identical small numbers
    unordered_map<int, int> frequency;
    for (int a : as) {
        if (a <= threshold) {
            frequency[a]++;
        }
    }
    for (const auto& entry : frequency) {
        if (entry.second > frequency_threshold) {
            cerr << "Warning: Performance bottleneck condition triggered - excessive identical small values" << endl;
            abort();
        }
    }
}

void check_costly_lower_bound_operations(const vector<int>& as) {
    int small_value_threshold = 50; // Arbitrary threshold for small divisor values
    int divisor_frequency_threshold = 10; // Arbitrary threshold for how many numbers a small value divides
    int count = 0;
    for (int a : as) {
        if (a <= small_value_threshold) {
            for (int b : as) {
                if (b % a == 0) {
                    count++;
                }
            }
        }
    }
    if (count > divisor_frequency_threshold * as.size()) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive lower_bound operations" << endl;
        abort();
    }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &as[i]);
  }
  sort(as, as + n);
  
  // Convert the array to a vector for easier handling
  vector<int> as_vector(as, as + n);
  
  // Apply checks after sorting
  check_repetitive_loop_condition(as_vector);
  check_costly_lower_bound_operations(as_vector);

  int prev = -1;
  for (int i = 0; i < n; i++) {
    if (prev == as[i]) continue;
    int t = as[i];
    LLI k = 0;
    while (t <= 200000) {
      k += n - (lower_bound(as, as + n, t) - as);
      t += as[i];
    }
    LLI cand = k * as[i];
    ans = max(ans, cand);
    prev = as[i];
  }
  printf("%lld\n", ans);
}