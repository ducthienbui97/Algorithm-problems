#include <iostream>
#include <vector>
using namespace std;
#define maxn 500001
#define For(i,N) for(int i=0; i<N; i++)
#define oo 1000000000
#define lmax 20000000
#define eps 1e-6

int x[maxn], y[maxn], N, x1, y1, x2, y2, a1, a2, b1, b2;
double dbest;
bool yes;

//swap a and b
void swap(int &a, int &b){
    int sw = a;
    a = b;
    b = sw;
}
//read input
void read(){
    scanf("%d", &N);
    For(i,N) scanf("%d%d", x+i, y+i);
    x[N]=x[0], y[N]=y[0];
    double s = 0;
    For(i,N)
        s += (x[i+1]-x[i]+0.0)*(y[i+1]+y[i]);
    ////cout<<s<<endl;
    if (s > 0)
        For(i,(N+1)/2)
            swap(x[i], x[N-i]), swap(y[i], y[N-i]);
}

struct Line{
    double a, b, c;
    Line(double x, double y, double z){
        this->a = x;
        this->b = y;
        this->c = z;
    }
};

struct Point{
    double x, y;
    Point(double a, double b){
        this->x = a;
        this->y = b;
    }
};

//Find insect two line
void cut(Line &l1, Line &l2, double &x, double &y){
    double dx = l1.c*1.0*l2.b - l2.c*1.0*l1.b;
    double dy = l1.c*1.0*l2.a - l2.c*1.0*l1.a;
    double d = l1.a*1.0*l2.b - l2.a*1.0*l1.b;
    if (-eps <= d && d <= eps)
        cout<<"waring!"<<endl;
    x = dx/d;
    y = -dy/d;
}

//check (x, y) in rect(x1, y1, x2, y2)
bool inside(double x, double y, double x1, double x2, double y1, double y2){
    return (x1 <= x && x <= x2) && (y1 <= y && y <= y2);
}

bool check(double x, double y, double c1, double c2, double d1, double d2){
    return inside(x, y, x1, x2, y1, y2) && inside(x+y, y-x, c1, c2, d1, d2); 
}

//check whether insect with rect(x1,y1,x2,y2)?
bool checkInsect(double c1, double c2, double d1, double d2){
    //cout<<":try "<<c1<<" "<<c2<<" "<<d1<<" "<<d2<<endl;
    if (c1 > c2 || d1 > d2)
        return false;
    Line line1[4] = {Line(1, 0, x1), Line(0, 1, y1), Line(1, 0, x2), Line(0, 1, y2)};
    Line line2[4] = {Line(1, 1, c1), Line(-1, 1, d1), Line(1, 1, c2), Line(-1, 1, d2)};
    double x, y;
    For(i,4)
        For(j,4){
            if (i < j && j - i != 2){
                cut(line2[i], line2[j], x, y);
                if (check(x, y, c1, c2, d1, d2))
                    return true;
                cut(line1[i], line1[j], x, y);
                if (check(x, y, c1, c2, d1, d2))
                    return true;
            }
            cut(line1[i], line2[j], x, y);
            if (check(x, y, c1, c2, d1, d2))
                    return true;
        }
    return false;
}

void process(){
    x1 = y1 = -oo;
    x2 = y2 = oo;
    For(i,N){
        if (x[i] == x[i+1])
            if (y[i+1] > y[i])
                x2 = min(x2, x[i]);
            else
                x1 = max(x1, x[i]);
        if (y[i] == y[i+1])
            if (x[i+1] > x[i])
                y1 = max(y1, y[i]);
            else
                y2 = min(y2, y[i]);
    }
    yes = (x1 <= x2 && y1 <= y2);
    //cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
    if (!yes) return;
    a1 = b1 = -oo;
    a2 = b2 = oo;
    For(i,N){
       a1 = max(x[i]+y[i]-lmax, a1);
       a2 = min(x[i]+y[i]+lmax, a2);
       
       b1 = max(y[i]-x[i]-lmax, b1);
       b2 = min(y[i]-x[i]+lmax, b2);
    }
    //cout<<"ab: "<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<endl;
    double cd = 0, ct = lmax, mid;
    while (ct - cd > eps){
        mid = (cd + ct) / 2;
        if (checkInsect(a1+mid, a2-mid, b1+mid, b2-mid))
            cd = mid;
        else 
            ct = mid;
    }
    //cout<<"mid = "<<mid<<endl;
    dbest = lmax - (cd + ct) / 2;
}

void print(){
    if (yes)
        printf("yes\n%0.3f\n", dbest);
    else
        printf("no\n");
}

int main(){
    read();
    process();
    print();
    return 0;
}
