// circular deque using array
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
class circular_deque_array{
    int *arr,st,en,sz,cap;
    public:
    circular_deque_array(int d){ //how much capacity do our deque have in one go
        cap=d;
        arr= new int[cap];
        st=0,en=-1,sz=0; //en is -1 so that when we ++ it, we can add element to start of array
    }
    void push_back(int num){
        if(sz==cap){
            cout<<"Queue Full!"<<endl;
            return;
        }
        if(sz==0){
            st=en=0;
            sz=1;
            arr[st]=num;
            return;
        }
        en = (en+1)%cap;
        arr[en]=num;
        sz++;
    }
    void push_front(int num){
        if(sz==cap){
            cout<<"Queue Full!"<<endl;
            return;
        }
        if(sz==0){
            st=en=0;
            sz=1;
            arr[st]=num;
            return;
        }
        st = (st-1 +cap)%cap;
        arr[st]=num;
        sz++;
    }
    
    int front(){
        if(sz){
            return arr[st];
        }
        cout<<"Queue Empty!"<<endl;
        return -1;
    }
    int back(){
        if(sz){
            return arr[en];
        }
        cout<<"Queue Empty!"<<endl;
        return -1;
    }
    void pop_front(){
        if(!sz){
            cout<<"Queue empty!"<<endl;
            return;
        }
        st = (st+1)%cap;
        sz--;
    }
    void pop_back(){
        if(!sz){
            cout<<"Queue empty!"<<endl;
            return;
        }
        en = (en-1+cap)%cap;
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
            pop_back();
        }
    }
};
int32_t main(){
    
    return 0;
}