// u can use LL or vectors to implement stacks . both have its own benefits and disadvantage 
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
// using vectors makes our task more easier well
class custom_stack{
    int arr[1000],sz=0;
    public:
        void push(int x){
            if(sz==1000){
                cout<<"Stack Full!"<<endl;
                return;
            }
            arr[sz]=x;sz++;
        }
        void pop(){
            if(sz==0){
                cout<<"Stack Empty!"<<endl;
                return;
            }
            sz--;
        }
        bool empty(){
            return (sz==0); 
        }
        int top(){
            if(sz==0){
                cout<<"Stack Empty!"<<endl;
                return;
            }
            return arr[sz-1];
        }
        int size(){
            return sz;
        }
        void clear(){
            sz=0;
        }
};
class Stack_using_vector{
    vi arr;
    public:
        void push(int num){
            arr.pb(num);
        }
        void pop(){
            if(arr.size()==0){
                return;
            }
            arr.pop_back();
        }
        int top(){
            if(arr.size()==0){
                return -1;
            }
            return arr.back();
        }
        bool empty(){
            return (arr.empty());
        }
        void clear(){
            arr.clear();
        }
        int size(){
            return arr.size();
        }
};
int32_t main(){

    return 0;
}
// stacks are used in applications like:
// Undo
// Undo and redo but we have to use two stacks for that 
// Expression evaluation (3 + 4*5)*5(5+1) 
// Code execution (basically call stack we use in reccursion)
// if we want to implement using LL then we have to push
// and pop at head is a better choice