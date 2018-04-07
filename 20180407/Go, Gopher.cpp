#include <bits/stdc++.h>
using namespace std;
bool filled[1111][1111];
vector<pair<int,int> > ans;
void solve(int t) {
    memset(filled,0,sizeof(filled));
    cerr <<t << endl;
    int n;
    cin >> n;
    int lx = ans[n - 1].first;
    int ly = ans[n - 1].second;
    while(true) {
        bool done = false;
        for(int i = 2; i < lx; i++) {
            for(int j = 2; j < ly; j++)
                if(!filled[i][j]) {
                    done = true;
                    cout << i <<" "<<j << endl;
                    int x,y;
                    cin >> x >> y;
                    if(x <= 0 && y <= 0)
                        return;
                    filled[x][y] = true;
                }
            if(!filled[i][ly]) {
                done = true;
                //cerr << i <<" "<<ly - 1 <<endl;
                cout << i <<" "<<ly - 1 <<endl;
                int x,y;
                cin >> x >> y;
                if(x <= 0 && y <= 0)
                    return;
                filled[x][y] = true;
            }
            if(!filled[i][1]) {
                done = true;
                cout <<i <<" "<<2 <<endl;
                //cerr <<i <<" "<<2 <<endl;
                int x,y;
                cin >> x >> y;
                if(x <= 0 && y <= 0)
                    return;
                filled[x][y] = true;
            }
        }

        for(int j = 2; j < ly; j++) {
            if(!filled[lx][j]) {
                done = true;
                cout << lx - 1 <<" "<<j<<endl;
                //cerr << lx - 1 <<" "<<j<<endl;
                int x,y;
                cin >> x >> y;
                if(x <= 0 && y <= 0)
                    return;
                filled[x][y] = true;
            }
            if(!filled[1][j]) {
                done = true;
                cout << 2 <<" "<<j<<endl;
                //cerr << 2 <<" "<<j<<endl;
                int x,y;
                cin >> x >> y;
                if(x <= 0 && y <= 0)
                    return;
                filled[x][y] = true;
            }
        }
        if(!done)
            break;
    }

    while(!filled[lx][ly]) {
        cout << lx - 1 <<" "<<ly - 1<<endl;
        //cerr << lx - 1 <<" "<<ly - 1<<endl;
        int x,y;
        cin >> x >> y;
        if(x <= 0 && y <= 0)
            return;
        filled[x][y] = true;
    }

    while(!filled[1][1]) {
        cout << 2 <<" "<< 2<<endl;
        //cerr << 2 <<" "<< 2<<endl;
        int x,y;
        cin >> x >> y;
        if(x <= 0 && y <= 0)
            return;
        filled[x][y] = true;
    }

    while(!filled[1][ly]) {
        cout << 2 <<" "<<ly - 1<<endl;
        //cerr << lx - 1 <<" "<<ly - 1<<endl;
        int x,y;
        cin >> x >> y;
        if(x <= 0 && y <= 0)
            return;
        filled[x][y] = true;
    }

    while(!filled[lx][1]) {
        cout << lx -1 <<" "<< 2<<endl;
        //cerr << 2 <<" "<< 2<<endl;
        int x,y;
        cin >> x >> y;
        if(x <= 0 && y <= 0)
            return;
        filled[x][y] = true;
    }
}
main() {
    for(int n = 1; n <= 200; n++) {
        int optimize = 1<<30;
        int lx = -1;
        int ly = -1;
        for(int i = 3; i <= n+2; i++)
            for(int j = 3; j <= n+2; j++) {
                if(i*j>= n && i*j <=optimize) {
                    optimize = i*j;
                    lx = i;
                    ly = j;
                }
            }
        ans.emplace_back(lx,ly);
    }
    int t;
    cin >> t;
    for(int i=1; i <= t; i++)
        solve(i);
}
