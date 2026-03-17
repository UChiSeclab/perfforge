#include <bits/stdc++.h>
using namespace std;
int flag = 0;
void recursion(int x) {
  if (x == 0) {
    if (flag == 0) cout << "YES" << endl;
    flag++;
    return;
  } else if (x < 0) {
    return;
  } else {
    recursion(x - 3);
    recursion(x - 7);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    int x;
    flag = 0;
    cin >> x;
    recursion(x);
    if (flag == 0) cout << "NO" << endl;
  }
  return 0;
}
