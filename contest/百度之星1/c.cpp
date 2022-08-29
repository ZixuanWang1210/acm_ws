#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;

int num[maxn], n, ans[maxn];//num记录原始数字，ans记录每个数字的归属

vector <int> ve[2];//ve[0]维护递减子序列，ve[1]维护递增子序列

void init() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d", &num[i]);

    ve[0].push_back(1e9);
    ve[1].push_back(-1);
}

int solve() {
    for(int i=1;i<=n;i++) {
        if((num[i] > *ve[1].rbegin() && num[i] < *ve[0].rbegin())) {
            if(num[i+1] >= num[i]) {
                ve[1].push_back(num[i]);
                ans[i] = 0;
            } else {
                ve[0].push_back(num[i]);
                ans[i] = 1;
            }
        } else if(num[i] <= *ve[0].rbegin()) {
            ans[i] = 1;
            ve[0].push_back(num[i]);
        } else if(num[i] >= *ve[1].rbegin()) {
            ans[i] = 0;
            ve[1].push_back(num[i]);
        } else {
            return 0;
        }
    }

    return 1;
}

void Print() {
    puts("YES");

    for(int i=1;i<=n;i++) {
        printf("%d ", ans[i]);
    }
}

int main() {
//    freopen("1.in", "r", stdin);
    init();
    int flag = solve();
    if(!flag) {
        puts("NO");
        return 0;
    }
    Print();

    return 0;
}
