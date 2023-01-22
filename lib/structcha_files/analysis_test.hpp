//Test analysis file class with specific items for Structcha test
//This can be used by both the analysis_test.hpp as well as other header/source files
#include <string.h>
#include <vector>

using namespace std;

class StructchaAnalysisTest
{
public:
    bool DataError = false;
    int Number = 0;
    int Size = 0;
    double array1;
    double array2;

    // Constructor receives the string vector.
    StructchaAnalysisTest(vector<string> analysisVector)
    {
        for (string s : analysisVector)
        {
            if (rawHeaderLine.substr(0, 9) == "[NUMBER]:")
            {
                Number = stoi(rawHeaderLine.substr(9));
            }
            else if (rawHeaderLine.substr(0, 7) == "[SIZE]:")
            {
                Size = stoi(rawHeaderLine.substr(7));
            }
            else if (rawHeaderLine.substr(0, 11) == "[FORMULA1]:")
            {
                double array1[Size] = calculateArray(rawHeaderLine.substr(11), Number);
            }
            else if (rawHeaderLine.substr(0, 11) == "[FORMULA2]:")
            {
                double array2[Size] = calculateArray(rawHeaderLine.substr(11), Number);
            }
            else
            {
                DataError = true;
                break;
            }
        }
    };

private:
    array<string,Size> calculateArray(string formula, int Number)
    {
        int i = 0;
        while (i < formula.length())
        {
            if (formula.substr(i,3) == "num")
            {
                i = i + 3;
            }
            else if (formula.substr(i,1) == "^")
            {

            } else if (formula.substr(i,1) == "*") {

            } else if (formula.substr(i,1) == "/") {
                
            }
        }
};