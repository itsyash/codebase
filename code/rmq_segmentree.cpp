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
#include<math.h>
#include<limits.h>

/* C Includes */
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include<stdio.h>
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
#define MAXSIZE 10000
#define n 6
int M[MAXSIZE];

int gcd(int a,int b){
    if(b>a) return gcd(b,a);
    return b==0?a:gcd(b,a%b);
}
//node is the index of the segment tree m, start and end are the index of the the array A
void BuildTree(int node,int start,int end,int A[],int N){
    //printf("for start=%d end%d and node=%d\n",start,end,node);
    if(start==end){
        M[node]=A[start];
       // printf("M[%d]=%d\n",node,M[node]);
    }
    else{
        BuildTree(2*node+1,start,(start+end)/2,A,N);
        BuildTree(2*node+2,(start+end)/2+1,end,A,N);
        M[node]=min(M[2*node+1],M[2*node+2]);
      //printf("M[%d]=%d\n",node,M[node]);
    }
}

int RMQ(int node,int start,int end,int s,int e){
    if(s<=start && e>=end)
        return M[node];
    else if(s>end || e<start)
        return -1;
    int q1 = RMQ(2*node+1,start,(start+end)/2,s,e);
    int q2 = RMQ(2*node+2,(start+end)/2+1,end,s,e);
    if(q1==-1)
        return q2;
    else if(q2==-1)
        return q1;
    if(q1<q2)
        return q1;
    return q2;
}

int main(){

    int a[n] = {2,5,1,4,9,3};
    BuildTree(0,0,n-1,a,10);
    int i=0;
    int x = (int)(ceil(log2(n)));//height of tree
    int max_size = 2*(int)pow(2,x)-1;
    while(i<max_size)
        cout<<M[i++]<<" ";
    cout<<endl;
    int qs = 4;  // Starting index of query range
    int qe = 5;// Ending index of query range

    // Print minimum value in arr[qs..qe]
    printf("Minimum of values in range [%d, %d] is = %d\n",qs, qe, RMQ(0,0, n-1,qs,qe));
    return 0;
}
