#include <bits/stdc++.h>
using namespace std;

int a[100010];

// Checkers for performance invariants
void check_sort_invariant(int n) {
    if (n > 10000) { // Example threshold for large sorting operations
        cerr << "Warning: sort_invariant triggered - large array for sorting" << endl;
        abort();
    }
}

void check_loop_invariant(int n, int max_height, int min_height) {
    if ((max_height - min_height) < 5 && n > 1000) { // Example condition where heights are close
        cerr << "Warning: loop_invariant triggered - excessive iterations due to similar heights" << endl;
        abort();
    }
}

bool cmp(int a, int b) { return a > b; }

int main() {
    int n, m;
    cin >> n >> m;
    long long sum = 0;
    int flag = 0;
    int M = n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    // Insert checker for sorting invariant before sorting
    check_sort_invariant(n);

    sort(a, a + n, cmp);

    long long h = a[0], ans = 0;

    // Check loop invariant before entering the loop
    int max_height = a[0]; // Since array is now sorted
    int min_height = a[n-1];
    check_loop_invariant(n, max_height, min_height);

    for (int i = 0; i < n; i++) {
        if (h == 1) {
            ans += n - i;
            break;
        }
        if (h <= a[i + 1]) {
            h--;
            ans++;
        }
        if (h > a[i + 1]) {
            ans += h - a[i + 1];
            h = a[i + 1];
        }
        if (h == 1) {
            ans += (n - i - 1);
            break;
        }
    }

    cout << sum - ans << endl;
}