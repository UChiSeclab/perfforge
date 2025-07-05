#include <bits/stdc++.h>
using namespace std;

bool bigger(string &a, string &b) {
  for (int i = 0; i < int((a).size()); i++) {
    if (a[i] != b[i]) {
      return a[i] > b[i];
    }
  }
  return 1;
}

void check_linear_search_invariant(long long start, const string& second) {
    if (start < 1000 && second.size() <= 3) {
        cerr << "Warning: Performance bottleneck condition triggered - Repeated Linear Search!" << endl;
        abort();
    }
}

void check_string_manipulation_invariant(const string& nw, const string& second) {
    if (nw.size() < second.size()) {
        cerr << "Warning: Performance bottleneck condition triggered - String Manipulation Overhead!" << endl;
        abort();
    }
}

void check_size_mismatch_invariant(const string& nw, const string& second) {
    if (nw.size() == second.size() && nw < second) {
        cerr << "Warning: Performance bottleneck condition triggered - Size Mismatch!" << endl;
        abort();
    }
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    char a;
    string second;
    cin >> a >> a >> a >> a;
    cin >> second;
    long long start = 1989, pw = 1;
    for (int i = 1; i < int((second).size()); i++) {
      pw *= 10;
      start += pw;
    }
    string nw = "";
    long long x = start;
    while (x) {
      nw += char('0' + x % 10);
      x /= 10;
    }
    reverse(nw.begin(), nw.end());
    
    // Check for potential bottlenecks
    check_linear_search_invariant(start, second);

    if (int((nw).size()) == int((second).size())) {
      if (bigger(second, nw))
        cout << second << endl;
      else
        cout << '1' << second << endl;
      continue;
    }
    
    while (1) {
      nw = "";
      x = start;
      while (int((nw).size()) < int((second).size())) {
        nw += char('0' + x % 10);
        x /= 10;
      }
      reverse(nw.begin(), nw.end());

      // Check for potential bottlenecks
      check_string_manipulation_invariant(nw, second);
      check_size_mismatch_invariant(nw, second);

      if (nw == second) {
        cout << start << endl;
        break;
      }
      start++;
    }
  }
  return 0;
}