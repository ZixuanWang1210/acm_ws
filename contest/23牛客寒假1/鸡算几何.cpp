#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;
using point_t=long double;  //全局数据类型，可修改为 long long 等

constexpr point_t eps=1e-8;
constexpr long double PI=3.1415926535897932384l;

// 点与向量
using T= double;
struct Point{
    T x,y;

    bool operator==(const Point &a) const {return (abs(x-a.x)<=eps && abs(y-a.y)<=eps);}
    bool operator<(const Point &a) const {if (abs(x-a.x)<=eps) return y<a.y-eps; return x<a.x-eps;}
    bool operator>(const Point &a) const {return !(*this<a || *this==a);}
    Point operator+(const Point &a) const {return {x+a.x,y+a.y};}
    Point operator-(const Point &a) const {return {x-a.x,y-a.y};}
    Point operator-() const {return {-x,-y};}
    Point operator*(const T k) const {return {k*x,k*y};}
    Point operator/(const T k) const {return {x/k,y/k};}
    T operator*(const Point &a) const {return x*a.x+y*a.y;}  // 点积
    T operator^(const Point &a) const {return x*a.y-y*a.x;}  // 叉积，注意优先级
    int toleft(const Point &a) const {const auto t=(*this)^a; return (t>eps)-(t<-eps);}  // to-left 测试
    T len2() const {return (*this)*(*this);}  // 向量长度的平方
    T dis2(const Point &a) const {return (a-(*this)).len2();}  // 两点距离的平方

    // 涉及浮点数
    long double len() const {return sqrtl(len2());}  // 向量长度
    long double dis(const Point &a) const {return sqrtl(dis2(a));}  // 两点距离
    long double ang(const Point &a) const {return acosl(max(-1.0l,min(1.0l,((*this)*a)/(len()*a.len()))));}  // 向量夹角
    Point rot(const long double rad) const {return {x*cos(rad)-y*sin(rad),x*sin(rad)+y*cos(rad)};}  // 逆时针旋转（给定角度）
    Point rot(const long double cosr,const long double sinr) const {return {x*cosr-y*sinr,x*sinr+y*cosr};}  // 逆时针旋转（给定角度的正弦与余弦）
};

T dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
 
T cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

void sol(){
    Point a[6];
    for(int i=0;i<6;i++){
        cin>>a[i].x>>a[i].y;
    }

    if(cross(a[0]-a[1],a[2]-a[1])<0) swap(a[0],a[2]);
    if(cross(a[3]-a[4],a[5]-a[4])<0) swap(a[3],a[5]);

    double len0=sqrt(dot(a[0]-a[1],a[0]-a[1]));
    double len1=sqrt(dot(a[3]-a[4],a[3]-a[4]));

    if(abs(len0-len1)>eps) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
