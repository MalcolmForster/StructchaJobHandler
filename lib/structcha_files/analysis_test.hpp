//Test analysis file class with specific items for Structcha test
//This can be used by both the analysis_test.hpp as well as other header/source files
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

class StructchaAnalysisTest
{
public:
    bool DataError = false;
    int Number = 0;
    int Size = 0;
    double array1[];
    double array2[];

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
                double array1[Size] = calculateArray(rawHeaderLine.substr(11), Number, Size);
            }
            else if (rawHeaderLine.substr(0, 11) == "[FORMULA2]:")
            {
                double array2[Size] = calculateArray(rawHeaderLine.substr(11), Number, Size);
            }
            else
            {
                DataError = true;
                break;
            }
        }
    };

private:
    double[] calculateArray(string formula, int Number, int Size)
    {
        int i = 0;
        int lengthOfString = formula.length();

        while(n < lengthOfString) {
            if (formula[i] == ' ' || formula[i] == '_')
            {
                formula[i] = '';
                lengthOfString = lengthOfString--;
            } else {
                n++;
            }
        }

        vector<double> tempVec;

        for (int s = 0; s < Size; s++) {
            i = 0;
            double cur = 0;
            while (i < formula.length())
            {
                string orderOfOps = "";
                if (formula.substr(i,3) == "num")
                {
                    cur=cur+(formula.stoi(substr(i,3))*s);
                    i = i + 3;
                }
                else if (formula.substr(i,1) == "^")
                {
                    cur = power(cur,nextNum(formula[i:],));
                }
                else if (formula.substr(i,1) == "*")
                {
                    cur = cur * (formula.substr(i+1,1));
                }
                else if (formula.substr(i,1) == "/")
                {
                    cur = cur / formula.substr(i+1,1);
                }
            }
            tempVec.push_back(cur);
        }

        double returnArray[tempVec.size()];
        return copy(tempVec.begin(), tempVec.end(), returnArray);    
    }

    double nextNum(string formSec, double numberInUse) {
        if(formSec.substr(0,3) == "num") {
            return numberInUse;
        } else {
            return stod(formSec.substr(i+1,1));
        }
    }
};