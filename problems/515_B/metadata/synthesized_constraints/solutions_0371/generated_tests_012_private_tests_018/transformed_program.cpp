#include <bits/stdc++.h>
using namespace std;

// Invariant checkers
void check_loop_invariant(int boycounter, int girlcounter, int boysize, int girlsize) {
    if (boycounter + girlcounter < boysize + girlsize) {
        cerr << "Warning: Potential inefficient loop iteration triggered!" << endl;
        abort();
    }
}

void check_balance_invariant(int boycounter, int girlcounter, int boysize, int girlsize) {
    if (boycounter == 0 || girlcounter == 0) {
        cerr << "Warning: Unbalanced happiness distribution triggered!" << endl;
        abort();
    }
}

void check_infinite_loop_invariant(int iterations) {
    if (iterations >= 10000000) {
        cerr << "Warning: Potential infinite loop condition triggered!" << endl;
        abort();
    }
}

int main() {
    int boysize, girlsize, boycounter, girlcounter, index = 0;
    bool boy[101] = {false}, girl[101] = {false};
    cin >> boysize >> girlsize;
    cin >> boycounter;
    for (int i = 0; i < boycounter; i++) {
        cin >> index;
        boy[index] = true;
    }
    cin >> girlcounter;
    for (int i = 0; i < girlcounter; i++) {
        cin >> index;
        girl[index] = true;
    }

    // Check initial conditions for balance
    check_balance_invariant(boycounter, girlcounter, boysize, girlsize);

    int iterations = 0;
    for (int i = 0; i <= 10000000; i++) {
        iterations++;
        if (boy[i % boysize] && !girl[i % girlsize]) {
            girl[i % girlsize] = true;
            girlcounter++;
        } else if (girl[i % girlsize] && !boy[i % boysize]) {
            boy[i % boysize] = true;
            boycounter++;
        }
        if (boycounter + girlcounter == boysize + girlsize) break;

        // Check for inefficient loop iteration
        check_loop_invariant(boycounter, girlcounter, boysize, girlsize);
    }

    // Check for potential infinite loop
    check_infinite_loop_invariant(iterations);

    if (boycounter + girlcounter == boysize + girlsize)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}