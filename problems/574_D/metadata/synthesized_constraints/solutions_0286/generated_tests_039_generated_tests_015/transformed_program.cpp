#include <bits/stdc++.h>
using namespace std;

long long int tree[100001 * 10];
long long int lazy[100001 * 10];
long long int arr[100001];

// Checkers
void check_recursive_operations_invariant(int n, int recursiveDepth) {
    if (n > 100000 && recursiveDepth > log2(n) + 10) {
        cerr << "Warning: Performance bottleneck condition triggered - recursive operations on segment trees are too deep!" << endl;
        abort();
    }
}

void check_update_frequency_invariant(int updateCount, int threshold) {
    if (updateCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - high frequency of updates on segment tree!" << endl;
        abort();
    }
}

void check_repeated_heights_invariant(const vector<int>& heights) {
    int maxCount = 0;
    unordered_map<int, int> heightFrequency;
    for (int height : heights) {
        heightFrequency[height]++;
        maxCount = max(maxCount, heightFrequency[height]);
    }
    if (maxCount > heights.size() / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated heights pattern in input!" << endl;
        abort();
    }
}

void check_segment_tree_size_invariant(int n) {
    if (n > 100000) {
        cerr << "Warning: Performance bottleneck condition triggered - segment tree size constraint exceeded!" << endl;
        abort();
    }
}

void build_tree(int node, int a, int b, int& recursiveDepth) {
    check_recursive_operations_invariant(b - a + 1, recursiveDepth);

    if (a > b) return;
    if (a == b) {
        tree[node] = arr[a] + a;
        return;
    }
    recursiveDepth++;
    build_tree(node * 2, a, (a + b) / 2, recursiveDepth);
    build_tree(node * 2 + 1, 1 + (a + b) / 2, b, recursiveDepth);
    recursiveDepth--;
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

void update_tree(int node, int a, int b, int i, int j, int value, int& updateCount) {
    check_update_frequency_invariant(updateCount, 1000); // Arbitrary threshold for demo purposes
    updateCount++;

    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        if (a != b) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (a > b || a > j || b < i) return;
    if (a >= i && b <= j) {
        tree[node] += value;
        if (a != b) {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }
    update_tree(node * 2, a, (a + b) / 2, i, j, value, updateCount);
    update_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j, value, updateCount);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query_tree(int node, int a, int b, int i, int j) {
    if (a > b || a > j || b < i) return 1000000007;
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        if (a != b) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (a >= i && b <= j) return tree[node];
    int q1 = query_tree(node * 2, a, (a + b) / 2, i, j);
    int q2 = query_tree(1 + node * 2, 1 + (a + b) / 2, b, i, j);
    int res = min(q1, q2);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    check_segment_tree_size_invariant(n);

    vector<int> heights(n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
        heights[i - 1] = arr[i];
    }
    arr[0] = arr[n + 1] = 0;
    check_repeated_heights_invariant(heights);

    int recursiveDepth = 0;
    build_tree(1, 0, n + 1, recursiveDepth);

    int ans = 0;
    int updateCount = 0;
    for (int i = 1; i <= n; i++) {
        update_tree(1, 0, n + 1, 0, i - 1, 1, updateCount);
        update_tree(1, 0, n + 1, i, n + 1, -1, updateCount);
        ans = max(ans, query_tree(1, 0, n + 1, 0, n + 1));
    }
    printf("%d\n", ans);
    return 0;
}