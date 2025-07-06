#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int x, y;
int dis[N];

// Check for high recursion depth and branching factor
void check_recursion_depth_and_branching(int n, int m, int currentDepth) {
    if (n < m && currentDepth > 50) {
        cerr << "Warning: High recursion depth and branching factor detected!" << endl;
        abort();
    }
}

// Check for frequent updates to the state array
void check_state_array_updates(int n, int m, int* dis, int currentNumber) {
    if (n < m && dis[currentNumber] != 0x3f3f3f3f) {
        cerr << "Warning: Frequent state array updates detected!" << endl;
        abort();
    }
}

// Check for excessive recursive search path
void check_excessive_recursive_search(int n, int m, int currentNumber) {
    if (n < m && currentNumber < m / 2) {
        cerr << "Warning: Excessive recursive search path detected!" << endl;
        abort();
    }
}

void dfs(int now, int d) {
    check_recursion_depth_and_branching(x, y, d); // Insert check for recursion depth
    check_excessive_recursive_search(x, y, now);  // Insert check for search path

    if (dis[now] <= d) return;
    dis[now] = d;
    check_state_array_updates(x, y, dis, now); // Insert check for state array updates

    if (now >= y) {
        dis[y] = min(dis[y], d + now - y);
        return;
    }

    dfs(now * 2, d + 1);
    if (now > 1) dfs(now - 1, d + 1);
}

int main() {
    cin >> x >> y;
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dfs(x, 0);
    cout << dis[y] << endl;
    return 0;
}