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
#define debug 0
#define ALPHABET_SIZE 26
#define CHAR_TO_INT(c) (int)c - (int)'a'

struct node{
	int value;
	node *children[ALPHABET_SIZE];
};

struct trie{
	node *root;
	int count;
};

node* newnode(){
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->value=0;
	REP(i,ALPHABET_SIZE){
		temp->children[i]=NULL;
	}
	return temp;
}

void initialize(trie *mytrie){
	mytrie->root = newnode();
	mytrie->count=0;
}
	
void insert(trie *mytrie , char key[]){
	if(debug)
		cout<<"inserting "<<key<<endl;
	int len=strlen(key);
	node *crawl;
	crawl = mytrie->root;
	mytrie->count++;
	
	REP(i,len){
		int index = CHAR_TO_INT(key[i]);
		if(debug)cout<<"inserting "<<key[i]<<endl;
		if(crawl->children[index]==NULL){
			if(debug)cout<<"new node at child "<<index<<endl;
			crawl->children[index]=newnode();
		}
		crawl = crawl->children[index];
	}
	crawl->value = mytrie->count;
}

void print(node *root){
	
	if(root->value!=0){
		cout<<"end of word "<<root->value<<endl;
		//return ;
	}
	
	REP(i,ALPHABET_SIZE){
		if(root->children[i]){
			printf("%c ",(char)i+(int)'a');
			print(root->children[i]);
		}
	}
}

int search(trie *mytrie,char key[]){
	if(debug)
		cout<<"searching "<<key<<endl;
	int len=strlen(key);
	node *crawl;
	crawl = mytrie->root;
	REP(i,len){
		int index = CHAR_TO_INT(key[i]);
		if(debug)cout<<"searching "<<key[i]<<endl;
		if(crawl->children[index]==NULL){
			return 0;
		}
		crawl = crawl->children[index];
	}
	return 1;
}

int main(){
	
	trie mytrie;
	initialize(&mytrie);
	
	int n;
	si(n);
	REP(i,n){
		char key[50];
		ss(key);
		insert(&mytrie,key);	
	}	
	
	print(mytrie.root);
	
	int m;
	si(m);
	REP(i,m){
		char key[50];
		ss(key);
		cout<<"for "<<key<<" -> "; 
		int found;
		found=search(&mytrie,key);
		if(found!=0)
			cout<<"found\n";
		else
			cout<<"not found\n";
	}
	
	return 0;
}
