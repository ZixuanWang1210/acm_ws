#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
#define _all(x) x.begin(), x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

template <typename T>
struct ST {
    ST(T a[], int n) {
        siz = n;
        maxv.resize(n + 1);
        minv.resize(n + 1);
        int t = __lg(n) + 1;
        for (int i = 0; i <= n; i++) maxv[i].resize(t), minv[i].resize(t);
        for (int i = 0; i <= n; i++) maxv[i][0] = minv[i][0] = i;
        for (int j = 1; j < t; j++) {
            for (int i = 0; i <= n - (1 << j) + 1; i++) {
                int x = maxv[i][j - 1], y = maxv[i + (1 << (j - 1))][j - 1];
                maxv[i][j] = a[x] > a[y] ? x : y;
                x = minv[i][j - 1], y = minv[i + (1 << (j - 1))][j - 1];
                minv[i][j] = a[x] < a[y] ? x : y;
            }
        }
    }
    T getmax(T a[], int l, int r) {
        int k = __lg(r - l + 1);
        int x = maxv[l][k], y = maxv[r - (1 << k) + 1][k];
        return a[x] > a[y] ? x : y;
    }
    T getmin(T a[], int l, int r) {
        int k = __lg(r - l + 1);
        int x = minv[l][k], y = minv[r - (1 << k) + 1][k];
        return a[x] < a[y] ? x : y;
    }

private:
    int siz = 0;
    vector<vector<T>> maxv, minv;
};

void sol() {
    int n;
    cin >> n;
    int a[n + 2] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ST<int> st(a, n);

    int Rmin[n + 1] = {0}, Rmax[n + 1] = {0};
    a[0] = a[n + 1] = inf;

    for (int i = n; i >= 1; i--) {
        Rmax[i] = i;
        while (a[i] >= a[Rmax[i] + 1]) Rmax[i] = Rmax[Rmax[i] + 1];
    }

    a[0] = a[n + 1] = -inf;
    for (int i = n; i >= 1; i--) {
        Rmin[i] = i;
        while (a[i] <= a[Rmin[i] + 1]) Rmin[i] = Rmin[Rmin[i] + 1];
    }

    // for(int i=1;i<=n;i++){
    //     cout<<Rmin[i]<<' '<<Rmax[i]<<endl;
    // }

    int idx = 1;
    int ans = 0;
    while (idx < n) {
        if (a[idx] > a[idx + 1]) {
            int R = Rmax[idx];
            R = st.getmin(a, idx, R);
            ans++;
            idx = R;
        } else {
            int R = Rmin[idx];
            R = st.getmax(a, idx, R);
            ans++;
            idx = R;
        }
    }
    cout << ans << endl;
    // cout<<st.getmin(a,4,10)<<endl;
    // // cout<<st.getmin(a,4,10)<<endl;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_--) {
        sol();
    }

    return 0;
}
