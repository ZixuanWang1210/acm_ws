for(int i=1;i<=n;i++) cin>>k[i];
k[0]=k[n+1]=inf;

for(int i=1;i<=n;i++){
    L[i]=i;
    while(k[i]>=k[L[i]-1]) L[i]=L[L[i]-1];
}
for(int i=n;i>=1;i--){
    R[i]=i;
    while(k[i]>=k[R[i]+1]) R[i]=R[R[i]+1];
}