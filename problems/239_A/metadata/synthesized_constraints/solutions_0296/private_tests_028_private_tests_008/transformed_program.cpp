#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// Invariant checkers as implemented above
void check_y_n_invariant(long long y, long long n) {
    if (y > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - y is too large compared to n!" << endl;
        abort();
    }
}

void check_k_n_invariant(long long k, long long n) {
    if (k < n / 1000) {
        cerr << "Warning: Performance bottleneck condition triggered - k is too small compared to n!" << endl;
        abort();
    }
}

void check_skipped_iterations(long long y, long long n, long long k) {
    if (y > n && n % k != 0) {
        cerr << "Warning: Performance bottleneck condition triggered - many iterations skipped due to s <= y!" << endl;
        abort();
    }
}

int main() {
    long long y, k, n;
    scanf("%I64d", &y);
    scanf("%I64d", &k);
    scanf("%I64d", &n);

    // Check for potential performance bottlenecks
    check_y_n_invariant(y, n);
    check_k_n_invariant(k, n);
    check_skipped_iterations(y, n, k);

    long long s;
    vector<int> ans;
    for (long long i = 1; i < 100001ll; i++) {
        s = i * k;
        if (s > n) break;
        if (s <= y)
            continue;
        else {
            ans.push_back((int)(s - y));
        }
    }
    if (ans.size() == 0)
        cout << -1;
    else {
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    }
    return 0;
}