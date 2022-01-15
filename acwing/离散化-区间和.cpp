#include<bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
typedef pair<int, int> pii;
vector<pii> add, query;
vector<int> alls;

int n, m;
int a[maxn], b[maxn];

int upper_bound(int x){
    int l = 0, r = alls.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(alls[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l + 1;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
       int x, c;
       cin >> x >> c;
       add.push_back({x, c});

       alls.push_back(x);
    }

    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end(), alls.end()));

    for(auto item : add){
        int x = upper_bound(item.first);
        a[x] += item.second;
    }

    for(int i = 1; i <= alls.size(); i++){
        b[i] = b[i - 1] + a[i];
    }

    for(auto item : query){
        int l = upper_bound(item.first), r = upper_bound(item.second);
        cout << b[r] - b[l - 1] << endl;
    }
}