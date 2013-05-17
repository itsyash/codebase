/* Author : Yashasvi girdhar
 * Given a singly linked list, swap kth node from beginning with kth node from end. Swapping of data is not allowed, only pointers should be changed
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

struct node{
	int data;
	node *next;
};

int n;

void insert(node *start,int n){
	while(start->next)
		start=start->next;
	start->next=(node *)malloc(sizeof(node));
	start->next->data=n;
	start->next->next=NULL;
}
void printlist(node *start){
	//start=start->next;
	while(start && printf("%d->",start->data))
		start=start->next;
	cout<<endl;
}

void swap(node *start,int k){
	if(k>n)//out of bound
		return;
	if(k==n-k+1)//y is equal to x
		return;
	if(n-k+1 < k)//y is before x, swap
		k=n-k+1;
	int count=1;
	start=start->next;
	while(start && count != k-1){
		count++;
		start=start->next;
	}
	//printlist(start);
	node *t1=start;
	node *t2=start->next->next;
	
	count=0;
	while(start && count != n-2*k+1){
		count++;
		start=start->next;
	}
	//printlist(start);
	node *t3=start;
	node *t4=start->next;
	
	if(t2->data==t4->data){ //y next to x case
		t1->next=t2;
		t3->next=t2->next;
		t2->next=t3;
	}
	
	else{
	//swap
		t3->next=t1->next;
		t1->next->next=t4->next;
		t4->next=t2;
		t1->next=t4;
	}
}
int main(){
	node *start=NULL;
	start=(node *)malloc(sizeof(node));
	start->next=NULL;
	
	si(n);
	REP(i,n){
		int temp;
		si(temp);
		insert(start,temp);
	}
	printlist(start->next);
	int k;
	si(k);
	swap(start,k);
	printlist(start->next);
	return 0;
}


