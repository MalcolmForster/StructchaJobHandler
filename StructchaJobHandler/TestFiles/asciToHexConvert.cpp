#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    //Declaring files to open/save to
    fstream asciFile;
    fstream hexFile;

    //Open files for either write or read
    hexFile.open("TestAnalysis.scan",ios::out); // open (or create) a file to save all the hex information into
    asciFile.open("TestFileASCII.txt", ios::in); // open a file to perform read operation using file object

    if (asciFile.is_open() && hexFile.is_open())
    { // checking whether the file is open
        string tp;
        while (getline(asciFile, tp))
        {                       // read data from file object and put it into string.
            for(size_t i = 0; i < tp.size(); i++) {
                hexFile << hex << std::setw(2) << std::setfill('0') << (unsigned)tp[i]; // convert string to hex and write into hexFile
            }
            hexFile << hex << ((unsigned)'\n'); //adds the hex for a new line into output file 
        }
        asciFile.close(); // close the read file object.
        hexFile.close(); // close to write file object.

    } else {
        cout << "Something went wrong opening the required files";
    }
}