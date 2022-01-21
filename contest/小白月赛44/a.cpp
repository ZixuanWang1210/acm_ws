#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
// typedef unsigned long long ull;
#define pii pair<int,pair<int,int>>
using namespace std;

int t, n;
const int maxn = 2e5 +10;
int a[maxn], b[maxn];
// priority_queue<pii, vector<pii>, greater<pii>> q;

struct point{
    ll key, l, r;
    bool operator < (point& x) const{
        return key > x.key;
        if(key == x.key){
            return l > x.l;
        }
    }
};
vector<point> q;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        int n; cin >> n;
        int l, r;
        for(int i = 1; i <= n; i ++ ){
            cin >> a[i];
            b[i] = a[i] - a[i - 1];
        }
        int flag = false;
        for(int i = 1; i <= n; i ++){
            ll l, r; l = i;
            if(flag == true){
                // l --;
                i ++;
                flag = false;
                if(i > n) break;
            }

            while((a[i] - a[i-1]) >= 0){
                i ++;
            }
            r = --i;
            flag = true;
            ll key = a[r] - a[l];
            point t = {key, l, r};
            q.push_back(t);
        }

        sort(q.begin(), q.end());

        ll tt = q[0].key;
        for(auto x : q){
            if(tt == x.key) cout << x.l << ' '<< x.r << " ";
        }
        cout << endl;
    }
    

    return 0;
}
