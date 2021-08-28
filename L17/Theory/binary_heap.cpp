// it is of two types, max and min binary heap, in which we can insert an element and get max or del max or get min or del min resp
// very easily 
//Application
//-> Priority scheduling 
//-> order of which work to do by the GPU
// priority queue is same as binary heap in cpp, we will implement that only 
// we will implement s.t we can perform all three tasks in logn T.C
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
// we will implement binary min heap using a vector 
// for any node i, 2*i and 2*i+1 are its left and right children and floor(i/2) is its parent
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
class minHeap{
    vector<int> v;
    int n;
    void siftUp(int i){ // for nodes >n/2, no child of them exists actually
        while(i>1 & v[i/2]>v[i]){
            swap(v[i/2],v[i]),i/=2; //i/2 means parent of i
        }
    }
    void siftDown(int i){
        while(i<=n/2){
            int min_id=i;
            if(v[2*i]<v[min_id]){
                min_id = 2*i;
            }
            if(2*i+1<=n & v[2*i+1]<v[min_id]){
                min_id=2*i+1;
            }
            if(min_id!=i){
                swap(v[i],v[min_id]);
                i=min_id;
            }else{
                break;
            }
        }
    }
    void build(){
        for(int i=n/2;i>=1;i--){
            siftDown(i);
        }
    }
public:
    minHeap(){
        v.pb(0); // to obtain 1 bases indexing
        n=0;
    }
    minHeap(vector<int> arr){
        for(int i:arr){
            v.pb(i);
        }
        n = arr.size();
        build();
    }
    int &top(){
        return v[1];
        
    }
    void push(int num){
        v.pb(num);
        n++;
        siftUp(n);
    }
    int size(){
        return n;
    }
    void pop(){
        swap(v[1],v[n]); //root sent to last node
        v.pop_back();
        n--;
        siftDown(1);
    }
};
int32_t main(){
    minHeap m(vi{6,10,1,0});
    // m.push(5);
    // m.push(6);
    // m.push(10);
    // m.push(1);
    cout<<m.top()<<endl;
    m.pop();
    cout<<m.top()<<endl;
    m.pop();
    cout<<m.top()<<endl;
    m.pop();
    cout<<m.top()<<endl;
    return 0;
}