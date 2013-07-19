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

int calculate(int a[],int n,int i,int j,int k,int ans){
    printf("for i=%d j=%d k=%d\n",i,j,k);
    //if(j==0 || j==n-1)return ans;
   // int i=j-1 , k=j+1;
    while(i>=0 && k<=n-1){
        printf("i=%d k=%d\n",i,k);
        if(a[i]+a[k] == 2*a[j]){
            printf("found ap for i=%d j=%d k=%d\n",i,j,k);
            int temp = calculate(a,n,i-1,i,j,ans+1) + calculate(a,n,j,k,k+1,ans+1);
            if(temp > ans)
                ans = temp;
            break;
        }
        else if(a[i]+a[k]>2*a[j])
            i--;
        else
            k++;
    }
    cout<<"returning ans="<<ans<<endl;
    return ans; 
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
        int ans=2;
        for(int i=1;i<n-1;i++){
            int temp = calculate(a,n,i-1,i,i+1,2);
            if(ans < temp)
                ans = temp;
        }
        cout<<"ans = "<<ans<<endl;
    }
    return 0;
}
