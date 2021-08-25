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
        int data;
        node* next;
        node(int d): data(d),next(NULL) {} //shortcut to implement constructor function
};
class custom_stackLL{
    node *head;int sz;
    public:
    custom_stackLL() : head(NULL),sz(0) {}
    void push(int num){
        node* newhead = new node(num);
        newhead->next=head;
        head=newhead;sz++;
    }
    int top(){
        if(sz){
            return head->data;
        }
        cout<<"Stack Empty!"<<endl;
        return -1;
    }
    void pop(){
        if(!sz){
            cout<<"Stack empty!"<<endl;
            return;
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
    custom_stackLL s;
    looper(i,1,6){
        s.push(i);
    }
    s.pop();
    s.push(10);
    while(!s.empty()){
        cout<<s.top()<<space;
        s.pop();
    }
    
    return 0;
}