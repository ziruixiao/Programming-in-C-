//
//  quiz.h
//  ECE2036
//
//  Created by Felix Xiao on 9/4/14.
//  Copyright (c) 2014 Felix Xiao. All rights reserved.
//

#ifndef __ECE2036__quiz__
#define __ECE2036__quiz__

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Quiz {
private:
    string quizFileName;
    string outputFileName;
    int currentQuestionNumber;
    int score;
    char correctAnswer;
    string question;
    string answerA;
    string answerB;
    string answerC;
    string answerD;
    ifstream inputFile;
    int questionDelimiter;
    int totalQuestions;
    
public:
    //constructor
    Quiz();
    
    //getters
    string getQuizFileName() { return quizFileName; }
    int getCurrentQuestionNumber() { return currentQuestionNumber; }
    int getScore() { return score; }
    
    //setters
    void setQuizFileName(string name) { quizFileName = name; }
    void setCurrentQuestionNumber(int num) { currentQuestionNumber = num; }
    void setScore(int num) { score = score + 1; }
    
    //make quiz methods
    void inputMessageMake();
    bool askAppend();
    void AskUserForFileName();
    string getQuestionOutputFormat();
    bool continueQuestions();
    
    //take quiz methods
    void inputMessageTake();
    void askQuestion(ifstream& i);
    bool continueTakingQuiz();
    void getReponse();
    void reportResults();
};

#endif /* defined(__ECE2036__quiz__) */
