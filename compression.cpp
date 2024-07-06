#include<bits/stdc++.h>
using namespace std;


int main()
{
    string filename("file.txt");
    char byte = 0;
    long long int i;
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    long long int count=0;
    while (input_file.get(byte)) {             //calculating the size of the input file.
        count++;
    }
    long long int input_size=8*count;

    string file("Encoded_file.txt");
    char c=0;
    ifstream f1(file);
    if(!f1.is_open())
    {
        cerr<<"Could not open the file - '"<<file<<"'"<<endl;
        return EXIT_FAILURE;
    }
    count=0;
    while (f1.get(byte)) {                    //calculating the size of the encoded file.
        count++;
    }
    long long int out_size1=count;
    ifstream Myfile("Huffman_Codes.txt");
    string temp;
    string temp1;
    long long int no_c=0;
    count=0;
    while(getline(Myfile,temp))
    {
        temp1=temp;
        no_c++;
        count+=temp1.size()-1;                //calculating the size of the huffmancode file
        
        
    }
    long long int huffman_code_file_size=no_c*8 + count;
    long long int total_output_size=huffman_code_file_size+ out_size1;
    long long int compression=input_size -total_output_size;
    //cout<<compression<<endl;
    float  comp_precentage= (compression/(float)input_size)*(100.0);                    //total compression
    cout<<"Compression percent: "<<comp_precentage<<"%";
  
}
