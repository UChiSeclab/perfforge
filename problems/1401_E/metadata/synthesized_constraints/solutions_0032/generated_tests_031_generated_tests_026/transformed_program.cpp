#include <bits/stdc++.h>

const int N = 1e6 + 5;

int lowbit(int x) { return x & -x; }

struct Fenwick {
    int c[N];
    void update(int x, int y) {
        for (; x < N; x += lowbit(x)) c[x] += y;
    }
    int query(int x) {
        int answer = 0;
        for (; x > 0; x ^= lowbit(x)) answer += c[x];
        return answer;
    }
} bit;

int n, m;
std::vector<std::pair<int, int>> v[N];
struct que {
    int x, l, r;
} q[N];

bool cmp(que x, que y) { return x.x < y.x; }

// Function to check extensive segment range processing
void check_extensive_segment_range(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive segment range processing!" << endl;
        abort();
    }
}

// Function to check large intersection range handling
void check_large_intersection_range(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large intersection range handling!" << endl;
        abort();
    }
}

// Function to check input pattern effect on query execution
void check_input_pattern_impact(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - input pattern affecting query execution!" << endl;
        abort();
    }
}

int main() {
    int64_t answer = 1;
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        int x, l, r;
        scanf("%d %d %d", &x, &l, &r);
        if (l == 0 && r == 1e6) ++answer;
        v[l].emplace_back(x, 1);
        v[r + 1].emplace_back(x, -1);
    }
    
    for (int i = 1; i <= m; i++) {
        int x, l, r;
        scanf("%d %d %d", &x, &l, &r);
        if (l == 0 && r == 1e6) ++answer;
        q[i] = {x, l, r};
    }
    
    // Check large intersection range after input is read
    check_large_intersection_range((n > 0 && m > 0) && (q[1].l == 0 && q[1].r == 1e6));

    std::sort(q + 1, q + m + 1, cmp);
    
    int cur = 0;
    for (int i = 1; i <= m; i++) {
        while (cur <= q[i].x) {
            for (auto j : v[cur]) {
                bit.update(j.first, j.second);
            }
            ++cur;
        }
        // Check input pattern impact just before heavy query execution
        check_input_pattern_impact(q[i].r - q[i].l > 500000);

        // Check extensive segment range processing
        check_extensive_segment_range(cur > 900000);

        answer += bit.query(q[i].r) - bit.query(q[i].l - 1);
    }
    
    printf("%lld\n", answer);
    return 0;
}