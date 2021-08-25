// doubly ended queue
#include <iostream>
#include <cstdio>
#include <stack>
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
class custom_Deque_LL{
    public:
        node *head;
        node *tail;
        int sz;
        custom_Deque_LL(){
            head=NULL;
            tail=NULL;
            sz=0;
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
            sz++;
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
            sz++;
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
            sz--;
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
            sz--;
        }
        int size(){
            return sz;
        }
        int front(){
            if(!sz){
                return -1;
            }
            return head->data;
        }
        int back(){
            if(!sz){
                return -1;
            }
            return tail->data;
        }
        void clear(){
            while(sz){
                pop_back();
            }
        }
        bool empty(){
            return (sz==0);
        }
};
int32_t main(){
    custom_Deque_LL d;
    looper(i,1,6){
        d.push_back(i);
    }
    d.push_front(10);
    cout<<d.front()<<space<<d.back()<<endl;
    d.pop_back();
    cout<<d.front()<<space<<d.back()<<endl;
    cout<<d.size()<<endl;
    cout<<d.empty()<<endl;
    d.clear();
    cout<<d.front()<<space<<d.back()<<endl;

    return 0;
}

