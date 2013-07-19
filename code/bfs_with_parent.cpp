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
#define V 6
int gcd(int a,int b){
    if(b>a) return gcd(b,a);
    return b==0?a:gcd(b,a%b);
}

void bfs(int graph[V][V]){

    int parent[V];
    bool visited[V];
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(0);
    visited[0]=1;
    parent[0]=-1;
    while(!q.empty()){
        int v = q.front();
        cout<<v<<" ";
        q.pop();
        for(int u=0 ; u<V ; u++){
            if(graph[v][u]>0 && visited[u]==0){
                q.push(u);
                cout<<u<<" pushed ";
                visited[u]=1;
                parent[u]=v;
            }
        }
    }
}

int main(){
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                       };
    bfs(graph);
    cout<<endl;
    return 0;
}
