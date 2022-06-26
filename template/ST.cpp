template<typename T> struct ST{
    ST(T a[], int n){
        siz = n;
        maxv.resize(n+1); minv.resize(n+1);
        int t = __lg(n) + 1;
        for(int i= 0;i<=n;i++) maxv[i].resize(t), minv[i].resize(t);
        for(int i = 0; i <= n; i++) maxv[i][0] = minv[i][0] = a[i];
        for(int j = 1; j < t; j++) 
        {
            for(int i = 0; i <= n - (1<<j)+1; i++)
            {
                maxv[i][j] = max(maxv[i][j-1], maxv[i+(1 << (j-1))][j-1]);
                minv[i][j] = min(minv[i][j-1], minv[i+(1 << (j-1))][j-1]);
            }
        }
    }
    T getmax(int l,int r){
	    int k = __lg(r-l+1);
	    return max(maxv[l][k],maxv[r-(1<<k)+1][k]);
    }    
    T getmin(int l,int r){
	    int k = __lg(r-l+1);
	    return min(minv[l][k],minv[r-(1<<k)+1][k]);
    }    
private:
    int siz = 0;
    vector<vector<T>> maxv, minv;
};

ST<ll> s(pre, n);
ll p1 = s.getmin(left[i], i-1), p2 = s.getmax(i, right[i] - 1);

// 最大值位置
template <typename T>
struct ST {
    ST(T a[], int n) {
        siz = n;
        maxv.resize(n + 1);
        minv.resize(n + 1);
        int t = __lg(n) + 1;
        for (int i = 0; i <= n; i++) maxv[i].resize(t), minv[i].resize(t);
        for (int i = 0; i <= n; i++) maxv[i][0] = minv[i][0] = i;
        for (int j = 1; j < t; j++) {
            for (int i = 0; i <= n - (1 << j) + 1; i++) {
                int x = maxv[i][j - 1], y = maxv[i + (1 << (j - 1))][j - 1];
                maxv[i][j] = a[x] > a[y] ? x : y;
                x = minv[i][j - 1], y = minv[i + (1 << (j - 1))][j - 1];
                minv[i][j] = a[x] < a[y] ? x : y;
            }
        }
    }
    T getmax(T a[], int l, int r) {
        int k = __lg(r - l + 1);
        int x = maxv[l][k], y = maxv[r - (1 << k) + 1][k];
        return a[x] > a[y] ? x : y;
    }
    T getmin(T a[], int l, int r) {
        int k = __lg(r - l + 1);
        int x = minv[l][k], y = minv[r - (1 << k) + 1][k];
        return a[x] < a[y] ? x : y;
    }

private:
    int siz = 0;
    vector<vector<T>> maxv, minv;
};