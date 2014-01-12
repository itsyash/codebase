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

struct node{
    int data;
    node *next;
    node *back;
};

int n;

void insert(node *start,int n){
    while(start->next)
        start = start->next;
    start->next = (node *)malloc(sizeof(node));
    start->next->data = n;
    start->next->next = NULL;
    start->next->back = start;
}

void printlist(node *start){
    while(start){
        printf("back=%d\t",start->back->data);
        printf("node-%d\t",start->data);
        if(start->next)
           printf("next=%d\n",start->next->data);
        start=start->next;
    }
    cout<<endl;
}

int main(){
    node *start=NULL;
    start = (node *)malloc(sizeof(node));
    start->next=NULL;
    start->back=NULL;
    si(n);
    REP(i,n){
        int temp;
        si(temp);
        insert(start,temp);
    }
    printlist(start->next);
    return 0;
}
