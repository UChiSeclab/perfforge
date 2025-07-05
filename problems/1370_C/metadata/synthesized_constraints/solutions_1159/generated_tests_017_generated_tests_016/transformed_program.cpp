#include <bits/stdc++.h>
using namespace std;

void check_high_divisor_range(long long n, int divisorCount) {
    if (divisorCount > 1000) {
        cerr << "Warning: High divisor range potential slowdown triggered!" << endl;
        abort();
    }
}

void check_frequent_vector_operations(int vectorSize) {
    if (vectorSize > 500) {
        cerr << "Warning: Frequent vector operations slowdown triggered!" << endl;
        abort();
    }
}

void check_odd_divisor_checks(long long n, int vectorSize) {
    if (n > 1e9 && vectorSize > 200) {
        cerr << "Warning: Odd divisor checks slowdown triggered!" << endl;
        abort();
    }
}

int Divisors(long long n) {
    vector<long long> v;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) {
                v.push_back(i);
            } else {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }
    // Check for potential bottlenecks after populating divisors
    check_frequent_vector_operations(v.size());

    int c = 0, i;
    for (i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 1 && v[i] != (n / 2) && v[i] != 1) {
            return 1;
        }
    }
    return 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long t, n, i, j, k, mini, l1, l2, l3, r1, r2, c, d, maxi, x, y, l, m, r, ans, last, flag, lastind;
    t = 1;
    cin >> t;
    
    while (t--) {
        cin >> n;

        int divisorCount = 0; // Initialize divisor count before checking
        if (n == 1) {
            cout << "FastestFinger\n";
        } else if (n % 2 == 1) {
            cout << "Ashishgup\n";
        } else if (n == 2) {
            cout << "Ashishgup\n";
        } else {
            x = Divisors(n);
            // Run checks for potential bottlenecks
            check_high_divisor_range(n, divisorCount);
            check_odd_divisor_checks(n, divisorCount);
            
            if (x == 1) {
                cout << "Ashishgup\n";
            } else {
                cout << "FastestFinger\n";
            }
        }
    }
}