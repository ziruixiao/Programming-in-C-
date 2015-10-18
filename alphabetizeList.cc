#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(int argc, char * argv[])
{

   ifstream inputFile;
   ofstream outputFile;

   if (argc < 2)
       cout << "Please input the filename" << endl;
   else 
   {
      inputFile.open(argv[1], ios::in);

	if (inputFile)
        {
	    string inputString;
            vector <string> names;
          
            while ( inputFile >> inputString)
		names.push_back(inputString);
	     
            inputFile.close();
     
            sort(names.begin(), names.end());

            outputFile.open(argv[1],ios::out);

	    for (vector <string>::iterator it = names.begin(); it < names.end(); ++it)
		outputFile << (*it) << endl;

   	    outputFile.close();

        }
        else
        {
           cout << "Error in opening file" << endl;
        }

   }

   return 0;
}
