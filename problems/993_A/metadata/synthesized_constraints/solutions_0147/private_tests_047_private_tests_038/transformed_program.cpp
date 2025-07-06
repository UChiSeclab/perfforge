#include <bits/stdc++.h>
using namespace std;

// Checker for exhaustive point checking
void check_exhaustive_point_checking(int min_x, int max_x, int min_y, int max_y, int threshold) {
    int bounding_box_area = (max_x - min_x) * (max_y - min_y);
    if (bounding_box_area > threshold) {
        cerr << "Warning: exhaustive_point_checking triggered - large bounding box area" << endl;
        abort();
    }
}

// Checker for determinant calculation overhead
void check_determinant_overhead(int determinant_count, int threshold) {
    if (determinant_count > threshold) {
        cerr << "Warning: determinant_overhead triggered - excessive determinant calculations" << endl;
        abort();
    }
}

const int inf = 1000000005;
pair<int, int> A[10], B[10];
int det(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
    int a = B.first - A.first, b = B.second - A.second, c = C.first - A.first,
        d = C.second - A.second;
    return (a * d - b * c);
}

bool inside(pair<int, int> a) {
    int mia = inf, mib = inf;
    int maa = -inf, mab = -inf;
    for (int i = 0; i < 4; ++i) {
        int cura = det(A[i], A[(i + 1) % 4], a),
            curb = det(B[i], B[(i + 1) % 4], a);
        mia = min(mia, cura);
        mib = min(mib, curb);
        maa = max(maa, cura);
        mab = max(mab, curb);
    }
    int ok = 0;
    if (mia >= 0 || maa <= 0) ++ok;
    if (mib >= 0 || mab <= 0) ++ok;
    return (ok == 2);
}

int main() {
    for (int i = 0; i < 4; ++i) scanf("%d%d", &A[i].first, &A[i].second);
    for (int i = 0; i < 4; ++i) scanf("%d%d", &B[i].first, &B[i].second);

    // Bounding box calculation
    int min_x = -100, max_x = 100, min_y = -100, max_y = 100;
    check_exhaustive_point_checking(min_x, max_x, min_y, max_y, 40000);  // Example threshold

    int determinant_count = 0;
    for (int x = min_x; x <= max_x; ++x) {
        for (int y = min_y; y <= max_y; ++y) {
            pair<int, int> cur = {x, y};
            determinant_count += 8;  // Each call to inside invokes det 8 times
            if (inside(cur)) {
                printf("YES");
                return 0;
            }
        }
    }
    
    check_determinant_overhead(determinant_count, 320000);  // Example threshold
    printf("NO");
    return 0;
}