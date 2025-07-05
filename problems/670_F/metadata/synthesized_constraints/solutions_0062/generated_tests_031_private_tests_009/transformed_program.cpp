#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize(2)
using namespace std;
int n, m, n2;
char s[1000111];
char p[1000111];
char ns[1000111];
vector<string> ans1;

void check_permutation_invariant(int permutation_count, int threshold) {
    if (permutation_count > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive permutations!" << endl;
        abort();
    }
}

void check_sort_invariant(int element_count, int threshold) {
    if (element_count > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated sorting with many elements!" << endl;
        abort();
    }
}

int find_length() {
  int i;
  for (i = 1; i <= 6; ++i) {
    if ((int)to_string(n - i).length() == i) {
      return i;
    }
  }
  return -1;
}
char as1[1000111], as2[1000111];
static bool cmp(const string &r1, const string &r2) {
  return (r1 + r2) < (r2 + r1);
}
int main() {
  int i;
  scanf("%s", s);
  scanf("%s", p);
  n = strlen(s);
  n2 = strlen(p);
  int k = n - find_length();
  if (k == -1) return 0;
  string dgt = to_string(k);
  unordered_map<char, int> st;
  for (auto ch : dgt) {
    st[ch]++;
  }
  for (i = 0; i < n; ++i) {
    if (st[s[i]] == 0) {
      ns[m++] = s[i];
    } else {
      st[s[i]]--;
    }
  }
  st.clear();
  for (i = 0; i < n2; ++i) {
    st[p[i]]++;
  }
  multiset<char> ss;
  for (i = 0; i < m; ++i) {
    if (st[ns[i]] == 0) {
      ss.insert(ns[i]);
    } else {
      st[ns[i]]--;
    }
  }
  
  // Inserting checks before potentially problematic operations
  check_permutation_invariant(m, 1000);  // Arbitrarily chosen threshold for permutations
  check_sort_invariant(ss.size(), 1000); // Arbitrarily chosen threshold for sorting

  if (ss.upper_bound('0') == ss.end()) {
    for (i = 0; i < n2; ++i) putchar(p[i]);
    for (auto ch : ss) putchar(ch);
  } else if (n2 == 0 || p[0] == '0') {
    putchar(*ss.upper_bound('0'));
    ss.erase(ss.upper_bound('0'));
    while (!ss.empty() && *ss.begin() == '0') {
      ss.erase(ss.begin());
      putchar('0');
    }
    printf("%s", p);
    for (auto ch : ss) putchar(ch);
  } else {
    ans1 = vector<string>(1, p);
    char c = *ss.upper_bound('0');
    ss.erase(ss.upper_bound('0'));
    for (auto ch : ss) {
      ans1.push_back(string(1, ch));
    }
    sort(ans1.begin(), ans1.end(), cmp);
    as1[0] = c;
    i = 1;
    for (auto &rs : ans1) {
      for (auto ch : rs) {
        as1[i++] = ch;
      }
    }
    ss.insert(c);
    for (i = 0; i < n2; ++i) {
      as2[i] = p[i];
    }
    for (auto ch : ss) {
      as2[i++] = ch;
    }
    if (strcmp(as1, as2) < 0) {
      printf("%s\n", as1);
    } else {
      printf("%s\n", as2);
    }
  }
  return 0;
}