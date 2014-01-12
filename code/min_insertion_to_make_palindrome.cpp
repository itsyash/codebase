/*
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

int dp[100][100];

int calc(string s, int b, int e){

    int &x  = dp[b][e];

    if(b==e){
        return x=0;
    }

    if(e-b==1){
        if(s[b] != s[e])return x=1;
        return x=0;
    }

    
    if(x != -1)
        return x;
    if(s[b]==s[e]){
        return x=calc(s,b+1,e-1);
    }
    return x=min(calc(s,b,e-1), calc(s,b+1,e))+1;
}

int l[100][100];

int compute_lcs(string p, string q, int m, int n){
    int &x = l[m][n];
    if(x != -1)
        return x;
    if(m==0 && n==0 && p[m]==q[n])
        return x=1;
    if(m==0 || n==0)return x=0;

    if(p[m]==q[n]){
        return x=compute_lcs(p,q,m-1,n-1) + 1;
    }
    return x=max(compute_lcs(p,q,m,n-1), compute_lcs(p,q,m-1,n) );

}

 bool isP(string s) {
      int n = s.size();
      for (int i=0;i<(n / 2) + 1;++i) {
         if (s[i] != s[n - i - 1]) {
             return false;
         }
      }
      return true;
    }

int main(){
    string s;
    cin >> s;
    int sz = s.size();
    memset(dp,-1,sizeof(dp));
    memset(l,-1,sizeof(l));
    cout<<calc(s,0,sz-1)<<endl;
    string r = s;
    reverse(r.begin(),r.end());
    int lc = compute_lcs(s,r,sz-1,sz-1);
    cout<<"lcs of "<<s<<" "<<r<<" "<<lc<<endl;
    cout<<sz - lc<<endl;
    cout<<isP(s)<<endl;
    return 0;
}