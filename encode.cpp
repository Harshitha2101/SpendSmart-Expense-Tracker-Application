#include<bits/stdc++.h>
using namespace std;
unordered_map<char,long long int>f;                    //for calculating the frequencies of characters in input file
unordered_map<char,string>mp;                          //used for encoding part
ofstream Code_file("Huffman_Codes.txt");               
ofstream Encoded_file("Encoded_file.txt");
vector<char> input;                                   //store the characters of input file in a vector
void show_codes(struct huffmanNode * root,string s);
void create_codes();
void encrypt();
void calculate_freq();
void Make_Code_File(struct huffmanNode * root,string s);
struct huffmanNode{            //struct of the node
    char val;
    long long int freq;
    struct huffmanNode * left;
    struct huffmanNode* right;
};


struct fun1 {                                  //function used for the priority queue such that the nodes ordered in non-decreasing of the frequency
 
    bool operator()(struct huffmanNode* l,struct  huffmanNode* r)
 
    {
        return (l->freq>r->freq);
    }
};



int main()
{
    
    string filename("file.txt");        //input file
    
    char byte = 0;
    long long int i;
    ifstream input_file(filename);
    if (!input_file.is_open()) {         //input file opening error handling
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (input_file.get(byte)) {           //storing the characters in a input file.
        input.push_back(byte);
    }
    /*for(long long int i=0;i<input.size();i++)
    {
        cout<<input[i]<<" ";
    }*/
    cout << endl;
    input_file.close();                        //closing the input file
    calculate_freq();                           //calculating the frequencies of the characters
    /*cout<<"Frequency of characters in the file:\n";
    for(auto x: f)
    {
        cout<<x.first<<" : "<<x.second<<endl;
    }*/
    
    create_codes();                              //function call for making the huffman codes.
    
    encrypt();                                   //encoding the input file
    Code_file.close();                           //closing the used files
    Encoded_file.close();
    
    return EXIT_SUCCESS;    
}
void encrypt()                                   //function to encrypt the input file using a map of the char and respecctive huffman code
{
    long long int i;
    
    for(i=0;i<input.size();i++)
    {
        Encoded_file<<mp[input[i]];
    }
   
 
}
/*void traverse(huffmanNode* r, string str,int flg) {
    if (flg&&r->left == NULL && r->right == NULL) {
        r->val = str;
        return;
    }

    traverse(r->left, str + '0',flg);
    traverse(r->right, str + '1',flg);
}*/
void show_codes(struct huffmanNode * root,string s)   //function to show the huffman codes
{
    if(!root)
    {
        return;
    }
    if(root->val!='$')
    {
        cout<<root->val<<": "<<s<<"\n";
        
    }
    if(root->val=='$' && root->right==NULL && root->left==NULL)
    {
         cout<< root->val << ": " << s << "\n";
        
    }
 
    show_codes(root->left, s + "0");
    show_codes(root->right, s + "1");
}
void calculate_freq()            //function to calculate the frequency of the characters.
{
    long long int i;
    long long int n=input.size();
    for(i=0;i<n;i++)
    {
        
        f[input[i]]++;
        
    }

}
void Make_Code_File(struct huffmanNode * root,string s)         //writing to the encoding file from the huffman trie.
{
    if(!root)
    {
        return;
    }
    if(root->val!='$')
    {
        Code_file<<root->val<<s<<"\n";
        mp[root->val]=s;
    }
    if(root->val=='$' && root->right==NULL && root->left==NULL)
    {
         Code_file<< root->val<< s << "\n";
         mp[root->val]=s;
    }
 
   Make_Code_File(root->left, s + "0");
   Make_Code_File(root->right, s + "1");
}
void create_codes()
{
    priority_queue<struct huffmanNode*, vector<struct huffmanNode*> ,fun1> heap;         //to keep the nodes in order with the non-decreasing frequencies.
  
    long long int i;
    for(auto x: f)           //simply pushing the nodes into the heap
    {
        struct huffmanNode* temp=new huffmanNode();
        temp->val=x.first;
        temp->freq=x.second;
        temp->left=NULL;
        temp->right=NULL;
        heap.push(temp);

    }
    while(heap.size()!=1)
    {
        struct huffmanNode* l=heap.top();        //selecting the least two frequencies node from the heap and combine them
        heap.pop();
        //cout<<"Nodes used in combining this time:\n";
        //cout<<l->val<<" : "<<l->freq<<endl;
        struct huffmanNode* r=heap.top();
        heap.pop();
        //cout<<r->val<<" : "<<r->freq<<endl<<endl;
        struct huffmanNode* parent=new huffmanNode();
        parent->val='$';                    //combining
        parent->freq=l->freq + r->freq;
        parent->left=l;
        parent->right=r;
        heap.push(parent);
    }
    //cout<<"Huffman Codes for characters:\n";
    //show_codes(heap.top(),"");
    Make_Code_File(heap.top(),"");
}
