#include<bits/stdc++.h>
using namespace std;

int mp[10000][10000]={0},mp2[10000][10000]={0};

void sol(){
    int n,k,x;
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
        }
    }
    int xx=1;
    for(int i=2;i<=n;i+=2){
        if(xx==k+1) xx=1;
        for(int j=1;j<=n;j++){
            mp2[j+xx][i]=mp[j][i];
        }
        xx++;
    }

    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            if(j%2==0){
                if(mp2[i][j]==0) mp2[i][j]=x;
                sum+=mp2[i][j];
            }
            else sum+=mp[i][j];
        }
        cout<<sum;
        if(i!=n) cout<<" ";
    }
    return;
}

int main(){
    int t; t=1;
    while(t--) sol();
    
    return 0;
}