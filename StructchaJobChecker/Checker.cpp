#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <vector>
#include "../lib/structcha_files/analysis_file.hpp"

using namespace std;

int main() {

    //declaring variables
    fstream binaryFile;
    fstream tempFile;
    string tp;

    //First section converts file from binary to readable text so information can be extracted.
    binaryFile.open("../TestFiles/TestAnalysis.scan",ios::in); // open the file which was written to before (ie the one in binary)
    tempFile.open("CheckingFile.txt",ios::out);
           
    while (getline(binaryFile, tp)) { // not needed as all binary is on one line I believe    
        for(size_t i = 0; i < (tp.size()/8); i++) {
            string bit_string = (tp.substr(i*8, 8));
            std::bitset<8> b(bit_string);
            unsigned char c = ( b.to_ulong());
            tempFile << c;
        }
    }

    binaryFile.close();
    tempFile.close();

    tempFile.open("CheckingFile.txt", ios::in);
    vector<string> fileLines;

    while (getline(tempFile,tp)){ //retrieves all value information from the file and saves into array
        if(tp.substr(0,2) != "//" && tp.size() != 0) {
            fileLines.push_back(tp);
        }
    }    
    
    StructchaAnalysisFile saf = setAnalysisFile(fileLines); // sets the Analysis object according to the analysis type.
    tempFile.close();

    return 0;
}
