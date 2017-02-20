#include <cstdio>
#include <iostream>
using namespace std;

void bi(int k, int len)
{
    int i;
    for(i=len-1;i>=0;i--)
    {
        //cout<<k<<" "<<i<<" ";
        if(k<(1<<i)) printf("0");
        else
        {
            printf("1");
            k-=(1<<(i));
            //cout<<"-"<<(1<<i)<<endl;
        }
    }
}

int gray(int num)
{
    return (num>>1)^num;
}


int main()
{
    int n;
    int i,j,k;
    freopen("grey.inp","r",stdin);
    freopen("grey.out","w",stdout);
    scanf("%d",&n);
    for(i=0;i<(1<<n);i++)
    {
        bi(gray(i),n);
        printf("\n");
    }
}
