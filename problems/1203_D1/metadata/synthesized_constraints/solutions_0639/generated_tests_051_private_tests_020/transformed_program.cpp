#include <bits/stdc++.h>
using namespace std;

// Checker functions based on the performance invariants
void check_heavy_substring_invariant(int txtLength, int patLength) {
    if (txtLength > 150 && patLength < 5) {
        cerr << "Warning: Heavy substring generation detected!" << endl;
        abort();
    }
}

void check_extensive_subsequence_invariant(int txtLength, int patLength) {
    if (txtLength > 150 && patLength < 5) {
        cerr << "Warning: Extensive subsequence checking detected!" << endl;
        abort();
    }
}

void check_quadratic_complexity_invariant(int txtLength) {
    if (txtLength > 180) {
        cerr << "Warning: Quadratic complexity slowdown detected!" << endl;
        abort();
    }
}

bool check(string txt, string pat) {
    long long int n = txt.length(), m = pat.length();
    long long int i = 0, j = 0;
    while (i < n && j < m) {
        if (txt[i] == pat[j]) {
            j++;
        }
        i++;
    }
    if (j < m) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string txt, pat;
    cin >> txt >> pat;
    
    // Place checks after reading inputs
    check_heavy_substring_invariant(txt.length(), pat.length());
    check_extensive_subsequence_invariant(txt.length(), pat.length());
    check_quadratic_complexity_invariant(txt.length());
    
    long long int ans = 0;
    for (long long int(i) = (0); (i) < (txt.length()); (i)++) {
        string pre = txt.substr(0, i);
        for (long long int len = 1; len <= txt.length() - i; len++) {
            string sub = txt.substr(i, len);
            string suff = txt.substr(i + len, txt.length() - i - len);
            string tmp = pre + suff;
            if (tmp.length() >= pat.length()) {
                if (check(tmp, pat)) {
                    ans = max(ans, len);
                }
            }
        }
    }
    cout << ans;
    return 0;
}