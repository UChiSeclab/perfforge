#include <bits/stdc++.h>
using namespace std;

int DP[201][201][201];

class MaxOccuranceCounter {
 private:
  int size;
  int max_changes;
  string s;
  string t;

 public:
  MaxOccuranceCounter(const int n, const int k, const string s, 
                      const string t) {
    this->size = n;
    this->max_changes = k;
    this->s = s;
    this->t = t;
    memset(DP, -1, sizeof(DP));
    
    // Performance checks
    check_high_recursion_invariant(max_changes, size);
    check_homogeneous_input_invariant(s, t);
  }

  int max_occurance(int idx, int freq_t0, int changes) {
    // Additional check inside function to monitor changes count
    check_dp_memoization_invariant(changes);

    if (idx >= size) {
      return 0;
    }
    if (DP[idx][freq_t0][changes] != -1) {
      return DP[idx][freq_t0][changes];
    }
    int ans = 0;
    if (changes < max_changes) {
      ans = max(ans, freq_t0 * (t[0] == t[1]) +
                         max_occurance(idx + 1, freq_t0 + 1, changes + 1));
      ans = max(ans, freq_t0 + max_occurance(idx + 1, freq_t0, changes + 1));
    }
    ans = max(ans,
              (s[idx] == t[1]) * freq_t0 +
                  max_occurance(idx + 1, freq_t0 + (s[idx] == t[0]), changes));
    return DP[idx][freq_t0][changes] = ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int n, k;
  string s, t;
  cin >> n >> k >> s >> t;

  MaxOccuranceCounter counter(n, k, s, t);
  cout << counter.max_occurance(0, 0, 0) << endl;

  return 0;
}