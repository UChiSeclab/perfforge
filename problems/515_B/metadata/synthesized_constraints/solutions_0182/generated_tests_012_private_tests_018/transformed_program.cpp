#include <bits/stdc++.h>
using namespace std;

// Checkers for performance bottlenecks
void check_progress_invariant(int iteration, int stable_iterations) {
    if (iteration > stable_iterations) {
        cerr << "Warning: Performance bottleneck condition triggered - insufficient progress in making friends happy." << endl;
        abort();
    }
}

void check_loop_invariant(int iteration, int max_iterations) {
    if (iteration >= max_iterations) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive looping without progress." << endl;
        abort();
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int *B = new int[n];
    int *G = new int[m];
    for (int i = 0; i < n; i++) B[i] = 0;
    for (int i = 0; i < m; i++) G[i] = 0;
    int b, g;
    cin >> b;
    for (int i = 0; i < b; i++) {
        int t;
        cin >> t;
        B[t] = 1;
    }
    cin >> g;
    for (int i = 0; i < g; i++) {
        int t;
        cin >> t;
        G[t] = 1;
    }
    int i = 0;
    int max = m * n;
    bool possible = false;
    int previous_happy_boys = b, previous_happy_girls = g;
    int stable_iterations = 0;
    const int max_stable_iterations = 1000; // Threshold for stable iterations

    do {
        int boy = i % n;
        int girl = i % m;
        if (B[boy])
            if (!G[girl]) G[girl] = 1;
        if (G[girl])
            if (!B[boy]) B[boy] = 1;
        i++;
        bool gF = true, bF = true;
        for (int i = 0; i < n; i++)
            if (B[i] == 0) {
                bF = false;
                break;
            }
        for (int i = 0; i < m; i++)
            if (G[i] == 0) {
                gF = false;
                break;
            }

        // Check for progress
        int current_happy_boys = count(B, B + n, 1);
        int current_happy_girls = count(G, G + m, 1);
        if (current_happy_boys == previous_happy_boys && current_happy_girls == previous_happy_girls) {
            stable_iterations++;
        } else {
            stable_iterations = 0;
        }
        previous_happy_boys = current_happy_boys;
        previous_happy_girls = current_happy_girls;

        // Performance checkers
        check_progress_invariant(stable_iterations, max_stable_iterations);
        check_loop_invariant(i, m * n * 10);

        if (bF && gF) {
            possible = true;
            break;
        }
    } while (i < m * n * 10);

    if (possible)
        cout << "Yes";
    else
        cout << "No";

    delete[] B;
    delete[] G;

    return 0;
}