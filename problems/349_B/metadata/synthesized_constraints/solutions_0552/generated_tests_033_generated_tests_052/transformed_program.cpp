#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_high_iterations_invariant(long long initial_digit, long long iterations) {
    if (iterations > 1000 && initial_digit < 5) {  // Example condition
        cerr << "Warning: Performance bottleneck condition triggered due to high iterations!" << endl;
        abort();
    }
}

void check_small_cost_difference(map<char, long long>& m) {
    long long min_cost = LLONG_MAX;
    long long second_min_cost = LLONG_MAX;

    for (auto& entry : m) {
        if (entry.second < min_cost) {
            second_min_cost = min_cost;
            min_cost = entry.second;
        } else if (entry.second < second_min_cost) {
            second_min_cost = entry.second;
        }
    }

    if (second_min_cost - min_cost <= 2) {  // Example small difference
        cerr << "Warning: Performance bottleneck condition triggered due to small differences in paint costs!" << endl;
        abort();
    }
}

void check_remaining_paint_usage(long long rem, long long smallest_paint_cost) {
    if (rem >= smallest_paint_cost && rem < 10) {  // Example condition
        cerr << "Warning: Performance bottleneck condition triggered due to inefficient remaining paint usage!" << endl;
        abort();
    }
}

void oj() {}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    oj();
    long long t, x, y, n;
    cin >> n;
    map<char, long long> m;
    for (long long i = 0; i < 9; i++) {
        cin >> x;
        m['1' + i] = x;
    }

    // Apply check for small differences in paint costs
    check_small_cost_difference(m);

    long long d = LLONG_MIN;
    char ch;
    for (auto x : m) {
        if (n / x.second > d) {
            ch = x.first;
            d = n / x.second;
        } else if (n / x.second == d) {
            if (x.second < m[ch])
                ch = x.first;
            else if (x.second == m[ch])
                ch = max(ch, x.first);
        }
    }

    if (d == 0) {
        cout << -1;
        return 0;
    }

    string ans(d, ch);
    long long rem = n - d * m[ch];
    long long i = 0;
    long long initial_digit = ch - '0';
    long long iterations = 0;

    while (rem > 0 && i < ans.length()) {
        for (long long j = 9; j >= 1; j--) {
            iterations++;
            if (rem + m[ans[i]] >= m[j + '0']) {
                rem = rem + m[ans[i]] - m[j + '0'];
                ans[i] = j + '0';
                break;
            }
        }
        i++;
    }

    // Apply check for high iterations in nested loops
    check_high_iterations_invariant(initial_digit, iterations);

    // Apply check for remaining paint utilization
    check_remaining_paint_usage(rem, m['1']);

    cout << ans;
    return 0;
}