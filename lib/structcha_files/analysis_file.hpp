#include <fstream>
#include <iostream>
#include <variant>
#include <string.h>
#include "analysis_test.hpp"

using namespace std;

/*
The StructchaAnalysisFile Class is meant to check if the data is correct for Structcha Analysis to be performed on it. It reads
all data in the file to see if the file is corrupted or incorrect and returns either the specified class requested to Checker.cpp
or an error message to help with debugging of the file. The files taken in a meant to be of the .scan file type via Checker.cpp
*/

class StructchaAnalysisFile
{
public:
    string JobName = "";
    string Company = "";
    string User = "";
    string Type = "";
    int number;
    int array1[5];
    int array2[5];

    int errorNum = 0; // initiate an error code

    // Finds and extracts information in the HEADER section of the .scan file first
    /*
        TODO in StructchaAnalysisFile class:
        1.  Change to find locations of all four main strings in the analysisFile string vector, these being header section open,
            header section close, data section open and close (for example "[[StructchaAnalysis<<HEADER]]")
        2.  Make method to read both HEADER and DATA information 
    */
    StructchaAnalysisFile(std::vector<string> analysisFile)
    {
        // will deal with error messages later string errorMessage = "No errors found"; // initiate and error message
        

        // ---Draft error numbers for errorNum below for reference
        // 0 = no error;
        // 1 = error with finding file HEADER section start, correct string not the first element of array
        // 2 = error with finding end of HEADER section
        // 3 = error with finding start of DATA section
        // 4 = error with finding end of DATA section
        // 5 = problem with header information (missing a header variable)
        // 6 = problem with data information (missing/incorrect data for the requested analysisFile Type)

        if (analysisFile[0].compare("[[StructchaAnalysis<<HEADER]]") == 0)
        {
            string s = "";
            int i = 1;
            int dataLineCount = analysisFile.size();
            while (analysisFile[i].compare("[[StructchaAnalysis>>HEADER]]") != 0 && i < dataLineCount && errorNum == 0)
            {
                s = analysisFile[i];
                setHeaderParameter(s);
                i++;
            }
            if (i >= dataLineCount && errorNum == 0)
            {
                //if no header close string found set error number
                errorNum = 2;
            }
            else if (errorNum == 0)
            {
                i++;
                // Then continues into the data section of the .scan file and extracts relevant information
                if (analysisFile[i].compare("[[StructchaAnalysis<<DATA]]") == 0)
                {
                    vector<string> dataVector;
                    i++;
                    while (analysisFile[i].compare("[[StructchaAnalysis>>DATA]]") != 0 && i < dataLineCount)
                    {
                        s = analysisFile[i];
                        dataVector.push_back(s);
                        //cout << "DL: " << s << endl;
                        i++;
                    }
                    if(analysisFile[dataLineCount-1].compare("[[StructchaAnalysis>>DATA]]") != 0) {
                        errorNum = 4;
                    }
                    setDataInfo(dataVector);
                }
                else
                {
                    // if data open not found in next vector element, set error number
                    errorNum = 3;
                }
            }
        }
        else
        {
            errorNum = 1;
        }
        cout << "Error number : " << errorNum << endl;
    }

    //Set this classes parameters based on information received in the file header
    void setHeaderParameter(string rawHeaderLine)
    {
        //string test = rawHeaderLine.substr(0, 7);
        if (rawHeaderLine.substr(0, 7) == "[NAME]:")
        {
            JobName = rawHeaderLine.substr(7);
        }
        else if (rawHeaderLine.substr(0, 10) == "[COMPANY]:")
        {
            Company = rawHeaderLine.substr(10);
        }
        else if (rawHeaderLine.substr(0,7) == "[USER]:")
        {
            User = rawHeaderLine.substr(7);
        }
        else if (rawHeaderLine.substr(0,7) == "[TYPE]:")
        {
            Type = rawHeaderLine.substr(7);
        }
        else
        {
            errorNum = 5;
        }
    }

    // Creates the analysis data set to match the type found in file header
    void setDataInfo(vector<string> analysisData) {    

        if(this -> Type == "Test") {
            StructchaAnalysisTest AnalysisData = StructchaAnalysisTest(analysisData);
        } else {
            cout << "Type not found";
        }
    }
};


// class TestAnalysisFile: public StructchaAnalysisFile {
//     public:
//         int number;
//         int array1[5];
//         int array2[5];
// };

StructchaAnalysisFile setAnalysisFile(std::vector<string> analysisFile)
{
    // for(size_t i=0; i < analysisFile.size(); i++) {
    //     cout << analysisFile[i] << endl;
    // }

    StructchaAnalysisFile saf = StructchaAnalysisFile(analysisFile);
    return saf;
};
