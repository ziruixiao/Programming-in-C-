//
//  quiz.cpp
//  ECE2036
//
//  Created by Felix Xiao on 9/4/14.
//  Copyright (c) 2014 Felix Xiao. All rights reserved.
//

#include "quiz.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//constructor
Quiz::Quiz() {
    score = 0;
    totalQuestions = 20;
    currentQuestionNumber = 1;
}

//make quiz methods
void Quiz::inputMessageMake() {
    cout << "This program will make a series of multiple choice questions \n\n" << endl;
    
}

bool Quiz::askAppend() { //this method asks the user to append or create a new test
    cout << "Do you want to add (a) to an existing test OR create a new test (c)?";
    char response;
    cin >> response;
    cin.ignore();
    if (response == 'a') {
        return 1; //append is 1
    } else {
        return 0; //overwrite is 0
    }
}

void Quiz::AskUserForFileName() {
    cout << "Input File Name (no spaces): ";
    string tempName;
    cin >> tempName;
    cin.ignore();
    setQuizFileName(tempName);
}

string Quiz::getQuestionOutputFormat() {
    //system("clear");
    
    cout << "Please input the question (answers will come later): " << endl;
    getline(cin, question, '\n');
    
    cout << "Input option A. " << endl;
    getline(cin, answerA, '\n');
    
    cout << "Input option B. " << endl;
    getline(cin, answerB, '\n');
    
    cout << "Input option C. " << endl;
    getline(cin, answerC, '\n');
    
    cout << "Input option D. " << endl;
    getline(cin, answerD, '\n');
    
    cout << "The correct answer is (a,b,c,d or n = none): ";
    cin >> correctAnswer;
    
    question = "-1\n" + question + "\n" + answerA +"\n" + answerB + "\n" + answerC + "\n" + answerD + "\n" + correctAnswer + "\n";

    cout << question;
    return question;
}

bool Quiz::continueQuestions() {
    string response;
    cout << "Do you want to add another question (y/n)? ";
    cin >> response;
    cin.ignore();
    
    if (response == "y") {
        return 1;
    } else {
        return 0;
    }
    
}


//take quiz methods
void Quiz::inputMessageTake() {
    cout << "This program will take a quiz from a pre-made file"<<endl;
    cout << "\n----------------------------------------------------\n" << endl;
}

void Quiz::askQuestion(ifstream& i) {
    if (currentQuestionNumber <= totalQuestions) {
        i.ignore();
        i.ignore();
        i.ignore();
        getline(i, question, '\n');
        getline(i, answerA, '\n');
        getline(i, answerB, '\n');
        getline(i, answerC, '\n');
        getline(i, answerD, '\n');
        i >> correctAnswer;
        i.ignore();
        i.ignore();
    
        cout << "Question " << getCurrentQuestionNumber() << ": ";
        cout << question << endl;
        cout << "a) " << answerA << endl;
        cout << "b) " << answerB << endl;
        cout << "c) " << answerC << endl;
        cout << "d) " << answerD << endl;
        cout << "e) None of the above" << endl;
    }
}

bool Quiz::continueTakingQuiz() {
    if (currentQuestionNumber <= totalQuestions) {
        return 1;
    } else {
        return 0;
    }
}

void Quiz::getReponse() {
    cout << "\nInput your answer: ";
    char response;
    cin >> response;
    cin.ignore();
    
    if (response == correctAnswer) {
        cout << "Correct!!" << endl;
        setScore(score+1);
    } else {
        cout << "Incorrect!!" << endl;
    }
    
    currentQuestionNumber = currentQuestionNumber + 1;
    
    cout << "\n\n" << endl;
}

void Quiz::reportResults() {
    cout << "Quiz is over. You scored a " << score << " out of " << currentQuestionNumber-1 << endl;
}
