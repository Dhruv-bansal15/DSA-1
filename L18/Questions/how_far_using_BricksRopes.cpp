// https://leetcode.com/discuss/interview-question/528584/google-onsite-how-far-can-we-reach-using-rope-and-bricks 
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
vi arr;
bool check(int id,int r,int b){ // check if we can reach to this ith level
    pqmax q;
    looper(i,0,id-1){
        if(arr[i+1]>arr[i]){
            q.push(arr[i+1] - arr[i]);
        }
    }
    while ((q.size())){
        if(r){
            r--;
            q.pop();
        }else if(b>=q.top()){
            b-= q.top();
            q.pop();
        }else{
            return 0;
        }
    }
    return 1;
}
//Method 2
class Solution{
public:
    int farthest_building(vi &v,int b,int r){
        int req=0,max_ans=0;
        pqmin q;
        looper(i,1,v.size()){
            if(v[i]<=v[i-1]){
                max_ans=i;
                continue;
            }
            int curr = v[i] - v[i-1];
            q.push(curr);
            if(q.size()>r){
                req+= q.top();
                q.pop();
            }
            if(req<=b){
                max_ans=i;
            }else{
                break;
            }
        }
        return max_ans;
    }
};
int32_t main(){
    int n,b,r;cin>>n>>b>>r;
    looper(i,0,n){
        int x;cin>>x;arr.pb(x);
    }
    int left=0,right=n-1;
    int curr_ans=-1;
    while(left<right){
        int mid = (left+right)/2;
        if(check(mid,r,b)){
            curr_ans=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    if(curr_ans!=-1){
        cout<<curr_ans;
    }else{
        cout<<0<<endl;
    }
    return 0;
}