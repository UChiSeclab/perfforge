#include <bits/stdc++.h>
using namespace std;

int a[1010];
int n;

void check_number_of_stops_invariant(int n) {
    if (n > 950) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of stops!" << endl;
        abort();
    }
}

void check_frequent_breaks_invariant(int loop_iterations, int n) {
    if (loop_iterations > 200 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent conditional breaks!" << endl;
        abort();
    }
}

void check_binary_search_iterations_invariant(int iterations) {
    if (iterations >= 200) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive binary search iterations!" << endl;
        abort();
    }
}

void check_inner_loop_calculations_invariant(int inner_loop_count, int n) {
    if (inner_loop_count > 5000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive inner loop calculations!" << endl;
        abort();
    }
}

bool check(int v) {
    n++;
    a[n - 1] = v;
    double l = 10, r = 100000000;
    int binary_search_iterations = 0; // Track iterations to check invariant
    int total_inner_loop_calculations = 0; // Track inner loop operations

    for (int it = 0; it < 200; ++it) {
        binary_search_iterations++;
        double m = (l + r) / 2;
        int v = 0;
        int st = 0;
        double have = m;
        int inner_loop_iterations = 0;

        for (int i = 0; i < n; ++i) {
            inner_loop_iterations++;
            int c = (int)(have / 10);
            if (c > a[i] - st) {
                v = 1;
                break;
            }
            if (c < a[i] - st) {
                v = -1;
                break;
            }
            have -= (a[i] - st) * 10;
            have += m;
            st = a[i];
        }

        total_inner_loop_calculations += inner_loop_iterations;

        if (v == -1)
            l = m;
        else if (v == 1)
            r = m;
        else {
            n--;
            check_binary_search_iterations_invariant(binary_search_iterations);
            check_inner_loop_calculations_invariant(total_inner_loop_calculations, n);
            return true;
        }
    }
    n--;

    check_binary_search_iterations_invariant(binary_search_iterations);
    check_inner_loop_calculations_invariant(total_inner_loop_calculations, n);
    return false;
}

int main() {
    scanf("%d", &n);
    check_number_of_stops_invariant(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    bool f1 = check(a[n - 1] + a[0]);
    bool f2 = check(a[n - 1] + a[0] + 1);
    if (f1 && f2) {
        printf("not unique\n");
    } else if (f1)
        printf("unique\n%d\n", a[n - 1] + a[0]);
    else
        printf("unique\n%d\n", a[n - 1] + a[0] + 1);
    return 0;
}