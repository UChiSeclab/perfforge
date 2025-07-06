#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int F[N][N];

// Function to check for large area overlap
void check_large_area_overlap(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large area overlap detected!" << endl;
        abort();
    }
}

// Function to check for extensive matrix traversal
void check_extensive_matrix_traversal(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive matrix traversal detected!" << endl;
        abort();
    }
}

int main() {
    int x1 = 200, y1 = 200, x2 = 0, y2 = 0;
    for (int i = 1; i <= 4; i++) {
        int x, y;
        cin >> x >> y;
        x += 100;
        y += 100;
        x1 = min(x, x1);
        y1 = min(y, y1);
        x2 = max(x, x2);
        y2 = max(y, y2);
    }
    x1 *= 2;
    y1 *= 2;
    x2 *= 2;
    y2 *= 2;

    // Check if the area of the first square is large enough to cause potential slowdowns
    int area1 = (x2 - x1) * (y2 - y1);
    check_large_area_overlap(area1 > 1000); // arbitrary threshold for demonstration

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            F[i][j] = 1;
        }
    }

    x1 = 200, y1 = 200, x2 = 0, y2 = 0;
    for (int i = 1; i <= 4; i++) {
        int x, y;
        cin >> x >> y;
        x += 100;
        y += 100;
        x1 = min(x, x1);
        y1 = min(y, y1);
        x2 = max(x, x2);
        y2 = max(y, y2);
    }
    x1 *= 2;
    y1 *= 2;
    x2 *= 2;
    y2 *= 2;

    int yy = (y1 + y2) / 2, xx = (x1 + x2) / 2;

    // Check for potential extensive matrix traversal
    check_extensive_matrix_traversal((x2 - x1) * (y2 - y1) > 1000); // arbitrary threshold for demonstration

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (F[i][j] == 0) continue;
            int x = j - i, y = i + j;
            if (x <= yy - x1 && x >= yy - x2 && y <= xx + y2 && y >= xx + y1) {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
}