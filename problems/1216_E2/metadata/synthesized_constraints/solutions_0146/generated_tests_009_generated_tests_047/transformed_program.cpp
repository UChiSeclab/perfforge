#include <bits/stdc++.h>
using namespace std;

// Function to check if `k` is very large and may cause performance issues
void check_large_k_invariant(long long k) {
    if (k > 1e17) { // Arbitrary threshold for large `k`
        cerr << "Warning: Performance bottleneck: very large `k` detected in binary search!" << endl;
        abort();
    }
}

// Function to check if string operations may become inefficient
void check_string_length_invariant(const string &s) {
    if (s.length() > 10) { // Threshold where string operations may become inefficient
        cerr << "Warning: Performance bottleneck: large string length in operations!" << endl;
        abort();
    }
}

long long k, all;
long long ten[13];

bool check(long long mid) {
    string s = to_string(mid);
    // Check for inefficient string operations
    check_string_length_invariant(s);
    long long len = s.length();
    long long tp, sum, x, y, t;
    all = sum = 0;
    t = 1;
    for (long long i = 1; i <= len; i++) {
        if (i == len)
            tp = mid - ten[len - 1] + 1;
        else
            tp = t * 9;
        y = sum * tp;
        sum += tp * i;
        t *= 10;
        x = (tp * (tp + 1) / 2) * i;
        all = all + x + y;
    }
    if (all < k) return 1;
    return 0;
}

bool check2(long long mid) {
    string s = to_string(mid);
    // Check for inefficient string operations
    check_string_length_invariant(s);
    long long len = s.length(), t = 1;
    all = 0;
    for (int i = 1; i < len; i++) all += t * 9 * i, t *= 10;
    all += (mid - ten[len - 1] + 1) * len;
    if (all < k) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    for (int i = 0; i <= 9; i++) ten[i] = pow(10, i);

    int q;
    cin >> q;
    while (q--) {
        cin >> k;

        // Check for large `k` that might lead to performance issues
        check_large_k_invariant(k);

        long long L = 1, r = 1e9, mid = 0, a = 0, aa = 0;
        while (L <= r) {
            mid = (L + r) / 2;
            if (check(mid))
                L = mid + 1, a = mid;
            else
                r = mid - 1;
        }
        check(a);
        k -= all;

        L = 1, r = a + 1;
        while (L <= r) {
            mid = (L + r) / 2;
            if (check2(mid))
                L = mid + 1, aa = mid;
            else
                r = mid - 1;
        }
        check2(aa);
        k -= all;
        string s = to_string(aa + 1);
        cout << s[k - 1] << endl;
    }

    return 0;
}