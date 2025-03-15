#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=1e5+9;
int t[4*maxN];
void build(int n,int b,int e){          //O(N)
    if(b==e){
        t[n]=0;      //initially all 0 node e save hocche
        return;         
    }
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n]=t[l]+t[r];     
}
void update(int n,int b,int e,int i,int v){     //O(logN)
    if(i<b || i>e){
        return;     //"out of" segment
    }
    if(b==e){
        t[n]=v;  
        return;  //"inside" segment
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    update(l,b,mid,i,v);
    update(r,mid+1,e,i,v);
    t[n]=t[l]+t[r];
}
int query(int n,int b,int e,int i,int j){     //O(logN)
    if(e<i || b>j){   //"out of" segment
        return 0; 
    }
    if(b>=i && e<=j){   //"inside" segment
        return t[n];    
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    return query(l,b,mid,i,j) + query(r,mid+1,e,i,j);
}
void mohaimin(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v(m);
    for(int i=0;i<m;i++){
        cin>>v[i].first>>v[i].second;
    }
    int q;
    cin>>q;
    vector<int> queries(q);
    for(int i=0;i<q;i++) cin>>queries[i];

    auto check=[&](int mid){
        build(1,1,n);               //we need to build this every time
        for(int i=0;i<=mid;i++){
            update(1,1,n,queries[i],1);     //mid porjonto query update
        }
        bool flag=false;
        for(int i=0;i<m;i++){
            int left=v[i].first, right=v[i].second,lenth,one,zero;
            lenth=(right-left)+1;
            one=query(1,1,n,left,right);    
            //sum return korbe jeta total number of one
            zero=lenth-one;
            //segment length-sum hocche total number of zero
            if(one>zero){
                flag=true;
                break;
            }
        }
        return flag;
    };

    int l=0,r=q-1,mid,ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    if(ans!=-1) ans++;
    cout<<ans<<ln;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        mohaimin();
    }
}
/*
intially array er shob element 0 thakbe. Erpor segments dibe (l,r) er
m amount er. Then Q ta queries dibe jekhane index dibe & shei index ke
1 korte hobe.
Now we need to find out that how many queries are required to find atleast
1 segment beautiful (beautiful conditin: number of 1 > number of 0). 

We'll use same build,update,query function that we used for "Segment
tree for the sum" problem. The only difference is here initially all
are 0 & we'll update the index to 1. 
number of 1=segment's sum & number of 0=segment's length-segment's sum

Now we have to find out how many changes are required to make atleast
1 segment beautiful. 

so:- 
1)we'll store all segments into a pair vector. 
2)all query into a vector. 
3) start from l=0 & r=q-1 & do a binary search on answer. 
4) we'll send mid to check function. And each time we'll build the tree
   why? Otherwise previous updates will stay. Then we'll update from 0
   to mid.
5) then we'll check all segment.We'll calculate length, number of one
   which will be found by sending the query function, then calculate
   number of 0. if one>zero then return true else false. 
6) if check function return true on binary search then we'll look for 
   lesser value so r=mid-1 else we'll make l=mid+1. 
7) since we are implementing binary search on answer on a 0-based query
   vector, so if ans!=-1 then we have to increase the ans by 1 since they
   demand 1-based answer. 
*/
