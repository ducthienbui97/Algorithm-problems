#include <bits/stdc++.h>
#define elif else if
using namespace std;
char c[10][1111];
int cnt;
void pin1(char x){
    for(int i=0;i<5;i++)
        c[i][cnt]='.';
    c[2][cnt++]=x;
}
void pin2(char x){
    for(int i=0;i<5;i++)
        if(i%2==0) c[i][cnt]='.';
        else c[i][cnt]=x;
    cnt++;
}
void pin3(char x,char y){
    for(int i=0;i<5;i++)
        c[i][cnt]='.';
    c[0][cnt]=c[4][cnt]=x;
    c[2][cnt]=y;
    cnt++;
}
void print(){
    for(int i=0;i<5;i++)
        printf("%s\n",c[i]);
}
char S[1111];
main(){
    scanf("%s",S);
    int n=strlen(S);
    pin1('#');
    pin2('#');
    pin3('#',S[0]);
    pin2('#');
    pin1('#');
    for(int i=2;i<=n;i++){
        if(i%3==0){
            pin2('*');
            pin3('*',S[i-1]);
            pin2('*');
            pin1('*');
        }
        elif(i%3==1||i==n){
            pin2('#');
            pin3('#',S[i-1]);
            pin2('#');
            pin1('#');
        }
        else{
            pin2('#');
            pin3('#',S[i-1]);
            pin2('#');
            pin1('*');

        }
    }
    print();
}
