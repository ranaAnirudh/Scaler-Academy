// Auto Complete
// Problem Description

// There is a dictionary A of N words and ith word has a unique weight Wi.

// An another string array B of size M contains the prefixes. For every prefix B[i], output atmost 5 words from the dictionary A which start with same prefix.

// Output the words in decreasing order of their weight.

// NOTE: If there is no word which start with the given prefix output -1.



// Problem Constraints
// 1 <= T <= 5

// 1 <= N <= 20000
// 1 <= M <= 10000

// 1 <= Wi <= 106

// 1 <= length of any string either in A or B <= 30



// Input Format
// First line is an integer T denoting the number of test cases.
// For each test case,

// First line denotes two space seperated integer N and M.
// Second line denotes N space seperated strings denoting the words in dictionary.
// Third line denotes N space seperated integers denoting the weight of each word in the dictionary.
// Fourth line denotes M space seperated integers denoting the prefixes.


// Output Format
// For every prefix B[i], print the space seperated output on a new line.

// NOTE: After every output there should be a space.



// Example Input
// Input 1:

//  1
//  6 3
//  abcd aecd abaa abef acdcc acbcc
//  2 1 3 4 6 5
//  ab abc a
// Input 2:

//  1
//  5 3
//  aaaa aacd abaa abaa aadcc
//  3 4 1 2 6 
//  aa aba abc


// Example Output
// Output 1:

//  abef abaa abcd 
//  abcd 
//  acdcc acbcc abef abaa abcd 
// Output 2:

//  aadcc aacd aaaa 
//  abaa abaa 
//  -1 
 
//  Explanation 1
//  For the prefix "ab" 3 words in the dictionary have same prefix: ("abcd" : 2, "abaa" : 3, "abef" : 4). Ouput them in decreasing order of weight.
//  For the prefix "abc" only 1 word in the dictionary have same prefix: ("abcd" : 2).
//  For the prefix "a" all 6 words in the dictionary have same prefix: ("abcd" : 2, "aecd" : 1, "abaa" : 3, "abef" : 4, "acdcc" : 6, "acbcc" : 5).
//  Since we can output atmost 5 words. Output top 5 weighted words in decreasing order of weight.
 
//  Explanation 2
//  For the prefix "aa" 3 words in the dictionary have same prefix: ("aaaa" : 3, "aacd" : 4, "aadcc" : 6). Ouput them in decreasing order of weight.
//  For the prefix "aba" 2 words in the dictionary have same prefix: ("abaa" : 1, "abaa" : 2).
//  For the prefix "abc" there is no word in the dictionary which have same prefix. So print -1.
 
//  Solution Approach
//  Create a prefix Trie, but the Node of a Trie will also contain contain an array that will denote the answer for each prefix B[i].

// How?

// Sort the given dictionary in decreasing order of its weight. Now insert the word in the Trie and update the answer array if its size is less than 5 (Since we need to output atmost 5 words).

// For each query, search for the prefix. If no word exists in the trie with the given prefix output -1.

// Else, the answer array at the end of prefix will be the answer.

// Print the answer in the given format.


Solution
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
  TrieNode *children[26];
  vector<int>ind;
};
struct TrieNode *getNode(){
   TrieNode *node=new TrieNode;
   for(int i=0;i<26;i++)node->children[i]=NULL;
   node->ind.clear();
   return node;
}
void insert(TrieNode *root,string s,int index){
    TrieNode* temp=root;
    for(int i=0;i<s.size();i++){
        if(temp->children[s[i]-'a']==NULL)
            temp->children[s[i]-'a']=getNode();
        temp->ind.push_back(index);
        temp=temp->children[s[i]-'a'];
    }
}
void search(TrieNode *root, string s,vector<string>&v){
    TrieNode* temp=root;
    for(int i=0;i<s.size();i++){
         if(temp->children[s[i]-'a']==NULL){
             cout<<-1;
             return;
         }
          temp=temp->children[s[i]-'a'];
    }
    int a=0;
    for(int i=0;i<temp->ind.size();i++){
        if(a==5)break;
        cout<<v[temp->ind[i]]<<" ";
        a++;
    }
    return;
}
int main()  {
    int t;cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string>v(n);//strings
        for(int i=0;i<n;i++)cin>>v[i];
        vector<int>w(n);//weight
        for(int i=0;i<n;i++)cin>>w[i];
        vector<string>x(m);//query
        for(int i=0;i<m;i++)cin>>x[i];
        // sort
        priority_queue<pair<int,string>>p;
        for(int i=0;i<n;i++)
            p.push({w[i],v[i]});
        v.clear();
        // cout<<v.size()<<endl;
        while(p.size()){
            // cout<<p.top().first;
            v.push_back(p.top().second);
            p.pop();
        }
        // cout<<v.size();
        
        
        TrieNode* root=new TrieNode;
        for(int i=0;i<n;i++)insert(root,v[i],i);
        //search query
        for(int i=0;i<m;i++){
            search(root,x[i],v);
            cout<<endl;
        }
    }
    
    return 0;
}
