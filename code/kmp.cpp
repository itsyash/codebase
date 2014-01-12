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
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
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
void print1d(int arr[], int n){ REP(i,n) cout<<arr[i]<<" "; cout<<endl;}


void precompute(string str, int lps[]){
    
    int len=0;

    int i=1;
    lps[0]=0;
    while(i < str.size()){
        cout<<"for i "<<i<<endl;
        if(str[i]==str[len]){
            cout<<"equal"<<endl;
            len++;
            lps[i] = len;
            i++;
        }
        else{
            cout<<"not equal"<<endl;
            if(len==0){
                cout<<"len = 0"<<endl;
                lps[i]=0;
                i++;
            }
            else{
                len = lps[len-1];
            }
        }
        cout<<"len is "<<len<<endl;
    }

}

void check(string str, string pat, int lps[]){

    int i=0,j=0;
    while(i < str.size()){
        cout<<"for i "<<i<<" j "<<j<<endl;
        

        if(str[i]==pat[j]){
            cout<<"equal\n";
            i++;
            j++;
        }
        else{
            cout<<"not equal\n";
            if(j!=0)
                j = lps[j-1];
            else{
                i++;
            }
        }

        if(j==pat.size()){
            cout<<"found matching\n";
            j=lps[j-1];
        }
    }
    // free(lps);
}

int main(){
    string pat="ABABCABAB";
    int lps[pat.size()];
    precompute(pat,lps);
    print1d(lps,pat.size());
    string str="ABABDABACDABABCABABCABAB";
    cout<<"checking\n\n\n";
    check(str,pat,lps);
   	return 0;
}
