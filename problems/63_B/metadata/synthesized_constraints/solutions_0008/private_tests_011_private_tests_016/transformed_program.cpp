#include <bits/stdc++.h>
using namespace std;
const double EPS = (1e-7);
double PI = 3.1415926535897932384626433832795;
int arr[123456];

void check_nested_loop_invariant(int n, int k, const int* arr) {
    int uniformLowRankCount = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 1) {
            uniformLowRankCount++;
        }
    }
    if (n > 90 && uniformLowRankCount > 90) {
        cerr << "Warning: Performance bottleneck due to high frequency of nested loop execution!" << endl;
        abort();
    }
}

void check_repeated_increment_invariant(int n, int k, const int* arr) {
    if (n > 90 && arr[0] == 1 && arr[n-1] != k) {
        cerr << "Warning: Performance bottleneck due to repeated increment operations for low initial ranks!" << endl;
        abort();
    }
}

void check_uniform_ranks_invariant(int n, int k, const int* arr) {
    int minRank = arr[0];
    if (n > 90 && minRank < k) {
        cerr << "Warning: Performance bottleneck due to high iteration count from uniform low ranks!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    // Inserted checks after input
    check_nested_loop_invariant(n, k, arr);
    check_repeated_increment_invariant(n, k, arr);
    check_uniform_ranks_invariant(n, k, arr);

    int ans = 0;
    if (n == 1) ans = max(0, k - arr[0]);
    for (int i = 0; i < 100000; ++i) {
        bool b = 0;
        for (int j = 0; j < n - 1; ++j) {
            if (arr[j] != arr[j + 1] && arr[j] < k) {
                arr[j]++;
                b = 1;
            }
            if (j == n - 2 && arr[j + 1] < k) {
                arr[j + 1]++;
                b = 1;
            }
        }
        ans += b;
    }
    cout << ans;
    return 0;
}