#include <bits/stdc++.h>
using namespace std;

// Checker functions to detect performance bottlenecks
void check_large_p_invariant(long long n, long long p) {
    if (std::abs(p) > n / 10) {
        std::cerr << "Warning: Performance bottleneck due to large p compared to n!" << std::endl;
        abort();
    }
}

void check_high_iteration_invariant(long long i) {
    if (i > 1e4) {
        std::cerr << "Warning: Performance bottleneck due to excessive loop iterations!" << std::endl;
        abort();
    }
}

void check_loop_operation_invariant(long long operations) {
    if (operations > 5e6) {
        std::cerr << "Warning: Performance bottleneck due to excessive operations inside loops!" << std::endl;
        abort();
    }
}

long long binpow(long long a, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 1)
        return binpow(a, n - 1) * a;
    else {
        long long b = binpow(a, n / 2);
        return b * b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, p, v = 0, a = -1;
    cin >> n >> p;

    // Check if p is large compared to n
    check_large_p_invariant(n, p);

    long long operations = 0; // Counter for operations within the loop

    for (long long i = 1; i <= 1e5; ++i) {
        // Check iteration count
        check_high_iteration_invariant(i);

        long long n1 = n - p * i;
        vector<long long> ans;
        while (n1 != 0) {
            ans.push_back(n1 % 2);
            n1 /= 2;
            operations++;
        }
        long long cont = 0, p2 = 0;
        for (long long j = 0; j < ans.size(); ++j) {
            if (ans[j] == 1) {
                p2 += 1;
                cont += binpow(2, j);
            }
            operations++;
        }
        if (cont >= i && p2 <= i) {
            a = i;
            break;
        }
        
        // Check for excessive operations inside loops
        check_loop_operation_invariant(operations);
    }
    
    cout << a;
    return 0;
}