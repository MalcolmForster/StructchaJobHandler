#include <fstream>
#include <iostream>
#include <variant>
#include <string.h>

using namespace std;

class StructchaAnalysisFile {
    public:
        string JobName;
        string Company;
        string User;
        string Type;
        int number;
        int array1[5];
        int array2[5];
        StructchaAnalysisFile(std::vector<string> analysisFile) {
            if(analysisFile[0].compare("[[StructchaAnalysis<<HEADER]]]")) {
                string s = "";
                int i = 1;
                int dataLineCount = analysisFile.size();
                while (analysisFile[i].compare("[[StructchaAnalysis>>HEADER]]") && i < dataLineCount) {
                    s = analysisFile[i];
                    cout << "HL: "<< s << endl;
                    i++;
                }
                i++;
                if(analysisFile[i].compare("[[StructchaAnalysis<<DATA")) {
                    i++;
                    while (analysisFile[i].compare("[[StructchaAnalysis>>DATA]]") && i < dataLineCount) {
                        s = analysisFile[i];
                        cout << "DL: "<< s << endl;
                        i++;
                    }
                }

            }
        }
};

// class TestAnalysisFile: public StructchaAnalysisFile {
//     public:
//         int number;
//         int array1[5];
//         int array2[5];    
// };

StructchaAnalysisFile setAnalysisFile(std::vector<string> analysisFile) {    
    // for(size_t i=0; i < analysisFile.size(); i++) {
    //     cout << analysisFile[i] << endl;
    // }

    StructchaAnalysisFile saf = StructchaAnalysisFile(analysisFile);
    return saf;
};

