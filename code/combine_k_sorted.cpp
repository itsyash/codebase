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

void swap(pair<int,int> a[],int i,int j){
    pair<int,int> temp = a[i];
    a[i]=a[j];
    a[j]=temp;
}

int parent(int i){
    return i/2;
}

void maxHeapify(pair<int,int> a[],int i,int n){

    
    int l = 2*i;
    int r = 2*i + 1;
    
    int largest = i;

    if(l<=n && a[l].first<a[largest].first) largest = l;
    if(r<=n && a[r].first<a[largest].first) largest = r;
    
   // printf("a[i=%d]=%d a[l=%d]=%d a[r=%d]=%d largest=%d\n",i,a[i],l,a[l],r,a[r],largest);

    if(largest!=i){
       // cout<<"changed\n";
        pair<int,int> temp = a[i];
        a[i]=a[largest];
       a[largest]=temp;
      //a[i] = (a[largest]=a[i])-a[i]+a[largest];   
        //REP(i,n+1)
          //  cout<<a[i]<<" ";
       // cout<<endl;
        maxHeapify(a,largest,n);
    }
}

void buildmaxHeap(pair<int,int> a[],int n){

    for(int i = n/2 ; i > 0 ; i--){
        maxHeapify(a,i,n);
    }
}

int returnmax(int a[]){
    return a[1];
}

pair<int,int> extractmax(pair<int,int> a[],int n){
    pair<int,int> max = a[1];
    a[1]=a[n];
    buildmaxHeap(a,n-1);
    return max;
}


void increaseKey(pair<int,int> a[],int i,int index, int key){
    
    a[i].first=key;
    a[i].second=index;
    while(i>1 && a[parent(i)].first>a[i].first){
        swap(a,i,parent(i));
        i=parent(i);
    }
}

void insert(pair<int,int> a[],int x,int index,int n){
    a[n+1].first=-99999;
    increaseKey(a,n+1,index,x);
}

void combine(int arr[3][4],int k,int n){
    pair<int,int> h[k+1];
    REP(i,k){
        h[i+1].first = arr[i][0];
        h[i+1].second = i;
    }
    buildmaxHeap(h,k);
    REP(i,k){
        cout<<h[i+1].first<<" ";
    }
    cout<<endl;
    int index[k];
    REP(i,k)
        index[i]=0;
    int count=n*k;
  //  while(count>0){

    pair<int,int> temp = extractmax(h,k);
    cout<<temp.first<<endl;
    index[temp.second]++;
    insert(h,arr[temp.second][index],temp.second,k);
} 

int main(){
    int arr[3][4] =  {{2, 6, 12, 34},
        {1, 9, 20, 1000},
        {23, 34, 90, 2000}};
    int k = 3, n=4;

    combine(arr,k,n);

}
