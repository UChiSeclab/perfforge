#include <bits/stdc++.h>
using namespace std;

// Checker function for large ctx with small oty
void check_large_ctx_small_oty(long long ctx, long long oty) {
    if (ctx > 1000000 && oty <= 2) {
        cerr << "Warning: Performance bottleneck condition triggered - Large ctx with small oty!" << endl;
        abort();
    }
}

// Checker function for small increment steps towards a large target
void check_small_increment_large_target(long long ctx, long long copies) {
    if (ctx - copies > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - Small increment towards large target!" << endl;
        abort();
    }
}

int main() {
    long long ctx, oty;
    cin >> ctx >> oty;

    // Check for the first invariant
    check_large_ctx_small_oty(ctx, oty);

    long long original = 1, copies = 0;
    while (original < oty) {
        copies++;
        original++;
    }

    if (original == oty && copies == ctx) {
        cout << "Yes" << endl;
        return 0;
    }

    // Check for the second invariant before starting the loop
    check_small_increment_large_target(ctx, copies);

    while (copies < ctx && copies != 0) {
        copies += 2;
        if (original == oty && copies == ctx) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}