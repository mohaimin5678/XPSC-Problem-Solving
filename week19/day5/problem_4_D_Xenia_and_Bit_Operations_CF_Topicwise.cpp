#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=(1<<17)+9;
int a[maxN],t[4*maxN];      //t is for tree

int merge(int ans_l, int ans_r,int len){
    //koto number bit on, odd number bit on hole odd, even bit hole even
    int pw=__lg(len);       
    if(pw & 1){     //odd checking
        return (ans_r | ans_l);       //odd tai OR operation
    }
    else{
        return (ans_r ^ ans_l);       //even tai XOR operation
    }
}

void build(int n,int b,int e){          //O(N)
    if(b==e){
        t[n]=a[b];  //a[e] o dite parbo since index same e. oi index
        return;     //er value tai node e save hocche 
    }
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n]=merge(t[l],t[r],e-b+1);
    //backtrack kore ashar por tar 2 child er value er OR/XOR result
    // e hobe n node er value
}

void update(int n,int b,int e,int i,int v){     //O(logN)
    if(i<b || i>e){   //i range er baire so niche ar jawar dorkar nai
        return;     //"out of" segment
    }
    if(b==e){
        t[n]=v;  //particular index e chole ashchi so node update korbo
        return;     //"inside" segment eta
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    update(l,b,mid,i,v);
    update(r,mid+1,e,i,v);
    t[n]=merge(t[l],t[r],e-b+1);
    //backtrack kore ashar por tar 2 child er value er OR/XOR result
    // e hobe n node er value
}

void mohaimin(){
    int n,m;
    cin>>n>>m;
    n=(1<<n);   //n jehetu power so 2^n assign kore dilam
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(m--){
        int idx,v;
        cin>>idx>>v;
        update(1,1,n,idx,v);
        cout<<t[1]<<ln;             
        //update er por backtrack kore ashar shomoy t[n] er shob value 
        //update er upor based hoye change hoye jabe
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while(t--){
        mohaimin();
    }
}
