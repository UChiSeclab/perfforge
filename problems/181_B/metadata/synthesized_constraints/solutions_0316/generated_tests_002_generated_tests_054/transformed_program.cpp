#include <bits/stdc++.h>
using namespace std;

pair<double, double> middle(pair<double, double> a, pair<double, double> b) {
  return make_pair((a.first + b.first) / 2, (b.second + a.second) / 2);
}

// Check if the number of point pairs is large, potentially leading to excessive computation.
void check_pair_combinations_invariant(long long n) {
    // The threshold is set arbitrarily close to the maximum input size.
    if ((n * (n - 1)) / 2 > 4000000) { // n choose 2, with n near maximum.
        cerr << "Warning: pair_combinations_invariant triggered - excessive point pair evaluations!" << endl;
        abort();
    }
}

// Check if there are frequent middle point checks that can degrade performance.
void check_middle_point_invariant(long long middlePointChecks) {
    // Assume a threshold for middle points checks that indicates potential performance issues.
    if (middlePointChecks > 1000000) {
        cerr << "Warning: middle_point_invariant triggered - frequent valid middle point checks!" << endl;
        abort();
    }
}

// Check if input distribution complexity can lead to intensive computation.
void check_input_distribution_invariant(long long validMiddlePoints) {
    // Threshold for valid middle point checks.
    if (validMiddlePoints > 100000) {
        cerr << "Warning: input_distribution_invariant triggered - complex input distribution!" << endl;
        abort();
    }
}

signed main() {
  long long n;
  cin >> n;
  
  // Insert the check for pair combinations invariant right after reading n
  check_pair_combinations_invariant(n);
  
  vector<pair<double, double> > v(n);
  set<pair<double, double> > points;
  for (long long i = 0; i < n; i++)
    cin >> v[i].first >> v[i].second, points.insert(v[i]);
  
  long long res = 0;
  long long middlePointChecks = 0; // Count the number of middle point checks
  long long validMiddlePoints = 0; // Count the number of valid middle points

  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      middlePointChecks++;
      if (points.count(middle(v[i], v[j]))) {
        res++;
        validMiddlePoints++;
      }
    }
  }
  
  // Check for the middle point invariant after processing all pairs
  check_middle_point_invariant(middlePointChecks);
  check_input_distribution_invariant(validMiddlePoints);
  
  cout << res << endl;
  return 0;
}