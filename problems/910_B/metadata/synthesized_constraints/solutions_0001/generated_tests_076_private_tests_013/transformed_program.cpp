#include <bits/stdc++.h>
using namespace std;

int arr[6], bar[6];
int ans = 6;
int n;

// Checkers integrated within the program
void check_recursive_exploration(int pos) {
    if (pos == 6) {
        cerr << "Warning: Excessive recursive exploration detected!" << endl;
        abort();
    }
}

void check_search_space_exploration(int totalLength, int n) {
    if (totalLength < n) {
        cerr << "Warning: Inefficient search space exploration detected!" << endl;
        abort();
    }
}

void check_suboptimal_matching(int a, int b, int n) {
    if (2 * a <= n && 2 * b <= n && (2 * a + 2 * b > n)) {
        cerr << "Warning: Frequent suboptimal matching detected!" << endl;
        abort();
    }
}

void f(int pos) {
    check_recursive_exploration(pos); // Check for deep recursion
    if (pos == 6) {
        int tmp = 0;
        for (int i = 0; i < 6; i++)
            if (bar[i] < n) tmp++;
        ans = min(ans, tmp);
        return;
    }

    for (int i = 0; i < 6; i++) {
        if (bar[i] >= arr[pos]) {
            bar[i] -= arr[pos];
            f(pos + 1);
            bar[i] += arr[pos];
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 6; i++) bar[i] = n;
    int a, b;
    scanf("%d%d", &a, &b);
    arr[0] = arr[1] = arr[2] = arr[3] = a;
    arr[4] = arr[5] = b;

    // Check for inefficient search space before starting recursion
    check_search_space_exploration(2 * a + 2 * b, n);

    // Check for suboptimal matching conditions
    check_suboptimal_matching(a, b, n);

    f(0);
    printf("%d", ans);
    return 0;
}