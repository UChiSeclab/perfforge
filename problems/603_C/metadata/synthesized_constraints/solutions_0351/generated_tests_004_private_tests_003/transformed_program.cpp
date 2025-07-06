#include <bits/stdc++.h>
using namespace std;

int arr[100005];
map<int, int> dp;

int solve(int n) {
    if (dp.count(n)) {
        return dp[n];
    }
    if (n % 2 == 1) {
        return 0;
    }
    int k = solve(n / 2);
    if (k == 0) {
        return dp[n] = 1;
    } else if (k == 1) {
        return dp[n] = 2;
    } else {
        return dp[n] = 1;
    }
}

// Check for odd K causing recursive usage
void check_odd_k_invariant(int K) {
    if (K % 2 == 1) {
        cerr << "Warning: Performance bottleneck condition triggered due to odd K causing recursive calls!" << endl;
        abort();
    }
}

// Check for large DP table initialization
void check_dp_initialization_invariant(int upperLimit) {
    if (upperLimit > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large DP table initialization!" << endl;
        abort();
    }
}

// Check for complex pile configurations
void check_complex_pile_invariant(const vector<int>& piles) {
    int evenCount = 0;
    for (int pile : piles) {
        if (pile % 2 == 0) evenCount++;
    }
    if (evenCount > piles.size() / 2) { // Arbitrary threshold: more than half piles are even
        cerr << "Warning: Performance bottleneck condition triggered due to complex pile configuration!" << endl;
        abort();
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    
    // Check for the odd K condition
    check_odd_k_invariant(K);

    vector<int> piles(N);
    for (int i = 0; i < N; i++) {
        cin >> piles[i];
    }
    
    // Check for complex pile configurations
    check_complex_pile_invariant(piles);

    if (K % 2 == 0) {
        int x = 0;
        for (int i = 1; i <= N; i++) {
            if (piles[i - 1] == 2) {
                x ^= 2;
            } else if (piles[i - 1] == 1) {
                x ^= 1;
            } else {
                x ^= (piles[i - 1] & 1) ^ 1;
            }
        }
        if (x) {
            cout << "Kevin\n";
        } else {
            cout << "Nicky\n";
        }
        return 0;
    }

    // Check if DP table initialization might be costly
    check_dp_initialization_invariant(10000);

    for (int i = 1; i <= 10000; i++) {
        if (i % 2 == 1) {
            if (dp[i - 1] != 0) {
                dp[i] = 0;
            } else {
                dp[i] = 1;
            }
        } else {
            if (dp[i - 1] != 0 && dp[i / 2] != 0) {
                dp[i] = 0;
            } else if (dp[i - 1] != 1 && dp[i / 2] != 1) {
                dp[i] = 1;
            } else {
                dp[i] = 2;
            }
        }
    }

    int x = 0;
    for (int i = 1; i <= N; i++) {
        x ^= solve(piles[i - 1]);
    }
    cout << (x ? "Kevin" : "Nicky") << "\n";
}