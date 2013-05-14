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
#define REP(i, n) for (int i = 1 ; i <= (n) ; i ++)
#define all(a) a.begin(),a.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin() ; it != container.end() ; it++) //to traverse any container
#define present(container,element) (container.find(element)!=container.end()) //should be used for set,map etc.
#define vpresent(container,element) (find(all(container),element)!=container.end()) //should be used for vectors.
#define PI 3.14159265359
#define DegToRad(a) PI/180*a
#define RadToDeg(a) 180/PI*a
#define debug 1



int main(){
	int tc;
	si(tc);
	REP(i,tc){
		int n;
		si(n);
		int h[n+1] , k[n+1];
		for(int j=1;j<=n;j++){
			si(h[j]);
		}
		for(int j=1;j<=n;j++){
			si(k[j]);
		}
		
		if(!debug){
			REP(j,n+1){
				cout<<h[j]<<" ";
			}
			cout<<endl;
			REP(j,n+1){
				cout<<k[j]<<" ";
			}
			cout<<endl;
		}
		//dp starts
		int max=*std::max_element(h,h+n+1);
		max=2*max;	
		int d[n+1][max+1];
		d[0][0]=0;
		for(int j=1;j<=max;j++)
			d[0][j]=10000000;
		
		//cout<<"initially\n";
		if(!debug){
			for(int p=0;p<=n;p++){
				for(int q=0;q<=max;q++){
					cout<<d[p][q]<<" ";
				}
				cout<<endl;
			}
		}
		//cout<<endl;
		
		for(int p=1;p<=n;p++){
			for(int q=0;q<=max;q++){
				//printf("for d[%d][%d]\n",p,q);
				d[p][q]=d[p-1][q];
				if(k[p]<=q){
					//printf("compare b/w d[%d][%d]=%d and 1+d[%d][%d]=%d\n",p-1,q,d[p-1][q],p,q-k[p],d[p][q-k[p]]);
					d[p][q]=min(d[p][q],1+d[p][q-k[p]]);
				}
				//printf("d[%d][%d]=%d\n",p,q,d[p][q]);
			}
		}
		
		//cout<<"\nfinally\n";
		if(!debug){
			for(int p=0;p<=n;p++){
				for(int q=0;q<=max;q++){
					cout<<d[p][q]<<" ";
				}
				cout<<endl;
			}
		}
		int res=0;
		for(int j=1;j<=n;j++){
			res = res + d[n][2*h[j]];
		}
		cout<<res<<endl;
			
	}
	return 0;
}
