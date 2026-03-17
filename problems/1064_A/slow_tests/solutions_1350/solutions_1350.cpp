#include <bits/stdc++.h>
using namespace std;
void swapstick(int &a, int &b, int &c) {
  int s;
  if (a > b) {
    s = b;
    b = a;
    a = s;
  }
  if (a > c) {
    s = c;
    c = a;
    a = s;
  }
  if (b > c) {
    s = c;
    c = b;
    b = s;
  }
}
bool succeed(int a, int b, int c) {
  if (a + b > c && a + c > b && b + c > a && a - b < c && a - c < b &&
      b - c < a) {
    return true;
  }
  return false;
}
int main(int argc, char **argv) {
  int a, b, c;
  int min = 500;
  cin >> a >> b >> c;
  swapstick(a, b, c);
  for (int i = a; i <= c; i++) {
    for (int j = b; j <= c; j++) {
      if (succeed(i, j, c)) {
        if (i - a + j - b < min) {
          min = i - a + j - b;
        }
      }
    }
  }
  cout << min << endl;
  return 0;
}
