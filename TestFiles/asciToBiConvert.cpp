#include <iostream>
#include <fstream>
#include <bitset>
#include <string>

using namespace std;

int main()
{
    //Declaring files to open/save to
    fstream asciFile;
    fstream binaryFile;

    //Open files for either write or read
    binaryFile.open("TestAnalysis.scan",ios::out); // open (or create) a file to save all the binary information into
    asciFile.open("TestFileASCII.txt", ios::in); // open a file to perform read operation using file object

    if (asciFile.is_open() && binaryFile.is_open())
    { // checking whether the file is open
        string tp;
        while (getline(asciFile, tp))
        {                       // read data from file object and put it into string.
            for(size_t i = 0; i < tp.size(); i++) {
                binaryFile << bitset<8>(tp.c_str()[i]); // convert string to bytes and write into binaryFile
            }
            binaryFile << bitset<8>('\n'); //adds the binary for a new line into output file 
        }
        asciFile.close(); // close the read file object.
        binaryFile.close(); // close to write file object.

        // Below is code for testing if file written correctly and converting backing to ascii text

        // binaryFile.open("TestAnalysis.scan",ios::in); // open the file which was written to before (ie the one in binary)

        // while (getline(binaryFile, tp)) { // not needed as all binary is on one line I believe
        //     for(size_t i = 0; i < (tp.size()/8); i++) {
        //         string bit_string = (tp.substr(i*8, 8));
        //         std::bitset<8> b(bit_string);
        //         unsigned char c = ( b.to_ulong());
        //         cout << c;
        //     }            
        // }
        // binaryFile.close();

    } else {
        cout << "Something went wrong opening the required files";
    }

    return 0;
}