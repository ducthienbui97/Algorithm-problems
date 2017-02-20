#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> score(n);
    for(int score_i = 0; score_i < n; score_i++){
       cin >> score[score_i];
    }
    int Min = score[0];
    int Max = score[0];
    int ans1 = 0,ans2 = 0;
    for(int i=1;i<n;i++){
        if(score[i] > Max){
            Max = score[i];
            ans1 ++;
        }
        if(score[i] < Min){
            Min = score[i];
            ans2 ++;
        }
    }
    cout << ans1 <<" "<<ans2<<endl;
    return 0;
}

