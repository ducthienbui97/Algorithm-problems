#include <stdio.h>
#include <math.h>

/// Interface

class vertex_t {
public :
    double x, y;
    vertex_t(double _x, double _y){ x=_x; y=_y; }
    vertex_t(){}
    void enter(){ scanf("%lf%lf", &x, &y); }
};
class line_t {
public :
    vertex_t A, B;
    line_t(vertex_t _A, vertex_t _B){ A=_A; B=_B; }
};
class polygon {
public :
    int n;
    vertex_t a[2309];
    line_t l(int i);
    void enter();
    vertex_t operator [] (int i){ return a[i]; }
};

/// Implementation

vertex_t operator - (vertex_t A, vertex_t B){ return vertex_t(A.x-B.x, A.y-B.y); }
double cross(vertex_t A, vertex_t B){ return A.x*B.y-A.y*B.x; }
double dot(vertex_t A, vertex_t B){ return A.x*A.y+B.y*B.x; }
void minimize(double &a, double b){ if (a>b) a=b; }
double abs(double a){ return a>0?a:-a; }

void polygon::enter(){
    int i;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    a[i].enter();
}
line_t polygon::l(int i){ return line_t(a[i], a[(i==n)?1:(i+1)]); }

polygon A, B;

double abs(vertex_t M){ return sqrt(M.x*M.x+M.y*M.y); }
double f(vertex_t M, line_t d){
    vertex_t A=d.A, B=d.B;
    double r=0;
    if (dot(M-A,B-A)<0) r = abs(M-A);
    else if (dot(M-B,B-A)>0) r = abs(M-B);
    else r = abs(cross(B-A,M-A))/abs(B-A);
    //printf("f((%lf,%lf), (%lf,%lf,%lf,%lf)=%lf\n", M.x, M.y, A.x, A.y, B.x, B.y, r);
    return r;
}

main(){
    freopen("raft.inp", "r", stdin);
    freopen("raft.out", "w", stdout);
    int i, j;
    double r=1e10;
    A.enter();
    B.enter();
    for (i=1; i<=A.n; i++)
    for (j=1; j<=B.n; j++)
    minimize(r, f(A[i], B.l(j)));
    for (i=1; i<=A.n; i++)
    for (j=1; j<=B.n; j++)
    minimize(r, f(B[j], A.l(i)));
    printf("%.6lf\n", r/2);
}
