#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long A[201], S[201][201], B[201][201][2][201];
long long i, j, k, l, r, md, q, n, m, mx, mn, a, b, x, c, s;
string s1, s2;

void check_recursion_depth(int currentDepth, int maxDepth) {
    if (currentDepth > maxDepth) {
        cerr << "Warning: Performance bottleneck condition triggered - recursion depth too high!" << endl;
        abort();
    }
}

void check_dp_efficiency(int overlapCount, int threshold) {
    if (overlapCount < threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - ineffective DP overlap!" << endl;
        abort();
    }
}

void check_input_complexity(int consecutiveSegments, int complexityThreshold) {
    if (consecutiveSegments > complexityThreshold) {
        cerr << "Warning: Performance bottleneck condition triggered - complex input structure!" << endl;
        abort();
    }
}

long long kkk(long long l, long long r, long long c, long long cnt);

long long solve(long long l, long long r) {
    if (S[l][r] != -1) return S[l][r];
    if (l == r) return S[l][r] = A[0];
    if (l > r) return S[l][r] = 0;
    
    long long n = r - l + 1, x = -2000000000;
    
    // Check for potential recursion depth issues
    check_recursion_depth(n, 50);  // Example threshold, you can adjust based on analysis
    
    for (long long i = n - 1; i >= 0; i--) {
        x = max<long long>(x, A[i] + kkk(l, r, 0, i + 1));
        x = max<long long>(x, A[i] + kkk(l, r, 1, i + 1));
    }
    return S[l][r] = x;
}

long long kkk(long long l, long long r, long long c, long long cnt) {
    if (B[l][r][c][cnt] != -1) return B[l][r][c][cnt];
    if (cnt == 0) return B[l][r][c][cnt] = solve(l, r);
    
    long long x = -2000000000;
    char b = c == 0 ? '0' : '1';
    
    int overlapCount = 0;
    for (long long i = l; i <= r; i++) {
        if (s1[i] == b) {
            x = max<long long>(x, solve(l, i - 1) + kkk(i + 1, r, c, cnt - 1));
            overlapCount++;
        }
    }
    
    // Check for DP efficiency
    check_dp_efficiency(overlapCount, 10);  // Example threshold
    
    return B[l][r][c][cnt] = x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);
    memset((S), (-1), sizeof(S));
    memset((B), (-1), sizeof(B));
    cin >> n >> s1;
    for (int i = 0; i < n; i++) cin >> A[i];
    
    // Check for input complexity
    int consecutiveSegments = 0;
    char lastChar = s1[0];
    for (char ch : s1) {
        if (ch == lastChar) {
            consecutiveSegments++;
        } else {
            lastChar = ch;
        }
    }
    check_input_complexity(consecutiveSegments, 70);  // Example threshold
    
    cout << solve(0, n - 1);
    return 0;
}