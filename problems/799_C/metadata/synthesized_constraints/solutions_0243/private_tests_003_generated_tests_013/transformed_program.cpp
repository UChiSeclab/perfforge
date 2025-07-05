#include <bits/stdc++.h>
using namespace std;
const int N = 100005, MIN = -3 * N;

// Structure to hold two maximum values with indices
struct Value {
    int first, second, first_index, second_index;
    Value() : first(MIN), second(MIN), first_index(-1), second_index(-1) {}
};

Value beauty[N][2];

// Update function that might be called excessively
void updateValue(Value &value, int new_value, int index) {
    if (new_value > value.first) {
        value.second = value.first;
        value.second_index = value.first_index;
        value.first = new_value;
        value.first_index = index;
    } else if (new_value > value.second) {
        value.second = new_value;
        value.second_index = index;
    }
}

// Checker for high cost iteration
void check_high_cost_invariant(int cost, int max_cost) {
    if (cost >= max_cost) {
        cerr << "Warning: High cost invariant triggered - excessive iterations over maximum cost values!" << endl;
        abort();
    }
}

// Checker for duplicated cost consideration
void check_duplicate_cost_invariant(int coins, int diamonds, int max_threshold) {
    if (coins >= max_threshold && diamonds >= max_threshold) {
        cerr << "Warning: Duplicate cost invariant triggered - excessive loop iterations for coins and diamonds!" << endl;
        abort();
    }
}

// Checker for excessive function calls
void check_excessive_function_calls_invariant(int update_count, int threshold) {
    if (update_count >= threshold) {
        cerr << "Warning: Excessive function calls invariant triggered - frequent updates causing performance issues!" << endl;
        abort();
    }
}

int main() {
    int n, cd[2];
    scanf("%d %d %d", &n, &cd[0], &cd[1]);

    // Insert checker for duplicate cost consideration 
    check_duplicate_cost_invariant(cd[0], cd[1], 100000);

    for (int i = 0; i < n; ++i) {
        int b, p;
        char c;
        scanf("%d %d %c", &b, &p, &c);
        // Check for high cost value iteration
        check_high_cost_invariant(p, 100000);
        updateValue(beauty[p][c - 'C'], b, p);
    }

    int update_count = 0;

    for (int k = 0; k < 2; ++k) {
        for (int i = 1; i <= cd[k]; ++i) {
            updateValue(beauty[i][k], beauty[i - 1][k].first, beauty[i - 1][k].first_index);
            updateValue(beauty[i][k], beauty[i - 1][k].second, beauty[i - 1][k].second_index);
            update_count += 2;  // Increment the update count for each call
        }
    }

    // Check for excessive function calls
    check_excessive_function_calls_invariant(update_count, 200000);

    int res = 0;
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i <= cd[k]; ++i) {
            res = max(res, beauty[i][k].first + beauty[cd[k ^ 1]][k ^ 1].first);
            if (beauty[i][k].first_index != beauty[cd[k] - i][k].first_index) {
                res = max(res, beauty[i][k].first + beauty[cd[k] - i][k].first);
            } else {
                res = max(res, beauty[i][k].first + beauty[cd[k] - i][k].second);
            }
        }
    }

    printf("%d\n", res);
}