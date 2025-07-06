#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
long long vis[400001];
int vis2[200001];

// Check function for prefix sum calculation
void check_prefix_sum_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to full prefix sum calculation!" << endl;
        abort();
    }
}

// Check function for nested loops
void check_nested_loop_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to extensive nested loop iterations!" << endl;
        abort();
    }
}

// Check function for absence of low-power cards
void check_low_power_card_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered due to absence of low-power video cards!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    long long sum1 = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        vis[a]++;
        vis2[a] = 1;
        sum1 += a;
    }

    // Check for the absence of low-power cards
    check_low_power_card_invariant(vis[1] == 0);

    long long mx = 0;
    if (vis[1]) {
        cout << sum1 << endl;
    } else {
        // Check for potential bottleneck in prefix sum calculation
        check_prefix_sum_invariant(true);

        for (int i = 1; i <= 400000; i++) {
            vis[i] += vis[i - 1];
        }
        for (int i = 2; i <= 200000; i++) {
            if (vis2[i] == 0) continue;

            long long sum = (vis[2 * i - 1] - vis[i - 1]) * i;

            // Check for potential bottleneck in nested loop
            check_nested_loop_invariant(true);

            for (int j = i * 2; j <= 400000 - i; j += i) {
                sum += (vis[i + j - 1] - vis[j - 1]) * j;
            }
            mx = max(mx, sum);
        }
        cout << mx << endl;
    }
    return 0;
}