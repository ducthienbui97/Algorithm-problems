#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double EPS = 1e-9;
class Point {
    public:
        double x,y;
        Point(double _x = 0,double _y = 0):
            x(_x),y(_y) {}
        Point(const Point& other):
            x(other.x),y(other.y){}
        Point operator - (const Point& other){
            return Point(x - other.x,y - other.y);
        }

    };
bool same(double a,double b){
    return abs(a-b) < EPS;
}
class Line {
    public:
        double a,b,c; // a*x + b*y  = c
        Line(Point p = Point(0,0),Point q= Point(0,0)):
            a(q.y - p.y),b(p.x - q.x),c(p.x*(q.y - p.y) + p.y*(p.x - q.x)){}
        bool parallel(Line other){
            return same(a*other.b,b*other.a) && !same(a*other.c,c*other.a);
        }
        bool same(Line other){
            return same(a*other.b,b*other.a) && same(a*other.c ,c*other.a);
        }
        void reduce(double x){
            a/=x,b/=x,c/=x;
        }
        void minus(Line& other,double mul){
            other.a -= a*mul,other.b -= b*mul,other.c -= c*mul;
        }
    };
Point crossed(Line l1,Line l2){
        l1.reduce(l1.a);
        l1.minus(l2,l2.a);
        l2.reduce(l2.b);
        l2.minus(l1,l1.b);
        if(same(l1.c,0)) l1.c = 0;
        if(same(l2.c,0)) l2.c = 0;
        return Point(l1.c,l2.c);
}
double area(Point a,Point b,Point c){
    Point v1 = Point(b.x-a.x,b.y-a.y);
    Point v2 = Point(c.x-a.x,c.y-a.y);
    return abs(v1.x*v2.y - v1.y*v2.x);
}
main(){
    ios_base::sync_with_stdio(false);
    double a,b;
    cin >> a>>b;
    Point centroid(0,0);
    double c = sqrt(a*a + b*b)/2;
    Point starterPoints[4],fixedPoints[4];
    Line fixedLines[4],starterLines[4];
    fixedPoints[0] = Point(-a/2,-b/2);
    fixedPoints[1] = Point(a/2,-b/2);
    fixedPoints[2] = Point(a/2,b/2);
    fixedPoints[3] = Point(-a/2,b/2);
    for(int i = 0; i < 4 ; i++)
        fixedLines[i] = Line(fixedPoints[i],fixedPoints[(i+1)&3]);
    double it = PI/180;
    double initial_angle = acos((a/2)/c);
    double min_V = -1e9;
    bool switched = false;
    for(int cc = 0; cc < 180;cc++){
        double angle = initial_angle + it*cc;
        double s = a*b;
        starterPoints[0] = Point(-cos(angle)*c,-sin(angle)*c);
        starterPoints[1] = Point(sin(angle)*c,-cos(angle)*c);
        starterPoints[2] = Point(cos(angle)*c,sin(angle)*c);
        starterPoints[3] = Point(-sin(angle)*c,cos(angle)*c);
        for(int i = 0; i < 4 ; i++)
            starterLines[i] = Line(starterPoints[i],starterPoints[(i+1)&3]);

        if(same(starterPoints[0],fixedPoints[1])
           switched = true;
        if(!switched){
            for(int i = 0; i < 4;i++)
                s+= area(starterPoint[i],crossed(fixedLines[i],starterLines[i]),crossed(fixedLines[i],starterLines[(i+3)&3]));
        }else{
            for(int i = 0; i < 4; i+=2){
                Point p1 = crossed(fixedLines[i],starterLines[(i+1)&3]);

            }
        }
    }
}
