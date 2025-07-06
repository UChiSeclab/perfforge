#include <bits/stdc++.h>
using namespace std;
char res[2000002], s[2000002];

// Check functions based on performance-characterizing invariants
void check_large_repeated_segments(int l, int x, int p) {
    if (l > 100 && x < p + 50) {
        cerr << "Warning: Large repeated segment insertion detected!" << endl;
        abort();
    }
}

void check_long_resulting_string(int len) {
    if (len > 1000000) {
        cerr << "Warning: Resulting string length too large!" << endl;
        abort();
    }
}

void check_small_overlapping_insertions(int x, int prev_x) {
    if (x - prev_x < 10) {
        cerr << "Warning: High frequency of small overlapping insertion points detected!" << endl;
        abort();
    }
}

void check_excessive_large_k(int k) {
    if (k > 100) {
        cerr << "Warning: Excessively large k value detected!" << endl;
        abort();
    }
}

int main() {
    int n, len = 0;
    cin >> n;
    int prev_x = -100; // Initialize to a large negative to prevent initial false positive
    for (int i = 0; i < n; i++) {
        int k, p = 1, l;
        cin >> s >> k;
        l = strlen(s);
        check_excessive_large_k(k); // Check for large k values
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            check_large_repeated_segments(l, x, p); // Check for large repeated segments
            check_small_overlapping_insertions(x, prev_x); // Check for small overlapping insertions
            prev_x = x; // Update prev_x
            for (int m = max(x, p); m < x + l; m++) {
                res[m] = s[m - x];
            }
            p = x + l - 1;
            if (len < p) len = p;
        }
    }
    check_long_resulting_string(len); // Check the length of resulting string
    for (int i = 1; i <= len; i++) {
        if (res[i])
            cout << res[i];
        else
            cout << 'a';
    }
    cout << endl;
    return 0;
}