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
int m,n,x;
map< pair<int,int>,int > cache; 
int doit(int n,int m,int x){
	
	cout<<"for n="<<n<<" m="<<m<<" x="<<x<<endl; 
	if(n==1){
		if(x>0 && x<=m){
			cout<<"returning 1\n";
			return 1;			//not storing these values in cache, as not needed,can directly return them always    instead of searching in the cache 								 
		}
		else{
			cout<<"returning 0\n"; 
			return 0;
		}
	}
	
	pair<int,int> key = make_pair(n,x);
	if(cache.find(key)!=cache.end()){
		cout<<"found..returning="<<cache[key]<<endl;
		return cache[key];
	}
	cout<<"calculating\n";
	int res=0;
	for(int i=1;i<=m;i++){
		if(x-i>0)	//sum >0
			res += doit(n-1,m,x-i);
	}
	cout<<"returning "<<res<<endl;
	return cache[key]=res;
	
}
	
int main(){
	
	si(n);si(m);si(x);
	//dp
	cache.clear();
	
	int ans;
	ans=doit(n,m,x);
	map< pair<int,int>,int >::iterator it;
	for(it=cache.begin() ; it!=cache.end() ; it++)
		cout << it->first.first << " " << it->first.second << " -> "<< it->second<<endl;
	
	cout<<ans<<endl;
	return 0;
}
