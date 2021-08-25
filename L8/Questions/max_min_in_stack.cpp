// we have to implement a stack where we can access max and min element in stack at
// any particular time
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
class Max_min_custom_stack{
    stack<int> s,max_s,min_s;
    public:
        void push(int num){
            s.push(num);
            min_s.empty()? min_s.push(num) : min_s.push(min(num,min_s.top()));
            max_s.empty()? max_s.push(num) : max_s.push(max(num,min_s.top()));
        }
        void pop(){
            s.pop(),min_s.pop(),max_s.pop();
        }
        int top(){
            if(s.empty()) return -1;
            return s.top();
        }
        int max_ele(){
            if(s.empty()){
                return -1;
            }
            return max_s.top();
        }
        int min_ele(){
            if(s.empty()){
                return -1;
            }
            return min_s.top(); 
        }

};
int32_t main(){
    Max_min_custom_stack s;
    looper(i,1,6){
        s.push(i);
    }
    cout<<s.max_ele()<<space<<s.min_ele()<<endl;
    s.pop();
    cout<<s.max_ele()<<space<<s.min_ele()<<endl;
    cout<<s.top()<<endl;;
    return 0;
}