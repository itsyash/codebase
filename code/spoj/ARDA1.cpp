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

vector< pair<int,int> > v;

int main(){
    int m1,m2;
    scanf("%d %d",&m1,&m2);

    char p[310][310];
    char t[1000000];
    for(int i=0;i<m1;i++)
    {
        scanf("%s",t);    
        for(int j=0;j<m2;j++)
        {  
            p[i][j]=t[j];
        }
    }
    
    int n1,n2;
    scanf("%d %d",&n1,&n2);   
    char s[2100][2100];
    char q[1000000];
    for(int i=0;i<n1;i++)
    {
        scanf("%s",q);    
        for(int j=0;j<n2;j++)
        {  
            s[i][j]=q[j];
        }
    }

    int flag=1;
    for (int i = 0; i < n1; ++i)
    {
        if(i+m1 > n1)
            break;
        for (int j = 0; j < n2; ++j)
        {
            if(j+m2 > n2)
                break;
            flag=0;
            if(s[i][j]==p[0][0] && j+m2 <= n2 && i+m1 <= n1){
                for (int k = 0; k < m1; ++k)
                {
                    for (int l = 0; l < m2; ++l)
                    {
                        // cout<<i<<" "<<j<<" "<<k<<" "<<" "<<l<<endl;
                        if(s[i+k][j+l] != p[k][l]){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1){
                        break;
                    }
                }
                if(flag==0){
                    pair<int,int> temp = make_pair(i+1,j+1);
                    v.push_back(temp);
                }
            }
        }
    }

    sort(v.begin(),v.end());
    if(v.size()==0){
        printf("NO MATCH FOUND...\n");
    }
    else{
        for (std::vector< pair<int,int> >::iterator i = v.begin(); i != v.end(); ++i)
        {
            printf("(%d,%d)\n",(*i).first,(*i).second);
        }
    }
	return 0;
}
