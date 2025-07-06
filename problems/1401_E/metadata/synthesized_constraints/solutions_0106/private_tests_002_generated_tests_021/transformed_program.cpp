#include <bits/stdc++.h>
using namespace std;

int bit[1000005];
inline int lowbit(int x) { return x & -x; }
void add(int pos, int val) {
    pos++;
    while (pos < 1000005) {
        bit[pos] += val;
        pos += lowbit(pos);
    }
}
int sum(int pos) {
    pos++;
    int ret = 0;
    while (pos > 0) {
        ret += bit[pos];
        pos -= lowbit(pos);
    }
    return ret;
}
int query(int l, int r) { return sum(r) - (l == 0 ? 0 : sum(l - 1)); }
struct hline {
    int y, l, r;
} arr[100005];
struct vline {
    int x, u, d;
} brr[100005];

// Checker functions
void check_fenwick_tree_update(bool condition) {
    if (condition) {
        cerr << "Warning: Fenwick tree update overhead condition triggered!" << endl;
        abort();
    }
}

void check_segment_overlap(bool condition) {
    if (condition) {
        cerr << "Warning: Segment overlap or length condition triggered!" << endl;
        abort();
    }
}

void check_input_symmetry(bool condition) {
    if (condition) {
        cerr << "Warning: Input symmetry and alignment condition triggered!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) cin >> arr[i].y >> arr[i].l >> arr[i].r;
    for (int i = 1; i <= m; i++) cin >> brr[i].x >> brr[i].u >> brr[i].d;

    // Check for segment overlap or length
    for (int i = 1; i <= n; i++) {
        check_segment_overlap(arr[i].r - arr[i].l > 900000); // Example threshold
    }
    for (int i = 1; i <= m; i++) {
        check_segment_overlap(brr[i].d - brr[i].u > 900000); // Example threshold
    }

    sort(arr + 1, arr + 1 + n, [=](hline a, hline b) -> bool { return a.y < b.y; });
    sort(brr + 1, brr + 1 + m, [=](vline a, vline b) -> bool { return a.u < b.u; });

    int cur1 = 1, cur2 = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    long long ans = 1;

    for (int y = 0; y < 1000000; y++) {
        while (cur2 <= m && brr[cur2].u == y) {
            int x = brr[cur2].x, d = brr[cur2].d;
            add(x, 1);
            pq.push({d, x});
            if (d - y == 1000000) ans++;
            cur2++;

            // Check potential Fenwick tree update overhead
            check_fenwick_tree_update(d - y > 800000); // Example threshold
        }
        while (cur1 <= n && arr[cur1].y == y) {
            int l = arr[cur1].l, r = arr[cur1].r;
            ans += query(l, r);
            if (r - l == 1000000) ans++;
            cur1++;
        }
        while (!pq.empty() && pq.top().first == y) {
            int x = pq.top().second;
            pq.pop();
            add(x, -1);
        }
    }

    // Check for input symmetry
    check_input_symmetry(n == m && m > 50000); // Example condition

    cout << ans << endl;
    return 0;
}