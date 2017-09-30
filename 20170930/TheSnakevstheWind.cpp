#include <bits/stdc++.h>
using namespace std;
int F[66][66];
int n;


bool is_ok(int x,int y) {
    return (x >=0 && x< n && y >= 0 && y < n && !F[x][y]);
}
void print() {
    for(int i = 0; i < n ; i++)
        for(int j=0; j < n; j++)
            cout << F[i][j] << (j<n-1?' ':'\n');

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int cnt = 0;
    string s;
    int x,y;
    cin >> s >> x >> y;
    while(cnt < n*n) {
        F[x][y] = ++cnt;
        switch(s[0]) {
        case 'n':
            if(is_ok(x - 1, y))
                x--;
            else if(is_ok(x,y + 1))
                y++;
            else if(is_ok(x,y - 1))
                y--;
            else if(is_ok(x+1, y))
                x++;
            break;
        case 's':
            if(is_ok(x + 1, y))
                x++;
            else if(is_ok(x,y + 1))
                y++;
            else if(is_ok(x,y - 1))
                y--;
            else if(is_ok(x - 1, y))
                x--;
            break;
        case 'w':
            if(is_ok(x,y - 1))
                y--;
            else if(is_ok(x - 1, y))
                x--;
            else if(is_ok(x + 1, y))
                x++;
            else if(is_ok(x,y + 1))
                y++;
            break;
        case 'e':
            if(is_ok(x,y + 1))
                y++;
            else if(is_ok(x - 1, y))
                x--;
            else if(is_ok(x + 1, y))
                x++;
            else if(is_ok(x,y - 1))
                y--;

            break;
        }
    }
    print();
    return 0;
}
