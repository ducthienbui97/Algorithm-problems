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
stack <int> v,d;
char c[1111111];
main()
{
  //  freopen("test.in","r",stdin);
    char *p;
    int i;
    bool check;
    while(gets(c)!=NULL)
    {
        check=true;
        while(!d.empty()) d.pop();
        while(!v.empty()) v.pop();
        p=strtok(c," ");
        d.push(0);
        while(p!=NULL)
        {
            sscanf(p,"%d",&i);
            if(v.empty())
            {
                if(i>0)
                {
                    check=false;
                    break;
                }
                else
                {
                    v.push(i);
                    d.push(0);
                }
            }
            elif(i>0)
            {
                if(v.top()>0)
                {
                    check=false;
                    break;

                }
                elif(i!=abs(v.top()))
                {
                    check=false;
                    break;
                }
                elif (i<=d.top())
                {
                    check=false;
                    break;
                }
                else
                {
                    v.pop();
                    d.pop();
                    i=d.top()+i;
                    d.pop();
                    d.push(i);
                }
            }
            else
            {
                v.push(i);
                d.push(0);
            }
            p=strtok(NULL," ");

        }
        if(!v.empty()) check=false;
        if(check) printf(":-) Matrioshka!\n");
        else  printf(":-( Try again.\n");

    }

}
