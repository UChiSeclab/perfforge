#include <bits/stdc++.h>
const long long int INF = 1e18;
const long long int MOD = 1000000007;
const int MX = 100005;
using namespace std;

// Checker functions as defined in Phase 3
void check_repeated_initialization(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated initialization of large data structure" << endl;
        abort();
    }
}

void check_frequent_search(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent use of upper_bound search" << endl;
        abort();
    }
}

void check_inefficient_handling(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient handling of small inputs" << endl;
        abort();
    }
}

int main() {
    int test_c;
    cin >> test_c;

    // Initialize the array `a` once outside the loop
    vector<long long int> a(MX);
    for (long long int i = 0; i < MX; i++) a[i] = ((i + 1) * (3 * i + 4)) / 2;

    while (test_c--) {
        long long int i, j;
        int n;
        cin >> n;
        int count = 0;

        // Check for repeated initialization
        check_repeated_initialization(!a.empty());

        while (n) {
            vector<long long int>::iterator it = upper_bound(a.begin(), a.end(), n);

            // Check for frequent search operations
            check_frequent_search(it == a.begin());

            i = it - a.begin();
            i--;

            if (i >= 0) {
                n -= a[i];
                count++;
            } else
                break;
        }

        // Check for inefficient handling of small inputs
        check_inefficient_handling(n < 2 && count == 0);

        cout << count << endl;
    }
    return 0;
}