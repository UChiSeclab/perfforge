#include <bits/stdc++.h>
using namespace std;

// Check for large pyramid height
void check_pyramid_height_invariant(long long mid) {
    if (mid > 10000) { // Assumed threshold for a large height
        cerr << "Warning: Performance bottleneck condition triggered due to large pyramid height calculation!" << endl;
        abort();
    }
}

// Check for wide binary search range
void check_binary_search_invariant(long long l, long long r) {
    if ((r - l) > 100000) { // Assumed threshold for large search space
        cerr << "Warning: Performance bottleneck condition triggered due to wide binary search range!" << endl;
        abort();
    }
}

// Check for large number of cards
void check_total_cards_invariant(long long x) {
    if (x > 500000000) { // Assumed threshold for a large number of cards
        cerr << "Warning: Performance bottleneck condition triggered due to large number of cards!" << endl;
        abort();
    }
}

long long x;
bool fun(long long mid) {
    check_pyramid_height_invariant(mid); // Check before expensive loop
    long long sum = 0;
    for (int i = 1; i < mid; i++) {
        sum += 3 * i;
    }
    sum += 2 * (mid);
    if (sum < x) {
        return false;
    } else {
        return true;
    }
}

long long Count(long long mid) {
    long long sum = 0;
    for (int i = 1; i < mid; i++) {
        sum += 3 * i;
    }
    sum += 2 * (mid);
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> x;
        check_total_cards_invariant(x); // Check based on card input
        long long s = 0;
        while (x >= 2) {
            long long l = 0, r = x / 2 + 1;
            while (l < r) {
                check_binary_search_invariant(l, r); // Check before binary search iteration
                long long mid = l + (r - l) / 2;
                if (fun(mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (Count(l) == x) {
                x = 0;
                s++;
            } else if (Count(l) > x) {
                x -= Count(l - 1);
                s++;
            } else {
                x -= Count(l);
                s++;
            }
        }
        cout << s << endl;
    }
    return 0;
}