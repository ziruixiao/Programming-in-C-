#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

//------------------------------------
class WordUnit
{
public: 
   WordUnit(): word(" "), frequency(1) {}
   WordUnit(string wordValue): word(wordValue), frequency(1) {}

   bool operator< (const WordUnit & RHS) const
   {  return((frequency > RHS.frequency)? true: false); }
  
   bool operator== (const string rhsStringObject) const
   {  return((word == rhsStringObject)? true:false); } 

   WordUnit & operator++()
   {  frequency++; return(*this); }

   void print() {cout << word << " " << frequency << endl;}

private: 
   string word;
   int frequency;
};

//------------------------------------

int main(int argv, char * argc[])
{

vector <WordUnit> wordList; //it is initially zero
string tempString;
int beginErase;

if (argv == 2) //then user has two strings at command prompt
{

   ifstream inputFile(argc[1], ios::in);

   while ( inputFile >> tempString)
   {

      // PREPARE THE STRING - TAKE OUT SPECIAL CHARACTERS
      if ( (beginErase = tempString.find_first_of(".,-\"?\' \n")) != string::npos)
         //{ tempString.erase(beginErase, string::npos); }
         { tempString.erase(beginErase, 1); }
      // PREPARE THE STRING - REMOVE CAPS
      tempString[0] = tolower(tempString[0]); //get rid of caps

      // UPDATE VECTOR AND FREQUENCY 
      int counter = 0; 
      bool GETOUT = false; 
      while (!GETOUT)
      {
        if ( counter >= wordList.size()) // then at end of list
        {  
            wordList.push_back(WordUnit(tempString));
            GETOUT = true;
        }
        else if ( wordList[counter] == tempString) //I overloaded this operator
        {  
  	   ++wordList[counter];
           GETOUT = true; 
        }
        else
        { counter++; }

      }//end of inner while loop
 
   } //end of outer while loop

   inputFile.close();

  // sort(wordList.begin(), wordList.end());

   //print the contents of the vector

   for (int i = 0; i < wordList.size(); i++) 
       wordList[i].print(); 
 
}

}//end main
