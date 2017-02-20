#include <bits/stdc++.h>
using namespace std;
# define M_PI           3.14159265358979323846

void run(int testnum){
    int p,x,y;
    cin >> p >> x >> y;
    double ang = 2.0*p/100;
    int x2 = 0, y2 = 50;
    int x1 = x - 50, y1= y - 50;
    int dot = x1*x2 + y1*y2;
    int det = x1*y2 - y1*x2;
    double angle = 2 + atan2(det, dot)/M_PI;
    if(angle > 2) angle -= 2;
    if(angle > ang || (x-50)*(x-50)+(y-50)*(y-50) >= 50*50)
        cout << "Case #" << testnum << ": white" <<endl;
    else
        cout << "Case #" << testnum << ": black" <<endl;
}
int main(){
    freopen("progress_pie.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++)
        run(i);
}
