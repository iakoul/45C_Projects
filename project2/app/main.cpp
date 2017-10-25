// main.cpp
//
// AARON ZHONG ID:67737879
// ICS 45C Fall 2014
// LAST MODIFIED: 11/07/14
// (C) All rights Reserved

#include <iostream>
#include <string>

#include "studentAndGrading.hpp"

int main()
{
  //....Data Parsing....
  int numberOfArtifacts = returnNumberFromLine();

  int* pointsArray = createDataArray(numberOfArtifacts);
  int* weightsArray = createDataArray(numberOfArtifacts);

  int numberOfStudents = returnNumberFromLine();
  Student* studentArray = createStudentArray(numberOfStudents);

  int numberOfScoreSets = returnNumberFromLine();
  int** twoD_scoreArray = create2dScoreArray(numberOfScoreSets, numberOfArtifacts);

  int numberOfCuts = returnNumberFromLine();  
  double** twoD_cutPointArray = create2dim_DoubleCutPointArray(numberOfCuts);
  
  //...... Data Munipulation ..........
  Student* updatedStudentArray = createUpdatedStudentArray(numberOfArtifacts, pointsArray,
                          weightsArray, twoD_scoreArray, 0,
                          numberOfStudents, studentArray, 
                          numberOfScoreSets);

  Student* finalStudentArray = createFinalStudentArray(twoD_cutPointArray[0], numberOfStudents, updatedStudentArray);


  //....... Actual Printing ............
  printAllCutPointScenarios(numberOfCuts,twoD_cutPointArray,
                            numberOfStudents, finalStudentArray);

  //....... DELETE ALL THAT MUST BE DELETED (arrrggg)..................
  delete [] pointsArray;
  delete [] weightsArray;  

  delete2dArray(twoD_scoreArray, numberOfScoreSets);
  delete2d_doubleArray(twoD_cutPointArray, numberOfCuts);

  delete [] studentArray;

  return 0;
}














  //........Print Tests (scratch work down below - Please Ignore)......
  
  //std::cout << "-------------" << std::endl;
  //std::cout << twoD_cutPointArray[0][0] << std::endl;
  //std::cout << calcLetterSingle(twoD_cutPointArray[0], updatedStudentArray[0]) << std::endl;
  /*std::cout << calcScore(numberOfArtifacts, 
                         pointsArray, 
                         weightsArray, 
                         twoD_scoreArray,
                         0) << std::endl;*/
  /*
  std::string temp;
  temp += std::cin.get();
  temp += std::cin.get();
  temp += std::cin.get();
  temp += std::cin.get();  
  std::cout << temp << std::endl;*/
  //std::cout << numberOfScoreSets << std::endl;
  //std::cout << pointsArray[0] << "and" << pointsArray[6] << std::endl;
  //std::cout << weightsArray[0] << "and" << weightsArray[6] << std::endl;
  //std::cout << twoDscoreArray[4][0] << "and" << twoDscoreArray[4][7] << std::endl;
  //std::cout << studentArray[2].finalPointGrade << std::endl;
  //std::cout << *(twoD_scoreArray[0]+6) << std::endl;


  //Questions To Ask Later:
  // how to make twoD_scoreArray  const?
  //FUNCTIONS I DON'T UNDERSTAND how actually deletes
  //void delete2dArray(int** twoD_array, int lenY); //.......???........
        //int** twoDscoreArray = create2dArray(numberOfScoreSets, numberOfArtifacts + 1);
        //int** filledScoreArray = fill2dArray(twoDscoreArray, numberOfScoreSets, numberOfArtifacts+1);
  //AND WHAT IS WITH THAT DOUBLE ARRAY SYNTAX?
  //Why are my structs fine? No (manual) deletion required?
  //What is going on with all that passing through parameters?
