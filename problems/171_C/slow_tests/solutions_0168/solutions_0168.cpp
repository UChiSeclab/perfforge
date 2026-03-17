#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int count = 1;
  long long int sum = 0;
  while (t--) {
    int p;
    cin >> p;
    sum += count * p;
    count++;
  }
  cout << sum << endl;
  return 0;
}
