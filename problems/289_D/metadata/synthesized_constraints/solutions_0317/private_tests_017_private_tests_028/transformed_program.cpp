#include <bits/stdc++.h>
const long long mod = (long long)1e9 + 7;
const bool debug = 0;

// Checker functions
void check_combination_explosion_invariant(int k, int n) {
    if (k == n) {
        cerr << "Warning: Performance bottleneck condition triggered - Combination explosion due to k being equal to n!" << endl;
        abort();
    }
}

void check_dfs_exploration_invariant(int k) {
    if (k > 7) {
        cerr << "Warning: Performance bottleneck condition triggered - High DFS exploration due to large k!" << endl;
        abort();
    }
}

void check_repeated_initialization_invariant(int k) {
    if (k > 7) {
        cerr << "Warning: Performance bottleneck condition triggered - Repeated initialization due to large k!" << endl;
        abort();
    }
}

long long solve(int n, int k) {
    // Check invariants related to performance bottlenecks
    check_combination_explosion_invariant(k, n);
    check_dfs_exploration_invariant(k);
    check_repeated_initialization_invariant(k);

    long long mul = 1;
    for (int i = k; i < n; ++i) {
        (mul *= (n - k)) %= mod;
    }
    int limit = 1;
    for (int i = 0; i < k; ++i) {
        limit *= k;
    }
    std::vector<int> next(k), prev(k), color(k), can(k);
    static int stack[16], size = 0;
    int answ = 0;
    for (int mask = 0; mask < limit; ++mask) {
        size = 0;
        for (int i = 0, temp = mask; i < k; ++i) {
            int div = temp / k;
            int rem = temp - div * k;
            next[i] = rem;
            prev[rem] = i;
            temp = div;
        }
        for (int i = 0; i < k; ++i) {
            color[i] = 0;
            can[i] = false;
        }
        bool flag = true;
        if (debug) {
            std::cout << std::string(40, '-') << std::endl;
            for (int i = 0; i < k; ++i) {
                printf("next[u=%d]=%d\n", i, next[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            if (color[i] == 0) {
                stack[size++] = i;
                color[i] = 1;
                while (size > 0) {
                    int u = stack[size - 1];
                    int v = next[u];
                    if (v == 0) {
                        can[u] = true;
                        --size;
                        color[u] = 2;
                    } else if (color[v] == 1) {
                        assert(can[v] == false);
                        can[u] = false;
                        can[v] = false;
                        color[u] = 2;
                        color[v] = 2;
                        --size;
                    } else if (color[v] == 2) {
                        can[u] = can[v];
                        color[u] = 2;
                        --size;
                    } else {
                        color[v] = 1;
                        stack[size++] = v;
                    }
                    if (debug) {
                        printf("\tvisit %d, next = %d, color = %d, can = %d\n", u, v, color[u], can[u]);
                    }
                }
            }
            if (debug) {
                printf("can[i=%d]=%d, size = %d\n", i, can[i], size);
            }
            if (!can[i]) {
                flag = false;
                break;
            }
        }
        answ += flag;
    }
    return answ * mul % mod;
}

int main() {
    int n, k;
    while (std::cin >> n >> k) {
        std::cout << solve(n, k) << std::endl;
    }
    return 0;
}