#include <bits/stdc++.h>
using namespace std;

// Function to check if three sides can form a triangle
bool check(int a, int b, int c) {
    if (a + b > c && b + c > a && a + c > b) return true;
    return false;
}

// Helper checker functions
void check_large_max_length(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large maximum stick length compared to others!" << endl;
        abort();
    }
}

void check_imbalanced_sticks(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - imbalanced stick lengths!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int max_length = max({a, b, c});
    int sum_of_others = a + b + c - max_length;

    // Insert checks based on the identified performance invariants
    check_large_max_length(max_length > 50 && sum_of_others < 50);
    check_imbalanced_sticks(max_length > sum_of_others);

    int mi = 1000;
    for (int i = 0; i <= max(a, max(b, c)); i++)
        for (int j = 0; j <= max(a, max(b, c)); j++)
            for (int k = 0; k <= max(a, max(b, c)); k++)
                if (check(a + i, b + j, c + k))
                    mi = min(mi, i + j + k);

    cout << mi;

    return 0;
}