#include <bits/stdc++.h>
const static int INF = 0x3f3f3f3f;
static inline void setio(void);
int n, m;
int stuff[101][101];
int sizes[101];
int memo2[101][101][101];
int memo[101][10001];
int best[101][101];
int m_start, which_row;

// Check for deep recursion and excessive recursive calls
void check_deep_recursion_invariant(int recDepth, int recCalls) {
    if (recDepth > 50 || recCalls > 100000) {
        std::cerr << "Warning: Performance bottleneck condition triggered due to deep recursion or excessive recursive calls!" << std::endl;
        abort();
    }
}

// Check for inefficient pruning in recursive calls
void check_pruning_invariant(int memoizedStates, int maxAllowedStates) {
    if (memoizedStates > maxAllowedStates) {
        std::cerr << "Warning: Performance bottleneck condition triggered due to inefficient state pruning!" << std::endl;
        abort();
    }
}

// Check for nested loop overhead
void check_nested_loop_invariant(int ml, int threshold) {
    if (ml > threshold) {
        std::cerr << "Warning: Performance bottleneck condition triggered due to excessive nested loop iterations!" << std::endl;
        abort();
    }
}

int go1(const int& i, const int& j, const int& ml, int recDepth) {
    check_deep_recursion_invariant(recDepth, 0); // Check recursion depth
    if (ml <= 0) return 0;
    if (i > j) return 0;
    int& ret = memo2[i][j][ml];
    if (ret != -1) return ret;
    ret = 0;
    ret = std::max(ret, stuff[which_row][i] + go1(i + 1, j, ml - 1, recDepth + 1));
    ret = std::max(ret, stuff[which_row][j] + go1(i, j - 1, ml - 1, recDepth + 1));
    return ret;
}

int go2(const int& row, const int& ml) {
    if (row >= n) return 0;
    int& ret = memo[row][ml];
    if (ret != -1) return ret;
    ret = 0;
    check_nested_loop_invariant(ml, 75); // Check nested loop overhead
    for (int i = 0; i <= std::min(ml, sizes[row]); ++i)
        ret = std::max(ret, best[row][i] + go2(row + 1, ml - i));
    return ret;
}

int main(void) {
    setio();
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> sizes[i];
        for (int j = 0; j < sizes[i]; ++j) std::cin >> stuff[i][j];
        memset(memo2, 0xff, sizeof(memo));
        best[i][0] = 0;
        which_row = i;
        for (int spend = 1; spend <= sizes[i]; ++spend)
            best[i][spend] = go1(0, sizes[i] - 1, m_start = spend, 1);
    }
    memset(memo, 0xff, sizeof(memo));
    std::cout << go2(0, m) << "\n";
    return 0;
}

static inline void setio(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.precision(10);
    std::cout << std::fixed;
}