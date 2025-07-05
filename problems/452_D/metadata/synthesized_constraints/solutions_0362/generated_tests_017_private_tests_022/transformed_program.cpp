#include <bits/stdc++.h>
using namespace std;

struct st {
    long long time, num;
    int id;
    st(long long a, long long b, int c) {
        time = a;
        id = c;
        num = b;
    }
};

bool operator<(const st &a, const st &b) {
    if (a.time != b.time) return a.time < b.time;
    return a.id > b.id;
}

multiset<st> a;

// Function to check the drying machine bottleneck
void check_drying_bottleneck(int t1, int t2, int n1, int n2) {
    if ((t2 > 2 * t1) && (n2 <= n1)) {
        cerr << "Warning: Performance bottleneck - Drying machines are a bottleneck!" << endl;
        abort();
    }
}

// Function to check task overlap management
void check_task_overlap(int n1, int n2, int t1, int t2) {
    int washingCapacity = n1 * t1;
    int dryingCapacity = n2 * t2;
    if (dryingCapacity < washingCapacity) {
        cerr << "Warning: Performance bottleneck - Overlap management issue!" << endl;
        abort();
    }
}

// Function to check multiset overuse
void check_multiset_overuse(int usageCount, int threshold) {
    if (usageCount > threshold) {
        cerr << "Warning: Performance bottleneck - Excessive use of multiset!" << endl;
        abort();
    }
}

int main() {
    int k, n1, n2, n3, t1, t2, t3;
    scanf("%d%d%d%d%d%d%d", &k, &n1, &n2, &n3, &t1, &t2, &t3);

    // Check drying bottleneck conditions
    check_drying_bottleneck(t1, t2, n1, n2);

    // Check task overlap conditions
    check_task_overlap(n1, n2, t1, t2);

    long long a1, a2;
    a1 = a2 = 0;
    a.insert(st(t1, n1, 1));
    int usageCount = 0;
    int multisetThreshold = 50000; // Arbitrary high threshold for demonstration

    while (k > 0) {
        st tmp = *a.begin();
        a.erase(a.begin());
        usageCount++;

        if (tmp.id == 1) {
            if (n2) {
                a.insert(st(tmp.time + t2, min((long long)n2, tmp.num), 2));
                a.insert(st(tmp.time + t1, min((long long)n2, tmp.num), 1));
            }
            if (tmp.num > n2) {
                a.insert(st(tmp.time + 1, tmp.num - n2, 1));
            }
            n2 -= min((long long)n2, tmp.num);
        } else if (tmp.id == 2) {
            if (n3) {
                a.insert(st(tmp.time + t3, min((long long)n3, tmp.num), 3));
            }
            if (tmp.num > n3) {
                a.insert(st(tmp.time + 1, tmp.num - n3, 2));
            }
            n2 += min((long long)n3, tmp.num);
            n3 -= min((long long)n3, tmp.num);
        } else {
            k -= tmp.num;
            n3 += tmp.num;
            if (k <= 0) {
                printf("%I64d\n", tmp.time);
                return 0;
            }
        }
    }

    // Check multiset overuse after loop
    check_multiset_overuse(usageCount, multisetThreshold);
}