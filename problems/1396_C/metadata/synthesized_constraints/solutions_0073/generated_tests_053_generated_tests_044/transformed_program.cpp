#include <bits/stdc++.h>
using namespace std;

long long seg[4000005];
long long lz[4000005];
long long dp[1000005];

// Checker Functions
void check_segment_tree_operations(long long n, long long totalSegmentTreeOps) {
    if (totalSegmentTreeOps > n * 10) { // Arbitrary multiplier to denote excessive operations.
        cerr << "Warning: Too many segment tree operations!" << endl;
        abort();
    }
}

void check_monster_count_strategy(long long n, const vector<long long>& a) {
    long long highMonsterStages = 0;
    for (long long monsters : a) {
        if (monsters > 1e5) { // High threshold for large counts of monsters.
            highMonsterStages++;
        }
    }
    if (highMonsterStages > n / 10) { // More than 10% of stages having a high monster count.
        cerr << "Warning: High monster counts in multiple stages!" << endl;
        abort();
    }
}

void check_level_transitions(long long n, long long d) {
    if (d > 1e8) { // Arbitrary large threshold for high teleportation time.
        cerr << "Warning: High teleportation time impacting transitions!" << endl;
        abort();
    }
}

void push(long long ver) {
    seg[2 * ver] += lz[ver];
    seg[2 * ver + 1] += lz[ver];
    lz[2 * ver] += lz[ver];
    lz[2 * ver + 1] += lz[ver];
    lz[ver] = 0;
}

void upd(long long ver, long long tl, long long tr, long long l, long long r, long long val) {
    if (tl > tr || l > r || tr < l || r < tl)
        return;
    else if (tl == l && tr == r) {
        seg[ver] += val;
        lz[ver] += val;
    } else {
        long long tm = (tl + tr) / 2;
        if (lz[ver]) push(ver);
        upd(2 * ver, tl, tm, l, min(tm, r), val);
        upd(2 * ver + 1, tm + 1, tr, max(tm + 1, l), r, val);
        seg[ver] = min(seg[2 * ver], seg[2 * ver + 1]);
    }
}

long long get(long long ver, long long tl, long long tr, long long l, long long r) {
    if (tl > tr || l > r || tr < l || r < tl)
        return 1e17;
    else if (tl == l && tr == r) {
        return seg[ver];
    } else {
        long long tm = (tl + tr) / 2;
        if (lz[ver]) push(ver);
        long long x = get(2 * ver, tl, tm, l, min(tm, r));
        long long y = get(2 * ver + 1, tm + 1, tr, max(tm + 1, l), r);
        seg[ver] = min(seg[2 * ver], seg[2 * ver + 1]);
        return min(x, y);
    }
}

long long n, r1, r2, r3, d;
vector<long long> a(1000005);
long long find(long long i) {
    long long x = a[i] * r1 + r1 * 2;
    long long y = r2 + r1;
    return min(x, y);
}

long long pah(long long i) {
    long long x = a[i] * r1 + r3;
    return x;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    cin >> n >> r1 >> r2 >> r3 >> d;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Insert checkers
    check_monster_count_strategy(n, a);
    check_level_transitions(n, d);

    dp[1] = pah(1);
    upd(1, 0, n, 1, 1, dp[1]);

    long long totalSegmentTreeOps = 0; // Track the number of segment tree operations
    for (long long i = 2; i <= n; i++) {
        if (i == 2)
            upd(1, 0, n, 0, i - 2, 3 * d + find(i - 1));
        else {
            upd(1, 0, n, i - 2, i - 2, 4 * d + find(i - 1));
            upd(1, 0, n, 0, i - 3, 3 * d + find(i - 1));
        }
        totalSegmentTreeOps += 3; // Count updates

        long long x = get(1, 0, n, 0, i - 2) + find(i);
        long long y = dp[i - 1] + pah(i) + d;
        dp[i] = min(x, y);
        upd(1, 0, n, i, i, dp[i]);
        totalSegmentTreeOps++; // Count update

        check_segment_tree_operations(n, totalSegmentTreeOps); // Check within the loop
    }

    long long ans = dp[n];
    long long sum = 0;
    for (long long i = n; i >= 1; i--) {
        if (i == n)
            sum += 2 * d + pah(i);
        else
            sum += 2 * d + find(i);
        ans = min(ans, dp[i - 1] + sum - d);
    }

    cout << ans;
}