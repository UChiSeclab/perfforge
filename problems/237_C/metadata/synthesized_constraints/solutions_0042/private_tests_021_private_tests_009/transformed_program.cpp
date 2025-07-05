#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance characterizations
void check_prime_calculation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive prime checking!" << endl;
        abort();
    }
}

void check_large_range_high_prime_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large range with high prime requirement!" << endl;
        abort();
    }
}

void check_cumulative_prime_count_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient cumulative prime count!" << endl;
        abort();
    }
}

void check_large_domain_binary_search_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - binary search over large domain!" << endl;
        abort();
    }
}

// Prime number checker
bool check(int p) {
    if (p < 2) return false;
    if (p == 2) return true;
    for (int i = 2; i <= sqrt(p); i++) {
        if ((p % i) == 0) return false;
    }
    return true;
}

int main() {
    int a, b, k, l = 1;
    scanf("%d%d%d", &a, &b, &k);

    // Performance check: large domain with high prime requirement
    check_large_range_high_prime_invariant((b - a + 1) > 100000 && k > 500);

    // Initialize array and auxiliary variables
    int arr[1000002];
    arr[a] = 0;
    int lEnd = b - a + 1;
    int m = -1;
    int h;
    int en = lEnd;
    int start = 1;
    l = (start + en) / 2;
    h = en;
    int cnt = 0;

    while (start <= en || start == (en + 2)) {
        int xEnd = b - l + 1;
        
        // Performance check: inefficient cumulative prime count
        check_cumulative_prime_count_invariant((xEnd + l) > 1000000);

        for (int i = a + cnt; i <= xEnd + l; i++) {
            // Performance check: prime calculation bottleneck
            check_prime_calculation_invariant((i - a) > 1000000);

            if (check(i))
                arr[i + 1] = arr[i] + 1;
            else
                arr[i + 1] = arr[i];
            cnt++;
        }

        en = h;
        bool flag;
        for (int i = a; i <= xEnd; i++) {
            if (arr[i + l] - arr[i] >= k)
                flag = true;
            else {
                flag = false;
                break;
            }
        }

        if (flag) {
            m = l;
            en = l - 1;
            l = (l - 1 + start) / 2;
        } else {
            start = l + 1;
            l = (en + l + 1) / 2;
        }
    }

    // Performance check: binary search over large domain
    check_large_domain_binary_search_invariant((b - a + 1) > 1000000);

    printf("%d", m);
    return 0;
}