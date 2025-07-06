#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_padding_invariant(const string& a, const string& b) {
    if (abs((int)a.length() - (int)b.length()) > 1000) {  // Using 1000 as an arbitrary threshold
        cerr << "Warning: Performance bottleneck condition triggered due to extensive padding!" << endl;
        abort();
    }
}

void check_consecutive_ones_invariant(const string& num) {
    int consecutiveOnes = 0;
    for (size_t i = 0; i < num.length() - 1; ++i) {
        if (num[i] == '1' && num[i + 1] == '1') {
            consecutiveOnes++;
        }
    }
    if (consecutiveOnes > 500) {  // Arbitrary threshold for excessive consecutive '11' patterns
        cerr << "Warning: Performance bottleneck condition triggered due to consecutive '11's!" << endl;
        abort();
    }
}

int main() {
    string a, b;
    cin >> a >> b;

    // Place checks after input is read and before processing
    check_padding_invariant(a, b);
    check_consecutive_ones_invariant(a);
    check_consecutive_ones_invariant(b);

    while (b.length() < a.length()) b = '0' + b;
    while (a.length() < b.length()) a = '0' + a;
    a = '0' + a;
    b = '0' + b;
    for (int i = 1; i < a.length(); i++) {
        if (a[i] == '1' && a[i + 1] == '1') {
            a[i - 1] = '1';
            a[i] = '0';
            a[i + 1] = '0';
        }
    }
    for (int i = a.length() - 1; i >= 0; i--) {
        if (a[i] == '1' && a[i + 1] == '1') {
            a[i - 1] = '1';
            a[i] = '0';
            a[i + 1] = '0';
        }
    }
    for (int i = 1; i < b.length(); i++) {
        if (b[i] == '1' && b[i + 1] == '1') {
            b[i - 1] = '1';
            b[i] = '0';
            b[i + 1] = '0';
        }
    }
    for (int i = b.length() - 1; i >= 0; i--) {
        if (b[i] == '1' && b[i + 1] == '1') {
            b[i - 1] = '1';
            b[i] = '0';
            b[i + 1] = '0';
        }
    }
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            if (a[i] == '1')
                cout << ">\n";
            else
                cout << "<\n";
            return 0;
        }
    }
    cout << "=\n";
    return 0;
}