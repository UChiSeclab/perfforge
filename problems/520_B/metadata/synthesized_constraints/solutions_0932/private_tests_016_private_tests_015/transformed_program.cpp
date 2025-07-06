#include <bits/stdc++.h>
using namespace std;

// Invariant checkers
void check_large_search_space(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large search space exploration!" << endl;
        abort();
    }
}

void check_repeated_distance_updates(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated distance updates!" << endl;
        abort();
    }
}

void check_inefficient_node_processing(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient node processing!" << endl;
        abort();
    }
}

int main() {
    list<int> a[10001];
    int n, m, val, maxi, visited[10001], dist[10001];
    list<int>::iterator it;
    cin >> n >> m;

    if (n == m) {
        cout << "0";
    } else {
        for (int i = 1; i <= 10000; ++i) {
            if (i - 1 <= 10000) a[i].push_back(i - 1);
            if (i * 2 <= 10000) a[i].push_back(i * 2);
        }

        memset(visited, 0, sizeof(visited));
        for (int i = 0; i <= 10000; ++i) dist[i] = INT_MAX;
        dist[n] = 0;

        // Check for large search space before entering the main loop
        check_large_search_space(n <= m && m > n * 2);

        for (int i = 0; i < 10000; ++i) {
            maxi = INT_MAX;

            // Check for repeated distance updates
            check_repeated_distance_updates(dist[m] != INT_MAX && dist[m] <= i + 1);

            for (int j = 0; j <= 10000; ++j) {
                if (!visited[j] && dist[j] < maxi) {
                    val = j;
                    maxi = dist[j];
                }
            }

            visited[val] = 1;
            if (val == m) break;

            // Check for inefficient node processing
            check_inefficient_node_processing(visited[m] != 1 && i > m / 2);

            for (it = a[val].begin(); it != a[val].end(); ++it) {
                if (!visited[*it] && dist[*it] > dist[val] + 1)
                    dist[*it] = dist[val] + 1;
            }
        }
        cout << dist[m];
    }
}