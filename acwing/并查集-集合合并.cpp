#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int n, m;
int p[maxn];

int find(int x){ //返回x所在集合的根节点 + 路径压缩
    if(x != p[x]) p[x] = find(p[x]); // 不是根节点 -> 父节点=根节点
    return p[x]; //回溯返回根节点
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i; //树根等于自己

    while(m--){
        char op;
        int a, b;
        cin >> op >> a >> b;
        if(op == 'Q'){
            if(find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else{
            p[find(a)] = find(b); //让a的根节点的父亲等于b节点
        }
    }
    return 0;
}