#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

typedef pair<int, int> ii;
vector<ii> V;
int ans=0;

void process(int k)
{
    int i;
    for(i=0; i<V.size(); i++)
    {
        if(V[i].second==k)
        {
            if(V[i].first==1)
                ans++;
            else process(V[i].first);
        }
    }
}

int main()
{
    freopen("2.inp", "r", stdin);
    freopen("2.out", "w", stdout);
    int a, b, n;
    cin >> n;
    while(cin >> a >> b)
    {
        if(a==0&&b==0)
            process(n);
        else
            V.push_back(ii(a, b));
    }
    cout << ans << endl;
    return 0;
}
