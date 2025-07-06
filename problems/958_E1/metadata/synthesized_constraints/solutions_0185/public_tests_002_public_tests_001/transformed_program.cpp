#include <bits/stdc++.h>
using namespace std;
const int maxn = 12;
int R, B;
struct Point {
    int x, y;
    void read() { scanf("%d%d", &x, &y); }
    Point operator-(const Point &o) const { return (Point){x - o.x, y - o.y}; }
    int operator*(const Point &o) const { return x * o.y - y * o.x; }
} RP[maxn], BP[maxn];
bool intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
    if (((c - b) * (d - b)) * ((c - a) * (d - a)) > 0) return false;
    if (((a - c) * (b - c)) * ((a - d) * (b - d)) > 0) return false;
    return true;
}
int M[maxn];
bool used[maxn];

void check_complex_intersection_condition(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - complex intersection scenarios!" << endl;
        abort();
    }
}

void check_dfs_recursion_depth(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth or many intersection checks in DFS!" << endl;
        abort();
    }
}

void check_frequent_intersection_checks(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent intersection checks due to close geometric configurations!" << endl;
        abort();
    }
}

bool check(int p) {
    // Check if a complex intersection configuration is causing performance issues.
    check_complex_intersection_condition(p > 5); // Example threshold for complex configurations.
    for (int i = 0; i < p; ++i)
        if (intersect(RP[i], BP[M[i]], RP[p], BP[M[p]])) return false;
    return true;
}

void dfs(int p) {
    // Check for excessive DFS recursion depth or frequent intersection checks.
    check_dfs_recursion_depth(p > 7); // Example threshold for recursion depth.
    if (p >= R) {
        throw 1;
    }
    for (int i = 0; i < R; ++i)
        if (!used[i]) {
            M[p] = i;
            used[i] = true;
            if (check(p)) {
                dfs(p + 1);
            }
            used[i] = false;
        }
}

int main() {
    scanf("%d%d", &R, &B);
    for (int i = 0; i < R; ++i) RP[i].read();
    for (int i = 0; i < B; ++i) BP[i].read();
    if (R != B) {
        printf("No\n");
        return 0;
    }

    // Check for frequent intersection checks due to input configurations.
    check_frequent_intersection_checks(R * B > 50); // Example threshold for frequent checks.

    try {
        dfs(0);
    } catch (int) {
        printf("Yes\n");
        return 0;
    }
    printf("No\n");
}