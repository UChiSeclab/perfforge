#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, b;
  long long maxx = 0;
  cin >> m >> b;
  for (long long i = 0; i <= m * b; i++) {
    long long t = (-1) * ceil((float)i / m) + b;
    long long sum = (t * (t + 1) / 2) * (i + 1) + (i * (i + 1) / 2) * (t + 1);
    maxx = max(maxx, sum);
  }
  cout << maxx;
}
