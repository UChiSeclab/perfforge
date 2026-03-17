#include <bits/stdc++.h>
using namespace std;
int a, b;
int fonk(int c) {
  if (c == 0) return a;
  if (c == 1) return b;
  return fonk(c - 1) + fonk(c - 2);
}
int main() {
  int c;
  scanf("%d %d", &a, &b);
  scanf("%d", &c);
  printf("%d", fonk(c));
  return 0;
}
