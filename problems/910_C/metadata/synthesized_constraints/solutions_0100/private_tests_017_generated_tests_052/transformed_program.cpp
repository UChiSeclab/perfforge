#include <bits/stdc++.h>
using namespace std;

int ct[10][10];
bool lead[10];

// Check for permutation explosion
void check_permutation_explosion(bool condition) {
    if (condition) {
        cerr << "Warning: Permutation explosion detected - excessive permutations!" << endl;
        abort();
    }
}

// Check for weight distribution of characters
void check_weight_distribution(bool condition) {
    if (condition) {
        cerr << "Warning: Heavy weight distribution detected - high computation per permutation!" << endl;
        abort();
    }
}

// Check for recursive depth and branching factor
void check_recursive_depth(bool condition) {
    if (condition) {
        cerr << "Warning: Recursive depth or branching factor too high!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> in(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
        lead[in[i][0] - 'a'] = true;
        reverse(in[i].begin(), in[i].end());
        for (int j = 0; j < in[i].length(); j++) {
            ct[in[i][j] - 'a'][j]++;
        }
    }

    vector<int> v(10);
    for (int i = 0; i < 10; i++) v[i] = i;

    long long minsum = 1e15;
    
    // Permutation explosion check before entering the loop
    check_permutation_explosion(next_permutation(v.begin(), v.end()));

    do {
        int zloc = find(v.begin(), v.end(), 0) - v.begin();
        if (lead[zloc]) continue;
        
        int sum = 0;
        
        // Check weight distribution before computing sum
        check_weight_distribution(zloc < 0 || zloc > 9); // Placeholder condition, can be adjusted

        for (int i = 0; i < 10; i++) {
            int p10 = 1;
            for (int j = 0; j < 6; j++) {
                sum += p10 * v[i] * ct[i][j];
                p10 *= 10;
            }
        }
        
        // Recursive depth check based on possible permutation depth
        check_recursive_depth(sum < 0); // Placeholder condition, can be adjusted

        minsum = min(static_cast<long long>(sum), minsum);
    } while (next_permutation(v.begin(), v.end()));

    cout << minsum << endl;
    return 0;
}