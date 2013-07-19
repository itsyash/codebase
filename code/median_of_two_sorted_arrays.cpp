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

int getmedian(int a[],int b[],int n){

    int p=0,q=n-1,r=0,s=n-1;
    while(q-p+1>2 && s-r+1>=2){
        int m1 =((q-p+1)%2==0) ? ( a[p+(q-p+1)/2]+a[p+(q-p+1)/2-1])/2 : a[p+(q-p+1)/2];
        int m2 =((s-r+1)%2==0) ? ( b[r+(s-r+1)/2]+b[r+(s-r+1)/2-1])/2 : b[r+(s-r+1)/2] ;
        printf("p=%d q=%d r=%d s=%d m1=%d m2=%d\n",p,q,r,s,m1,m2);
        if(m1 > m2){
            q = p+(q-p+1)/2;
            r = r+(s-r+1)/2;
        }
        else{
            p = p+(q-p+1)/2;
            s = r+(s-r+1)/2;
        }
        printf("p=%d q=%d r=%d s=%d m1=%d m2=%d\n",p,q,r,s,m1,m2);
    }

return (max(a[p],b[r])+min(a[q],b[s]))/2;

}


int main(){
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    int median = getmedian(ar1,ar2,n1);
    cout<<median<<endl; 
    return 0;
}
