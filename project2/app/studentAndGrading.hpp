// studentAndGrading.hpp
//
// AARON ZHONG ID:67737879
// ICS 45C Fall 2014
// LAST MODIFIED: 11/07/14
// (C) All rights Reserved

#ifndef STUDENTANDGRADING_HPP
#define STUDENTANDGRADING_HPP
#include <iostream>
#include <string>

#include "input.hpp"

struct Student //1
{
  int ID;
  std::string gradeOption;
  std::string name;
  double finalPointGrade = -1;
  std::string finalLetterGrade = "N/A";
};

Student* createStudentStructFromLine(); //2
Student* createStudentArray(const int numberOfStudents); //3

//4
double calcScore(const int numberOfArtifacts, const int* pointsArray, 
                 const int* weightsArray, int** twoD_scoreArray, const int whichStudent); 
                                            // ^make sure to delete this

//........... Calculate and Recreate studentArray ....... // 5
Student* createUpdatedStudentArray (const int numberOfArtifacts, const int* pointsArray,
                           const int* weightsArray, int** twoD_scoreArray, const int whichStudent,
                           // ^ fed into calcScore function
                           
                           const int numberOfStudents, Student* studentArray, 
                           const int numberOfScoreSets);
                           // ^ required for current function

//........... Calculate Grade ................ // 6
std::string calcLetterSingle(const double* cutPointArray, const Student studentStruct);


//........... Create finalStudentArray ................ // 7
Student* createFinalStudentArray (const double* cutPointArray, 
                                  const int numberOfStudents, Student* studentArray);
 

//........... Print ALL studentArray element ................ //8
void printAllWithScores(const int numberOfStudents, const Student* studentArray); //8
void printAllWithLetters(const int numberOfStudents, const Student* studentArray); //8.5


//...........Print FINAL OUTPUT........................ //9
void printAllCutPointScenarios(const int numberOfCuts, double** twoD_cutPointArray, 
                               const int numberOfStudents, Student* finalStudentArray);

#endif //studentandgrading
