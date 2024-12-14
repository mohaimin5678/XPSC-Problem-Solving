#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n;
    string s;
    cin>>n>>s;
    int need=0;
    int matchPairs=0;
    int i=0,j=n-1;
    while(i<j){
        if(s[i]!=s[j]) need++;
        else matchPairs+=2;
        i++;
        j--;
    }
    int odd=0;
    if(n%2==1) odd=1;

    string t;
    for(int k=0;k<=n;k++){
        if(k<need) t.push_back('0');
        else if(k==need) t.push_back('1');
        else{
            int rem=k;
            rem-=need;
            if(rem==0){
                t.push_back('1');
                continue;
            }
            if(rem%2==1){
                rem-=odd;
                if(rem==0){
                    t.push_back('1');
                    continue;
                }
            }
            if(matchPairs>=rem && rem%2==0) t.push_back('1');
            else t.push_back('0');
        }
    }
    cout<<t<<endl;
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
    return 0;
}

/*
explanation with testcase=

testcase: 
9
 1  0  0  1 0   0  0  1  1 
 mp nc mp   od nc  mp   mp

here mp=matching pairs , nc=need changes & od means odd exist
they want to know that using 0 to n(9) numbers of 1, can we
make the given string palindrome? if we can, the print t[i]=1
else t[i]=0;
so intially we need to check atleast how many changes can make
this string a palindrome. Using 2 pointers formula we will count
them. Also we'll count how many matching pairs exists & if there
is any odd number exists who has no pair. 

now i=0 means using 0 amounts of 1. (need=2,matched=4,odd=1)
i<need so we can't cause we need atleast 2 amount of 1 to make
it palindrome. 
so t=[0 ]

now i=1 means using 1 amount of 1. (need=2,matched=4,odd=1)
i<need again so t=[0 0 ]

now i=2 means using 2 amounts of 1. (need=2,matched=4,odd=1)
since i==need so we can make it palindrome. 
so t=[0 0 1 ]

now i=3 means using 3 amounts of 1. (need=2,matched=4,odd=1)
since i>need so lets calculate remaining after fulfilling the 
need. so rem=i-need=3-2=1. since rem is odd so we'll check
if we have odd=1 then we can subtract it from rem. for this 
testcase we have. so rem=rem-odd=1-1=0 since we can distribute it
into needed position & on odd position(changing odd position's 
index won't change the palindrome). so we can make it palindrome. 
so t=[0 0 1 1 ]

now i=4 means using 4 amounts of 1. (need=2,matched=4,odd=1)
since i>need so lets calculate remaining after fulfilling the 
need. so rem=i-need=4-2=2. now rem%2==0 so lets check if its 
lower or equal to matched pair. In this testcase yes, so we can
make the palindrome. 
so t=[0 0 1 1 1]
how? 
 1  0  0  1 0   0  0  1  1 
 1  1  0  0 0   1  0  0  1
--------------------------- XOR
 0  1  0  1 0   1  0  1  0 which is palindrome
here we first filled up the change needed index & then put 2 ones
on matched pairs. the sign changed after the XOR but it provided
a palindrome string. 

now i=5 means using 5 amounts of 1. (need=2,matched=4,odd=1)
since i>need so lets calculate remaining after fulfilling the 
need. so rem=i-need=5-2=3. since rem is odd so we can subtract
odd=1 from rem. so rem=rem-odd=3-1=2 since we can distribute it
into needed position & on odd position(changing odd position's 
index won't change the palindrome). now rem%2==0 so lets check 
if its lower or equal to matched pair. In this testcase yes, so 
we can make the palindrome. 
so t=[0 0 1 1 1 1 ]
how? 
 1  0  0  1 0   0  0  1  1 
 1  1  0  0 1   1  0  0  1
--------------------------- XOR
 0  1  0  1 1   1  0  1  0 which is palindrome
here we first filled up the change needed index & then put 1 one
on odd position with no pair, then 2 ones on matched pairs. the 
sign changed after the XOR but it provided a palindrome string.

now i=6 means using 6 amounts of 1. (need=2,matched=4,odd=1)
since i>need so lets calculate remaining after fulfilling the 
need. so rem=i-need=6-2=4. now rem%2==0 so lets check if its 
lower or equal to matched pair. In this testcase yes, so we can
make the palindrome. 
so t=[0 0 1 1 1 1 1 ]
how? 
 1  0  0  1 0   0  0  1  1 
 1  1  1  0 0   1  1  0  1
--------------------------- XOR
 0  1  1  1 0   1  1  1  0 which is palindrome

now i=7 means using 7 amounts of 1. (need=2,matched=4,odd=1)
since i>need so lets calculate remaining after fulfilling the 
need. so rem=i-need=7-2=5. since rem is odd so we can subtract
odd=1 from rem. so rem=rem-odd=5-1=4 since we can distribute it
into needed position & on odd position(changing odd position's 
index won't change the palindrome). now rem%2==0 so lets check 
if its lower or equal to matched pair. In this testcase yes, so 
we can make the palindrome. 
so t=[0 0 1 1 1 1 1 1 ]
how? 
 1  0  0  1 0   0  0  1  1 
 1  1  1  0 1   1  1  0  1
--------------------------- XOR
 0  1  1  1 1   1  1  1  0 which is palindrome

now i=8 means using 8 amounts of 1. (need=2,matched=4,odd=1)
since i>need so lets calculate remaining after fulfilling the 
need. so rem=i-need=8-2=6. now rem%2==0 so lets check if its 
lower or equal to matched pair. In this testcase NO, so we can't
make the palindrome. 
so t=[0 0 1 1 1 1 1 1 0 ]
how? 
 1  0  0  1  0  0  0   1  1 
 1  1  1  [] 0  1  1  []  1
--------------------------- XOR
 0  1  1  [] 0  1  1  []  0 we can put 2 ones on those 2 places
 0  1  1   0 0  1  1   0  0 so after putting one on those places
the XOR result is not a palindrome. 

now i=9 means using 9 amounts of 1. (need=2,matched=4,odd=1)
since i>need so lets calculate remaining after fulfilling the 
need. so rem=i-need=9-2=7. since rem is odd so we can subtract
odd=1 from rem. so rem=rem-odd=7-1=6 since we can distribute it
into needed position & on odd position(changing odd position's 
index won't change the palindrome). now rem%2==0 so lets check 
if its lower or equal to matched pair. In this testcase NO, so 
we can't make the palindrome. 
so t=[0 0 1 1 1 1 1 1 0 0]
how? 
 1  0  0  1  0  0  0  1  1 
 1  1  1  1  1  1  1  1  1
--------------------------- XOR
 0  1  1  0  1  1  1  0  0  so after putting one on those places
the XOR result is not a palindrome.

so t=0011111100
*/