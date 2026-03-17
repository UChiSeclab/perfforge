#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int count1 = 0;
  for (int i = 0; i < n; i++) {
    int count2 = 0;
    for (int j = 0; j < n; j++) {
      if (a[i] == a[j]) {
        count2++;
      }
    }
    count1 = max(count1, count2);
  }
  cout << count1;
  return 0;
}
