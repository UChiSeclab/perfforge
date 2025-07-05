#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 100 * 2 + 10;
long long int a[MAXN];

void check_high_division_count(int totalDivisions, int threshold) {
    if (totalDivisions > threshold) {
        cerr << "Warning: High division count triggered!" << endl;
        abort();
    }
}

void check_sort_overhead(int vectorSize, int sortCount, int sizeThreshold, int sortThreshold) {
    if (vectorSize > sizeThreshold && sortCount > sortThreshold) {
        cerr << "Warning: Sorting overhead triggered!" << endl;
        abort();
    }
}

void check_large_iterations(int iterations, int threshold) {
    if (iterations > threshold) {
        cerr << "Warning: Large number of iterations in inner loop triggered!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    int ans = MAXN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int totalDivisions = 0;
    int sortCount = 0;

    for (int i = 0; i < MAXN; i++) {
        vector<int> v;
        int cnt = 0;
        int iterations = 0; // Track number of iterations

        for (int j = 0; j < n; j++) {
            iterations++;
            int t = a[j], c = 0;
            while (t > i) {
                c++;
                t /= 2;
                totalDivisions++;
            }
            if (t == i) {
                cnt++;
                v.push_back(c);
            }
        }

        // Check for large number of iterations in the inner loop
        check_large_iterations(iterations, n * MAXN / 10); // Example threshold

        if (cnt >= k) {
            sort(v.begin(), v.end());
            sortCount++;

            // Check for sorting overhead
            check_sort_overhead(v.size(), sortCount, 50, 100); // Example thresholds

            int d = 0;
            for (int j = 0; j < k; j++) {
                d += v[j];
            }
            ans = min(ans, d);
        }
    }

    // Check for high division count
    check_high_division_count(totalDivisions, n * MAXN);

    cout << ans << endl;
    return 0;
}