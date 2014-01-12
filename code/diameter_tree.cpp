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

struct node{
	int data;
	node *left;
	node *right;
};


node* newnode(int n){
	//cout<<"new node\n";
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->left=NULL;
	temp->right=NULL;
    temp->data = n;
	return temp;
}
void insert(node **root,int n){
	//cout<<"inserting "<<n<<endl;
	if((*root)==NULL){//root
		(*root)=newnode(n);
	//	(*root)->data=n;
		return ;
	}
    int x=rand()%100;
	if(n <= (*root)->data){
		//cout<<"to left of "<<(*root)->data<<endl;
		insert(&((*root)->left),n);
	}
	else{
		//cout<<"to right of "<<(*root)->data<<endl;
		insert(&((*root)->right),n);
	}
}

void printtree(node **root){ 
	if((*root)==NULL)
		return;
	printtree(&((*root)->left));
	//cout<<"printing "<< (*root)->data <<endl;
	cout<< (*root)->data <<" ";
	printtree(&((*root)->right));
}

pair<int,int> diameter(node *root){
    if(root->left==NULL && root->right==NULL){
        pair<int,int> p;
        p.first=1;
        p.second=1;
        return p;
    }
    
    pair<int,int> l,r;
    l.first=l.second=0;
    r.first=r.second=0;
    
    if(root->left)
        l = diameter(root->left);
    if(root->right)
        r = diameter(root->right);
    
    int h=max(l.second+1,r.second+1);
     pair<int,int> p;
     int temp=max(l.first,r.first);
     p.first=max(temp,l.second+1+r.second);
     p.second=h;
     return p;

}

int main(){
    node *root = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->left->left  = newnode(4);
    root->left->right = newnode(5);
    root->left->left->left = newnode(6);
    root->left->right->left = newnode(7);
    root->left->right->right = newnode(8);
    root->left->right->right->right = newnode(9);
    root->left->right->left->left = newnode(10);
    printtree(&root);
    
    pair<int,int> d = diameter(root);
    cout<<"diameter= "<<d.first<<endl;
    cout<<"height= "<<d.second<<endl;
    return 0;
}
