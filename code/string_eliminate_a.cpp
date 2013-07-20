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

int main(){
	char str[50];
	ss(str);
	int flag=1;
	
	int count=0;
	REP(i,strlen(str)){
		if(flag==1 && str[i]!='a' && str[i]!='b'){
			if(str[i]=='c'){
				if(count>0){
					for(int j=0;j<count-1;j++)
						cout<<"a";
					count=0;
				}
				else if(count==0)
					cout<<str[i];
			}
			else{
				if(count>0){
					for(int j=0;j<=count;j++)
						cout<<"a";
					count=0;
					cout<<str[i];
				}
				else if(count<=0)
					cout<<str[i];
			}
		}
		else if(flag==1 && str[i]=='b')
			continue;
		else if(flag==1 && str[i]=='a')
			flag=2;
		else if(flag==2 && str[i]=='c'){
			count--;
			flag=1;
			continue;
		}
		else if(flag==2 && str[i]=='b'){
			continue;
		}
		else if(flag==2 && str[i]=='a'){
			//cout<<"a";
			count++;
		}
		else if(flag==2 && str[i]!='c' && str[i]!='b' && str[i]!='a'){
			flag=1;
			while(count>=0){
				cout<<"a";
				count--;
			}
			cout<<str[i];
		}
	}
	if(flag==2 && count==0)
		cout<<"a";
	else if(count>0){
		REP(i,count+1)
			cout<<"a";
	}
	cout<<endl;
		
		
	return 0;
}
