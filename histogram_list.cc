#include <iostream>
#include <algorithm>
#include <list>
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

   bool operator> (const string rhsStringObject) const
   {  return((word > rhsStringObject)? true:false); } 

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

list <WordUnit> wordList; //it is initially zero
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

    
      // UPDATE LIST AND FREQUENCY 

      list <WordUnit>::iterator curr = wordList.begin();
      bool GETOUT =false;

      while (!GETOUT)
      {
        if (curr == wordList.end())  //are we at the end of the list
        { wordList.push_back(WordUnit(tempString)); GETOUT = true;}
	else if ( *curr == tempString) //increase the frequency
        {   ++(*curr);  GETOUT=true; }
        else if (*curr > tempString)
        {  wordList.insert(curr, WordUnit(tempString)); GETOUT = true; }
        else
       {curr++;}
      } //end inner while loop
 
   } //end of outer while loop

   inputFile.close();

   wordList.sort();

   //print the contents of the vector
   list <WordUnit>::iterator it = wordList.begin();

   while (it != wordList.end())
   {  (it++)->print(); }

}

}//end main
