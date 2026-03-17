#include <bits/stdc++.h>
using namespace std;
long long pos[100001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long i = 1;
  while (true) {
    long long num1 = i / 2;
    long long num2 = i / 3;
    long long num3 = i / 6;
    num1 -= i / 6;
    num2 -= i / 6;
    if (max(n - num1, (long long)0) + max(m - num2, (long long)0) <= num3) {
      cout << i;
      return 0;
    }
    i++;
  }
  return 0;
}
