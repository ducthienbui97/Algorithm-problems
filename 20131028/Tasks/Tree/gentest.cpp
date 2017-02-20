#include <iostream>
#define maxn 10000
using namespace std;
int id[maxn];

void gen(int N){
	int x, y;
	for (int i=1; i<=N; i++)
		id[i] = i;
	for (int i=1; i<=2*N; i++){
		x = rand() % N + 1;
		y = rand() % N + 1;
		swap(id[x], id[y]);
	}
	for (int i=2; i<=N; i++){
		x = rand() % (i - 1) + 1;
		cout<<id[x]<<" "<<id[i]<<endl;		
	}
	
}

int main(int num, char** args){
	int N;
	//cout<<args[0]<<endl;
	N = atoi(args[1]);	
	cout<< N << endl;
	gen(N);	
	return 0;
}
