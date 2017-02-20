#include<stdio.h>
#include<cstring>
using namespace std;
char a[1050000][21];
int main()
{
    freopen("grey.inp","r",stdin);
    freopen("grey.out","w",stdout);
    int n,i,j,x;
    scanf("%d",&n);
    a[1][0]='0';
    a[2][0]='1';
    x=1;
    while(x!=n)
    {
        int m=1<<(x+1);
        for(i=1;i<=(1<<x);i++)
        {
            strcpy(a[m-i+1],a[i]);
            a[m-i+1][x]='1';
        }
        for(i=1;i<=(1<<x);i++)
            a[i][x]='0';
        
        
        x=x+1;
    }
    
    for(i=1;i<=(1<<n);i++)
    {
        printf("%s",a[i]);
        printf("\n");
    }
    //scanf(" ");
}
        
        
