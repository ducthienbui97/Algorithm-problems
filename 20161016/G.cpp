#include<bits/stdc++.h>
using namespace std;

long long dou[100];
double solve(long long a){
    double a1;
    if(a==0) return 0;
    for(long long i=1;i<=60;i++){
        if(a==dou[i]) return 0.5;
        if(a<dou[i]){
            a1 = ( 1.*(dou[i-1]+1) / (a+1) ) * ( 0.5*(i-1)/i );
            cout<<a1<<' '<<dou[i-1]<<' ';
            return a1 + ( 1.*(a-dou[i-1])/(a+1) ) * ( 1./i + solve( a-dou[i-1]-1 )*(i-1)/i );
        }
    }
}

double solve(long long a,long long b){
    --a;
    double soa,sob = solve(b);
    for(long long i=1;i<=60;i++){
        if(a==dou[i]){
            soa=solve(a)*i/(i+1);
            break;
        } else if( a<dou[i] ) {
            soa=solve(a);
            break;
        }
    }
    cout<<soa<<' '<<sob<<endl;
    return (sob-soa*(a+1)/(b+1))/(b-a)*(b+1);
}

long long run(long long a,long long b){
    long long aa=a;
    long long lia=0,lib=0;
    double res=0;
    for(long long i=1;i<=60;i++){
        if( aa>dou[i-1] and b<=dou[i] ) {
            cout<<solve(aa,b)<<endl;
            return 0;
        }
        if(dou[i]>=a and b>dou[i]){
            res+=solve(a,dou[i])*(dou[i]-a+1);
            a=dou[i]+1;
            cout<<"WTF "<<dou[i]<<' '<<res<<endl;
        }
        if(dou[i]>=b){
            res+=solve(a,b)*(b-a+1);
            cout<<"WTF "<<a<<' '<<b<<' '<<res<<endl;
            break;

        }
    }
    cout<<"Hell "<<res/(b-aa+1)<<' '<<res<<' '<<(b-aa+1)<<endl;

}

int main(){
    freopen("test.cpp","r",stdin);
    long long t,a,b;
    dou[0]=0;
    for(long long i=1;i<=60;i++) {
        dou[i]=(dou[i-1]+1)*2-1;
        //cout<<dou[i]<<endl;
    }
    cout<<solve(5);
    //cout<<solve(2,3)<<' '<<solve(2)<<' '<<solve(3);

    cin>>t;
    for(long long i=1;i<=t;i++){
        cin>>a>>b;
        run(a,b);
    }


}
