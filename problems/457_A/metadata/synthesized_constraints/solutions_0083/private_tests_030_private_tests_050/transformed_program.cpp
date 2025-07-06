#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-4;
const double Q = (1.0 + sqrt(5.0)) / 2.0;
char a[100000 + 100];
char b[100000 + 100];
int A[100000 + 100];
int B[100000 + 100];

// Checker functions
void check_padding_invariant(int lengthA, int lengthB) {
    if (abs(lengthA - lengthB) > 1000) {  // Arbitrary threshold
        cerr << "Warning: Performance bottleneck condition triggered - extensive padding required!" << endl;
        abort();
    }
}

void check_equal_neutralization_invariant(int equalCount) {
    if (equalCount > 50000) {  // Arbitrary threshold
        cerr << "Warning: Performance bottleneck condition triggered - high frequency of equal element neutralization!" << endl;
        abort();
    }
}

void check_adjustment_invariant(int adjustmentCount) {
    if (adjustmentCount > 10000) {  // Arbitrary threshold
        cerr << "Warning: Performance bottleneck condition triggered - repeated adjustments in arrays!" << endl;
        abort();
    }
}

string solve(string &a, string &b) {
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    int n = a.size();
    int equalCount = 0;
    for (int i = 0; i < n; i++) {
        A[i] = a[i] - '0';
        B[i] = b[i] - '0';
        if (A[i] == B[i]) {
            A[i] = B[i] = 0;
            equalCount++;
        }
    }
    check_equal_neutralization_invariant(equalCount);  // Check for neutralization invariant

    int adjustmentCount = 0;
    for (int i = 0; i < n - 2; i++) {
        if (A[i] >= B[i]) {
            A[i] -= B[i];
            B[i] = 0;
        } else if (B[i] >= A[i]) {
            B[i] -= A[i];
            A[i] = 0;
        }
        if (A[i] < -20 || B[i] > 20) {
            return "<";
        } else if (A[i] > 20 || B[i] < -20) {
            return ">";
        }
        A[i + 1] += A[i];
        A[i + 2] += A[i];
        A[i] = 0;
        B[i + 1] += B[i];
        B[i + 2] += B[i];
        B[i] = 0;
        adjustmentCount++;
    }
    check_adjustment_invariant(adjustmentCount);  // Check for adjustment invariant

    double aa = A[n - 2] * Q + A[n - 1];
    double bb = B[n - 2] * Q + B[n - 1];
    if (aa < bb - EPS) {
        return "<";
    } else if (aa > bb + EPS) {
        return ">";
    } else {
        return "=";
    }
}

int main() {
    scanf("%s%s", a, b);
    string strA(a);
    string strB(b);
    check_padding_invariant(strA.size(), strB.size());  // Check for padding invariant
    while (strA.size() < strB.size()) {
        strA = '0' + strA;
    }
    while (strB.size() < strA.size()) {
        strB = '0' + strB;
    }
    printf("%s\n", solve(strA, strB).c_str());
    return 0;
}