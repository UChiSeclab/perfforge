#include <bits/stdc++.h>
using namespace std;

long long read() {
    long long res = 0;
    bool f = false;
    char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + ch - '0', ch = getchar();
    return f ? -res : res;
}

void write(long long in) {
    if (in < 0) {
        putchar('-'), write(-in);
        return;
    }
    if (in > 9) write(in / 10);
    putchar(in % 10 + '0');
}

int n, a = 0;
struct Node {
    int lt, rt, ans;
} T[4000005];

void update(int num) {
    T[num].ans = T[T[num].lt].ans + T[T[num].rt].ans;
}

int build(int l, int r) {
    int now = ++a;
    if (l == r) {
        T[now].ans = 1;
        return now;
    }
    int mid = (l + r) >> 1;
    T[now].lt = build(l, mid);
    T[now].rt = build(mid + 1, r);
    update(now);
    return now;
}

int ask(int num, int l, int r, int f, int t) {
    if (f > t) return 0;
    if (f <= l && r <= t) {
        return T[num].ans;
    }
    int mid = (l + r) >> 1, res = 0;
    if (f <= mid) res += ask(T[num].lt, l, mid, f, t);
    if (t > mid) res += ask(T[num].rt, mid + 1, r, f, t);
    return res;
}

void down(int num, int l, int r, int s) {
    if (l == r) {
        T[num].ans = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (s <= mid)
        down(T[num].lt, l, mid, s);
    else
        down(T[num].rt, mid + 1, r, s);
    update(num);
}

struct EL {
    int ele, num;
} M[1000005];

bool cmp(EL x, EL y) { return x.ele > y.ele; }
long long ans = 0;
int root;

// Invariant Check 1: Detects when the sequence has many elements with equal absolute values
void check_frequent_updates_invariant(int current, int previous) {
    if (current == previous) {
        cerr << "Warning: Frequent updates in the segment tree due to similar absolute values!" << endl;
        abort();
    }
}

// Invariant Check 2: Detects when querying ranges becomes frequent due to high potential inversions
void check_high_query_invariant(int queries, int threshold) {
    if (queries > threshold) {
        cerr << "Warning: High query overhead in the segment tree!" << endl;
        abort();
    }
}

int main() {
    n = read();
    int query_count = 0;
    for (int i = 1; i <= n; i++) M[i].ele = abs(read()), M[i].num = i;
    
    sort(M + 1, M + 1 + n, cmp);
    root = build(1, n);
    M[0].ele = -1;
    
    for (int i = 1; i <= n; i++) {
        check_frequent_updates_invariant(M[i].ele, M[i - 1].ele);  // Check for frequent updates
        
        if (M[i].ele != M[i - 1].ele)
            for (int j = i; M[j].ele == M[i].ele; j++) down(root, 1, n, M[j].num);
        
        ans += min(ask(root, 1, n, 1, M[i].num - 1), ask(root, 1, n, M[i].num + 1, n));
        query_count++;
    }
    
    // Set an estimated threshold for queries based on typical input sizes
    check_high_query_invariant(query_count, n * log2(n));  // Check for high query overhead
    
    write(ans);
    return 0;
}