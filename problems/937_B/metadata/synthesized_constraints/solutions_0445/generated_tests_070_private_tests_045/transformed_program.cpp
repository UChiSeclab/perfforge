#include <iostream>
#include <cmath>
using namespace std;

// Checker Functions
void check_large_y_vs_p(bool condition) {
    if (condition) {
        cerr << "Warning: large_y_vs_p invariant triggered - potential for excessive loop iterations" << endl;
        abort();
    }
}

void check_large_inner_loop_iterations(bool condition) {
    if (condition) {
        cerr << "Warning: large_inner_loop_iterations invariant triggered - potential for slow factor checking" << endl;
        abort();
    }
}

void check_slow_outer_loop_exit(bool condition) {
    if (condition) {
        cerr << "Warning: slow_outer_loop_exit invariant triggered - potential for prolonged outer loop execution" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long p, y;
    cin >> p >> y;
    long long ans = -1;

    // Place check after input to trigger if y is significantly larger than p.
    check_large_y_vs_p(y > p + 1e4); // Arbitrary threshold for demonstration

    for (long long i = y; i >= 2; i--) {
        if (i <= p or y - i > 300) break;

        // Check if the outer loop is likely to run too long without exceeding the threshold.
        check_slow_outer_loop_exit(y - i <= 300 && i > p + 1e4);

        long long cnt = 0;

        // Check for potentially large inner loop iterations.
        check_large_inner_loop_iterations(sqrt(i) > 1e6); // Arbitrary threshold for demonstration

        for (long long j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                if ((j >= 2 and j <= p) or (i / j >= 2 and i / j <= p)) cnt++;
            }
        }

        if (cnt == 0) {
            ans = max(i, ans);
        }
    }
    cout << ans;
    return 0;
}