#include<iostream>
#include<complex>
#include<vector>
#define X real()
#define Y imag()
using namespace std;
//const double eps=0.0001;
const double eps=0.00000001;
typedef complex<double> point;
struct circle{
    point center;
    double R;
    void set(point C,double r){
        center=C;
        R=r;
    }
    bool thuoc(point P){
        P=P-center;
        return (abs(P)-eps) < R;
    }
};
int N;
point a[300];
circle C[300];
vector<point> tapgiao;
point ansp;
void input(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a[i].X>>a[i].Y;
    }
}

vector<point> cutCC(circle C1,circle C2){
    vector<point> ans;
    if ((abs(C1.center - C2.center) > C1.R + C2.R + eps) || (abs(C1.center - C2.center) + eps < max(C1.R,C2.R) - min(C1.R,C2.R))) return ans;
    point u=C2.center-C1.center;
    double O1O2=abs(u), R1=C1.R, R2=C2.R;
    double O1H=(O1O2/2 + (R1*R1 - R2*R2)/(2*O1O2));
    double L=sqrt(R1*R1 - O1H*O1H);
    u = u/abs(u)*O1H;
    point H = C1.center + u;
    point AH = point(-u.Y,u.X);
    AH = AH/abs(AH)*L;
    ans.push_back(H + AH);
    ans.push_back(H - AH);
    return ans;
}

bool kt(double R){
    //printf("%.9lf\n",R);
    vector<point> giao;
    //cout<<R<<endl;
    for(int i=0;i<N;i++) C[i].set(a[i],R);
    tapgiao.clear();
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            giao=cutCC(C[i],C[j]);
            for(int k=0;k<giao.size();k++) tapgiao.push_back(giao[k]);
        }
    }
    int d;
    //cout<<tapgiao.size()<<endl;
    for(int i=0;i<tapgiao.size();i++){
        d=0;
        for(int j=0;j<N;j++){
            if (C[j].thuoc(tapgiao[i])) d++;
        }
        if (d==N) {
            ansp=tapgiao[i];
            return true;
        }
    }
    return false;
}

void solve(){
    double d=0,c=10000000,md,ans;
    while(d+eps<c){
        md=(d+c)/2.0;
        if (kt(md)){
            ans=md;
            c=md;
        } else d=md;
    }
    printf("%.9lf %.9lf %.9lf",ansp.X,ansp.Y,ans);
    //cout<<ans;
}
int main(){
    //freopen("MINCIRCLE.INP","r",stdin);
    //freopen("MINCIRCLE.OUT","w",stdout);
    input();
    solve();
}
