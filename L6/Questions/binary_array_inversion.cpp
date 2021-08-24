// given a binary array, u have to simply invert each element in range l to r for each query
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
int32_t main(){
    int n;cin>>n;
    vi arr;
    looper(i,0,n){
        int x;cin>>x;arr.pb(x);
    }   
    int q;cin>>q;
    vi operational_arr(n+1); //0 based indexing assumed in the ques
    while(q--){
        int l,r;cin>>l>>r;
        operational_arr[l]++;operational_arr[r+1]--;
    }
    looper(i,1,n){
        operational_arr[i]+= operational_arr[i-1];
    }
    looper(i,0,n){
        if(operational_arr[i]%2==0){
            cout<<arr[i]<<space;
        }else{
            cout<<1 - arr[i]<<space;
        }
    }
    cout<<endl;
    return 0;
}

//NOTE:
// u can also implement this using XOR
// u just have to flip l and r+1th bit in operational array and 
// then take prefix XOR, then indices where there is 1 needs to be flipped in 
// the final array