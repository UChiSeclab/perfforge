#include <bits/stdc++.h>
using namespace std;
long long int a[2000000];
int main() {
  long long int n;
  cin >> n;
  for (long long int j = 0; j < n; j++) {
    long long int num;
    cin >> num;
    a[num] = -1;
  }
  long long int r = 1, m = 1000000;
  long long int t = 0, i = 0;
  while (i < n) {
    t++;
    if (a[++r] == -1) i++;
    if (a[--m] == -1) i++;
  }
  cout << t;
  return 0;
}
