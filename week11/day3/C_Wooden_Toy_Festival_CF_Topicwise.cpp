#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];

        sort(v.begin(),v.end());

        auto check=[&](int time) {
            int cnt=1,l=0;
            for(int r=0;r<n;r++){
                if((v[r]-v[l])>2*time){
                    l=r;
                    cnt++;
                }
            }
            return cnt<=3;
        };

        int l=0,r=1e9,mid,ans;
        while(l<=r) {
            mid=l+(r-l)/2;
            if (check(mid)) {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
            
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
array of input dewa thakbe. Carvers 3 jon & tara different pattern
choose kore kore multiple/single input niye kaj korte parbe. 
Kaj korar shomoy tara jodi Y pattern choose kore & tader choosed
input gula individually X hoy tahole individual input er jonno
waiting time hobe |X-Y| min. 
So now amader ei 3 jon er kaj er maximum waiting time ta ke 
minimize korte hobe. 
suppose: 
6
5 4 2 1 30 60
        sorting -->     1 2 4 5      30              60
                       |   3   |    |30|            |60|
                       abs(3-1)=2  abs(30-30)=0  abs(60-60)=0
                       abs(3-2)=1
                       abs(3-4)=1
                       abs(3-5)=2
so highest waiting time is 2 for all 3 workers. 
but how did we selected this patterns & how did we decided the
range?
we used this function to calculate it: 
int cnt = 1, l = 0;
for (int r = 0;r < n;r++){
    if((v[r]-v[l])>2*time){
        l=r;
        cnt++;
    }
}

suppose we want to make all the range & pattern based on waiting
time=1 :- 
                l,r
so sorted array: 1 2 4 5 30 60
initially l==r==0 & cnt=1;
r++ 
              l r
sorted array: 1 2 4 5 30 60
(v[r]-v[l])=(2-1)=1 <2*1

r++
              l   r
sorted array: 1 2 4 5 30 60
(v[r]-v[l])=(4-1)=3 > 2
so l=r & cnt++ so cnt=2
                 l,r
sorted array: 1 2 4 5 30 60

r++
                  l r
sorted array: 1 2 4 5 30 60
(v[r]-v[l])=(5-4)=1 <2

r++
                  l   r
sorted array: 1 2 4 5 30 60
(v[r]-v[l])=(30-4)=26 >2
so l=r & cnt++ so cnt=3
                      l,r
sorted array: 1 2 4 5 30 60

r++
                      l  r
sorted array: 1 2 4 5 30 60
(v[r]-v[l])=(60-30)=30 >2
so l=r & cnt++ so cnt=4
                         l,r
sorted array: 1 2 4 5 30 60
loop over. 
But to finish the array, it took 4 carvers so it cant be possible. 



lets try with waiting time=2 :- 
                l,r
so sorted array: 1 2 4 5 30 60
initially l==r==0 & cnt=1;
r++ 
              l r
sorted array: 1 2 4 5 30 60
(v[r]-v[l])=(2-1)=1 <2*2=4

r++
              l   r
sorted array: 1 2 4 5 30 60
(v[r]-v[l])=(4-1)=3 < 4

r++
              l     r
sorted array: 1 2 4 5 30 60
(v[r]-v[l])=(5-1)=4 <= 4

r++
              l       r
sorted array: 1 2 4 5 30 60
(v[r]-v[l])=(30-1)=29> 4
so l=r & cnt++ so cnt=2
                      l,r
sorted array: 1 2 4 5 30 60

r++
                      l  r
sorted array: 1 2 4 5 30 60
(v[r]-v[l])=(60-30)=30> 4
so l=r & cnt++ so cnt=3
                         l,r
sorted array: 1 2 4 5 30 60
loop over. 
now to maintain waiting min=2, it took 3 carvers so it is the
minimum value of maximum waiting time. 

how its a binary search on answer problem???
-> because if waiting time 2 min is enough for 3 carvers to make
all of them from the array then 3,4,5,6,7... mins waiting time
can also finish the whole array. 
from here we can see a monotonic behavior. where 
1(can't)    2(can)  3(can)  4(can)...
if 2 was the mid value then we can say if mid is acceptable then
all values>mid are also acceptable. But if mid is not acceptable
then all values<mid won't be acceptable either. 
so from here we can understand that if we use binary search on
answer we can solve this problem. 

we'll simply pass the mid as time into this check funtion: 
int cnt = 1, l = 0;
for (int r = 0;r < n;r++){
    if((v[r]-v[l])>2*time){
        l=r;
        cnt++;
    }
}
return cnt<=3;

it'll return if the carvers amount are <=3 or not. if not then
we'll shift l=mid+1, if it is then we'll save the mid value on
answer & then shift r=mid-1 for potential answer for more minimum
value of mid. 

the initial range:-
l=0 (same pattern for all then 0 waiting time)
r=10^9 (if pattern=0 then v[i]=10^9-0 == 10^9 as waiting time)

*/
