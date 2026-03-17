#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, c = 1;
  cin >> n >> m;
  long long int n1, m1;
  n1 = n;
  m1 = m;
  n = n - m;
  while (n >= m) {
    n = n - m;
    c++;
  }
  if (n <= 0) n = 0;
  int same_mem = m - n;
  if (c == 1)
    cout << (n * ((c * (c + 1)) / 2)) << " " << ((n1 - m1 + 1) * (n1 - m1)) / 2;
  else {
    cout << ((m - n) * ((c * (c - 1)) / 2)) + (n * ((c * (c + 1)) / 2)) << " "
         << ((n1 - m1 + 1) * (n1 - m1)) / 2;
  }
}
