#include <bits/stdc++.h>
using namespace std;

int n, k;
map<int, int> m1;
map<int, int> m2;
int a[101], b[101], c[101], d[101];
int dp1[100001], dp2[100001];

// Invariant Checkers
void check_dp_range_invariant(int max1, int max2, int n) {
    int threshold = 10000; // Define a reasonable threshold considering problem constraints
    if (max1 > threshold || max2 > threshold) {
        cerr << "Warning: dp_range_invariant triggered - large sum of taste-calorie differences" << endl;
        abort();
    }
}

void check_ratio_distribution_invariant(int countCloseToK, int n) {
    int threshold = n / 2; // Half of the fruits having a ratio close to k can imply a problem
    if (countCloseToK > threshold) {
        cerr << "Warning: ratio_distribution_invariant triggered - many fruits close to the k ratio" << endl;
        abort();
    }
}

void check_category_distribution_invariant(int l1, int l2, int n) {
    int threshold = n / 2; // If more than half of fruits are categorized, it might cause issues
    if (l1 > threshold || l2 > threshold) {
        cerr << "Warning: category_distribution_invariant triggered - many fruits in one category" << endl;
        abort();
    }
}

int main() {
    memset(dp1, -0x3f3f3f3f, sizeof(dp1));
    memset(dp2, -0x3f3f3f3f, sizeof(dp2));
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    
    int l1 = 1, l2 = 1;
    int max1 = 0, max2 = 0;
    int countCloseToK = 0; // Count how many fruits have a taste-calorie ratio close to k

    for (int i = 1; i <= n; i++) {
        int x = a[i] - k * b[i];
        if (x >= 0) {
            m1[l1] = i;
            max1 += x;
            c[l1] = x;
            l1++;
        } else if (x < 0) {
            m2[l2] = i;
            max2 += -x;
            d[l2] = -x;
            l2++;
        }
        
        if (abs(a[i] - k * b[i]) < k) { // Consider "close" if within k range
            countCloseToK++;
        }
    }

    // Insert invariant checks
    check_dp_range_invariant(max1, max2, n);
    check_ratio_distribution_invariant(countCloseToK, n);
    check_category_distribution_invariant(l1, l2, n);
    
    dp1[0] = 0;
    dp2[0] = 0;
    for (int i = 1; i < l1; i++) {
        for (int j = max1; j >= c[i]; j--) {
            dp1[j] = max(dp1[j], dp1[j - c[i]] + a[m1[i]]);
        }
    }
    for (int i = 1; i < l2; i++) {
        for (int j = max2; j >= d[i]; j--) {
            dp2[j] = max(dp2[j], dp2[j - d[i]] + a[m2[i]]);
        }
    }
    int ans = -1;
    for (int i = 1; i <= max(max1, max2); i++) {
        ans = max(ans, dp1[i] + dp2[i]);
    }
    if (dp1[0] != 0) ans = max(ans, dp1[0]);
    cout << ans << endl;
}