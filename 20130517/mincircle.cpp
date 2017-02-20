#include <stdio.h>
#include <complex>
using namespace std;

typedef complex<double> point;

#define X real()
#define Y imag()

point rev(point u){ return point(-u.Y, u.X); }

struct line {
    double A, B, C;    // Ax+By=C
    void setn(point n,point M){ A=n.X; B=n.Y;C=A*M.X+B*M.Y; }
    void setu(point u,point M){ setn(rev(u),M); }
};

point intersect(line u, line v){
    double D=u.A*v.B-v.A*u.B;
    double Dx=u.C*v.B-v.C*u.B;
    double Dy=u.A*v.C-v.A*u.C;
    return point(Dx/D, Dy/D);
};

struct circle {
    point O;
    double R;
    bool contain(point M){ return abs(M-O)<=R+0.00001; }

    void circle3(point A, point B, point C){
        line jAB, jAC;
        jAB.setn(B-A,(A+B)*0.5);
        jAC.setn(C-A,(A+C)*0.5);
        O=intersect(jAB, jAC);
        R=abs(O-A);
    }

    void circle2(point A, point B){
        O=(A+B)*0.5;
        R=abs(O-A);
    }

};

void mini(circle &A, circle B){
    if (A.R>B.R) A=B;
}

point a[222];
circle C1, C2;
int n;

bool ok(circle C){
    int i;
    for (i=1; i<=n; i++)
    if (!C.contain(a[i])) return false;
    return true;
}

main(){
    int i, j, k;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    scanf("%lf%lf", &a[i].X, &a[i].Y);
    C2.circle2((0,0),(1e6,1e6));
    for (i=1; i<=n; i++)
    for (j=1; j<i; j++){
        C1.circle2(a[i], a[j]);
        if(C1.R<C2.R) if (ok(C1)) C2=C1;
    for (k=1; k<j; k++)   {
        C1.circle3(a[i], a[j], a[k]);
        if(C1.R<C2.R) if (ok(C1)) C2=C1;
    }
    }
    printf("%.6lf %.6lf %.6lf\n",C2.O.X,C2.O.Y,C2.R);
}
