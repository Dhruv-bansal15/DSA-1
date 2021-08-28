//https://leetcode.com/problems/lru-cache/
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
class LRUCache{
    int curr_time,cap;
    unordered_map<int,int> key_value,key_time;
public:
    LRUCache(int capacity){
        cap=capacity,curr_time=0;
    }
    int get(int key){
        auto it = key_value.find(key);
        if(it==key_value.end()){
            return -1;
        }
        key_time[key]=curr_time++;
        return key_value[key];
    }
    void put(int key,int value){
        if(key_value.count(key)){
            key_value.erase(key),key_time.erase(key);
        }
        if(key_value.size()==cap){
            int curr_key = 0,min_time=INT_MAX;
            for(auto p:key_time){
                if(p.ss<min_time){
                    min_time=p.ss,curr_key=p.ff;
                }
            }
            key_value.erase(curr_key),key_time.erase(curr_key);
        }
        key_value[key]=value,key_time[key]=curr_time++;
    }
};
// a bit faster soln is here 
class LRUCache{
    int curr_time,cap;
    map<int,int> time_key; //map stores key in sorted form, so we can directly know which key to delete whenever cap reached
    unordered_map<int,int> key_value,key_time;
public:
    LRUCache(int capacity){
        cap=capacity,curr_time=0;
    }
    int get(int key){
        auto it = key_value.find(key);
        if(it==key_value.end()){
            return -1;
        }
        time_key.erase(key_time[key]); //existing time should be deleted first
        key_time[key]=curr_time;
        time_key[curr_time]= key;
        curr_time++;
        return key_value[key];
    }
    void put(int key,int value){
        if(key_value.count(key)){
            time_key.erase(key_time[key]);
            key_value.erase(key),key_time.erase(key);
        }
        if(key_value.size()==cap){
            int curr_key = time_key.begin()->ss;
            key_value.erase(curr_key),key_time.erase(curr_key);
            time_key.erase(time_key.begin());
        }
        key_value[key]=value,key_time[key]=curr_time;
        time_key[curr_time]=key;
        curr_time++;

    }
};
int32_t main(){
    
    return 0;
}