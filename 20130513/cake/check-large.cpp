#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;


void chayfile(){
    cout<<"Nhap ten bai chay (.exe): ";
    string namefile;
    cin>>namefile;
    string text=namefile+" <A-large-practice.in >cake-large.out";
    system(&text[0]);
}

void sofile(){
    cout<<"so file\n";
    ifstream f1,f2,f3;
    ofstream fo;
    f1.open("A-large-practice.in");
    f2.open("A-large-practice.out");
    f3.open("cake-large.out");
    fo.open("result-large.txt");
    int T,a,G,L,U;
    long long intx,inty;
    double x,y;
    f1>>T;
    string s;
    cout<<T<<endl;
    for(int i=0;i<T;i++){
        f1>>a>>L>>U>>G;
        for(int j=0;j<L+U;j++) f1>>x>>y;
        f2>>s>>s;
        f3>>s>>s;
        fo<<"Test case "<<i+1<<endl;
        cout<<"Test case "<<i+1<<endl;
        for(int j=0;j<G-1;j++){
            f2>>x;
            f3>>y;
            intx=(long long) trunc(x*100000000);
            inty=(long long) trunc(y*100000000);
            intx/=100;
            inty/=100;
            if (intx!=inty){
                fo<<"sai: "<<intx<<" "<<inty<<endl;
            } else fo<<"dung"<<endl;
        }
    }
}
int main(){
    chayfile();
    sofile();
}
