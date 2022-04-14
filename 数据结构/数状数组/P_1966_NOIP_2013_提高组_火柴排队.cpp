#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;

const int maxn=1e5+10;
int a[maxn],b[maxn],c[maxn],bb[maxn];
struct node{
    int num,ord;
} fi[maxn],se[maxn];
int ans;
int n;
vector<int> mp;

bool cmp(node x,node y){
    return x.num<y.num;
}

int get(int x){
    return lower_bound(mp.begin(),mp.end(),x)-mp.begin()+1;
}

void merge_sort(int l, int r){
    if(l >= r) return;

    int mid = l + r >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(c[i] <= c[j]) bb[k++] = c[i++];
        else{
            bb[k++] = c[j++];
            ans += mid - i + 1; //使用全局变量存储答案
            ans%=99999997;
        }
    }
    while(i <= mid) bb[k++] = c[i++];
    while(j <= r) bb[k++] = c[j++];

    for(int k = 0, i = l; i <= r; i++){
        c[i] = bb[k++];
    }
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>fi[i].num;
        fi[i].ord=i;
    }
    for(int i=1;i<=n;i++){
        cin>>se[i].num;
        se[i].ord=i;
    }
    sort(fi+1,fi+1+n,cmp);
    sort(se+1,se+1+n,cmp);
    for(int i=1;i<=n;i++){
        c[fi[i].ord]=se[i].ord;
    }

    merge_sort(1,n);
    cout<<ans<<endl;


    return 0;
}
