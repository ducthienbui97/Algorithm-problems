#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int cha[366];
void solve(int nTest){
    string ans;
    string s;
    cin >> s;
    for(char c:s) cha[c]++;

    cnt[0] = cha['Z']; // ZERO
    cha['Z']-=cnt[0];
    cha['E']-=cnt[0];
    cha['R']-=cnt[0];
    cha['O']-=cnt[0];

    cnt[2] = cha['W']; // TWO
    cha['T']-=cnt[2];
    cha['W']-=cnt[2];
    cha['O']-=cnt[2];

    cnt[6] = cha['X']; // SIX
    cha['S']-=cnt[6];
    cha['I']-=cnt[6];
    cha['X']-=cnt[6];

    cnt[7] = cha['S']; //SEVEN
    cha['S']-=cnt[7];
    cha['E']-=cnt[7];
    cha['V']-=cnt[7];
    cha['E']-=cnt[7];
    cha['N']-=cnt[7];

    cnt[5] = cha['V']; //FIVE
    cha['F']-=cnt[5];
    cha['I']-=cnt[5];
    cha['V']-=cnt[5];
    cha['E']-=cnt[5];

    cnt[4] = cha['F']; //FOUR
    cha['F']-=cnt[4];
    cha['O']-=cnt[4];
    cha['U']-=cnt[4];
    cha['R']-=cnt[4];

    cnt[3] = cha['R']; //THREE
    cha['T']-=cnt[3];
    cha['H']-=cnt[3];
    cha['R']-=cnt[3];
    cha['E']-=cnt[3];
    cha['E']-=cnt[3];

    cnt[1] = cha['O']; //ONE
    cha['O']-=cnt[1];
    cha['N']-=cnt[1];
    cha['E']-=cnt[1];

    cnt[9] = cha['N']/2; //NINE
    cha['N']-=cnt[9];
    cha['I']-=cnt[9];
    cha['N']-=cnt[9];
    cha['E']-=cnt[9];

    cnt[8] = cha['E']; //EIGHT
    cha['E']-=cnt[8];
    cha['I']-=cnt[8];
    cha['G']-=cnt[8];
    cha['H']-=cnt[8];
    cha['T']-=cnt[8];

    cout <<"Case #"<<nTest<<": ";
    for(int i=0;i<10;i++)
    while(cnt[i]){
        cout<<i;cnt[i]--;
    }
    cout <<endl;
}
main(){
   freopen("A-large-practice.in","r",stdin);
   freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
    }

