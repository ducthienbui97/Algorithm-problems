#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <utility>
#include <climits>
#include <vector>
#include <cstring>
#include <deque>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#define elif else if
using namespace std;
int c[31322];
int d[31322];
main()
{
   int a=0,b=0;
    char xx[11];
    d[0]=0;
    c[0]=0;
    for(int i=1; i<=31311; i++)
    {

        if(i>9999) d[i]=5;
        elif(i>999) d[i]=4;
        elif(i>99) d[i]=3;
        elif(i>9) d[i]=2;
        else d[i]=1;
        c[i]=c[i-1]+d[i];
    }
    long long int t,n,l,r;

    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        l=1;
        while(n>c[l])
        {
            n-=c[l];
            l++;
        }
       r=1;
        while(n>d[r])
        {
            n=n-d[r];
            r++;
        }
        sprintf(xx,"%lld",r);
        printf("%c\n",xx[n-1]);
    }
}
