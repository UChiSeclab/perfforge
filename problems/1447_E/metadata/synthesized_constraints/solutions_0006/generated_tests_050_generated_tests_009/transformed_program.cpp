#include <bits/stdc++.h>
const int maxn = 2e5 + 10;
int n;
long long a[maxn];
int ans = 0;
std::set<long long> p;

// Checker functions for performance invariants
void check_recursive_depth_invariant(bool condition) {
    if (condition) {
        std::cerr << "Warning: Performance bottleneck condition triggered - excessive recursion depth due to high bit diversity!" << std::endl;
        abort();
    }
}

void check_set_operations_invariant(bool condition) {
    if (condition) {
        std::cerr << "Warning: Performance bottleneck condition triggered - excessive set operations due to closely packed numbers!" << std::endl;
        abort();
    }
}

void check_recursive_branching_invariant(bool condition) {
    if (condition) {
        std::cerr << "Warning: Performance bottleneck condition triggered - non-empty recursive branches leading to excessive computation!" << std::endl;
        abort();
    }
}

int solve(int bit, std::set<long long> p) {
    if (bit == 0) return p.size();

    int currentDepth = 30 - bit;
    check_recursive_depth_invariant(currentDepth > 20);

    int ret = 0;
    std::set<long long> a[2];
    for (auto i : p) {
        a[(i >> (bit - 1)) & 1].insert(i);
    }

    check_set_operations_invariant(p.size() > 100 && currentDepth > 15);

    if (a[0].empty()) {
        ret = solve(bit - 1, a[1]);
    } else if (a[1].empty()) {
        ret = solve(bit - 1, a[0]);
    } else {
        check_recursive_branching_invariant(!a[0].empty() && !a[1].empty() && currentDepth > 10);
        ret = std::max(solve(bit - 1, a[0]), solve(bit - 1, a[1])) + 1;
    }

    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        p.insert(a[i]);
    }
    printf("%d\n", n - solve(30, p));
}