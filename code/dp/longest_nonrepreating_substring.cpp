/* Author : Yashasvi girdhar
 * Problem: Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6. For “BBBB” the longest substring is “B”, with length 1. For “GEEKSFORGEEKS”, there are two longest substrings shown in the below diagrams, with length 7. 
 * 
 * below solution is not the best solution
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
#define all(a) a.begin(),a.end()
#define REP(i, n) for (int i = 0 ; i < (n) ; i ++)
#define tr(container,it) for(typeof(container.begin()) it = container.begin() ; it != container.end() ; it++) //to traverse any container
#define present(container,element) (container.find(element)!=container.end()) //should be used for set,map etc.
#define vpresent(container,element) (find(all(container),element)!=container.end()) //should be used for vectors.
#define PI 3.14159265359
#define DegToRad(a) PI/180*a
#define RadToDeg(a) 180/PI*a
#define debug 0


int main(){
	int tc;
	si(tc);
	REP(t,tc){
		char s[1000];
		ss(s);
		int n=strlen(s);
		
		int maxsub[n][n];
		
		REP(i,n){
			REP(j,n){
				if(j<i)
					maxsub[i][j]=-1;
				else if(i==j)
					maxsub[i][j]=1;
				else 
					maxsub[i][j]=-2;
			}
		}
		if(debug){
			REP(i,n){
				REP(j,n){
					cout<<maxsub[i][j]<<" ";
				}
				cout<<endl;
			}
		}	
		if(debug)cout<<endl<<"****"<<endl<<endl;
		int flag[n];
		REP(i,n)
			flag[i]=0;
		
		for(int l=1;l<n;l++){
			
			for(int i=0,j=l ; j<n ; i++,j++){
				
				if(flag[i]==1)
					continue;
				if(debug)cout<<"for i="<<i<<" j="<<j<<endl;	
				char tmp[50]="";
				strncat(tmp,s+i,j-i);
				if(debug)cout<<tmp<<endl;
				if(strchr(tmp,s[j])){
					if(debug)cout<<"found\n";
					//maxsub[i][j]=max(maxsub[i+1][j],maxsub[i][j-1]);
					flag[i]=1;
				}
				
				else if(s[i]!=s[j])
					maxsub[i][j]=1+max(maxsub[i+1][j],maxsub[i][j-1]);
					
			}
		}
		
		if(!debug){
			REP(i,n){
				REP(j,n){
					cout<<maxsub[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		//maximum length is max value in the 2-d array
		int mx=-3;
		REP(i,n){
			int x = distance(maxsub[i], find(maxsub[i], maxsub[i] + n, -2));
			if(maxsub[i][x-1] > mx)
				mx = maxsub[i][x-1];
		}
		cout<<"max = "<<mx<<endl;	
		
	}
	return 0;
}
