#include <iostream>
#include <cstdio>
using namespace std;

int n;
int xx[105], yy[105];
int cnt, po;
int s1, s2, s3, s4;

void check_excessive_iterations(int x20390, int y12098, int x21981, int y98911) {
    if ((x21981 - x20390) > 25 || (y98911 - y12098) > 25) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested loop iterations!" << endl;
        abort();
    }
}

void check_repeated_boundary_checks(int s1, int s2, int s3, int s4, int n) {
    if (s1 < n || s2 < n || s3 < n || s4 < n) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated boundary checks!" << endl;
        abort();
    }
}

void check_sparse_distribution(int cnt, int n) {
    if (cnt > 1) {
        cerr << "Warning: Performance bottleneck condition triggered - sparse distribution of points!" << endl;
        abort();
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 4 * n + 1; i++) {
        scanf("%d%d", &xx[i], &yy[i]);
    }
    
    for (int x20390 = 0; x20390 <= 50; x20390++) {
        for (int y12098 = 0; y12098 <= 50; y12098++) {
            for (int x21981 = x20390; x21981 <= 50; x21981++) {
                for (int y98911 = y12098; y98911 <= 50; y98911++) {
                    check_excessive_iterations(x20390, y12098, x21981, y98911);
                    
                    s1 = s2 = s3 = s4 = cnt = po = 0;
                    for (int k = 1; k <= 4 * n + 1; k++) {
                        int x = xx[k], y = yy[k];
                        int f = 0;
                        if (x == x20390 && y >= y12098 && y <= y98911) {
                            s1++;
                            f = 1;
                        }
                        if (x == x21981 && y >= y12098 && y <= y98911) {
                            s2++;
                            f = 1;
                        }
                        if (y == y12098 && x >= x20390 && x <= x21981) {
                            s3++;
                            f = 1;
                        }
                        if (y == y98911 && x >= x20390 && x <= x21981) {
                            s4++;
                            f = 1;
                        }
                        if (!f) cnt++, po = k;
                    }
                    
                    // Check repeated boundary conditions
                    check_repeated_boundary_checks(s1, s2, s3, s4, n);
                    
                    // Check if exactly one point isn't on the boundary
                    check_sparse_distribution(cnt, n);
                    
                    if (s1 >= n && s2 >= n && s3 >= n && s4 >= n && cnt == 1) {
                        printf("%d %d\n", xx[po], yy[po]);
                        return 0;
                    }
                }
            }
        }
    }
}