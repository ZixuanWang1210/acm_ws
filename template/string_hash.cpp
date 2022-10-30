struct StringHash{
    StringHash(string s,int b=13331,LL m=LLONG_MAX){
        int n=s.length();
        s=' '+s;
        h.resize(n+1),w.resize(n+1);
        h[0]=0, w[0]=1, base=b, P=m;
        for(int i=1; i<=n; i++)
            h[i] = (h[i-1]*base+s[i])%P, w[i]=w[i-1]*base%P;
    }

    LL get(int l, int r){
        return (h[r]-h[l-1]*w[r-l+1]%P+P)%P;
    }
private:
    LL base, P;
    vector<LL> h,w;
};