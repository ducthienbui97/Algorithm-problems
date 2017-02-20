/*
PROG: cowfun
LANG: C++
pos: your_id_here
*/
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<cassert>
#define FOR(i, a, b) for(int i=(a), _b=(b); i < _b; ++i)
#define FORE(i, a, b) for(int i=(a), _b=(b); i <= _b; ++i)
#define FORD(i, a, b) for(int i=(a), _b=(b); i >= _b; --i)
#define MP make_pair
#define PB push_back
#define SZ size()
#define BG begin()
#define ED end()
#define THERE(c, v) (c.find(v) != c.ED)
#define ALL(c) c.BG, c.ED
#define TR(c, it) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define EXIST(c, u) ( c.find(u) != c.end() )

typedef pair<int, int> II;
typedef pair<int, II> III;
typedef vector<int> VI;
typedef vector<II> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;
typedef long long LL;

static inline int rint(){ int n; scanf("%d ", &n); return n; }
static inline void wint(const int n){ printf("%d\n", n); }
static inline void wint_(const int n){ printf("%d ", n); }
#define endl putchar('\n')
static inline void rll(LL& n){
    double t; scanf("%lf", &t); n = LL(t);
}
static inline void wll(const LL n){
    printf("%0.0lf", double(n));
}
const int DBG = 1;
const int MAXN = 10+100000;
const int MAXM = 10+200000;
const int INF = 1000000001;

char sTestFolder[1024];
char sTestInput1[1024];			// co the co nhieu input
char sTestOutput1[1024];			// co the co nhieu output
char sSubmissionOutput1[1024];	// ...

char sResult[1024];
char sDescription[1024];

void ReadComparerInput();
void ReadTestInput();
void ReadTestOutput();
void ReadSubmissionOutput();
void Report_Sai();
void Report_Dung();
void Report_SaiDinhDang();
void Report_DungMotPhan(int nPercent);

int bl[MAXN];
int m, n, ansda, ansbl;
set<II> g;

int main(int argc, char* argv[])
{
	ReadComparerInput();
	ReadTestInput();

    //sprintf(sDescription, "Doc du lieu OK"); Report_Dung();
	ReadTestOutput();
	ReadSubmissionOutput();	// Output cua thi sinh, phai kiem tra khi doc

	if(ansbl == -1){
        if(ansda == -1){
            sprintf(sDescription, "DA: -1, BL: -1");
            Report_Dung();
        }
        sprintf(sDescription, "DA: +1, BL: -1");
        Report_Sai();
    }

	FOR(i, 0, n){
        int u = i, v = bl[i]-1;
        if(u>v) swap(u, v);
        II e = II(u, v);
        if(!THERE(g, e)){
            sprintf(sDescription, "Sai o (%d, %d)", i+1, bl[i]);
            Report_Sai();
        }
        g.erase(g.find(e));
    }

	//chon mot trong 3 ham de thu nghiem
	//Report_DungMotPhan(50);
	//Report_SaiDinhDang();
	Report_Dung();
	return 0;
}

void ReadTestInput() //Du lieu
{
	FILE* f = fopen(sTestInput1, "rt");
    fscanf(f, "%d %d", &n, &m);
    int u, v;
    FOR(i, 0, m){
        fscanf(f, "%d %d", &u, &v);
        u--; v--;
        if(u>v) swap(u, v);
        g.insert(II(u, v));
    }
	fclose(f);
}

void ReadSubmissionOutput() //Bai hoc sinh
{
	FILE* f = fopen(sSubmissionOutput1, "rt");

	fscanf(f, "%d", &ansbl);

	if(ansbl == -1) return;

	FOR(i, 0, n) fscanf(f, "%d", bl+i);

	fclose(f);
}

void ReadTestOutput() //Dap an
{
	FILE* f = fopen(sTestOutput1, "rt");
	fscanf(f, "%d", &ansda);
	fclose(f);
}

void ReadComparerInput() //Dia chi file
{
	FILE* f = fopen("COMPAR$R.INP", "rt");
	fgets(sTestFolder, 255, f);
	fclose(f);

	strcpy(sTestInput1, sTestFolder);
	strcat(sTestInput1, "TRANSTAX.INP");

	strcpy(sTestOutput1, sTestFolder);
	strcat(sTestOutput1, "TRANSTAX.OUT");

	strcpy(sSubmissionOutput1, "TRANSTAX.OUT");

	strcpy(sResult, "");
	strcpy(sDescription, "");
}

void Report()
{
	FILE* f = fopen("COMPAR$R.OUT", "wt");
	fprintf(f, "%s\n%s", sResult, sDescription);
	fclose(f);
	exit(0);
}

void Report_Sai()
{
	strcpy(sResult, "SAI");
	Report();
}

void Report_Dung()
{
	strcpy(sResult, "DUNG");
	Report();
}

void Report_SaiDinhDang()
{
	strcpy(sResult, "SAIDINHDANG");
	Report();
}

void Report_DungMotPhan(int nPercent)
{
	sprintf(sResult, "DUNGMOTPHAN %d", nPercent);
	Report();
}
