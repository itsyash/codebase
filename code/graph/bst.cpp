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


node* newnode(){
	//cout<<"new node\n";
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void insert(node **root,int n){
	//cout<<"inserting "<<n<<endl;
	if((*root)==NULL){//root
		(*root)=newnode();
		(*root)->data=n;
		return ;
	}
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

vector<int> postorderTraversal(node *root) {
        vector<int> a;
        if(!root)
            return a;
            
        stack<node*> s;
        s.push(root);
        while(!s.empty()){
            node *t = s.top();
            cout<<" t is "<< t->data<<endl;
            if(t->right){
            	cout<<"right "<<t->right->data<<endl;
            	node *temp= t->right;
                s.push(temp);
               
            }
            if(t->left){
            	cout<<"left "<<t->left->data<<endl;
            	node *temp = t->left;
                s.push(temp);
                
            }
            if(!t->left && !t->right){
                cout<<"vector push\n";
                a.push_back(t->data);
                s.pop();
                // t=NULL;
            }
             t->right = NULL;
             t->left = NULL;
        }
         return a;
}

int main(){
	int n;
	si(n);
	
	node *root=NULL;
	//initialize(&bst);
	REP(i,n){
		int temp;
		si(temp);
		insert(&root,temp);
	}
		
	printtree(&root);		
	cout<<endl;
	int a;
	std::vector<int> v;
	v =  postorderTraversal(root);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;


		
	return 0;
}
