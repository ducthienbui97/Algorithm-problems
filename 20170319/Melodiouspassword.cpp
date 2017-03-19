#include <bits/stdc++.h>
//https://www.hackerrank.com/contests/w30/challenges
using namespace std;
const string vowels = "aeiou";
const string consonants ="bcdfghjklmnpqrstvwxz";
void bt(int n,bool vowel,string cur){
    if(!n){
        cout << cur <<'\n';
        return ;
    }
    if(vowel){
        for(char c: vowels){
            bt(n-1,!vowel,cur+c);
        }
    }
    else{
        for(char c: consonants){
            bt(n-1,!vowel,cur+c);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    bt(n,true,"");
    bt(n,false,"");
    return 0;

}
