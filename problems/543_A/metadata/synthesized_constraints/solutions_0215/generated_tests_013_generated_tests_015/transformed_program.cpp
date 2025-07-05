#include <bits/stdc++.h>
using namespace std;
const int N = 501;
int n, m, b, mod, a[N], F[2][N][N];

void enter() {
  cin >> n >> m >> b >> mod;
  for (int i = 1; i <= n; i++) cin >> a[i];
}

void check_bug_limit(int b, const vector<int>& a) {
    int min_a = *min_element(a.begin(), a.end());
    if (b > min_a * 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high bug limit!" << endl;
        abort();
    }
}

void check_complexity(int m, int b) {
    if (m > 400 && b > 400) {
        cerr << "Warning: Performance bottleneck condition triggered - high m and b values!" << endl;
        abort();
    }
}

void check_low_bug_rate(int n, const vector<int>& a, int b) {
    int low_bug_programmers = count_if(a.begin(), a.end(), [](int x) { return x <= 2; });
    if (low_bug_programmers > n / 2 && b > 400) {
        cerr << "Warning: Performance bottleneck condition triggered - many low bug-rate programmers!" << endl;
        abort();
    }
}

void process() {
  F[0][0][0] = 1;
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= b; k++) {
        if (j < n)
          F[i % 2][j + 1][k] = (F[i % 2][j + 1][k] + F[i % 2][j][k]) % mod;
        if (i < m && j < n && a[j + 1] + k <= b)
          F[(i + 1) % 2][j][k + a[j + 1]] =
              (F[(i + 1) % 2][j][k + a[j + 1]] + F[i % 2][j][k]) % mod;
        if (i < m) F[i % 2][j][k] = 0;
      }
}

void print() {
  int res = 0;
  for (int j = 0; j <= b; j++) res = (res + F[m % 2][n][j]) % mod;
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  enter();

  vector<int> a_vector(a + 1, a + n + 1);
  check_bug_limit(b, a_vector);  // Check if the bug limit is too high
  check_complexity(m, b);  // Check complexity threshold
  check_low_bug_rate(n, a_vector, b);  // Check for low bug-rate programmers

  process();
  print();
}