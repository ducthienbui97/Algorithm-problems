#include <stdio.h>
#include <math.h>

double point1[1005][4], point2[1005][4];
main(){
	freopen("raft.inp","r",stdin);
	freopen("raft.out","w",stdout);
    long n, m, i, j;
    double xm, ym, xa, ya, xb, yb, a, b, c, AA, BB, CC, mini, result_1, result_2, a1, b1, c1;
    scanf("%ld", &m);
    for(i=1;i<=m;i++) scanf("%lf %lf", &point1[i][1], &point1[i][2]);
    point1[m+1][1]= point1[1][1]; point1[m+1][2]= point1[1][2];
    scanf("%ld", &n);
    for(i=1;i<=n;i++) scanf("%lf %lf", &point2[i][1], &point2[i][2]);
    point2[n+1][1]= point2[1][1]; point2[n+1][2]= point2[1][2];
        mini= 1000000000;
        //
        for(j=1;j<=m;j++){
            xm= point1[j][1]; ym= point1[j][2];
        for(i=2;i<=n+1;i++){
            xa= point2[i-1][1]; ya= point2[i-1][2];
            xb= point2[i][1]; yb= point2[i][2];
            c= sqrt((xb-xa)*(xb-xa)+(ya-yb)*(ya-yb));
            a= sqrt((xa-xm)*(xa-xm)+(ya-ym)*(ya-ym));
            if(a<mini) {mini= a; result_1= xa; result_2= ya;}
            b= sqrt((xb-xm)*(xb-xm)+(yb-ym)*(yb-ym));
            if(b<mini) {mini= b; result_1= xb; result_2= yb;}
            if(b*b+c*c-a*a>=0 && a*a+c*c-b*b>=0){
            AA= yb-ya; BB= -(xb-xa); CC= -(yb-ya)*xa+(xb-xa)*ya;
            if(mini>fabs(AA*xm+BB*ym+CC)/(sqrt(AA*AA+BB*BB))) {
                    mini= fabs(AA*xm+BB*ym+CC)/(sqrt(AA*AA+BB*BB));
                                                              }
                                                }
                          }
            }
        //
        for(j=1;j<=n;j++){
            xm= point2[j][1]; ym= point2[j][2];
        for(i=2;i<=m+1;i++){
            xa= point1[i-1][1]; ya= point1[i-1][2];
            xb= point1[i][1]; yb= point1[i][2];
            c= sqrt((xb-xa)*(xb-xa)+(ya-yb)*(ya-yb));
            a= sqrt((xa-xm)*(xa-xm)+(ya-ym)*(ya-ym));
            if(a<mini) {mini= a; result_1= xa; result_2= ya;}
            b= sqrt((xb-xm)*(xb-xm)+(yb-ym)*(yb-ym));
            if(b<mini) {mini= b; result_1= xb; result_2= yb;}
            if(b*b+c*c-a*a>=0 && a*a+c*c-b*b>=0){
            AA= yb-ya; BB= -(xb-xa); CC= -(yb-ya)*xa+(xb-xa)*ya;
            if(mini>fabs(AA*xm+BB*ym+CC)/(sqrt(AA*AA+BB*BB))) {
                    mini= fabs(AA*xm+BB*ym+CC)/(sqrt(AA*AA+BB*BB));
                                                              }
                                                }
                          }
            }
        //
        printf("%.6lf\n", mini/2);
}
