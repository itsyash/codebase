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
#include <limits.h>


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

int dp[10000];
int p[1500][1500];

int isP(string s, int b, int e) {
    cout<<"p "<<b<<" "<<e<<endl;
  int &x = p[b][e];
  if(x != -1) return x;
  if(b==e)return x=1;
  int n = e - b +1;
  // cout<<n<<endl;
  for (int i=b ;i<b+(n / 2) + 1;++i) {
     // cout<<i<<" "<<e-i<<endl;
     if (s[i] != s[e-i]) {
         return x=0;
     }
  }
  return x=1;
}



int calc(string s, int i){
   cout<<"calc "<<i<<endl;
   int &x = dp[i];
   if(x != -1)
        return x;
   if(i==0)
        return x=0;
        
   if(isP(s,0,i)){
        cout<<"its palin\n";
       return x=0;
   }
   
   cout<<"counting min\n";

   int mn = INT_MAX, temp;
   for(int j=0;j<i;j++){
       cout<<"for j "<<j<<endl;
       if(isP(s,j+1,i)==1){
            cout<<"is palin "<<j+1<<" "<<i<<endl;
            temp = calc(s,j) + 1;
            mn = min(mn,temp);
       }
   }
   cout<<"for i "<<i<<" returning "<<mn<<endl;
   return x=mn;
}

int minCut(string s) {
    if(s.size() <= 1)return 0;
    
    memset(dp,-1,sizeof(dp));
    memset(p,-1,sizeof(p));
    
    return calc(s,s.size()-1);
}


int main(){
    string s;
    cin >> s;
    cout<<minCut(s)<<endl;
    return 0;
}