#include <bits/stdc++.h>
int mod = 1000000007;
const double pi = 3.141592653689793238460;
const int inf = 0x3f3f3f3f;
using namespace std;

void check_poss_size_invariant(size_t possSize) {
    if (possSize > 1000) {  // Example threshold based on typical usage patterns
        cerr << "Warning: poss_size_invariant triggered - large set of possibilities!" << endl;
        abort();
    }
}

void check_frequent_scans_invariant(size_t possSize, int n) {
    if (possSize * n > 3000) {  // Example threshold, n is the number of elements in `a`
        cerr << "Warning: frequent_scans_invariant triggered - excessive scans over array!" << endl;
        abort();
    }
}

void check_sort_accumulate_invariant(size_t currSize) {
    if (currSize > 20) {  // Example threshold for sorting and accumulation
        cerr << "Warning: sort_accumulate_invariant triggered - large sorting/accumulation overhead!" << endl;
        abort();
    }
}

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  int a[10005];
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> poss;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    while (x > 0) {
      poss.push_back(x);
      x /= 2;
    }
  }

  // Check for large possibility set
  check_poss_size_invariant(poss.size());

  int ans = inf;
  for (auto x : poss) {
    vector<int> curr;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      int y = a[i];
      while (y > x) {
        y /= 2;
        cnt++;
      }
      if (y == x) {
        curr.push_back(cnt);
      }
    }

    // Check sorting and accumulation overhead
    check_sort_accumulate_invariant(curr.size());

    if (curr.size() < k) continue;
    sort((curr).begin(), (curr).end());
    ans = min(ans, accumulate(curr.begin(), curr.begin() + k, 0));
  }

  // Check for excessive scans over the array
  check_frequent_scans_invariant(poss.size(), n);

  cout << ans << endl;
}