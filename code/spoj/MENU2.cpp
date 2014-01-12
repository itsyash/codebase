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

int days, dishes, budget;
double maxval=0.0;
int mincost=999999, availmincost=99999;
int precount=0;
int ndays[25];
double dp[25][110][52][2];

double calc(int c[], int v[], int tday, int cost, int prev, int store[]){
   
    // printf("tday=%d cost=%d prev=%d and maxval=%f\n",tday,cost,prev,maxval);

    if(tday > days){
        return 0.0;
    }

    double &x = dp[tday][cost][prev][precount];

    if(x != -1.0){
        return x;
    }

   // cout<<"continue\n";

    x=-10000000.0;


    double tmax=-1;
    for (int j = 1; j <= dishes; ++j)
    {
        int flag=0;
        if(cost + c[j] <= budget){
            store[tday]=j;
            if(j==prev){
                precount++;
                if(precount==1)
                    tmax = calc(c,v,tday+1,cost+c[j],j,store) + (double)v[j]*0.5;
                else if(precount >= 2)
                    tmax = calc(c,v,tday+1,cost+c[j],j,store) + (double)0;
            }
            else{
                precount=0;
                tmax = calc(c,v,tday+1,cost+c[j],j,store) + (double)v[j];
            }
            if(tmax > x){
                x=tmax;
            }
           
        }
    }
    return x;
}


int main(){
    scanf("%d %d %d",&days,&dishes,&budget);
    
    while( days!=0 && dishes!=0 && budget!=0){
        precount=0, maxval=0.0, mincost=9999999;
        
        // memset(dp,-1,sizeof(dp));

        for (int i = 0; i < 25; ++i)
        {
            for (int j = 0; j < 25; ++j)
            {
               for (int k = 0; k < 25; ++k)
               {
                     for (int l = 0; l < 2; ++l)
                     {
                        dp[i][j][k][l]= -1;
                         // cout<<dp[i][j][k][l]<<" ";
                     }
               }
               // cout<<endl;
            }
            // cout<<endl;
        }

        int c[dishes+1], v[dishes+1];
        for (int i = 1; i <= dishes; ++i){
            scanf("%d %d",&c[i],&v[i]);
            if(c[i] > availmincost)
                availmincost = c[i];
        }
        int store[days];
        double ans = calc(c,v,1,0.0,0,store);
        printf("%.1lf\n",max(0.0,ans) );
        // cout<<"cost "<<mincost<<endl;
        // if (maxval != 0.0)
        // {
        //     for (int i = 0; i < 3; ++i)
        //     {
        //         cout<<ndays[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        scanf("%d %d %d",&days,&dishes,&budget);    
    }
	return 0;
}
