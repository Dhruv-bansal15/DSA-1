#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <functional>
#include <numeric>
using namespace std;
#define int long long 
#define vi vector<int>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define tester int t;cin>>t;while(t--)
#define looper(a,b,c) for(int a=b;a<c;a++)
#define ss second
#define pqmax priority_queue<int>
#define pqmin priority_queue<int,vi,greater<int> >
#define mod 1000000007
#define vs vector<string>
#define mp map<int,int>
#define ump unordered_map<int,int>
#define space ' '
#define stc stack<char>
#define sti stack<int>
#define all(arr) arr.begin(),arr.end()
#define looprev(i,a,b) for(int i=a;i>=(b);i--)
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<space;std::cout<<std::endl;
#define si set<int>
int gCd(int a,int b){
    if(b==0)
        return a;
    return gCd(b,a%b);
}
int fact(int n){
    int res=1;
    for(int i=2;i<=n;i++)
        res = (res*i)%mod;
    return res;
}
int nCr(int n,int r){
    return fact(n)/ (fact(r)*fact(n-r));
}
    
bool compare(pair<int,int> &one, pair<int,int> &two){
    return one.second < two.second;
}
class node{
    public:
        int data;node *next;node *prev;
        node(int d){
            data =d ;
            next=NULL;
            prev=NULL;
        }
};
class Linked_List{
    public:
        node *head;
        node *tail;
        int size;
        Linked_List(){
            head=NULL;
            tail=NULL;
            size=0;
        }
        void push_front(int d){
            node *new_head=new node(d);
            if(!head){
                tail=new_head;head=new_head;
            }else{
                new_head -> next = head;
                head ->prev = new_head;
                head= new_head;
            }
            size++;
        }
        void push_back(int d){
            node *new_tail= new node(d);
            if(!tail){
                head=new_tail;
                tail=new_tail;
            }else{
                tail->next= new_tail;
                new_tail -> prev= tail;
                tail= new_tail;
            }
            size++;
        }
        void insert(node *curr,int d){ //insert just after this node 
            node *new_node= new node(d);
            new_node->next = curr-> next;
            curr-> next = new_node;
            new_node-> prev=curr;
            if(new_node-> next){
                new_node-> next -> prev= new_node;
            }else{
                tail= new_node;
            }
            size++;
        }
        void pop_back(){
            if(!tail){
                return;
            }
            if(!(tail-> prev)){
                delete head;
                head=tail=NULL;
            }else{
                node *new_tail= tail->prev;
                new_tail->next=NULL;
                delete tail;
                tail=new_tail;
            }
            size--;
        }
        void pop_front(){
            if(!head){
                return;
            }
            if(!head->next){
                delete tail;
                head=tail=NULL;
            }else{
                node *new_head= head->next;
                new_head->prev=NULL;
                delete head;
                head= new_head;
            }
            size--;
        }
        void pop(node *curr){ //delete this curr node and update the linked list accordingly
            if(size==1){
                delete curr;
                head=tail=NULL;
            }
            if(curr->prev){
                curr->prev->next= curr->next;
            }
            if(curr->next){
                curr->next->prev = curr->prev;
            }
            if(curr==head){
                head= curr->next;
            }
            if(curr==tail){
                tail= curr->prev;
            }
            delete curr;
            size--;
        }
        void print_rec_fun(node *curr){
            if(!curr){
                return;
            }
            cout<<curr->data<<space;
            print_rec_fun(curr->next);
        }
        void print_rec(){
            print_rec_fun(head);
            cout<<endl;
        }
        void print_iteratively(){
            node *curr = head;
            while(curr){
                cout<<curr->data<<space;
                curr= curr->next;
            }
            cout<<endl;
        }
        void reverse(){
            node *curr=head;
            while(curr){
                swap(curr->next,curr->prev);
                curr=curr->prev; //coz we have already swapped in prev step so cant do curr->next
            } 
            swap(tail,head);
        }
        void reverse_ifSinglyLL(){ //assuming here our LL is singly linked 
            node *curr=head,*prev=NULL;
            while(curr){
                node *next_node= curr->next;
                curr->next=prev;
                prev=curr;
                curr=next_node;
            }
            swap(head,tail); //at end of above loop the curr is pointing towards initial tail
        }


};
int32_t main(){
    Linked_List l;
    looper(i,0,11){
        l.push_back(i);
    }
    l.print_iteratively();
    // lets try the other operations we implemented in our custom ll
    l.pop_back();
    l.print_iteratively();

    l.pop_front();
    l.print_iteratively();

    l.insert(l.head,88);
    l.print_iteratively();

    l.pop(l.head);
    l.print_iteratively();

    l.pop(l.tail);
    l.print_iteratively();

    cout<<l.size<<endl;

    l.reverse();
    l.print_iteratively();
    
    return 0;
}

// Uses of ll
// Caching, web chrome tabs(doubly ll), multiple searches on a single tab on any browser
// Undo-redo, 