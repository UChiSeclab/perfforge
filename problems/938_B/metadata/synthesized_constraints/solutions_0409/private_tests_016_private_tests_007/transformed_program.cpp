#include <bits/stdc++.h>
using namespace std;
int a[1000001], n, i, t, w, l, r;

// Function to check large range without prizes
void check_large_range_invariant(int l, int r, int t, int w) {
    if ((r - l > 100000) && (t <= w)) {
        cerr << "Warning: Large range without prizes causing performance bottleneck!" << endl;
        abort();
    }
}

// Function to check if prizes are far from starting positions
void check_far_prize_invariant(int a[], int n) {
    if ((a[1] > 500000) || (a[n] < 500000)) {
        cerr << "Warning: Prize position far from start causing prolonged execution!" << endl;
        abort();
    }
}

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    // Check once after reading the input to ensure no extreme conditions
    check_far_prize_invariant(a, n);

    t = 1;
    w = n;
    l = 1;
    r = 1000000;
    
    for (i = 1; i <= 1000000; i++) {
        l++;
        r--;
        
        // Check during the loop execution to catch performance issues
        check_large_range_invariant(l, r, t, w);

        if (a[t] == l) t++;
        if (a[w] == r) w--;
        if (t > w) break;
    }
    
    printf("%d\n", i);
}