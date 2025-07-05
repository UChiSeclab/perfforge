#include <bits/stdc++.h>
using namespace std;

int arr[501];
bool vis[501][501][501];
bool anw[501][501][501];

// Checkers for performance bottlenecks
void check_combination_complexity(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high combination complexity!" << endl;
        abort();
    }
}

void check_large_close_values_with_large_k(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large and close coin values with large k!" << endl;
        abort();
    }
}

void check_max_recursive_depth(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - maximal recursive depth!" << endl;
        abort();
    }
}

bool dp(int id, int sb, int sum) {
    if (sum + sb == 0) return anw[id][sb][sum] = 1;
    if (id == 0) return anw[id][sb][sum] = 0;
    if (vis[id][sb][sum]) return anw[id][sb][sum];
    vis[id][sb][sum] = 1;
    bool ws = dp(id - 1, sb, sum);
    if (sum - arr[id - 1] >= 0) {
        if (sb - arr[id - 1] >= 0)
            ws |= dp(id - 1, sb - arr[id - 1], sum - arr[id - 1]);
        ws |= dp(id - 1, sb, sum - arr[id - 1]);
    }
    return anw[id][sb][sum] = ws;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    // Check for large combination complexity
    check_combination_complexity(n > 10 && k > 250); // Example threshold
    
    // Check for large and close coin values with large k
    sort(arr, arr + n);
    bool close_values = true;
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] > 5) { // Example close threshold
            close_values = false;
            break;
        }
    }
    check_large_close_values_with_large_k(close_values && k > 250); // Example threshold

    // Check max recursive depth
    check_max_recursive_depth(k > 400); // Example threshold for k
    
    vector<int> tp;
    for (int i = 0; i <= k; i++)
        if (dp(n, i, k)) tp.push_back(i);
    printf("%d\n", int(tp.size()));
    for (int i = 0; i < tp.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", tp[i]);
    }
    printf("\n");
}