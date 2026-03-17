#include <bits/stdc++.h>
using namespace std;
int dominant[5005];
int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    int len = s.length() - 4;
    int num = 0;
    for (int i = 4; i < s.length(); i++) num = num * 10 + s[i] - '0';
    if (len > 3) {
      if (num < 1989 + 10 * (((long long)ceil(pow(10, len - 1)) - 1) / 9))
        num += (int)ceil(pow(10, len));
    } else
      for (int i = 1989 + 10 * ((int)(ceil(pow(10, len - 1)) - 1) / 9);
           i < 1989 + 10 * ((int)(ceil(pow(10, len - 1)) - 1) / 9) +
                   (int)ceil(pow(10, len));
           i++) {
        if ((i - num) % (int)ceil(pow(10, len)) == 0) {
          num = i;
          break;
        }
      }
    cout << num << '\n';
  }
  return 0;
}
