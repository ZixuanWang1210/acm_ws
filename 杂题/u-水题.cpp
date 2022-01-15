#include <bits/stdc++.h>
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

typedef pair<double, int> pdi;
vector<pdi> v;

int n;

bool cmp(pdi &a, pdi &b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    cin >> n;
    
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        v.push_back({(double)b / (double)a, i + 1});
    }

    sort(v.begin(), v.end(), cmp);

    cout << v.front().second;

    return 0;
}
