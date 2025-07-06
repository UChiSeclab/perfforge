#include <bits/stdc++.h>
using namespace std;

// Performance checker functions
void check_iteration_invariant(int n, int totalMatchboxes) {
    if (totalMatchboxes > 100000000 && n > 100000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations due to high total matchbox count and large n." << endl;
        abort();
    }
}

void check_sort_invariant(int n, int m) {
    if (n > 100000000 && m > 10) {
        cerr << "Warning: Performance bottleneck condition triggered - potential sorting overhead with large n and moderate m." << endl;
        abort();
    }
}

void check_container_capacity_invariant(int n, int maxMatchboxes) {
    if (maxMatchboxes > 50000000 && n > 100000000) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of matchboxes in a single container." << endl;
        abort();
    }
}

struct warehouse {
    int matchbox;
    int match;
};

int main() {
    int n, m, i = 0, j, sum, begin = 1;
    cin >> n >> m;
    warehouse s[20], tmp;

    int totalMatchboxes = 0;
    int maxMatchboxes = 0;

    // Input reading and invariant check
    do {
        cin >> s[i].matchbox >> s[i].match;
        totalMatchboxes += s[i].matchbox;
        maxMatchboxes = max(maxMatchboxes, s[i].matchbox);
        i++;
    } while (i < m);

    // Check for potential bottlenecks before sorting
    check_iteration_invariant(n, totalMatchboxes);
    check_container_capacity_invariant(n, maxMatchboxes);

    for (i = 0; i < m - 1; i++) {
        for (j = i + 1; j < m; j++) {
            if (s[i].match < s[j].match) {
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }

    // Check for sorting bottleneck
    check_sort_invariant(n, m);

    for (i = 0, begin, sum = 0; i < m; i++) {
        for (j = 0; j < s[i].matchbox; j++) {
            if (begin <= n) {
                begin++;
                sum += s[i].match;
            }
        }
    }
    cout << sum << endl;
    return 0;
}