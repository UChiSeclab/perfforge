#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[101] = {0, 0}, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int j = 1; j <= 100; j++) {
      if (j == x) arr[j]++;
    }
  }
  sort(arr, arr + 101);
  cout << arr[100] << endl;
  return 0;
}
