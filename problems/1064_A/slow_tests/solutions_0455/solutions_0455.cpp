#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int answer = 1e9 + 7;
void read() { cin >> a >> b >> c; }
int main() {
  read();
  if (b > a && b > c) swap(b, c);
  if (c > a && c > b) swap(a, c);
  for (int i = a; i <= 400; i++)
    for (int j = b; j <= i; j++)
      for (int k = c; k <= i; k++) {
        if (i < j + k) answer = min(answer, i - a + j - b + k - c);
      }
  cout << answer;
}
