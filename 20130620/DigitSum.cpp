#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
long long int num[20];
main() {
    long long int a,b,i,j;
    while(scanf("%lld%lld",&a,&b)!=EOF) {
        if(a>b) swap(a,b);
        if(a<0&&b<0) break;
        for(i=0; i<=9; i++)
            num[i]=0;
        if(a==0) num[0]=1;
        for(; a<=b; a++) {
           if(a%1000000000==0 && a+1000000000<=b){
                for(j=0; j<=9; j++)
                    num[j]+=900000000;
                i=a/1000000000;
                while(i) {
                    num[i%10]+=1000000000;
                    i=(i-i%10)/10;
                    }
                a+=1000000000-1;
            }
           else if(a%100000000==0 && a+100000000<=b){
                for(j=0; j<=9; j++)
                    num[j]+=80000000;
                i=a/100000000;
                while(i) {
                    num[i%10]+=100000000;
                    i=(i-i%10)/10;
                    }
                a+=100000000-1;
            }
            else if(a%10000000==0 && a+10000000<=b) {
                for(j=0; j<=9; j++)
                    num[j]+=7000000;
                i=a/10000000;
                while(i) {
                    num[i%10]+=10000000;
                    i=(i-i%10)/10;
                    }
                a+=10000000-1;
                }
            else if(a%1000000==0 && a+1000000<=b) {
                for(j=0; j<=9; j++)
                    num[j]+=600000;
                i=a/1000000;
                while(i) {
                    num[i%10]+=1000000;
                    i=(i-i%10)/10;
                    }
                a+=1000000-1;
                }
            else if(a%100000==0 && a+100000<=b) {
                for(j=0; j<=9; j++)
                    num[j]+=50000;
                i=a/100000;
                while(i) {
                    num[i%10]+=100000;
                    i=(i-i%10)/10;
                    }
                a+=100000-1;
                }
            else if(a%10000==0 && a+10000<=b) {
                for(j=0; j<=9; j++)
                    num[j]+=4000;
                i=a/10000;
                while(i) {
                    num[i%10]+=10000;
                    i=(i-i%10)/10;
                    }
                a+=10000-1;
                }
            else if(a%1000==0 && a+1000<=b) {
                for(j=0; j<=9; j++)
                    num[j]+=300;
                i=a/1000;
                while(i) {
                    num[i%10]+=1000;
                    i=(i-i%10)/10;
                    }
                a+=1000-1;
                }
            else if(a%100==0 && a+100<=b) {
                for(j=0; j<=9; j++)
                    num[j]+=20;
                i=a/100;
                while(i) {
                    num[i%10]+=100;
                    i=(i-i%10)/10;
                    }
                a+=100-1;

                }
            else if(a%10==0 && a+10<=b) {
                for(j=0; j<=9; j++)
                    num[j]+=1;
                i=a/10;
                while(i) {
                    num[i%10]+=10;
                    i=(i-i%10)/10;
                    }
                a+=10-1;
                }
            else {
                i=a;
                while(i!=0) {
                    num[i%10]++;
                    i=(i-i%10)/10;
                    }
                }
            }
          long long int ans=0;
        for(i=0; i<=9; i++)
         ans+=(i*num[i]);
         cout<<ans<<endl;
        }

    }

