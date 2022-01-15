#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
typedef pair<int, int> pii;

vector<int> v;
vector<pii> add, quire;

int n, m;
int a[maxn], s[maxn];

int upper_bound(int x){
    int l = 0, r = v.size() - 1;
    while(l < r){
        int mid = r + l >> 1;
        if(x > v[mid]) l = mid + 1;
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
        v.push_back(x);
    }

    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        quire.push_back({l, r});
        v.push_back(l);
        v.push_back(r);
    }
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 0; i < add.size(); i++){
        int x = upper_bound(add[i].first);
        a[x] += add[i].second;
    }

    for(int i = 1; i <= v.size(); i++){
        s[i] = s[i - 1] + a[i];
    }

    for(int i = 0; i < quire.size(); i++){
        int l = upper_bound(quire[i].first), r = upper_bound(quire[i].second);
        cout << s[r] - s[l - 1] << endl;
    }
}