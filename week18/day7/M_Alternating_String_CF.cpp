#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2==0){
        map<char,int> even,odd;
        for(int i=0;i<n;i++){
            if(i%2==0){
                odd[s[i]]++;
            }
            else even[s[i]]++;
        }
        int mxOdd=INT_MIN,mxEven=INT_MIN;
        for(auto [x,y]:odd){
            mxOdd=max(mxOdd,y);
        }
        for(auto [x,y]:even){
            mxEven=max(mxEven,y);
        }
        cout<<n-mxEven-mxOdd<<ln;
        return;
    }
    vector<int> beforeOdd(26),beforeEven(26);
    vector<int> afterOdd(26),afterEven(26);
    for(int i=0;i<n;i++){
        int num=s[i]-'a';
        //adding all char to after frequency vector
        if(i%2==0){
            afterOdd[num]++;
        }
        else afterEven[num]++;
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        int num=s[i]-'a';
        //removing the character from after vector
        if(i%2==0){
            afterOdd[num]--;
        }
        else afterEven[num]--;

        int mxOdd=0,mxEven=0;
        for(int c=0;c<26;c++){
            //now checking without the removing character, which char
            //got the max odd frequency 
            int cnt=beforeOdd[c]+afterEven[c];
            mxOdd=max(cnt,mxOdd);
        }
        for(int c=0;c<26;c++){
            //now checking without the removing character, which char
            //got the max even frequency
            int cnt=beforeEven[c]+afterOdd[c];
            mxEven=max(cnt,mxEven);
        }
        //so we are keeping max odd-even frequency so operations needed
        //are the number without max odd-even frequency & we'll check
        //for the lowest possible value. 
        ans=min(ans,n-mxOdd-mxEven);

        //after doing all the calculation we'll add the removing char
        //to before vector so that we can use it to the next calculation. 
        if(i%2==0){
            beforeOdd[num]++;
        }
        else beforeEven[num]++;
    }
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
tough enough to watch 2 solution videos. 
so N==even is very simple just check the frequency & remove the highest
odd character frequency & even character frequency from N. Since we're
doing 0-based indexing so Im keeping odd as even & even as odd cause 
0-based are minusing 1 position from their original position. Means which
is meant to be first index (odd) is now becoming 0th index(even) so if
i get i%2==0 which means its even but i'll count them as odd & vice-versa. 

Now challenge is N==odd, then we must have to delete 1 character from the
string to make the string even. So not only we need to find which even & 
odd character has the max frequency but also which character we need to
delete to get the minimum output. 
Now we know that if we remove a character then string length will be
changed. Means after removing the character, the characters that were 
on odd position, will now be on even position and the characters that
were on even position will now be on odd position. 
so what we did is we took before-after odd vector, before-after even
vector of size 26(all alphabet). 
First we'll put all character from the string to afterOdd & afterEven 
frequency vector. 
Then we'll loop through the string & remove the s[i] from after vector,
removing the character makes afterEven as odd positions & afterOdd as
even positions. So we'll count mxOdd where we'll loop through each alphabet
and check which alphabet has highest beforeOdd+afterEven frequency. 
Also we'll count mxEven where we'll loop through each alphabet and check
which alphabet has highest beforeEven+afterOdd frequency. 
then we'll check if the N-mxOdd-mxEven is minimum then ans, if it is 
then it is the new updated answer. 
after doing all the calculation for the removing character, we'll then
add it to the beforeOdd vector or beforeEven vector based on their index
frequency. So that next time we can use this character's frequency to
calculate next character's answer. 
*/
