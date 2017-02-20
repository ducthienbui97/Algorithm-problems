#include <bits/stdc++.h>
using namespace std;
bool B1[100][2];
bool B2[100][2];
bool OK[100][2];
main(){
    ios_base::sync_with_stdio(false);
    string s1,s2;
    cin >> s1 >> s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int n = max(s1.length(),s2.length());
    for(int i = 0; i <= n; i++){
        if(i>= s1.length()||s1[i]=='0')
            B1[i][0] = true;
        else if(s1[i]=='1')
            B1[i][1] = true;
        else
            B1[i][0] = B1[i][1] = true;

        if(i>= s2.length()||s2[i]=='0')
            B2[i][0] = true;
        else if(s2[i]=='1')
            B2[i][1] = true;
        else
            B2[i][0] = B2[i][1] = true;
    }
    for(int i = 0,nr = false,rem = false,ur = true,nur = false; i <= n; i++,rem = nr,nr = false,ur = nur,nur = false){
        if(B1[i][0]&&B2[i][0]){
            if(rem) OK[i][1] = true,nur = true;
            if(ur) OK[i][0] = true, nur = true;
        }
        if(B1[i][1]&&B2[i][1]){
            if(rem) OK[i][1] = true,nr =true;
            if(ur) OK[i][0] = true,nr = true;
        }
        if((B1[i][0]&&B2[i][1])||(B2[i][0]&&B1[i][1])){
            if(rem) OK[i][0] = true,nr = true;
            if(ur) OK[i][1] = true,nur = true;
        }
    }
    if(!OK[n][1]) n--;
    for(int i = n ; i >= 0; i--)
        if(OK[i][1]&&OK[i][0])
            putchar('?');
        else if(OK[i][0])
            putchar('0');
        else if(OK[i][1])
            putchar('1');

}
/*
101??001
1?01101
*/
