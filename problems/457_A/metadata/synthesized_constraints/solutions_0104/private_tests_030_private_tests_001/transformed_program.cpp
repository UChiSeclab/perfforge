#include <bits/stdc++.h>
using namespace std;
const int N = 130000;
const unsigned long long MAX = 5 * 1e9 + 4;
unsigned long long a[100005], b[100005];
int len1, len2, len;

// Checker functions based on performance-characterizing invariants
void check_length_difference(int len1, int len2) {
    if (abs(len1 - len2) > 10000) {
        cerr << "Warning: Performance bottleneck - significant length difference in strings." << endl;
        abort();
    }
}

void check_one_density(const string& s) {
    int one_count = count(s.begin(), s.end(), '1');
    if (one_count > s.length() * 0.8) {
        cerr << "Warning: Performance bottleneck - high density of '1's in the string." << endl;
        abort();
    }
}

void check_cascading_operations(const string& s) {
    int half_length = s.length() / 2;
    int cluster_count = count(s.begin(), s.begin() + half_length, '1');
    if (cluster_count > half_length * 0.7) {
        cerr << "Warning: Performance bottleneck - potential cascading operations due to clustered '1's." << endl;
        abort();
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    len1 = s1.length();
    len2 = s2.length();

    // Performance checks
    check_length_difference(len1, len2);
    check_one_density(s1);
    check_one_density(s2);
    check_cascading_operations(s1);
    check_cascading_operations(s2);

    if (len1 < len2)
        for (int i = len1; i < len2; i++) s1 = "0" + s1;
    else if (len1 > len2)
        for (int i = len2; i < len1; i++) s2 = "0" + s2;

    len = max(len1, len2);
    for (int i = 0; i < len; i++) {
        if (s1[i] == '1') a[i]++;
        if (s2[i] == '1') b[i]++;
        if (a[i] > b[i]) {
            a[i + 1] += (a[i] - b[i]);
            a[i + 2] += a[i] - b[i];
        } else {
            b[i + 1] += (b[i] - a[i]);
            b[i + 2] += (b[i] - a[i]);
        }
    }

    long double t1 = a[len + 1] + a[len] * ((sqrt(5) + 1) / 2);
    long double t2 = b[len + 1] + b[len] * ((sqrt(5) + 1) / 2);

    if (fabs(t1 - t2) < 1e-15)
        cout << "=" << endl;
    else if (t1 > t2)
        cout << ">" << endl;
    else if (t1 < t2)
        cout << "<" << endl;
}