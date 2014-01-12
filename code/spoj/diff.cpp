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

int lcs[90][90];
int back[90][90];
int n,m;
int maxlcs=-1;
string s1,s2;

set<string> seq;
map<string,bool> processed[81][81];

void backtrack(int i, int j,string word){
    
    cout<<"i j "<<i<<" "<<j<<" "<<endl;
    if(processed[i][j].find(word)!=processed[i][j].end())
        return;

    if(i==0 || j==0){
        seq.insert(word);
    }

    else if(s1[i-1]==s2[j-1]){
        // cout<<"equal\n";
        word = s1[i-1] + word;
        backtrack(i-1,j-1,word);
    }
    else if(lcs[i-1][j] > lcs[i][j-1]){
        backtrack(i-1,j,word);
    }
    else if(lcs[i][j-1] > lcs[i-1][j]){
        backtrack(i,j-1,word);
    }
    else{
        backtrack(i-1,j,word);
        backtrack(i,j-1,word);
    }
    processed[i][j][word] = true;
}

void printlcs(int i, int j,string word){
    
     // cout<<"i j "<<i<<" "<<j<<" "<<word<<endl;
    // if(processed[i][j].find(word)!=processed[i][j].end())
    //     return;

    if(i==0 || j==0){
        cout<<word<<endl;
        return;
    }

    else if(s1[i-1]==s2[j-1]){
        // cout<<"equal\n";
        word = s1[i-1] + word;
        printlcs(i-1,j-1,word);
    }
    else if(lcs[i-1][j] >= lcs[i][j-1]){
        // cout<<1<<endl;
        printlcs(i-1,j,word);
    }
    else{
        // cout<<2<<endl;
        printlcs(i,j-1,word);
    }
}


void printdiff(int i, int j){
    cout<<"i j "<<i<<" "<<j<<endl;
    if(i>0 && j>0 && s1[i-1]==s2[j-1]){
        // cout<<"equal "<<s1[i-1]<<endl;
        printdiff(i-1,j-1);
        cout<<" "<<s1[i-1]<<endl;
    }
    else if(i>0 && (j==0 || lcs[i][j-1] <= lcs[i-1][j])){
        printdiff(i-1,j);
        cout<< "- "<<s1[i-1]<<endl;
    }
    else if(j>0 && (i==0 || lcs[i][j-1] >= lcs[i-1][j])){
        printdiff(i,j-1);
        cout<< "+ "<<s2[j-1]<<endl;
    }
    else
        cout<<" ";
}

int main(){
    int tc;
    si(tc);
    while(tc--){
        seq.clear();
        // processed.clear();
        char temp1[100], temp2[100];
        scanf("%s",temp1);
        scanf("%s",temp2);
        s1 = temp1;
        s2 = temp2;
        n = s1.size();
        m = s2.size();
        for(int i=0;i<=n;i++)
            lcs[i][0]=0;
        for(int i=0;i<=m;i++)
            lcs[0][i]=0;

        for(int i=1;i <= n;i++){
            for (int j = 1; j <= m; ++j)
            {
                if(s1[i-1]==s2[j-1]){
                    lcs[i][j] = lcs[i-1][j-1]+1;    
                }
                else{
                    lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
        }

        // for (int i = 0; i <= n; ++i)
        // {
        //     print1d(lcs[i],m+1);
        // }
        // maxlcs = lcs[n][m];
        // cout<<maxlcs<<endl;
        // backtrack(n,m,"");
        // for (std::set<string>::iterator i = seq.begin(); i != seq.end(); ++i)
        // {
        //    printf("%s\n",i->c_str());
        // }
        // printf("\n\n\n");
        printlcs(n,m,"");
        printdiff(n,m);
    }
	return 0;
}
