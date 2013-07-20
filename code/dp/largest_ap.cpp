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

int calculate(int a[],int n){

    cout<<"in function\n";
    if(n<=2)return n;

    int d[n][n];
    int llap = 2; 

    for(int i=0;i<n;i++)
        d[i][n-1]=2;

    for(int j=n-2 ; j>=1 ; j--){
        int i=j-1 , k=j+1;
        
        printf("i=%d j=%d k=%d\n",i,j,k);

        while(i>=0 && k<= n-1){

            printf("i=%d k=%d\n",i,k);

            if(a[i]+a[k]<2*a[j])
                k++;

            else if(a[i]+a[k] > 2*a[j]){
                d[i][j]=2;
                    i--;
            }

            else if(a[i]+a[k]==2*a[j]){
                printf("found ap i=%d j=%d k=%d\n",i,j,k);
                d[i][j] = d[j][k]+1;
                llap = max(llap,d[i][j]);
                printf("llap=%d\n",llap);
                i--;
                k++;
            }
        }
        while (i >= 0)
        {
            d[i][j] = 2;
            i--;
        }
    }
    REP(i,n){
       REP(j,n){
          cout<<d[i][j]<<" ";
       }
      cout<<endl;
    } 
    return llap;
}

int main(){
    int tc;
    si(tc);
    REP(t,tc){
        int n;
        si(n);
        int a[n];
        REP(i,n)
            si(a[i]);
        int ans; 
        ans = calculate(a,n);
        cout<<"ans="<<ans<<endl;
    }
    return 0;
}
