#include <iostream>
#include <fstream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
    fstream asciFile;
    fstream binaryFile;

    binaryFile.open("TestAnalysis.scan",ios::out); // open (or create) a file to save all the binary information into
    asciFile.open("TestFileASCII.txt", ios::in); // open a file to perform read operation using file object

    if (asciFile.is_open())
    { // checking whether the file is open
        string tp;
        while (getline(asciFile, tp))
        {                       // read data from file object and put it into string.
            for(size_t i = 0; i < tp.size(); i++) {
                binaryFile << bitset<8>(tp.c_str()[i]); // print the data of the string
            }            
        }
        asciFile.close(); // close the file object.
    } else {
        cout << "Something went wrong opening the required files";
    }
}