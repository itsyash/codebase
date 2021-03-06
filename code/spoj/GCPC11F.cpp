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
#include <string.h>
#include <limits.h>

using namespace std;
typedef vector<int > vd;
typedef vector<long long int > vl;
typedef vector<bool > vb;
typedef vector<char > vc;
typedef vector<vd > vvd;

#define pb push_back
#define si(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",n)
#define pi(n) printf("%d\n",n)
#define REP(i, s, n) for (int i = (s) ; i < (n) ; i ++)
#define all(a) a.begin(),a.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin() ; it != container.end() ; it++) //to traverse any container
#define present(container,element) (container.find(element)!=container.end()) //should be used for set,map etc.
#define vpresent(container,element) (find(all(container),element)!=container.end()) //should be used for vectors.
#define PI 3.14159265359
#define DegToRad(a) PI/180*a
#define RadToDeg(a) 180/PI*a

#define isSet(a,i) (((a)>>i)&(1LL))
#define NumSetBits(a) __builtin_popcount(a)

#define SIEVE(a) ({int b=ceil(sqrt(a));vd d(a,0);vd e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})
#define tobits(n)({vd e;while(n>0){e.pb(n%2);n /= 2;}reverse(e.begin(),e.end());e;})
#define debug 1 

int gcd(int a,int b){ if(b>a) return gcd(b,a); return b==0?a:gcd(b,a%b);}
void swap(int *m,int *n){ int temp = *n; *n = *m;*m = temp;}
void print1d(int arr[], int n){ REP(i,0,n) cout<<arr[i]<<" "; cout<<endl;}

int main(){
    int tc;
    si(tc);
    getchar();
    int count[26]={0};
    int maxcount=0, maxindex=-1;
    while(tc--){
        // for (int i = 0; i < 26; ++i)
            // count[i]=0;
        memset(count,0,sizeof(count));
        maxcount=0, maxindex=-1;
        string str;
        getline(cin,str);
        int l = str.size();
        // cout<<str<<endl;
        for (int i = 0; i < l; ++i){
            if(str[i]==' ')continue;
            count[str[i]-65]++;
            // cout<<str[i]-65<< " ";
            if(count[str[i]-65] >= maxcount){
                maxcount = count[str[i]-65];
                maxindex = str[i]-65;
            }
        }
        int c=0;
        for (int i = 0; i < 26; ++i)
        {
            if(count[i]==maxcount)c++;
        }
        if(c>1){
            cout<<"NOT POSSIBLE"<<endl;
            continue;
        }
        int d = maxindex-4;
        if(d < 0)d += 26;
        cout<<d<<endl;
        for (int i = 0; i < l; ++i)
        {
            if(str[i]==' '){
                cout<<" ";
                continue;
            }
            int temp = str[i]-65-d;
            char ch = str[i] - d;

            if(temp < 0){
                ch = str[i] - d + 26 ;
            }
            cout<<ch;
        }
        cout<<endl;
    }
	return 0;
}
