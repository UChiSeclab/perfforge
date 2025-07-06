#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 11;
const int MAXN = maxn;
const long long oo = 0x3f3f3f3f3f3f3f3f;
const long long ooo = 0x3f3f3f3f;

// Checker Functions
void check_network_flow_complexity(int n, int m, const vector<int>& a, const vector<int>& b) {
    int threshold = 100; 
    if (n > threshold || m > threshold) {
        cerr << "Warning: Network flow complexity invariant triggered - large number of cards" << endl;
        abort();
    }
}

void check_conditional_loop_invariant(int A, int B, const vector<int>& a, const vector<int>& b, const vector<bool>& type) {
    int validCombinations = 0;
    for (int j = 0; j < B; ++j) {
        for (int k = 0; k < A; ++k) {
            if ((type[k] == 0 && b[j] > a[k]) || (type[k] == 1 && b[j] >= a[k])) {
                validCombinations++;
                if (validCombinations > 2000) {
                    cerr << "Warning: Conditional loop invariant triggered - too many valid combinations" << endl;
                    abort();
                }
            }
        }
    }
}

void check_spfa_iterations(int iterationCount) {
    int iterationThreshold = 10000;
    if (iterationCount > iterationThreshold) {
        cerr << "Warning: SPFA iterations invariant triggered - excessive iterations" << endl;
        abort();
    }
}

// Original Program
long long read() {
    long long x = 0, f = 1;
    register char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int to[maxn << 1], nxt[maxn << 1];
long long cost[maxn << 1], cap[maxn << 1], flow[maxn << 1];
int head[maxn], tot;
void init() {
    memset(head, -1, sizeof head);
    tot = 0;
}
void add(int u, int v, long long c, long long w) {
    to[tot] = v;
    cap[tot] = c;
    flow[tot] = 0;
    cost[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot++;
    swap(u, v);
    to[tot] = v;
    cap[tot] = 0;
    flow[tot] = 0;
    cost[tot] = -w;
    nxt[tot] = head[u];
    head[u] = tot++;
}
struct QUEUE {
    int que[maxn];
    int front, rear;
    void init() { front = rear = 0; }
    void push(int x) { que[rear++] = x; }
    int pop() { return que[front++]; }
    bool empty() { return front == rear; }
} que;
int n, m, s, t;
bool vis[maxn];
long long pre[maxn], dis[maxn];
bool spfa() {
    que.init();
    memset(vis, 0, sizeof vis);
    memset(pre, -1, sizeof pre);
    memset(dis, 0x3f, sizeof dis);
    que.push(s);
    vis[s] = 1;
    dis[s] = 0;
    int iterationCount = 0; // Track iterations
    while (!que.empty()) {
        int u = que.pop();
        vis[u] = 0;
        for (int i = head[u]; ~i; i = nxt[i]) {
            long long v = to[i], c = cap[i], f = flow[i], w = cost[i];
            if (c > f && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pre[v] = i;
                if (!vis[v]) {
                    que.push(v);
                    vis[v] = 1;
                }
            }
        }
        iterationCount++;
    }
    check_spfa_iterations(iterationCount); // Check for excessive iterations
    return dis[t] != oo;
}
long long mcmf() {
    long long mc = 0, mf = 0;
    while (spfa()) {
        long long tf = oo + 1;
        for (int i = pre[t]; ~i; i = pre[to[i ^ 1]]) {
            tf = min(tf, cap[i] - flow[i]);
        }
        mf += tf;
        for (int i = pre[t]; ~i; i = pre[to[i ^ 1]]) {
            flow[i] += tf;
            flow[i ^ 1] -= tf;
        }
        mc += dis[t] * tf;
    }
    return mc;
}
int a[MAXN], b[MAXN];
bool type[MAXN];
char str[MAXN];
int main() {
    while (cin >> n >> m) {
        vector<int> a(n+1), b(m+1);
        vector<bool> type(n+1);
        for (int i = 1; i <= n; i++) {
            scanf("%s", str + 1);
            a[i] = read();
            if (str[1] == 'A')
                type[i] = 1;
            else
                type[i] = 0;
        }
        for (int i = 1; i <= m; i++) b[i] = read();
        
        // Check for potential performance bottlenecks
        check_network_flow_complexity(n, m, a, b);
        check_conditional_loop_invariant(n, m, a, b, type);

        long long mx = 0;
        init();
        s = 2 * n + m + 1;
        t = s + 1;
        int ss = t + 1;
        n = ss;
        for (int j = 1; j <= m; j++) add(ss, j, 1, 0);
        for (int j = 1; j <= n; j++) add(m + j, m + n + j, 1, -2ll * ooo);
        for (int j = 1; j <= n; j++) add(m + n + j, t, 1, 0);
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                if (type[k] == 0 && b[j] > a[k])
                    add(j, m + k, 1, ooo);
                else if (type[k] == 1 && b[j] >= a[k])
                    add(j, m + k, 1, ooo - (b[j] - a[k]));
            }
        }
        for (int j = 1; j <= m; j++) add(j, t, 1, ooo - b[j]);
        add(s, ss, 666, 0);
        for (int i = 1; i <= m; i++) {
            for (int i = 0; i <= tot - 1; i++) flow[i] = 0;
            cap[tot - 2] = i;
            long long mc = mcmf();
            if (i <= n) {
                mc += ooo * i;
                mc = -mc;
            } else {
                mc += ooo * n;
                mc -= ooo * (i - n);
                mc = -mc;
            }
            mx = max(mx, mc);
        }
        printf("%lld\n", (long long)(mx));
    }
    return 0;
}