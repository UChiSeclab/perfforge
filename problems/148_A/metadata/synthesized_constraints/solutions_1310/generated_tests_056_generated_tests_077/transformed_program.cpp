#include <bits/stdc++.h>
using namespace std;

// Function to check for performance issues related to large dragon count without early termination
void check_dragon_count_invariant(long long d, bool earlyExitPossible) {
    if (d > 50000 && !earlyExitPossible) {
        cerr << "Warning: Performance bottleneck condition triggered due to high dragon count without early exit!" << endl;
        abort();
    }
}

// Function to check for performance issues related to attack intervals
void check_attack_intervals_invariant(long long k, long long l, long long m, long long n) {
    if (!(k == 1 || l == 1 || m == 1 || n == 1)) {
        cerr << "Warning: Performance bottleneck condition triggered due to lack of early termination in attack intervals!" << endl;
        abort();
    }
}

// Function to check for performance issues related to memory usage
void check_memory_usage_invariant(long long d) {
    if (d > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered due to large memory allocation!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long d;
    long long arr[4];
    for (long long i = 0; i < 4; i++) cin >> arr[i];
    cin >> d;

    // Check for attack intervals invariant and dragon count invariant
    check_attack_intervals_invariant(arr[0], arr[1], arr[2], arr[3]);
    check_dragon_count_invariant(d, arr[0] == 1 || arr[1] == 1 || arr[2] == 1 || arr[3] == 1);
    
    if (arr[0] == 1 || arr[1] == 1 || arr[2] == 1 || arr[3] == 1) {
        cout << d << "\n";
    } else {
        // Check for memory usage invariant
        check_memory_usage_invariant(d);
        
        vector<bool> damage(d + 1, 1);
        for (long long i = 0; i < 4; i++) {
            for (long long j = arr[i]; j <= d; j += arr[i]) {
                damage[j] = 0;
            }
        }
        long long ans = 0;
        for (long long i = 1; i <= d; i++) {
            ans += damage[i];
        }
        cout << d - ans << "\n";
    }
    return 0;
}