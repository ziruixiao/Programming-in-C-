//
//  main_make_quiz.cpp
//  ECE2036
//
//  Created by Felix Xiao on 9/4/14.
//  Copyright (c) 2014 Felix Xiao. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "quiz.h"

using namespace std;
/*
int main() {
    
    ofstream outputFile;
    Quiz quizObject = Quiz();
    
    //system("clear");
    
    quizObject.inputMessageMake();
    
    if (quizObject.askAppend()) {
        quizObject.AskUserForFileName();
        //cout << quizObject.getQuizFileName();
        outputFile.open(quizObject.getQuizFileName().c_str(), ios::app);
    } else { //overwrite the file name
        quizObject.AskUserForFileName();
        //cout << quizObject.getQuizFileName();
        outputFile.open(quizObject.getQuizFileName().c_str(), ios::out);
    }
    
    if (!outputFile) {
        cout << "There is an error in the file" << endl;
        return 0; //quit program on error
    }
    
    do {
        outputFile << quizObject.getQuestionOutputFormat() << endl;
    } while (quizObject.continueQuestions()); //end of the while loop
     
     
}*/

