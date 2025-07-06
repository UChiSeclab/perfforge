#include <bits/stdc++.h>
using namespace std;
const long double eps = FLT_MIN, inf = 1e60;
long double x, y, z;

void check_close_to_one_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - two or more variables close to 1!" << endl;
        abort();
    }
}

void check_logarithmic_trigger_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - logarithmic path triggered by values <= 1!" << endl;
        abort();
    }
}

void check_logarithmic_preference_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - preference for logarithmic paths!" << endl;
        abort();
    }
}

long double f(int idx) {
    if (idx == 1) return (x <= 1.) ? -inf : z * log(y) + log(log(x));
    if (idx == 2) return (x <= 1.) ? -inf : y * log(z) + log(log(x));
    if (idx == 3 || idx == 4)
        return (x <= 1.) ? -inf : log(z) + log(y) + log(log(x));
    if (idx == 5) return (y <= 1.) ? -inf : z * log(x) + log(log(y));
    if (idx == 6) return (y <= 1.) ? -inf : x * log(z) + log(log(y));
    if (idx == 7 || idx == 8)
        return (y <= 1.) ? -inf : log(z) + log(x) + log(log(y));
    if (idx == 9) return (z <= 1.) ? -inf : y * log(x) + log(log(z));
    if (idx == 10) return (z <= 1.) ? -inf : x * log(y) + log(log(z));
    if (idx == 11 || idx == 12)
        return (z <= 1.) ? -inf : log(x) + log(y) + log(log(z));
}

long double g(int idx) {
    if (idx == 1) return pow(x, pow(y, z));
    if (idx == 2) return pow(x, pow(z, y));
    if (idx == 3 || idx == 4) return pow(x, y * z);
    if (idx == 5) return pow(y, pow(x, z));
    if (idx == 6) return pow(y, pow(z, x));
    if (idx == 7 || idx == 8) return pow(y, x * z);
    if (idx == 9) return pow(z, pow(x, y));
    if (idx == 10) return pow(z, pow(y, x));
    if (idx == 11 || idx == 12) return pow(z, y * x);
}

long double t(int idx) {
    return (x <= 1 && y <= 1 && z <= 1) ? g(idx) : f(idx);
}

int main() {
    map<int, string> ans;
    ans[1] = "x^y^z";
    ans[2] = "x^z^y";
    ans[3] = "(x^y)^z";
    ans[4] = "(x^z)^y";
    ans[5] = "y^x^z";
    ans[6] = "y^z^x";
    ans[7] = "(y^x)^z";
    ans[8] = "(y^z)^x";
    ans[9] = "z^x^y";
    ans[10] = "z^y^x";
    ans[11] = "(z^x)^y";
    ans[12] = "(z^y)^x";

    cin >> x >> y >> z;

    // Insert checks after input is read
    check_close_to_one_invariant((fabs(x - 1) < 0.1 && fabs(y - 1) < 0.1) || 
                                 (fabs(x - 1) < 0.1 && fabs(z - 1) < 0.1) || 
                                 (fabs(y - 1) < 0.1 && fabs(z - 1) < 0.1));
    
    check_logarithmic_trigger_invariant(x <= 1 || y <= 1 || z <= 1);
    
    check_logarithmic_preference_invariant(x <= 1.1 && y <= 1.1 && z <= 1.1);

    long double maxi;
    int idx = -1;
    for (int i = 1; i <= 12; i++) {
        fprintf(stderr, "t(%d) = %.10Lf\n", i, t(i));
        if (idx == -1 || (t(i) - maxi > eps)) maxi = t(i), idx = i;
    }
    cout << ans[idx] << endl;
    return 0;
}