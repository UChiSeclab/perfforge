#include <bits/stdc++.h>
using namespace std;
int h[100005];
int n, a, r, m;

// Check for high variation in initial pillar heights
void check_high_variation_invariant(const vector<int>& heights) {
    int min_height = *min_element(heights.begin(), heights.end());
    int max_height = *max_element(heights.begin(), heights.end());
    if (max_height - min_height > 100000) {
        cerr << "Warning: Performance bottleneck due to high variation in pillar heights!" << endl;
        abort();
    }
}

// Check for large search space for target heights
void check_large_search_space_invariant(int min_height, int max_height) {
    if (max_height - min_height > 100000) {
        cerr << "Warning: Performance bottleneck due to large search space for target heights!" << endl;
        abort();
    }
}

// Check for frequent brick movements or adjustments
void check_frequent_movements_invariant(long long dp, long long dm) {
    if (dp > 1000000 || dm > 1000000) {
        cerr << "Warning: Performance bottleneck due to frequent brick movements or adjustments!" << endl;
        abort();
    }
}

long long costMv(long long x, long long y) {
    return x * m + y * (a + r);
}

long long cost(int target) {
    long long dp = 0;
    long long dm = 0;
    for (int(i) = 0; (i) < (n); (i)++) {
        if (h[i] > target) {
            dp += h[i] - target;
        }
        if (h[i] < target) {
            dm += target - h[i];
        }
    }
    // Check for frequent movements condition
    check_frequent_movements_invariant(dp, dm);

    long long mv = min(dp, dm);
    long long ans = (dp - mv) * r + (dm - mv) * a;
    long long l = 0, r = mv;
    while (r - l > 2) {
        long long m1 = l + (r - l) / 3;
        long long m2 = r - (r - l) / 3;
        if (costMv(m1, mv - m1) > costMv(m2, mv - m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    long long tmp = costMv(l, mv - l);
    for (long long i = l; i <= r; i++) {
        tmp = min(tmp, costMv(i, mv - i));
    }
    ans += tmp;
    return ans;
}

int main(void) {
    scanf("%d%d%d%d", &n, &a, &r, &m);
    vector<int> heights(n);
    for (int(i) = 0; (i) < (n); (i)++) {
        scanf("%d", &h[i]);
        heights[i] = h[i];
    }

    // Check for high variation in initial pillar heights
    check_high_variation_invariant(heights);

    int l = 0, r = 1000000000;
    while (r - l > 2) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (cost(m1) > cost(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    long long ans = cost(l);
    for (int(i) = (l); (i) < (r + 1); (i)++) {
        ans = min(ans, cost(i));
    }

    // Check for large search space for target heights
    check_large_search_space_invariant(l, r);

    printf("%lld\n", ans);
}