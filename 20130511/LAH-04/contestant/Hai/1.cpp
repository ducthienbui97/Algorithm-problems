#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

typedef pair<int, int> student;
vector<student> S;
int counter=-1, n;

void process(int a, int b)
{
    int i;
    if(counter>n-1)
    {
        cout << "No" << endl;
        return;
    }
    if(a==b)
    {
        cout << "Yes" << " " << counter << endl;
        return;
    }
    for(i=0; i<S.size(); i++)
    {
        if(S[i].first==a)
        {
            counter++;
            process(S[i].second, b);
            break;
        }
    }
}

int main()
{
    freopen("1.inp", "r", stdin);
    freopen("1.out", "w", stdout);
    int i, a, b, c;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> a >> b;
        S.push_back(student(a,b));
    }
    while(cin >> a >> b)
    {
        if(a==0&&b==0)
            return 0;
        else    process(a, b);
        counter=-1;
    }
    return 0;
}

