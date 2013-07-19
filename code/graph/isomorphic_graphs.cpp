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

struct node{
	int data;
	node *left;
	node *right;
};


node* newNode(int n){
	//cout<<"new node\n";
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}


void printtree(node **root){ 
	if((*root)==NULL)
		return;
	printtree(&((*root)->left));
	//cout<<"printing "<< (*root)->data <<endl;
	cout<< (*root)->data <<" ";
	printtree(&((*root)->right));
}

int isomorphic(node *n1,node *n2){

	if(n1==NULL && n2==NULL)
		return 1;
	else if(n1==NULL || n2==NULL)
		return 0;
	return (n1->data==n2->data && ( ( isomorphic(n1->left,n2->left) && isomorphic(n1->right,n2->right) ) || (isomorphic(n1->left,n2->right) && isomorphic(n1->right,n2->left) ) )  );
}
int main(){
	
	node *n1 = newNode(1);
    n1->left        = newNode(2);
    n1->right       = newNode(3);
    n1->left->left  = newNode(4);
    n1->left->right = newNode(5);
    n1->right->left  = newNode(6);
    n1->left->right->left = newNode(7);
    n1->left->right->right = newNode(8);
 
    node *n2 = newNode(1);
    n2->left         = newNode(3);
    n2->right        = newNode(2);
    n2->right->left   = newNode(4);
    n2->right->right   = newNode(5);
    n2->left->right   = newNode(6);
    n2->right->right->left = newNode(8);
    n2->right->right->right = newNode(7);
	
		
	printtree(&n1);		
	cout<<endl;
	printtree(&n2);		
	cout<<endl;
	
	if(isomorphic(n1,n2))
		cout<<"yes\n";
	else
		cout<<"no\n";
		
	return 0;
}

