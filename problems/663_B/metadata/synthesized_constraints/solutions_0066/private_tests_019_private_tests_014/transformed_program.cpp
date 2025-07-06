#include <bits/stdc++.h>
using namespace std;
const int N = 510000;
long long a[N], ten[N], ans[N];
struct node {
    long long x, y;
} b[N];
bool cmp(const node &a, const node &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
char s[N];

void check_sort_invariant(int elementCount) {
    if (elementCount > 50000) {
        cerr << "Warning: sort_invariant triggered - potentially sorting a large dataset" << endl;
        abort();
    }
}

void check_loop_invariant(int up) {
    if (up > 3000) {
        cerr << "Warning: loop_invariant triggered - excessive iterations in nested loops" << endl;
        abort();
    }
}

void check_deduplication_invariant(int duplicateCount) {
    if (duplicateCount > 10000) {
        cerr << "Warning: deduplication_invariant triggered - high overhead due to duplicates" << endl;
        abort();
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", s + 1);
        long long n = 0;
        int len = 0;
        for (int i = 1; i <= strlen(s + 1); i++)
            if (s[i] >= '0' && s[i] <= '9') n = n * 10 + s[i] - '0', len++;
        int top = 0;
        for (int i = 1; i <= len; i++) {
            a[++top] = n % 10;
            n /= 10;
        }
        ten[0] = 1;
        for (int i = 1; i <= 20; i++) ten[i] = ten[i - 1] * 10;
        for (int i = 1; i <= top; i++) a[i] = a[i - 1] + ten[i - 1] * a[i];
        int tp = 0;
        for (int i = 1; i <= top; i++) {
            int up = 0;
            if (i == 1)
                up = 3000;
            else if (i == 2)
                up = 700;
            else
                up = 300;
            
            check_loop_invariant(up); // Invariant check for loop condition
            
            for (int j = 0; j <= up; j++) {
                if (a[i] + j * ten[i] < 1989) continue;
                b[++tp].x = a[i] + j * ten[i];
                b[tp].y = i;
            }
        }
        
        check_sort_invariant(tp); // Invariant check before sorting

        sort(b + 1, b + 1 + tp, cmp);
        for (int i = 1; i <= top; i++) ans[i] = 0;
        
        int duplicateCount = 0; // Track duplicates
        
        for (int l = 1; l <= tp;) {
            int r = l;
            while (r < tp && b[r + 1].x == b[l].x) r++;
            
            duplicateCount += (r - l); // Counting duplicates
            
            for (int i = l; i <= r; i++)
                if (ans[b[i].y] == 0) {
                    ans[b[i].y] = b[i].x;
                    break;
                }
            l = r + 1;
        }
        
        check_deduplication_invariant(duplicateCount); // Invariant check for deduplication
        
        cout << ans[top];
        printf("\n");
    }
}