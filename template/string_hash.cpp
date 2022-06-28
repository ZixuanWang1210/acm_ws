struct StringHash{
    StringHash(int n,string s,int b,int m){
        int len=s.length();
        s=' '+s;

        h.resize(n+1),w.resize(n+1);
        h[0]=0, w[0]=1, base=b, P=m;

        for(int i=1; i<=len; i++)
            h[i] = (h[i-1]*base+s[i])%P, w[i]=w[i-1]*base%P;
    }

    LL get(int l, int r){
        return (h[r]-h[l-1]*w[r-l+1]%P+P)%P;
    }
private:
    LL base, P;
    vector<LL> h,w;
};

// 回文串hash
LL p[maxn],hasL[maxn],hasR[maxn];
string str;

int getHas(int l,int r,LL has[]){
    if(l>r) swap(l,r);
    return (has[r]-has[l-1]*p[r-l+1]%mod)%mod;
}

int n=str.length();
str.resize(2*n);
for(int i=2*n;i;i-=2){
    str[i]=str[i/2];
    str[i-1]='#';
}
n-=1;
n*=2;

int base=1331;
p[0]=1;
for(int i=1,j=n;j<=n;i++,j--){
    hasL[i]=hasL[i-1]*base%mod+str[i];
    hasL[i]%=mod;
    hasR[j]=hasR[j+1]*base%mod+str[j];
    hasR[j]%=mod;
    p[i]=p[i-1]*base%mod;
}
