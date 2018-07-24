#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std; 
struct node{
   node* Alphabets[26];
   bool isleaf;	
   string word;			
};
node* getnode();
void insert(node*,string,int);
bool search(node*,string,int);
void search_recur(node*);

int main(){
 	node *root;
	string a;
	root=getnode();
	insert(root,"hello",5);
	insert(root,"hell",4);
	insert(root,"he",2);	
	cout<<"Enter word to search"<<endl;
	cin>>a;
	if(!search(root,a,a.length()))
		cout<<"No strings found";
	
}
void search_recur(node* ptr){
	if(ptr->isleaf)
		cout<<ptr->word<<endl;
	for(int i=0;i<26;i++){
		  if(ptr->Alphabets[i])
			search_recur(ptr->Alphabets[i]);	
		}
}
bool search(node* root,string a,int n){
	int index=0;node*ptr;
	ptr=root;
	for(int i=0;i<n;i++){
		index=a[i]-'a';
	   if(!ptr->Alphabets[index])	
		return false;
	   ptr=ptr->Alphabets[index];		  
	}		
	search_recur(ptr);
	return true;
}
void insert(node* root,string a,int n){
	int index=0;node *ptr;	
 	ptr=root;
 	for(int i=0;i<n;i++){
	  index=a[i]-'a';
	   if(!ptr->Alphabets[index])
		ptr->Alphabets[index]=getnode();
		ptr=ptr->Alphabets[index];
	}
	ptr->isleaf=true;
	ptr->word=a;
	//cout<<"inserted"<<endl;
}
node* getnode(){
   	node* np;
	np=(node*)malloc(sizeof(node));
	for(int i=0;i<26;i++)
		np->Alphabets[i]=NULL;	
	np->isleaf=false;
	return np;
}
