#include <bits/stdc++.h>
using namespace std;

long long int cost(vector<long long int> a, long long int n, long long int c) {
    long long int ans = 0;
    for (long long int i = 0; i < n; i++) {
        ans += abs(a[i] - pow(c, i));
    }
    return ans;
}

void check_exponentiation_overhead(long long n, long long r) {
    if (n < 60 && r > 10) {  // These thresholds are derived from the problem context
        cerr << "Warning: Exponentiation overhead due to excessive range of potential base values!" << endl;
        abort();
    }
}

void check_loop_iteration_bottleneck(long long r, long long l) {
    if ((r - l) > 1000) {  // Arbitrary threshold for large number of iterations
        cerr << "Warning: Loop iteration bottleneck due to large range of potential base values!" << endl;
        abort();
    }
}

void check_large_number_operations(const vector<long long int>& a, long long int c, long long int n) {
    long long int operationCostThreshold = 100000000;  // Example threshold for significant cost
    long long int cost = 0;
    for (long long int i = 0; i < n; i++) {
        cost += abs(a[i] - pow(c, i));
    }
    if (cost > operationCostThreshold) {
        cerr << "Warning: Large number operations causing high cost!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (long long int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    if (n >= 60) {
        cout << cost(a, n, 1) << '\n';
    } else {
        long long int l = 1;
        double temp = 18 / (n + 0.0);
        long long int r = floor(pow(10, temp));
        
        check_exponentiation_overhead(n, r); // Check for exponentiation overhead
        check_loop_iteration_bottleneck(r, l); // Check for loop iteration bottleneck

        long long int ans = LLONG_MAX;
        for (long long int i = l; i <= r; i++) {
            check_large_number_operations(a, i, n); // Check for large operation cost
            ans = min(ans, cost(a, n, i));
        }
        cout << ans << '\n';
    }
}