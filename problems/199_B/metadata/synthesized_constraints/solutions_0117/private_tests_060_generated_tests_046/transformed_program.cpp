#include <bits/stdc++.h>
const double pi = acos(-1.0);
double GetDis(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Checker functions
void check_encompassing_radii(double innerR, double outerR, double otherInnerR, double otherOuterR, double centerDistance) {
    if (centerDistance + otherOuterR <= outerR && centerDistance + otherInnerR >= innerR) {
        cerr << "Warning: Performance bottleneck condition triggered - encompassing radii!" << endl;
        abort();
    }
}

void check_trigonometric_load(double centerDistance, double r1, double R1, double r2, double R2) {
    if (centerDistance < std::abs(R1 - R2) || centerDistance > r1 + R2) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive trigonometric load!" << endl;
        abort();
    }
}

void check_non_intersecting_bands(double centerDistance, double r1, double R1, double r2, double R2) {
    if (centerDistance >= R1 + r2) {
        cerr << "Warning: Performance bottleneck condition triggered - non-intersecting bands!" << endl;
        abort();
    }
}

int main() {
    double xx, yy, dis, EPS;
    double x[2], y[2], r[2], R[2];
    scanf("%lf%lf%lf%lf", &x[0], &y[0], &r[0], &R[0]);
    scanf("%lf%lf%lf%lf", &x[1], &y[1], &r[1], &R[1]);
    
    double centerDistance = GetDis(x[0], y[0], x[1], y[1]);
    
    // Insert the checks at the beginning
    check_encompassing_radii(r[0], R[0], r[1], R[1], centerDistance);
    check_encompassing_radii(r[1], R[1], r[0], R[0], centerDistance);
    
    check_trigonometric_load(centerDistance, r[0], R[0], r[1], R[1]);
    check_trigonometric_load(centerDistance, r[1], R[1], r[0], R[0]);
    
    check_non_intersecting_bands(centerDistance, r[0], R[0], r[1], R[1]);
    check_non_intersecting_bands(centerDistance, r[1], R[1], r[0], R[0]);
    
    int ans = 0;
    bool flag = true;
    
    for (int i = 0; i <= 360000; i++) {
        EPS = i / 180000.0 * pi;
        xx = x[1] + cos(EPS) * r[1];
        yy = y[1] + sin(EPS) * r[1];
        dis = GetDis(xx, yy, x[0], y[0]);
        if (dis > r[0] && dis < R[0]) {
            flag = false;
            break;
        }
    }
    if (flag) ans++;
    
    flag = true;
    for (int i = 0; i <= 360000; i++) {
        EPS = i / 180000.0 * pi;
        xx = x[1] + cos(EPS) * R[1];
        yy = y[1] + sin(EPS) * R[1];
        dis = GetDis(xx, yy, x[0], y[0]);
        if (dis > r[0] && dis < R[0]) {
            flag = false;
            break;
        }
    }
    if (flag) ans++;
    
    flag = true;
    for (int i = 0; i <= 360000; i++) {
        EPS = i / 180000.0 * pi;
        xx = x[0] + cos(EPS) * r[0];
        yy = y[0] + sin(EPS) * r[0];
        dis = GetDis(xx, yy, x[1], y[1]);
        if (dis > r[1] && dis < R[1]) {
            flag = false;
            break;
        }
    }
    if (flag) ans++;
    
    flag = true;
    for (int i = 0; i <= 360000; i++) {
        EPS = i / 180000.0 * pi;
        xx = x[0] + cos(EPS) * R[0];
        yy = y[0] + sin(EPS) * R[0];
        dis = GetDis(xx, yy, x[1], y[1]);
        if (dis > r[1] && dis < R[1]) {
            flag = false;
            break;
        }
    }
    if (flag) ans++;
    
    printf("%d\n", ans);
    return 0;
}