#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
string s[10000000];
int N, len;
void readInput(char* file){
	ifstream fin(file);
	fin>> len;
	N = (int)pow(2.0, len + .0);
	fin.close();
}

void readOutput(char* file){
	//cout<<"N = "<<N<<endl;
	ifstream fin(file);
	for (int i=0; i<N; i++)
		fin>> s[i];
	fin.close();
}

int checkOne(string& sx, string& sy){
	int counter = 0;
	for (int i=0; i< (int) sx.size(); i++)
		if (sx[i] != sy[i]){
			counter++;
		}
	return counter;
}

int main(int num, char** argv){
	return 0;
	readInput(argv[1]);
	
	readOutput(argv[2]);
	
	for (int i=0; i<N; i++)
		if ((int) s[i].size() != len)
			return 1;
	for (int i=0; i<N; i++)
		if (checkOne(s[i], s[(i + 1)% N]) != 1)
			return 2;
	sort(s, s + N);
	for (int i=0; i<N; i++)
		if (checkOne(s[i], s[(i + 1)% N]) == 0)
			return 3;
	return 0;	
}

