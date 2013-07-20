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

void swap(int a[],int i,int j){
    int temp = a[i];
    a[i]=a[j];
    a[j]=temp;
}

int parent(int i){
    return i/2;
}

void maxHeapify(int a[],int i,int n){

    
    int l = 2*i;
    int r = 2*i + 1;
    
    int largest = i;

    if(l<=n && a[l]>a[largest]) largest = l;
    if(r<=n && a[r]>a[largest]) largest = r;
    
   // printf("a[i=%d]=%d a[l=%d]=%d a[r=%d]=%d largest=%d\n",i,a[i],l,a[l],r,a[r],largest);

    if(largest!=i){
       // cout<<"changed\n";
        int temp = a[i];
        a[i]=a[largest];
       a[largest]=temp;
      //a[i] = (a[largest]=a[i])-a[i]+a[largest];   
        //REP(i,n+1)
          //  cout<<a[i]<<" ";
       // cout<<endl;
        maxHeapify(a,largest,n);
    }
}

void buildmaxHeap(int a[],int n){

    for(int i = n/2 ; i > 0 ; i--){
        maxHeapify(a,i,n);
    }
}

int returnmax(int a[]){
    return a[1];
}

int extractmax(int a[],int n){
    int max = a[1];
    a[1]=a[n];
    buildmaxHeap(a,n-1);
    return max;
}


void increaseKey(int a[],int i,int key){
    
    a[i]=key;
    while(i>1 && a[parent(i)]<a[i]){
        swap(a,i,parent(i));
        i=parent(i);
    }
}

void insert(int a[],int x,int n){
    a[n+1]=-99999;
    increaseKey(a,n+1,x);
}

int main(){
    int n=14;
	int a[14+1]={0,4,1,3,2,16,9,10,14,8,7,23,6,30,8};
    buildmaxHeap(a,n);
    
    REP(i,n+1)
       cout<<a[i]<<" ";
   cout<<endl;
   REP(i,3)
   cout<<extractmax(a,n)<<endl; 
    REP(i,n+1)
       cout<<a[i]<<" ";
    cout<<endl;
    increaseKey(a,11,23);
    REP(i,n+1)
       cout<<a[i]<<" ";
    cout<<endl;
    increaseKey(a,14,25);
    REP(i,n+1)
       cout<<a[i]<<" ";
    cout<<endl;
    insert(a,28,n);
    REP(i,n+1)
       cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
