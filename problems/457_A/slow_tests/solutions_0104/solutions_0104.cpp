#include <bits/stdc++.h>
using namespace std;
const int N = 130000;
const unsigned long long MAX = 5 * 1e9 + 4;
unsigned long long a[100005], b[100005];
int len1, len2, len;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  len1 = s1.length();
  len2 = s2.length();
  if (len1 < len2)
    for (int i = len1; i < len2; i++) s1 = "0" + s1;
  else if (len1 > len2)
    for (int i = len2; i < len1; i++) s2 = "0" + s2;
  len = max(len1, len2);
  for (int i = 0; i < len; i++) {
    if (s1[i] == '1') a[i]++;
    if (s2[i] == '1') b[i]++;
    if (a[i] > b[i]) {
      a[i + 1] += (a[i] - b[i]);
      a[i + 2] += a[i] - b[i];
    } else {
      b[i + 1] += (b[i] - a[i]);
      b[i + 2] += (b[i] - a[i]);
    }
  }
  long double t1 = a[len + 1] + a[len] * ((sqrt(5) + 1) / 2);
  long double t2 = b[len + 1] + b[len] * ((sqrt(5) + 1) / 2);
  if (fabs(t1 - t2) < 1e-15)
    cout << "=" << endl;
  else if (t1 > t2)
    cout << ">" << endl;
  else if (t1 < t2)
    cout << "<" << endl;
}
