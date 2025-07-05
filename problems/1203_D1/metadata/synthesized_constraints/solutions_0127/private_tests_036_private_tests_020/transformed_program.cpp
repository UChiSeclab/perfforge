#include <bits/stdc++.h>
using namespace std;

// Check for excessive nested loop iterations
void check_high_nested_iterations(size_t s_length, size_t t_length) {
    if (s_length >= 200 && t_length <= 1) {
        cerr << "Warning: Performance bottleneck triggered - excessive nested loop iterations with long s and short t!" << endl;
        abort();
    }
}

// Check for excessive continuation in inner loops
void check_excessive_continuation(size_t s_length, size_t t_length) {
    if (s_length > 100 && t_length < s_length / 2) {
        cerr << "Warning: Performance bottleneck triggered - frequent continuation in inner loops due to structure of s!" << endl;
        abort();
    }
}

// Check for inefficient subsequence checking
void check_inefficient_subsequence(size_t s_length, size_t t_length) {
    if (s_length >= 150 && t_length <= 10) {
        cerr << "Warning: Performance bottleneck triggered - inefficient subsequence checking with large s and small t!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long int q = 1;
    while (q--) {
        string s, t;
        cin >> s >> t;

        // Invoke performance checks after reading inputs
        check_high_nested_iterations(s.length(), t.length());
        check_excessive_continuation(s.length(), t.length());
        check_inefficient_subsequence(s.length(), t.length());
        
        long long int mx = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                long long int pos = 0;
                for (int p = 0; p < s.length(); p++) {
                    if (i <= p && p <= j) continue;
                    if (pos <= t.length() && s[p] == t[pos]) pos++;
                }
                if (pos == t.length()) {
                    mx = max(mx, (long long int)j - i + 1);
                }
            }
        }
        cout << mx << "\n";
    }
}