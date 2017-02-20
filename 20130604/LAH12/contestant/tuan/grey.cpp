#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n,m;
string s[4194305];

void doub (int k)
{
	for (int i=1; i<=k; i++) {
		s[2*k-i+1]=s[i];
	    //cout <<s[i]<<endl;
	}
}

void odd (int k)
{
	for (int i=1; i<=k; i++) {
		s[i]+='0';
		s[i+k]+='1';	
	}
}

int main ()
{
	freopen ("grey.inp" ,"r" ,stdin);
	freopen ("grey.out" ,"w" ,stdout);
	scanf ("%d" ,&n);
	m=pow(2,n);
	s[1]="0"; s[2]="1";
	for (int i=2; i<=m;) {
		doub (i);
		odd (i);
		i=i*2;		
	}
	//cout << s[1]<< endl;
	for (int i=1; i<=m; i++) {
		s[i].resize(s[i].size()-1);
		cout<<s[i]<<endl;	
	}
}
