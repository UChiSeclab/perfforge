#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_minimal_increment(int a, int m) {
    if ((a % m) < m / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - minimal increments leading to excessive iterations!" << endl;
        abort();
    }
}

void check_non_divisible_progress(int a, int m) {
    if ((a % m) != 0 && (a % m) < m / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - non-divisible progress with small increments!" << endl;
        abort();
    }
}

int main() {
    int a, m;
    cin >> a >> m;
    
    // Initial checks to detect potential slowdowns
    check_minimal_increment(a, m);
    check_non_divisible_progress(a, m);
    
    while (a <= 10000000) {
        a += a % m;
        if (a % m == 0) {
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}