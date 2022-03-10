#include <bits/stdc++.h>
using namespace std;

multiset<long long> mts;
int Q;
int main() {
    cin >> Q;
    int op, k;
    long long x;
    while (Q--) {
        cin >> op >> x;
        if (op == 1) {
            mts.insert(x);
        } else {
            cin >> k;
            if (op == 2) {
                auto p = mts.upper_bound(x);
                while (p != mts.begin() && k) {
                    --k;
                    --p;
                }
                if (k)
                    printf("-1\n");
                else
                    printf("%lld\n", *p);
            } else {
                --k;
                auto p = mts.lower_bound(x);
                while (p != mts.end() && k) {
                    --k;
                    ++p;
                }
                if (p == mts.end())
                    printf("-1\n");
                else
                    printf("%lld\n", *p);
            }
        }
    }
    return 0;
}