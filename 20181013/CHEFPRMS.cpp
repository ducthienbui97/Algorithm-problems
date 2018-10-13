#include <bits/stdc++.h>
using namespace std;
const int MAX = 222;
bool isPrime[MAX];
bool isSemiPrime[MAX];
bool isSemiPrimeSum[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = false;
    isPrime[0] = false;
    for(int i = 2; i < MAX; i++)
        if(isPrime[i]) {
           for(int j = i + i; j < MAX; j += i)
                isPrime[j] = false;
        }
    for(int i = 2; i < MAX; i++)
        if (isPrime[i])
        for(int j = i + 1; j < MAX; j++)
            if(isPrime[j] && i*j < MAX)
                isSemiPrime[i*j] = true;
    for(int i = 2; i < MAX; i++)
        if(isSemiPrime[i])
        for(int j = i; j < MAX; j++)
            if(isSemiPrime[j] && i + j < MAX)
                isSemiPrimeSum[i + j] = true;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int x;
        cin >> x;
        cout << (isSemiPrimeSum[x]?"YES":"NO") << endl;
    }
}

