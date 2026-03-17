#include <bits/stdc++.h>
using namespace std;
struct warehouse {
  int matchbox;
  int match;
};
int main() {
  int n, m, i = 0, j, sum, begin = 1;
  cin >> n >> m;
  warehouse s[20], tmp;
  do {
    cin >> s[i].matchbox >> s[i].match;
    i++;
  } while (i < m);
  for (i = 0; i < m - 1; i++)
    for (j = i + 1; j < m; j++)
      if (s[i].match < s[j].match) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
      };
  for (i = 0, begin, sum = 0; i < m; i++) {
    for (j = 0; j < s[i].matchbox; j++)
      if (begin <= n) {
        begin++;
        sum += s[i].match;
      }
  }
  cout << sum << endl;
  return 0;
}
