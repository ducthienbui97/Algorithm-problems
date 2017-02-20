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
typedef pair<int,int> pii;
int l[33333],r[33333];
int a[33333];
main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    stack<int> left,right;
    for(int i=1; i<=n; i++)
    {
        l[i]=1;
        r[i]=1;
    }
    int i=1;
    while(i<=n)
    {
        if(left.empty())
        {
            l[i]=i;
            left.push(i);
            i++;
        }
        elif(a[left.top()]<a[i])
        {
            left.pop();
        }
        else
        {
            l[i]=i-left.top();
            left.push(i);
            i++;
        }
    }
    i=n;
    while(i>0)
    {
        if(right.empty())
        {
            r[i]=n-i+1;
            right.push(i);
            i--;
        }
        elif(a[right.top()]>a[i])
        {
            right.pop();
        }
        else
        {
            r[i]=right.top()-i;
            right.push(i);
            i--;
        }
    }
    int k=1;
    int x;
    for(int i=1; i<=n; i++)
        if(l[i]+r[i]-1>k&&l[i]>1&&r[i]>1)
        {
            k=l[i]+r[i]-1;
          //  cout<<l[i]<<" "<<r[i]<<endl;
          x=i;
        }
    if(k==1)
    printf("-1");
    else
    printf("%d %d",x,k);
}
