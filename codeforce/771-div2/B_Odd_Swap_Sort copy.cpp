#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int t;

void sol() {
    int n;
    cin >> n;
    vector<int> v(2*n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> odd(n), even(n);
    for (int i=0;i<n;i++) {
        int x=v[i];
        if (x & 1)
            odd.push_back(x);
        else
            even.push_back(x);
    }

    // for(auto x:odd){
    //     cout<<x<<endl;
    // }

    int ok = is_sorted(odd.begin(), odd.end()) & is_sorted(even.begin(), even.end());
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        sol();
    }

    return 0;
}
