#include<bits/stdc++.h>
using namespace std;


void compare(vector<char>i1,vector<char>i2)
{
    long long int i;
    long long int n1=i1.size();
    long long int n2=i2.size();
    if(n1!=n2)
    {
        cout<<"File are not same!!";
    }
    else
    {
        for(i=0;i<n1;i++)
        {
            if(i1[i]!=i2[i])
            {
                cout<<"Files are not same";
                return;
            }
        }
    }
    cout<<"Both files are Same!!";
    
}
  
// Driver code
int main()
{
    // opening both file in read only mode
    string filename1("file.txt");
    string filename2("Decoded_file.txt");
    ifstream input_1(filename1);
    ifstream input_2(filename2);
    if (!input_1.is_open()) {
        cerr << "Could not open the file - '"
             << filename1 << "'" << endl;
        return EXIT_FAILURE;
    }
    if (!input_2.is_open()) {
        cerr << "Could not open the file - '"
             << filename2 << "'" << endl;
        return EXIT_FAILURE;
    }
    vector<char>i1;
    char byte=0;
    vector<char>i2;
    while (input_1.get(byte)) {           //storing the characters in a input file.
        i1.push_back(byte);
    }
    while (input_2.get(byte)) {           //storing the characters in a input file.
        i2.push_back(byte);
    }
    compare(i1,i2);
    
   
    return 0;
}
