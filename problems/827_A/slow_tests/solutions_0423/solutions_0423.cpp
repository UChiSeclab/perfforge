#include <bits/stdc++.h>
using namespace std;
struct tri {
  int b, e, s;
};
bool operator<(tri an, tri ath) { return an.b < ath.b; }
int main() {
  int n, a[2000000] = {}, k, sup = 0;
  string y;
  cin >> n;
  vector<tri> vec;
  vector<string> st;
  for (int i = 0; i < n; i++) {
    cin >> y >> k;
    st.push_back(y);
    for (int j = 0; j < k; j++) {
      tri z;
      cin >> z.b;
      z.b--;
      z.e = y.size() + z.b - 1;
      z.s = i;
      vec.push_back(z);
    }
  }
  sort(vec.begin(), vec.end());
  for (int i = vec[0].b; i <= vec[0].e; i++)
    a[i] = st[vec[0].s][i - vec[0].b] - 'a' + 1;
  sup = vec[0].e;
  for (int i = 1; i < vec.size(); i++) {
    if (vec[i].e <= sup) continue;
    for (int j = max(sup + 1, vec[i].b); j <= vec[i].e; j++)
      a[j] = st[vec[i].s][j - vec[i].b] - 'a' + 1;
    sup = vec[i].e;
  }
  for (int i = 0; i <= sup; i++) {
    if (a[i] == 0)
      cout << 'a';
    else
      cout << (char)(a[i] - 1 + 'a');
  }
}
