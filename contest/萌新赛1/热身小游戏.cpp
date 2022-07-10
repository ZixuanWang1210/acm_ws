#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=2e5+10;

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");
 
private:
	using ll = long long;
 
	int v;
 
	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}
 
public:
 
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
 
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
 
	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }
 
	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}
 
	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}
 
	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
 
template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}
 
using Mint = modnum<int(1e9) + 7>;

struct node{
    int l,r;
    Mint w;
    Mint lazy;
} tr[maxn<<2];

#define rt tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]

void pushup(int u){
    rt.w=ls.w*rs.w;
}

void pushdown(int u){
    if((int)rt.lazy){
        ls.lazy=rt.lazy;
        // ls.w*=ls.lazy;
        rs.lazy=rt.lazy;
        ls.w=1;
        rs.w=1;
        // rs.w*=rs.lazy;
        rt.lazy=0;
    }
}

void build(int u,int l,int r){
    if(l==r) rt={l,l,1,0};
    else{
        tr[u]={l,r,1,0};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r){
    if(rt.l>=l&&rt.r<=r){
        rt.lazy=1,rt.w=1;
    }
    else{
        pushdown(u);
        int mid=rt.l+rt.r>>1;
        if(l<=mid) modify(u<<1,l,r);
        if(r>mid) modify(u<<1|1,l,r);
        pushup(u);
    }
}

void modify1(int u,int l,int r,int k){
    if(rt.l>=l&&rt.r<=r){
        // rt.lazy=1,rt.w=1;
        rt.w=k;
    }
    else{
        pushdown(u);
        int mid=rt.l+rt.r>>1;
        if(l<=mid) modify1(u<<1,l,r,k);
        if(r>mid) modify1(u<<1|1,l,r,k);
        pushup(u);
    }
}

auto query(int u,int l,int r){
    if(l<=rt.l&&r>=rt.r) return rt.w;
    else{
        pushdown(u);
        int mid=rt.l+rt.r>>1;
        Mint sum=1;
        if(l<=mid) sum*=query(u<<1,l,r);
        if(r>mid) sum*=query(u<<1|1,l,r);
        return sum;
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int q; cin>>q;
    build(1,1,q);
    Mint n=1;
    for(int i=1;i<=q;i++){
        int op; cin>>op;
        if(op==1){
            int x; cin>>x;
            modify1(1,i,i,x);
            // n=n*x;
            // cout<<query(1,1,q)<<endl;
        }
        else if(op==2){
            int l,r; cin>>l>>r;
            modify(1,l,r);
            // int res=query(1,l,r);
        }
        else cout<<query(1,1,q)<<endl;
    }

    return 0;
}
