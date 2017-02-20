#include<cstdio>
#include<cmath>
#include<fstream>
using namespace std;

const double EPS = 1e-6;

bool equal(const double &x, const double &y) {
	if(fabs(x - y) <= EPS) return true;
	if(fabs(x) <= EPS || fabs(y) <= EPS) return false;
	return fabs((x-y)/x) <= EPS || fabs((x-y)/y) <= EPS;
}

int main(int argc, char ** argv) {
	ifstream inp(argv[1]), ans(argv[2]), out(argv[3]);
	double x, y;
	if((ans >> x) && (out >> y)) {
		if(equal(x, y)) return 0;
	}
	return 1;
}
