#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#define elif else if
using namespace std;
int used[55][55];
int set[55][55];
int F[55];
int total[55];
int  num[55];
int sum[55];
class SurveillanceSystem {
	public:
		string getContainerInfo(string containers, vector <int> reports, int L) {
		sum[0]=0;
		for(int i=0;i<(int) reports.size();i++)
			num[reports[i]]++;
		for(int i=1;i<=(int) containers.length();i++){
			sum[i]=sum[i-1]+(containers[i-1]=='X');
		}
		for(int i=0;i<(int) reports.size();i++)
			for(int j=L;j<=(int) containers.length();j++){
				if(!used[j-L+1][j]&&sum[j]-sum[j-L]==reports[i]){
					used[j-L+1][j]=true;
					total[reports[i]]++;
					for(int l=j-L+1;l<=j;l++){
						set[reports[i]][l]++;
					}
				}
		}
		for(int i=0;i<(int) reports.size();i++)
			for(int j=1;j<=(int) containers.length();j++){
				if(!set[reports[i]][j]) continue;
				if(total[reports[i]]-set[reports[i]][j]<num[reports[i]]) F[j]=2;
				else F[j]=max(F[j],1);
			}
	string s;
	for(int j=1;j<=(int) containers.length();j++){
			if(F[j]==1) s+='?';
			elif(F[j]==2) s+='+';
			else s+='-';
	}
	return s;
}			
		
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "-X--XX"; int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "??++++"; verify_case(0, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "-XXXXX-"; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-???"; verify_case(1, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "------X-XX-"; int Arr1[] = {3, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; string Arg3 = "++++++++++?"; verify_case(2, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "-XXXXX---X--"; int Arr1[] = {2, 1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arg3 = "???-??++++??"; verify_case(3, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X"; int Arr1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; string Arg3 = "???++++?++++++++++++++++++++??????--"; verify_case(4, Arg3, getContainerInfo(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SurveillanceSystem ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
