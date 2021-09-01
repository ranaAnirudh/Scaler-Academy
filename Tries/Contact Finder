/*
Contact Finder
Problem Description

We want to make a custom contacts finder applications as part of our college project. The application must perform two types of operations:

Type 1: Add name B[i] ,denoted by 0 in vector A where B[i] is a string in vector B denoting a contact name. This must store B[i] as a new contact in the application.

Type 2: Find partial for B[i] ,denoted by 1 in vector A where B[i] is a string in vector B denoting a partial name to search the application for. It must count the number of contacts starting with B[i].

You have been given sequential add and find operations. You need to perform each operation in order.

And return as an array of integers, answers for each query of type 2(denoted by 1 in A) .



Problem Constraints
1 <= |A| <= 10000

1 <= |length of strings in B| <= 10



Input Format
First argument is the vector A, which denotes the type of query.

Second argument is the vector B, which denotes the string for corresponding query.



Output Format
Return an array of integers, denoting answers for each query of type 1.



Example Input
Input 1:

A = [0, 0, 1, 1]
B = ["hack", "hacker", "hac", "hak"]
Input 2:

A = [0, 1]
B = ["abcde", "abc"]


Example Output
Output 1:

 
[2, 0]
Output 2:

[1]


Example Explanation
Explanation 1:

 
We perform the following sequence of operations:
Add a contact named "hack".
Add a contact named "hacker".
Find the number of contact names beginning with "hac". There are currently two contact names in the application and both of them start with "hac", so we have 2.
Find the number of contact names beginning with "hak". There are currently two contact names in the application but neither of them start with "hak", so we get0.
Explanation 2:

 
Add "abcde"
Find words with prefix "abc". We have answer as 1.
*/

/*
Solution Approach:
Handling operations:

Add : We will simply insert the string in the trie.
We will increase the value of the variable of the nodes that are visited in the process by .

Find : We need to find the number of strings which have been inserted into the trie and have as a prefix.
We will start from the root of the trie and traverse it using the string .
The value of the variable stored in the final node ( the node where the traversal ends) is the answer to this operation.
This is because all the strings that have as prefix must have visited this node and no other string can visit this node.
*/
//Solution

struct TrieNode
{
    struct TrieNode* children[26];
    int count;
    bool end;
};
struct TrieNode* getNode()
{
    struct TrieNode* node = new TrieNode;
    int i;
    for(i=0;i<26;i++)
    {
        node->children[i]=NULL;
    }
    node->end=false;
    node->count=0;
    return node;
}

void insert(TrieNode* root,string key)
{
    int i;
    struct TrieNode* temp=root;
    int len=key.length();
    for(i=0;i<len;i++)
    {
        if(!temp->children[key[i]-'a'])
        temp->children[key[i]-'a']=getNode();
        temp=temp->children[key[i]-'a'];
        temp->count++;
    }
    temp->end=true;
}
int search(TrieNode* root,string s){
    
    TrieNode* temp=root;
    for(int i=0;i<s.length();i++){
        if(temp->children[s[i]-'a']==NULL)return 0;
        
        temp=temp->children[s[i]-'a'];
    }
    if(temp->count==0) return 0;
    return temp->count;
}
vector<int> Solution::solve(vector<int> &A, vector<string> &B) {
    struct TrieNode* root=getNode();
    vector<int>v;
    for(int i=0;i<A.size();i++){
        if(A[i]==0)insert(root,B[i]);
        else {
            if(search(root,B[i]))v.push_back(search(root,B[i]));
            else v.push_back(0);
        }
    }
    return v;  
}
