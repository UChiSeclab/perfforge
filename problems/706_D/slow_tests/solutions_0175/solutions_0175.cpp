#include <bits/stdc++.h>
using namespace std;
int TRIE[200005 * 32 * 2][2];
int isword[200005 * 32 * 2];
int nxt;
void ins(string &s) {
  int v = 0;
  for (int i = 0; i < s.size(); i++) {
    if (TRIE[v][s[i] - '0'] == -1) TRIE[v][s[i] - '0'] = nxt++;
    isword[v]++;
    v = TRIE[v][s[i] - '0'];
  }
  isword[v]++;
}
void del(string &s) {
  int v = 0;
  int u;
  for (int i = 0; i < s.size(); i++) {
    if (isword[v] > 0) isword[v]--;
    if (isword[v] == 0 && i > 0) TRIE[u][s[i - 1] - '0'] = -1;
    u = v;
    v = TRIE[v][s[i] - '0'];
  }
  if (isword[v] > 0) isword[v]--;
  if (isword[v] == 0) TRIE[u][s[31] - '0'] = -1;
}
string bin(int a) {
  string k = "";
  while (a) {
    k += to_string(a % 2);
    a /= 2;
  }
  int u = k.length();
  for (int i = 0; i < 32 - u; i++) k += "0";
  reverse(k.begin(), k.end());
  return k;
}
long long int query(string &s) {
  int v = 0;
  string k = "";
  for (int i = 0; i < s.size(); i++) {
    if (TRIE[v][1 - (s[i] - '0')] != -1) {
      v = TRIE[v][1 - (s[i] - '0')];
      if (s[i] == '0')
        k += "1";
      else
        k += "0";
    } else {
      v = TRIE[v][s[i] - '0'];
      k += s[i];
    }
  }
  long long int val = 0, bit;
  for (int i = 0; i <= 31; i++) {
    bit = (s[i] == k[i]) ? 0 : 1;
    val <<= 1;
    val += bit;
  }
  return val;
}
int main() {
  memset(isword, 0, sizeof(isword));
  memset(TRIE, -1, sizeof(TRIE));
  isword[0] = 1;
  nxt = 1;
  int q, a;
  string s;
  cin >> q;
  string k = bin(0);
  ins(k);
  for (int i = 0; i < q; i++) {
    cin >> s >> a;
    string k = bin(a);
    if (s == "+")
      ins(k);
    else if (s == "-")
      del(k);
    else
      cout << query(k) << endl;
  }
  return 0;
}
