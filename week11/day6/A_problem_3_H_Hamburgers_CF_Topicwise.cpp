#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    ll bgot,sgot,cgot,bprice,sprice,cprice;
    cin>>bgot>>sgot>>cgot>>bprice>>sprice>>cprice;
    ll money;
    cin>>money;
    ll bcnt=0,scnt=0,ccnt=0;
    for(auto x:s){
        if(x=='B') bcnt++;
        if(x=='S') scnt++;
        if(x=='C') ccnt++;
    }
    auto check=[&](ll quantity){
        ll bread=max(0LL,bcnt*quantity-bgot);
        ll sausage=max(0LL,scnt*quantity-sgot);
        ll cheese=max(0LL,ccnt*quantity-cgot);
        
        ll totalPrice=(bread*bprice)+(sausage*sprice)+(cheese*cprice);
        return totalPrice<=money;
    };
    ll l=0,r=1e15,mid,ans=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}

/*
our target is to get maximum quanitity of hamburgers. 
so binary search on answer will be based on quantity. 
using string we'll count how many bread,sausage & cheese we'll
be needed to make a hamburger. 

now suppose in binary search we passed 100 quantity in check
function. 
then we have to calculate the amount of bread,sausage & cheese 
needs to make 100 hamburgers. 
we'll multiply the bcnt(number of bread needs to make 1 hamburger)
with 100. And then from there we'll delete the number of breads
we already got. 
same operation for sausage & cheese. 
then we'll have the amounts of bread,sausage & cheese we need to
make 100 hamburgers. now we'll calculate the price for all of them.
If total price is <= the money we have, then return true.(means
we can purchase & make 100 hamburgers) and ELSE false.(means
the total price is more than what we have). 
If we find true, we'll check if we can make more hamburgers so
we'll move right. If we find false, we'll move left to find less
quantity which is possible to make. 

testcase: 
BBC
1 10 1
1 10 1
21

to make 1 hamburger: 2 bread, 1 cheese
we have 1 bread, 1 cheese
money=21

suppose quantity=5
so bread needed=(5*2)-1=9 , sausage needed=(5*0)-10=0 (negative ignore)
cheese needed=(5*1)-1=4
so total price=(9*1)=9 + (4*1)=4 = 13<21 so ans can be 5

suppose quantity=7
so bread needed=(7*2)-1=13 , sausage needed=(7*0)-10=0 (negative ignore)
cheese needed=(7*1)-1=6
so total price=(13*1)=13 + (6*1)=6 19<21 so ans can be 7

suppose quantity=8
so bread needed=(8*2)-1=15 , sausage needed=(8*0)-10=0 (negative ignore)
cheese needed=(8*1)-1=7
so total price=(15*1)=15 + (7*1)=7 22>21 so 8 hamburgers not possible. 
so final answer=7 
*/