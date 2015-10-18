#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;


class WordUnit
{
public: 

bool operator< (const WordUnit & RHS) const
{
   if (frequency > RHS.frequency)
       return(true);
   else
       return(false);
}

string word;
int frequency;
};

int main(int argv, char * argc[])
{

vector <WordUnit> wordList; //it is initially zero
WordUnit tempWordUnit;
string tempString;
int beginErase;

if (argv == 2) //then user has two strings at command prompt
{

ifstream inputFile(argc[1], ios::in);

while ( inputFile >> tempString)
{

//Condition the string... get rid of special characters

if ( (beginErase = tempString.find_first_of(".,- \n")) != string::npos)
{
    tempString.erase(beginErase, string::npos);
}

tempString[0] = tolower(tempString[0]); //get rid of caps

//Now update vector list and freqency
int counter = 0;
bool GETOUT = false;

while (!GETOUT)
{

if ( counter >= wordList.size()) // then at end of list
{  GETOUT = true;
   tempWordUnit.word = tempString;
   tempWordUnit.frequency = 1;
   wordList.push_back(tempWordUnit);
}
else if ( wordList[counter].word == tempString)
{  wordList[counter].frequency++ ; GETOUT = true; }
else
{counter++;}

}//end of inner while loop
 
}

sort(wordList.begin(), wordList.end());


//print the contents of the vector

for (int i = 0; i < wordList.size(); i++)
{ cout << wordList[i].word <<" " << wordList[i].frequency << endl;}


}

}//end main
