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
typedef vector<int > vd;
typedef vector<long long int > vl;
typedef vector<bool > vb;
typedef vector<char > vc;
typedef vector<vd > vvd;

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

#define SIEVE(a) ({int b=ceil(sqrt(a));vd d(a,0);vd e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})


#define debug 1 


int gcd(int a,int b){
	    if(b>a) return gcd(b,a);
	        return b==0?a:gcd(b,a%b);
}
void swap(int *m,int *n){
    int temp = *n;
    *n = *m;
    *m = temp;
}
struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.first < right.first;
    }
};

int compare (const void *a, const void *b)
{
	const int *ia = (const int *)a; // casting pointer types 
	const int *ib = (const int *)b;
	return *ia  - *ib; 
}

void dfs(int M[][5], int n, int r, int c, bool visited[][5]){
    cout<<"in dfs r= "<<r<<" c= "<<c<<endl;
    visited[r][c]=1;

    static int row[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int col[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    for(int i=0; i<8; i++){
        if(r+row[i]>=0 && r+row[i]<n && c+col[i]>=0 && c+col[i]<n){

            if(visited[r+row[i]][c+col[i]]==0 && M[r+row[i]][c+col[i]]==1)
                dfs(M,n,r+row[i],c+col[i],visited);
        }
    }
}


int countcomponents(int M[][5],int n){
    
    bool visited[5][5];
    memset(visited,'0',sizeof(visited));
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0 && M[i][j]==1){
                dfs(M,n,i,j,visited);
                count++;
            }
        }
    }
    return count;
  

}

int main(){
    int n=5;
    int M[5][5]= {  {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}};
    
    int c = countcomponents(M,n);
    cout<<c<<endl;
    return 0;
}
