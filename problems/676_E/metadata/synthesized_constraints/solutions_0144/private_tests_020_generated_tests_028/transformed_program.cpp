#include <bits/stdc++.h>
using namespace std;
const int c = -100005;
int var = 0;

bool isDiv(vector<int>& v, int k) {
    bool pos = true;
    int temp = 0;
    for (int i = 0; i < v.size(); i++) {
        temp += v[i];
        if (temp % k != 0) {
            pos = false;
            break;
        } else {
            temp /= k;
        }
    }
    if (temp != 0) pos = false;
    return pos;
}

// Checker functions for performance-characterizing invariants
void check_large_degree_no_unknowns(bool condition) {
    if (condition) {
        cerr << "Warning: Large polynomial degree with no unknown coefficients may cause performance issues!" << endl;
        abort();
    }
}

void check_stream_conversion_overhead(bool condition) {
    if (condition) {
        cerr << "Warning: Excessive stringstream operations due to pre-defined coefficients!" << endl;
        abort();
    }
}

void check_modulo_operations(bool condition) {
    if (condition) {
        cerr << "Warning: Heavy use of modulo operations with large k or complex coefficient sequences!" << endl;
        abort();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int predefined_count = 0;  // Count of pre-defined coefficients

    for (int i = 0; i < n + 1; i++) {
        string s;
        cin >> s;
        if (s == "?") {
            a[i] = c;
            var++;
        } else {
            stringstream myStream;
            myStream.str(s);
            myStream >> a[i];
            predefined_count++;  // Increment for each pre-defined coefficient
        }
    }

    // Check for large polynomial degree with no unknowns
    check_large_degree_no_unknowns(n > 10000 && var == 0);

    // Check for excessive stringstream operations
    check_stream_conversion_overhead(predefined_count > 5000);

    // Check for heavy modulo operations
    check_modulo_operations(k > 5000 && predefined_count > 5000);

    if (var == 0) {
        if (k == 0) {
            if (a[0] == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        } else {
            if (isDiv(a, k))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    } else {
        if (k == 0) {
            if (a[0] != 0 && a[0] != c)
                cout << "No" << endl;
            else if (a[0] == 0)
                cout << "Yes" << endl;
            else {
                if ((n + 1 - var) % 2 == 0)
                    cout << "No" << endl;
                else
                    cout << "Yes" << endl;
            }
        } else {
            if ((n + 1) % 2 == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}