// studentAndGrading.cpp
//
// AARON ZHONG ID:67737879
// ICS 45C Fall 2014
// LAST MODIFIED: 11/07/14
// (C) All rights Reserved

#include "studentAndGrading.hpp"

//1 Student Struct

Student* createStudentStructFromLine() //2
{
  
  Student* student = new Student{std::stoi(getTilSpaceOrNewl()),
                              getTilSpaceOrNewl(),
                              getTilNewl()};
  return student;
}

Student* createStudentArray(const int numberOfStudents) //3
{
  Student* studentArray = new Student[numberOfStudents];

  for (int i = 0; i < numberOfStudents; ++i)
    {
      Student* temp = createStudentStructFromLine();
      studentArray[i].ID = temp->ID;
      studentArray[i].gradeOption = temp->gradeOption;
      studentArray[i].name = temp->name;
      delete temp;
    }
  return studentArray;
}

//4
double calcScore(const int numberOfArtifacts, const int* pointsArray, 
              const int* weightsArray, int** twoD_scoreArray, const int whichStudent) // how to make twoD_scoreArray  const?
{

  double finalScore = 0;

  for (unsigned short i = 0; i < numberOfArtifacts; ++i)
    {
      double num1 = twoD_scoreArray[whichStudent][i+1]; // +1 because the first index is the ID, so it will skip that value
      double num2  = weightsArray[i];
      double dem1 = pointsArray[i];                                        
      finalScore += num2*num1/dem1;
    }

  //delete function
 

  return finalScore;    
}

//........... Calculate and Recreate studentArray ................ //5
Student* createUpdatedStudentArray(const int numberOfArtifacts, const int* pointsArray,
                                 const int* weightsArray, int** twoD_scoreArray, const int whichStudent,
                           
                                 const int numberOfStudents, Student* studentArray, 
                                 const int numberOfScoreSets)
{
  for (unsigned short int i = 0; i < numberOfScoreSets ; ++i)
    {
      for (unsigned short int k = 0; k < numberOfStudents; ++k)
        {
          if (twoD_scoreArray[i][0] == studentArray[k].ID)
            {
              studentArray[k].finalPointGrade =  calcScore(numberOfArtifacts, pointsArray, 
                                                           weightsArray, twoD_scoreArray, i);
              break;
            }
        }
    }
  return studentArray;
}

//........... Calculate Grade ................ 
std::string calcLetterSingle(const double* cutPointArray, const Student studentStruct) // 6
{
  const std::string letterGradeArray[7] = {"A","B","C","D","F","P","NP"};
  std::string finalLetter = "?";

  if (studentStruct.gradeOption == "G")
    {
      for (unsigned short int i = 0; i < 4; ++i)
        {
          if (studentStruct.finalPointGrade >= cutPointArray[i])
            {
              finalLetter = letterGradeArray[i];
              break;
            }
        }
      if (finalLetter == "?")
        {
          finalLetter = letterGradeArray[4];
        }
    }

  else
    {
      for (unsigned short int i = 0; i < 3; ++i)
        {
          if (studentStruct.finalPointGrade >= cutPointArray[i])
            {
              finalLetter = letterGradeArray[5];
              break;
            }
        }
      if (finalLetter == "?")
        {
          finalLetter = letterGradeArray[6];
        }
    }
  return finalLetter;
}


//........... Create finalStudentArray ................ // 7
Student* createFinalStudentArray (const double* cutPointArray, 
                                  const int numberOfStudents, Student* studentArray)
{
  for (unsigned short int i = 0; i < numberOfStudents; ++i)
    {
      studentArray[i].finalLetterGrade = calcLetterSingle(cutPointArray, studentArray[i]);
    }
  return studentArray;
}

//........... Print ALL studentArray elements ................ // 8

void printAllWithScores(const int numberOfStudents, const Student* studentArray)
{
  for (unsigned short int i = 0; i < numberOfStudents; ++i)
    {
      std::cout << studentArray[i].ID << " " << studentArray[i].name << " "
                << studentArray[i].finalPointGrade << std::endl;
    }
  std::cout << std::endl; 
}

void printAllWithLetters(const int numberOfStudents, const Student* studentArray) //8.5
{ 
  for (unsigned short int i = 0; i < numberOfStudents; ++i)
    {
      std::cout << studentArray[i].ID << " " << studentArray[i].name << " "
                << studentArray[i].finalLetterGrade  <<std::endl;
    }
  std::cout << std::endl;  
}

//...........Print FINAL OUTPUT........................ //9
void printAllCutPointScenarios(const int numberOfCuts, double** twoD_cutPointArray,
                               const int numberOfStudents, Student* finalStudentArray)
{
  std::cout << std::endl;
  printAllWithScores(numberOfStudents, finalStudentArray);

  for (unsigned short int i = 0; i < numberOfCuts; ++i)
    {
      Student* tempStudentArray = createFinalStudentArray(twoD_cutPointArray[i], numberOfStudents, finalStudentArray);
      std::cout << "CUTPOINT " << i+1 << std::endl;
      printAllWithLetters(numberOfStudents, tempStudentArray);    
    }
}


