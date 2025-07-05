#include <bits/stdc++.h>
using namespace std;
using lint = long long;

// Power function utilization check
void check_power_function_invariant(lint n, lint k) {
    if (n > 10 && k > 10) {
        cerr << "Warning: Performance bottleneck condition triggered in power calculations!" << endl;
        abort();
    }
}

// Block size calculation check
void check_block_size_invariant(lint blockSize) {
    if (blockSize > 1e6) {
        cerr << "Warning: Performance bottleneck condition triggered in block size calculations!" << endl;
        abort();
    }
}

// Binary search iterations check
void check_binary_search_invariant(lint iterations) {
    if (iterations > 100) {
        cerr << "Warning: Performance bottleneck condition triggered during binary search!" << endl;
        abort();
    }
}

lint pw(lint n, lint k) {
    check_power_function_invariant(n, k);
    if (k == 0) return 1;
    if (k & 1) return n * pw(n, k - 1);
    lint res = pw(n, k / 2);
    return res * res;
}

lint get_block_size_up_to_nth_block(lint n) {
    lint lg = log10(n);
    lint add = 0;
    lint res = 0;
    for (lint len = 0; len <= lg; len++) {
        lint cnt = (len == lg) ? n - lint(pw(10ll, len)) + 1
                               : lint(pw(10ll, len + 1)) - lint(pw(10ll, len));
        res += add * cnt + ((cnt * (cnt + 1)) / 2) * (len + 1);
        add += cnt * (len + 1);
    }
    check_block_size_invariant(res); // Place check after calculation
    return res;
}

lint get_in_block(lint n) {
    lint lg = log10(n);
    lint add = 0;
    lint res = 0;
    for (lint len = 0; len <= lg; len++) {
        lint cnt = (len == lg) ? n - lint(pw(10ll, len)) + 1
                               : lint(pw(10ll, len + 1)) - lint(pw(10ll, len));
        res += cnt * (len + 1);
    }
    return res;
}

char solve(lint k) {
    lint le = 1, ri = 1e9;
    lint block = 0;
    lint iterations = 0;  // Counter for binary search iterations
    while (le <= ri) {
        iterations++;
        lint mid = (le + ri) / 2;
        if (get_block_size_up_to_nth_block(mid) >= k) {
            block = mid;
            ri = mid - 1;
        } else {
            le = mid + 1;
        }
    }
    check_binary_search_invariant(iterations); // Check after binary search completion

    k -= get_block_size_up_to_nth_block(block - 1);
    le = 1, ri = 1e9;
    lint ans = -1;
    iterations = 0;  // Reset counter for the second binary search
    while (le <= ri) {
        iterations++;
        lint mid = (le + ri) / 2;
        if (get_in_block(mid) >= k) {
            ans = mid;
            ri = mid - 1;
        } else {
            le = mid + 1;
        }
    }
    check_binary_search_invariant(iterations); // Check after second binary search

    return to_string(ans)[k - get_in_block(ans - 1) - 1];
}

int main() {
    lint q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        lint k;
        cin >> k;
        cout << solve(k) << "\n";
    }
}