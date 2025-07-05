#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_number_of_entries(int n) {
    if (n > 10000) { // Assuming a threshold for illustration
        cerr << "Warning: Performance bottleneck condition triggered - high number of strings!" << endl;
        abort();
    }
}

void check_large_number_of_positions(int k) {
    if (k > 10000) { // Assuming a threshold for illustration
        cerr << "Warning: Performance bottleneck condition triggered - large number of positions!" << endl;
        abort();
    }
}

void check_character_overwrites(int max_movement) {
    if (max_movement > 100000) { // Threshold represents excessive character movements
        cerr << "Warning: Performance bottleneck condition triggered - excessive character overwrites!" << endl;
        abort();
    }
}

void check_output_length(int len) {
    if (len > 1000000) { // Threshold represents a very large output length
        cerr << "Warning: Performance bottleneck condition triggered - large output length!" << endl;
        abort();
    }
}

char rez[2000001], s[2000001];
int main() {
    int n, k, l, len = 0, p, poz;
    cin >> n;

    // Check for high number of entries
    check_high_number_of_entries(n);

    for (int i = 0; i < n; i++) {
        p = 1;
        cin >> s >> k;
        
        // Check for large number of positions
        check_large_number_of_positions(k);

        l = strlen(s);
        for (int j = 0; j < k; j++) {
            cin >> poz;
            for (int m = max(poz, p); m < poz + l; m++) {
                rez[m] = s[m - poz];
            }
            p = poz + l - 1;
            if (len < p) len = p;
        }
    }

    // Check for excessive character overwrites
    int max_movement = 0; // Calculate max_movement as needed
    check_character_overwrites(max_movement);

    for (int i = 1; i <= len; i++) {
        if (rez[i])
            cout << rez[i];
        else
            cout << 'a';
    }

    // Check for large output length
    check_output_length(len);

    return 0;
}