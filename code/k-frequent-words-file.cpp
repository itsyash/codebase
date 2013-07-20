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
#include <stdio.h>
#include <string.h>
#include <ctype.h>

using namespace std;
#define debug 1 
#define ALPHABET_SIZE 26
#define CHAR_TO_INT(c) (int)c - (int)'a'
#define REP(i,n) for (int i=0 ; i< (n) ; i++)
int gcd(int a,int b){
    if(b>a) return gcd(b,a);
    return b==0?a:gcd(b,a%b);
}

typedef struct trienod{
    int end;
    int freq;
    int indexMinheap;
    trienod *children[ALPHABET_SIZE];
}trienode;

typedef struct heapnod{
    trienode *root;
    int freq;
    char *word;
}heapnode;

typedef struct heap{
    int size;
    int capacity;
    heapnode *array;
}minheap;

struct trie{
    trienode *root;
    int count;
};

trienode* newTrienode(){
    trienode *temp;
    temp=(trienode *)malloc(sizeof(trienode));
    temp->end=0;
    temp->freq=0;
    for(int i=0 ; i < ALPHABET_SIZE ; i++){
        temp->children[i]=NULL;
    }
    return temp;
}

minheap* newminheap(int n){

    minheap *temp = new minheap;
    temp->size=0;
    temp->capacity=n;
    temp->array = new heapnode[n];
    return temp;
}

void printrie(trienode *root){

    if(root->end==1){
        cout<<"end of word "<<root->freq<<endl;
        //return ;
    }

    REP(i,ALPHABET_SIZE){
        if(root->children[i]){
            printf("%c ",(char)i+(int)'a');
            printrie(root->children[i]);
        }
    }
}

void insert_trie(trie *mytrie , char key[]){
    if(!debug)
        cout<<"inserting "<<key<<endl;
    int len=strlen(key);
    trienode *crawl;
    crawl = mytrie->root;
    mytrie->count++;

    for(int i=0;i<len;i++){
        int index = CHAR_TO_INT(tolower(key[i]));
        if(!debug)cout<<"inserting "<<key[i]<<endl;
        if(crawl->children[index]==NULL){
            if(!debug)cout<<"new node at child "<<index<<endl;
            crawl->children[index]=newTrienode();
        }
        crawl = crawl->children[index];
    }
        crawl->end=1;
        crawl->freq++;

}


void insertword(char word[],trie *mytrie,minheap *heap){

   insert_trie(mytrie,word);

}

void initialize(trie *mytrie){
    mytrie->root = newTrienode();
    mytrie->count=0;
}



void printKMostFreq(FILE *fp, int k){

    char buffer[40];

    minheap *heap = newminheap(k);
    trie mytrie;
    initialize(&mytrie);

    while(fscanf(fp,"%s",buffer) != EOF){
        insertword(buffer,&mytrie,heap);
    }
   printrie(mytrie.root);
}


int main(){
    int k = 5;
    FILE *fp = fopen ("file.txt", "r");
    if (fp == NULL)
        printf ("File doesn't exist ");
    else
        printKMostFreq (fp, k);
    return 0;
}
