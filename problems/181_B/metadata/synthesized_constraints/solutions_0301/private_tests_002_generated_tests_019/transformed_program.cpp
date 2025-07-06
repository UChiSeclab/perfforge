#include <bits/stdc++.h>
using namespace std;

void check_large_data_invariant(int n) {
    if (n > 2500) { // Close to maximum constraint
        cerr << "Warning: Large data invariant triggered - potential quadratic complexity issues!" << endl;
        abort();
    }
}

void check_dense_point_invariant(int numberOfAdjustments) {
    if (numberOfAdjustments > 5000) { // Arbitrarily chosen threshold for excessive adjustments
        cerr << "Warning: Dense point invariant triggered - excessive boundary adjustments!" << endl;
        abort();
    }
}

void check_collinear_points_invariant(int potentialMidpoints) {
    if (potentialMidpoints > 1000) { // Arbitrarily chosen threshold for potential midpoint checks
        cerr << "Warning: Collinear points invariant triggered - too many midpoint checks!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    check_large_data_invariant(n); // Check for large input size

    int a[n][2], br = 0;
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];

    int p[2];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (a[j][0] < a[i][0]) {
                p[0] = a[i][0];
                p[1] = a[i][1];
                a[i][0] = a[j][0];
                a[i][1] = a[j][1];
                a[j][0] = p[0];
                a[j][1] = p[1];
            } else if ((a[j][0] == a[i][0]) && (a[j][1] < a[i][1])) {
                p[0] = a[i][0];
                p[1] = a[i][1];
                a[i][0] = a[j][0];
                a[i][1] = a[j][1];
                a[j][0] = p[0];
                a[j][1] = p[1];
            }
        }

    int donjagranica = 0, gornjagranica = n - 1, sredina;
    int donjagranica2, gornjagranica2, sredina2;
    double g[2];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            g[0] = (a[i][0] + a[j][0]) / 2.0;
            g[1] = (a[i][1] + a[j][1]) / 2.0;

            int adjustmentCounter = 0; // Counter for boundary adjustments
            while (a[donjagranica][0] != a[gornjagranica][0]) {
                sredina = (donjagranica + gornjagranica) / 2;
                if (a[sredina][0] >= g[0])
                    gornjagranica = sredina;
                else
                    donjagranica = sredina + 1;
                adjustmentCounter++;
            }
            check_dense_point_invariant(adjustmentCounter); // Check for dense points

            while (a[gornjagranica][0] == a[gornjagranica + 1][0]) {
                gornjagranica++;
            }
            while (a[donjagranica][0] == a[donjagranica - 1][0]) {
                donjagranica--;
            }
            donjagranica2 = donjagranica;
            gornjagranica2 = gornjagranica;

            int midpointCounter = 0; // Counter for potential midpoints
            while (donjagranica2 < gornjagranica2) {
                sredina2 = (donjagranica2 + gornjagranica2) / 2;
                if (a[sredina2][1] >= g[1])
                    gornjagranica2 = sredina2;
                else
                    donjagranica2 = sredina2 + 1;
                midpointCounter++;
            }
            check_collinear_points_invariant(midpointCounter); // Check for collinear points

            if ((a[donjagranica2][0] == g[0]) && (a[donjagranica2][1] == g[1])) 
                br++;
            gornjagranica = n - 1;
            donjagranica = 0;
        }
    cout << br;
    return 0;
}