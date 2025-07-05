#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
int v[N];

void check_distance_range_invariant(int maxx, int minn) {
    if (maxx - minn > 1e9) { // Example threshold for large distances
        cerr << "Warning: Performance bottleneck condition triggered - large distance range!" << endl;
        abort();
    }
}

void check_divisor_density_invariant(int first_diff) {
    int divisor_count = 0;
    for (int i = 1; i * i <= first_diff; ++i) {
        if (first_diff % i == 0) {
            ++divisor_count;
            if (i != first_diff / i) ++divisor_count;
        }
    }
    if (divisor_count > 1000) { // Example threshold for high divisor density
        cerr << "Warning: Performance bottleneck condition triggered - high divisor density!" << endl;
        abort();
    }
}

void check_point_distribution_invariant(int* differences, int size) {
    int max_diff = *max_element(differences, differences + size);
    int min_diff = *min_element(differences, differences + size);
    if (max_diff - min_diff > 1e8) { // Example threshold for disparity
        cerr << "Warning: Performance bottleneck condition triggered - non-uniform point distribution!" << endl;
        abort();
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
    sort(v, v + n);
    int minn = v[0], maxx = v[n - 1];

    check_distance_range_invariant(maxx, minn); // Check for large distance range

    for (int i = 1; i < n; ++i) v[i - 1] = v[i] - v[i - 1];
    sort(v, v + n - 1);

    check_divisor_density_invariant(v[0]); // Check for high divisor density
    check_point_distribution_invariant(v, n - 1); // Check for non-uniform distribution

    int ans = maxx - minn + 1 - n;
    for (long long now = 1; now * now <= v[0]; ++now) {
        if (v[0] % now != 0) continue;
        int answer = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (v[i] % now != 0) {
                answer = -1;
                break;
            }
            answer += v[i] / now - 1;
        }
        if (answer != -1) ans = min(answer, ans);
        int then = now;
        now = v[0] / now;
        answer = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (v[i] % now != 0) {
                answer = -1;
                break;
            }
            answer += v[i] / now - 1;
        }
        if (answer != -1) ans = min(answer, ans);
        now = then;
    }
    printf("%d\n", ans);
    return 0;
}