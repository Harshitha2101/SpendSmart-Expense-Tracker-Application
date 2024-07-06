#include<bits/stdc++.h>
using namespace std;
unordered_map<string ,char>mp; 
char code[128][128] = {{'\0'}};
ofstream Decoded_file("Decoded_file.txt");
void decode(string temp1);

int main()
{
    ifstream Myfile("Huffman_Codes.txt");           //opening the huffman_code file
    string temp;
    string temp1; 
    while(getline(Myfile,temp))
    { 
        temp1=temp;                                    //reading the file line by line
        mp[temp1.substr(1,temp1.size()-1)]=temp1[0];   //storing the codes and characters in  a map
        //cout<<temp1.substr(1,temp1.size()-1)<<": "; 
        //cout<<mp[temp1.substr(1,temp1.size()-1)]<<endl;
    }
    
    ifstream File("Encoded_file.txt");        //opening the encoded file.
    temp1="";
    while(getline(File,temp))
    {
        temp1+=temp;                            //storing the encoded file into a string.
    }
    //cout<<"Encoded_text: "<<temp1<<endl;
    decode(temp1);                //calling the decode function
    Myfile.close();
    return 0;
}
/*void decode1(FILE *fp_out)
{
    struct MinHeapNode *n = head;
    int i = 0;
    int l = strlen(stFinal);

    while (stFinal[i] && i < l)
    {
        if (stFinal[i++] == '0' && n->left)
        {
            n = n->left;
        }
        else if (n->right)
            n = n->right;

        if (n != NULL && n->data != '$')
            putchar(n->data), n = head;
            fputc(n->data,fp_out);  
        
        if (n == NULL)
        {
            n = head;
        }
    }

    putchar('\n');
    if (head != n)
        printf("garbage input\n");
}*/
void decode(string temp1)
{
    long long int i=0;
    long long int n=temp1.size();
    long long int j;
    string temp="";
    
    while(i<n)                //traversing the encoded string till last
    {
        temp+=temp1[i];          //adding the character at every iteration
        unordered_map<string,char>::iterator it ;
        it=mp.find(temp);
        //cout<<"Median: "<<temp<<endl;
        if(it!=mp.end())          //if the code found in the map and the codes are prefix free then it matches with a unique character.
        {
            //cout<<mp[temp];
            Decoded_file<<mp[temp];     //writing to the decoding file.
            temp="";
            
        }
        
        i++;
    }   
    
}
