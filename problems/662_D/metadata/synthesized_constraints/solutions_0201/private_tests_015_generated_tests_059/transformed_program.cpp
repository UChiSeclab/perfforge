#include <bits/stdc++.h>
using namespace std;

void check_long_numeric_part(int len) {
    if (len > 3) {  // Check for long numeric parts, as they can cause slowdown
        cerr << "Warning: Performance bottleneck condition triggered - long numeric part" << endl;
        abort();
    }
}

void check_lengthy_year_sequence(int len, int num) {
    int baseYear = 1989;
    int rangeLimit = baseYear + 10 * ((int)(ceil(pow(10, len - 1)) - 1) / 9);
    if (num < rangeLimit) {  // Check if the year sequence is lengthy, which can slow down the computation
        cerr << "Warning: Performance bottleneck condition triggered - lengthy year sequence" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int len = s.length() - 4;
        int num = 0;
        for (int i = 4; i < s.length(); i++) num = num * 10 + s[i] - '0';
        
        // Insert checks based on the inferred invariants
        check_long_numeric_part(len);
        check_lengthy_year_sequence(len, num);
        
        if (len > 3) {
            if (num < 1989 + 10 * (((long long)ceil(pow(10, len - 1)) - 1) / 9))
                num += (int)ceil(pow(10, len));
        } else
            for (int i = 1989 + 10 * ((int)(ceil(pow(10, len - 1)) - 1) / 9); 
                 i < 1989 + 10 * ((int)(ceil(pow(10, len - 1)) - 1) / 9) + 
                 (int)ceil(pow(10, len)); 
                 i++) {
                if ((i - num) % (int)ceil(pow(10, len)) == 0) {
                    num = i;
                    break;
                }
            }
        cout << num << '\n';
    }
    return 0;
}