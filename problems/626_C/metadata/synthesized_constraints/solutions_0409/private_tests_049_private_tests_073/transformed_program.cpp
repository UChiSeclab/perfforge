#include <bits/stdc++.h>
using namespace std;

void check_high_value_invariant(long long n, long long m) {
    if (n > 800000 || m > 800000) {  // Threshold slightly below max
        cerr << "Warning: Performance bottleneck condition triggered due to high value of n or m!" << endl;
        abort();
    }
}

void check_balance_invariant(long long n, long long m) {
    if (n > 500000 && m > 500000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large values of both n and m!" << endl;
        abort();
    }
}

void check_large_search_invariant(long long queueSize1, long long queueSize2) {
    if (queueSize1 > 400000 && queueSize2 > 400000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large search space in queues!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    // Check for high values of n or m before the main loops
    check_high_value_invariant(n, m);
    
    if (n == 0) {
        cout << 3 * m << endl;
        return 0;
    }
    if (m == 0) {
        cout << 2 * n << endl;
        return 0;
    }

    long long u = 2, v = 3;
    priority_queue<long long> pq1, pq2;

    // Check for balance between n and m
    check_balance_invariant(n, m);

    while (1) {
        if (u % 6 == 0) {
            u += 2;
            continue;
        } else {
            pq1.push(u);
            u += 2;
            n--;
        }
        if (n <= 0) break;
    }
    
    while (1) {
        if (v % 6 == 0) {
            v += 3;
            continue;
        } else {
            pq2.push(v);
            v += 3;
            m--;
        }
        if (m <= 0) break;
    }

    long long w = 6;

    // Check for large search space after filling the queues
    check_large_search_invariant(pq1.size(), pq2.size());

    while (1) {
        u = pq1.top();
        v = pq2.top();
        if (w > u && w > v) break;
        if (u > v) {
            pq1.pop();
            pq1.push(w);
            w += 6;
        } else {
            pq2.pop();
            pq2.push(w);
            w += 6;
        }
    }

    cout << max(pq1.top(), pq2.top()) << endl;
    return 0;
}