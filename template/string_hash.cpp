struct StringHash{
    LL h[N], w[N], base, P;
    void init(LL b, LL m){
        h[0]=0, w[0]=1, base=b, P=m;
    }
    void add(char *s){
        int len=strlen(s+1);
        for(int i=1; i<=len; i++)
            h[i] = (h[i-1]*base+s[i])%P, w[i]=w[i-1]*base%P;
    }
    LL get(int l, int r){
        return (h[r]-h[l-1]*w[r-l+1]%P+P)%P;
    }
}has;