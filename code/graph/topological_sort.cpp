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

void pushtostack(int v,int visited[],stack<int> &stk);
list<int> *adj;
int main(){
	
	int v;
	si(v);
	adj = new list<int>[v];
	int e;
	si(e);
	int m,n;
	REP(i,e){
		si(m);
		si(n);
		adj[m].pb(n);
	}
	list<int>::iterator it;
	if(debug){
		REP(i,v){
			tr(adj[i],it){
				cout<<*it<<" ";
			}
			cout<<endl;
		}
	}
	
	//start sorting
	
	int visited[v];
	REP(i,v)
		visited[i]=0;
	
	stack<int> stk;
		
	REP(i,v){
		if(visited[i]==0)
			pushtostack(i,visited,stk);
	}	
	cout<<"sorted:\n";
	while(!stk.empty()){
		cout<<stk.top()<<" ";
		stk.pop();
	}
	return 0;
}

void pushtostack(int v,int visited[],stack<int> &stk){
	
	visited[v]=1;
	
	list<int>::iterator it;
	tr(adj[v],it){
		if(visited[*it]==0)
			pushtostack(*it,visited,stk);
	}
	stk.push(v);
}
