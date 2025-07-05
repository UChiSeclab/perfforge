#include <bits/stdc++.h>
using namespace std;

vector<long long> factors(long long n, int &flag, long long p, int &divisor_checks) {
    vector<long long> ans;
    for (int i = 1; i <= sqrt(n); i++) {
        divisor_checks++;
        if (n % i == 0) {
            if (n / i == i) {
                ans.push_back(i);
                if (i <= p && i != 1) flag = 1;
            } else {
                if (i <= p && i != 1) flag = 1;
                if (n / i <= p && n / i != i) flag = 1;
                ans.push_back(i);
                ans.push_back(n / i);
            }
        }
    }
    return ans;
}

void solve() {
    int t = 1;
    while (t--) {
        long long int p, y;
        cin >> p >> y;
        long long int temp = y;
        long long int ans;
        int iteration_count = 0;
        
        while (temp--) {
            int flag = 0;
            int divisor_checks = 0;
            vector<long long int> div = factors(y, flag, p, divisor_checks);

            // Check for performance bottlenecks
            check_excessive_iterations_invariant(iteration_count);
            check_close_to_p_invariant(y, p, iteration_count);
            check_inefficient_factorization_invariant(divisor_checks);

            if (div.size() == 2) {
                ans = y;
                break;
            } else if (flag == 0) {
                ans = y;
                break;
            }
            y--;
            iteration_count++;
        }
        
        if (ans > p)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
}

int main() {
    solve();
    return 0;
}