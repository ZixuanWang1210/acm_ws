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
