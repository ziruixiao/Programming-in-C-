//
//  main_take_quiz.cpp
//  ECE2036
//
//  Created by Felix Xiao on 9/4/14.
//  Copyright (c) 2014 Felix Xiao. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "quiz.h"
/*
using namespace std;

int main() {
    ifstream inputFile;
    Quiz quiz = Quiz();
    
    quiz.inputMessageTake();
    
    quiz.AskUserForFileName();
    
    inputFile.open(quiz.getQuizFileName().c_str(), ios::in);
    if (!inputFile) {
        cout << "There was an error in the file" << endl;
        return 0; //exit program
    }
    
    quiz.askQuestion(inputFile);
    while (quiz.continueTakingQuiz()) {
        quiz.getReponse();
        quiz.askQuestion(inputFile);
    }
    
    quiz.reportResults();
    
}
 */

