#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const long long INF = 10010010100100LL;
int N;
long long P[MAXN];
long long rem[MAXN];

// Check functions
void check_frequent_updates(int num_updates, int threshold) {
    if (num_updates > threshold) {
        cerr << "Warning: frequent_updates - excessive updates to rem array detected!" << endl;
        abort();
    }
}

void check_incremental_updates(int incremental_count, int threshold) {
    if (incremental_count > threshold) {
        cerr << "Warning: incremental_updates - too many small incremental updates detected!" << endl;
        abort();
    }
}

void check_while_loop_iterations(int iteration_count, int max_iterations) {
    if (iteration_count > max_iterations) {
        cerr << "Warning: while_loop_iterations - excessive iterations detected!" << endl;
        abort();
    }
}

int main(void) {
    cin >> N;
    
    int incremental_count = 0; // Initialize incremental update counter
    int num_updates = 0; // Counter to track updates in rem array

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        rem[i] = INF;
    }
    rem[0] = rem[N - 1] = 1;
    
    int iteration_count = 0; // Counter to track number of iterations of the while loop
    
    while (true) {
        bool seen = false;
        iteration_count++; // Increment iteration count for while loop
        
        for (int i = 1; i < N; i++) {
            if (rem[i] > min(rem[i - 1] + 1, P[i])) {
                rem[i] = min(rem[i - 1] + 1, P[i]);
                seen = true;
                num_updates++; // Increment update count for rem array
                if (P[i] - P[i-1] == 1) {
                    incremental_count++; // Increment incremental update counter
                }
            }
        }
        for (int i = N - 2; i >= 0; i--) {
            if (rem[i] > min(rem[i + 1] + 1, P[i])) {
                rem[i] = min(rem[i + 1] + 1, P[i]);
                seen = true;
                num_updates++; // Increment update count for rem array
                if (P[i] - P[i+1] == 1) {
                    incremental_count++; // Increment incremental update counter
                }
            }
        }
        
        // Check for frequent updates and incremental updates
        check_frequent_updates(num_updates, N); // Check condition after processing
        check_incremental_updates(incremental_count, N / 2); // Check condition after processing

        if (!seen) break;
    }
    
    // Check while loop iterations
    check_while_loop_iterations(iteration_count, N); // Check condition after the loop
    
    cout << *max_element(rem, rem + N) << "\n";
    return 0;
}