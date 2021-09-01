// Problem Description

// Given an array of integers A. Find and return the number of subarrays whose xor values is less than B.
// NOTE: As the answer can be very large, return the answer modulo (109+7).



// Problem Constraints
// 1 <= length of the array <= 100000
// 1 <= A[i] <= 105
// 1 <= B <= 106



// Input Format
// The argument given is the integer array A
// Second argument is an integer B.



// Output Format
// Return an integer denoting the number of subarrays whose xor values is less than B.



// Example Input
// Input 1:

//  A = [8, 3, 10, 2, 6, 7, 6, 9, 3]
//  B = 3
// Input 2:

//  A = [9, 4, 3, 11]
//  B = 7


// Example Output
// Output 1:
//  5
// Output 2:

//  3


// Example Explanation
// Explanation 1:

//  Generate all the subarrays and their corresponding xor and there are only 5 such subaraays which have xor less than 3.
// Explanation 2:

//  Subarrays with xor < 7 are : [9, 4, 3, 11], [4] and [3].
//  So, the answer is 3.
 
//  Solution Approach:
//  Use trie data structure. An efficient approach will be to calculate all of the prefix xor values i.e. a[1:i] for all i. It can be verified that the xor of a subarray a[l:r] can be written as (a[1:l-1] xor a[1:r]), where a[i, j] is the xor of all the elements with index such that, i <= index <= j.

// We will store a number as binary number in trie. The left child will shows that the next bit is 0 and the right child will show the next bit is 1. If xor[i, j] represents the xor of all elements in the subarray a[i, j], then at an index i what we have is, a trie which has xor[1:1], xor[1:2]…..xor[1:i-1] already inserted. Now we somehow count how many of these (numbers in trie) are such that its xor with xor[1:i] is smaller than k. This will cover all the subarrays ending at the index i and having xor i.e. xor[j, i] <=k;
// Now, to count the numbers that are below a given node, we modify the trie and each node will also store the number of leafs in that subtree and this would be modified after each insertion.

// Time complexity: O(n*log(max)), where max is the maximum element in the array.

#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define line cout<<"----------------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
ll k;
struct node
{
    ll mark;
    node *next[4];
    node()
    {
        mark=false;
        for(ll i=0;i<3;i++) next[i]=NULL;
    }
};
node *root;
void add(string str)
{
    node *temp=root;
    ll cnt=0;
    for(ll i=0;i<str.size();i++)
    {
        ll d=str[i]-'0';
        if(temp->next[d]==NULL)
        {
            temp->next[d]=new node();
        }
        temp=temp->next[d];
        temp->mark++;
    }
}
ll check (string str,string str1)
{
    ll ans=0;
    node *temp=root;
    for(ll i=0;i<str.size();i++)
    {
        if(str[i]=='0' and str1[i]=='1')
        {
            if(temp->next[0]!=NULL) ans+=temp->next[0]->mark;
            if(temp->next[1]==NULL) return ans;
            temp=temp->next[1];
        }
        else if(str[i]=='0' and str1[i]=='0')
        {
            if(temp->next[0]!=NULL) temp=temp->next[0];
            else return ans;
        }
        else if(str[i]=='1' and str1[i]=='1')
        {
            if(temp->next[1]!=NULL) ans+=temp->next[1]->mark;
            if(temp->next[0]==NULL) return ans;
            temp=temp->next[0];
        }
        else if(str[i]=='1' and str1[i]=='0')
        {
            if(temp->next[1]==NULL) return ans;
            temp=temp->next[1];
        }
    }
    return ans;
}
void del(node* temp)
{
    for(ll i=0;i<3;i++)
    {
        if(temp->next[i]) del(temp->next[i]);
    }
    delete(temp);
}
ll ara[100009];
string str1;

int Solution::solve(vector<int> &A, int B) 
{
    
    ll t;
    str1="";
    k = B;
    ll n = A.size();
    ll m=k;
    while(m)
    {
        if(m%2==0) str1+='0';
        else str1+='1';
        m/=2;
    }
    ll maxi=-1;
    for(ll i=0;i<n;i++)
    {
        
        ara[i] = A[i];
        maxi=max(maxi,ara[i]);
        
    }
      ll log=log2(maxi)+1;
      root=new node();
      string str;
      for(ll i=0;i<log;i++) str+='0';
      for(ll i=str1.size();i<log;i++) str1+='0';
        reverse(str1.begin(),str1.end());
      add(str);
      ll sum=0;
      ll ans=0;
      for(ll i=0;i<n;i++)
      {
          str="";
          sum=sum^ara[i];
          ll d=sum;
          while(d)
          {
              if(d%2==0) str+='0';
              else str+='1';
              d>>=1;
          }
          for(ll i=str.size();i<log;i++) str+='0';
            reverse(str.begin(),str.end());
            ans+=check(str,str1);
          add(str);
      }
      if((int)log2(k)+1>log)
      {
          ans=n*(n+1)/2;
      }
      return ans%mod;
      del(root);
}
