#include <bits/stdc++.h>
using namespace std;
char check(){
    map<int,int> lo;
    int n,m;
    cin >> n;
    for(int i = 0; i < n;i++){
        int x;
        cin >> x;
        lo[x] = i;
    }
    int max_l = -1;
    cin >> m;
    char rep = '1';
    for(int i = 0; i < m;i++){
        int x;
        cin >> x;
        if(rep=='1' && lo.find(x) != lo.end())
            if(lo[x] < max_l)
                rep = '0';
            else
                max_l = lo[x];
    }
    return rep;
}
main(){
    ios_base::sync_with_stdio(false);
    string s;
    for(int i=0;i<5;i++)
        s+= (check());
    cout << s<<endl;
}
/*
3 1 2 3
4 1 3 5 6
3 5 1 4
4 150 1 20 5
4 1 5 6 2
3 2 1 6
5 100 20 45 10 3
4 3 100 80 10
5 90 1 4 8 80
5 90 1 8 100 5
*/
