/* Author : Yashasvi girdhar
*/

/* Data Structure Includes */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>

/*other Includes */
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>

/* C Includes */
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
typedef vector<int > vi;
typedef vector<long long int > vl;
typedef vector<bool > vb;
typedef vector<char > vc;
typedef vector<vi > vvi;

#define pb push_back
#define si(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",n)
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define all(a) a.begin(),a.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin() ; it != container.end() ; it++) //to traverse any container
#define present(container,element) (container.find(element)!=container.end()) //should be used for set,map etc.
#define vpresent(container,element) (find(all(container),element)!=container.end()) //should be used for vectors.
#define PI 3.14159265359
#define DegToRad(a) PI/180*a
#define RadToDeg(a) 180/PI*a
#define debug 1 
int gcd(int a,int b){
    if(b>a) return gcd(b,a);
    return b==0?a:gcd(b,a%b);
}
void swap(int *m,int *n){
    int temp = *n;
    *n = *m;
    *m = temp;
}
struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.first < right.first;
    }
};


const int MAXN = 1 << 21;
char *S;
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

bool sufCmp(int i, int j)
{
    if (pos[i] != pos[j])
        return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA()
{
    N = strlen(S);
    REP(i, N) sa[i] = i, pos[i] = S[i];
    for (gap = 1;; gap *= 2)
    {
        sort(sa, sa + N, sufCmp);
        REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
        REP(i, N) pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1) break;
    }
}

void buildLCP()
{
    for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
    {
        for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
            ++k;
        lcp[pos[i]] = k;
        if (k)--k;
    }
}

int main(){
	
    S = strdup("banana");
    buildSA();
    buildLCP();
    REP(i,N)
        cout<<sa[i]<<" ";//sorted suffixes
    cout<<endl;
    REP(i,N)
        cout<<pos[i]<<" ";//positions
    cout<<endl;
    REP(i,N)
        cout<<lcp[i]<<" ";//lcp between i & i+1 in sa array
    cout<<endl;
    return 0;
}
