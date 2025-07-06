#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_map_size_invariant(int mapSize, int threshold) {
    if (mapSize > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - large map size leading to high combinatorial complexity!" << endl;
        abort();
    }
}

void check_repeated_updates_invariant(int iterationCount, int threshold) {
    if (iterationCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated updates in nested loops!" << endl;
        abort();
    }
}

void check_valid_combinations_invariant(int combinationsCount, int threshold) {
    if (combinationsCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - too many valid combinations!" << endl;
        abort();
    }
}

int a[(int)1e5 + 1000], b[(int)1e5 + 1000];
int FF[(int)1e5 + 1000];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) b[i] *= k;
    for (int i = 1; i <= n; i++) FF[i] = a[i] - b[i];
    
    map<int, int> now, trans;
    now[0] = 0;

    // Check for potential performance bottleneck before entering the loop based on size
    check_map_size_invariant(now.size(), 100);

    for (int i = 1; i <= n; i++) {
        int iterationCount = 0;  // Track the number of iterations

        for (auto c : now) {
            trans[c.first + FF[i]] = c.second + a[i];
            iterationCount++;
        }

        // Check for excessive iterations within nested loops
        check_repeated_updates_invariant(iterationCount, 1000);
        
        int combinationsCount = trans.size();  // Check the number of combinations
        // Check for too many valid combinations
        check_valid_combinations_invariant(combinationsCount, 100);

        for (auto c : trans) {
            now[c.first] = max(now[c.first], c.second);
        }
        trans.clear();
    }
    
    if (now[0] == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", now[0]);
    }
}