#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_permutation_complexity(int unique_char_count) {
    if (unique_char_count >= 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high permutation complexity!" << endl;
        abort();
    }
}

void check_nested_loop_operations(int max_string_length, int n) {
    if (max_string_length >= 6 && n > 500) {
        cerr << "Warning: Performance bottleneck condition triggered - costly nested loop operations!" << endl;
        abort();
    }
}

void check_leading_zero_avoidance(int leading_zero_checks) {
    if (leading_zero_checks > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive leading zero checks!" << endl;
        abort();
    }
}

int ct[10][10];
bool lead[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int n;
    cin >> n;
  
    vector<string> in(n);
    set<char> unique_chars; // To track the number of unique characters
    int max_string_length = 0; // To track the maximum string length

    for (int i = 0; i < n; i++) {
        cin >> in[i];
        lead[in[i][0] - 'a'] = true;
        reverse(in[i].begin(), in[i].end());
        max_string_length = max(max_string_length, (int)in[i].length());
        for (int j = 0; j < in[i].length(); j++) {
            ct[in[i][j] - 'a'][j]++;
            unique_chars.insert(in[i][j]);
        }
    }
  
    check_permutation_complexity(unique_chars.size());
    check_nested_loop_operations(max_string_length, n);

    vector<int> v(10);
    for (int i = 0; i < 10; i++) v[i] = i;

    int minsum = 2 * (int)1e9;
    int leading_zero_checks = 0; // To track leading zero checks

    do {
        int zloc = find(v.begin(), v.end(), 0) - v.begin();
        if (lead[zloc]) {
            leading_zero_checks++;
            continue;
        }
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            int p10 = 1;
            for (int j = 0; j < 6; j++) {
                sum += p10 * v[i] * ct[i][j];
                p10 *= 10;
            }
        }
        minsum = min(sum, minsum);
    } while (next_permutation(v.begin(), v.end()));
  
    check_leading_zero_avoidance(leading_zero_checks);

    cout << minsum << endl;
    return 0;
}