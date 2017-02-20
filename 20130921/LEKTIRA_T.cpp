#include <bits/stdc++.h>
using namespace std;
string S,Min,c;
main(){
    ios_base::sync_with_stdio(false);
    cin>>c;
    int n=c.length();
    for(int i=1;i<c.length();i++)
    for(int j=i+1;j<c.length();j++){
        S=c.substr(0,i)+c.substr(i,j-i)+c.substr(j);
        reverse(&S[0],&S[i]);
        reverse(&S[i],&S[j]);
        reverse(&S[j],&S[n]);
        if(!Min.length()) Min=S;
        else Min=min(S,Min);
    }
    cout<<Min;
}
/*abcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcdeabcde*/
