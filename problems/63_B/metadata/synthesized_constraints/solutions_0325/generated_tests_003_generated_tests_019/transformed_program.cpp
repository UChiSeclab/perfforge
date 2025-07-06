#include <bits/stdc++.h>
using namespace std;

// Function to check large rank gap condition
void check_large_rank_gap(int k, const vector<int>& ranks) {
    if (k > ranks[0] + 50) {  // Arbitrary threshold for "significantly higher"
        cerr << "Warning: Performance bottleneck condition triggered - large rank gap!" << endl;
        abort();
    }
}

// Function to check high soldier count with low initial ranks
void check_high_soldier_low_rank(int n, int k, const vector<int>& ranks) {
    int low_rank_count = count_if(ranks.begin(), ranks.end(), [k](int rank) { return rank <= k / 2; });
    if (n > 50 && low_rank_count > n / 2) {  // Thresholds based on `n` and low ranks
        cerr << "Warning: Performance bottleneck condition triggered - high soldier count with low ranks!" << endl;
        abort();
    }
}

// Function to check frequent rank updates
void check_frequent_rank_updates(int k, const vector<int>& ranks) {
    if (count(ranks.begin(), ranks.end(), k - 1) > ranks.size() / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent rank updates!" << endl;
        abort();
    }
}

int main() {
  map<int, int> freq;
  int n, k, res = 0;
  cin >> n >> k;
  vector<int> ranks(n);
  
  for (int i = 0; i < n; i++) {
    cin >> ranks[i];
    freq.find(ranks[i]) != freq.end() ? freq[ranks[i]] += 1
                                      : freq[ranks[i]] = 1;
  }

  // Insert performance checks
  check_large_rank_gap(k, ranks);
  check_high_soldier_low_rank(n, k, ranks);
  check_frequent_rank_updates(k, ranks);

  while (freq[k] < n) {
    for (int i = k - 1; i > 0; i--) {
      if (freq.find(i) != freq.end() && freq[i] > 0) {
        freq[i] -= 1;
        freq.find(i + 1) != freq.end() ? freq[i + 1] += 1 : freq[i + 1] = 1;
      }
    }
    res++;
  }
  cout << res;
  return 0;
}