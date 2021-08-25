// FIFO first in first out 
// first come first server 
// applications->
// single core processors: they do tasks in the queue , its just that time allocayed to each task at one time is very less
// ATM queue
// Preamptive round robing (sort of advance concept, leave it for later)
// Flash sales of flipcart
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
// lets implement using Singly linked LL
class node{
    public:
        int data;
        node* next;
        node(int d): data(d),next(NULL) {} //shortcut to implement constructor function
};
class custom_queueLL{
    node *head,*tail;int sz;
    public:
    custom_queueLL() : head(NULL),sz(0),tail(NULL) {}
    void push(int num){
        node* newtail = new node(num);
        if(!sz){
            head=tail=newtail;
        }else{
            tail->next=newtail;
            tail=newtail;
        }
        sz++;
    }
    int front(){
        if(sz){
            return head->data;
        }
        cout<<"Queue Empty!"<<endl;
        return -1;
    }
    int back(){
        if(sz){
            return tail->data;
        }
        cout<<"Queue Empty!"<<endl;
        return -1;
    }
    void pop(){
        if(!sz){
            cout<<"Queue empty!"<<endl;
            return;
        }
        if(sz==1){
            tail=NULL;
        }
        node *newhead= head->next;
        delete head;
        head= newhead;
        sz--;
    }
    int size(){
        return sz;
    }
    bool empty(){
        return (sz==0);
    }
    void clear(){
        while(sz){
            pop();
        }
    }
};
int32_t main(){
    custom_queueLL q;
    looper(i,1,6){
        q.push(i);
    }
    cout<<q.size()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.clear();
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    return 0;
}