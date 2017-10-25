// input.cpp
//
// AARON ZHONG ID:67737879
// ICS 45C Fall 2014
// LAST MODIFIED: 11/07/14
// (C) All rights Reserved

#include "input.hpp"

std::string getTilSpaceOrNewl() //10
{
    std::string temp;
    std::string totalTemp;

    while (temp != " " && temp!= "\n")
      {
        totalTemp = totalTemp + temp;
        temp = std::cin.get(); //does this create a memory leak? 
                               //Answer: No because strings are well behaved
      }
    return totalTemp;
}

std::string getTilNewl() //11
{
    std::string temp;
    std::string totalTemp;

    while (temp != "\n")
      {
        totalTemp = totalTemp + temp;
        temp = std::cin.get(); 
                              
      }
    return totalTemp;
}

int returnNumberFromLine() //12
{
  std::string artifactNumberStr;
  int artifactNumber;
  std::getline(std::cin,artifactNumberStr);
  artifactNumber = std::stoi(artifactNumberStr);

  return artifactNumber;
}

//3 is struct Student

int* createDataArray(const int artifactNumber) //13
{
  int* ArtifactArray = new int[artifactNumber];
  std::string temp;
  std::string totalPointsStr;

  for (int i = 0; i < artifactNumber ; ++i)
  {
    ArtifactArray[i] = std::stoi(getTilSpaceOrNewl());
  }
  return ArtifactArray;
}


int** create2dArray(const int y, const int x) //14
{
  int** twoD_array = new int*[y];
  for (int i = 0; i < y; ++i)
    {
      twoD_array[i] = new int[x];
    }

  return twoD_array;
}

int** fill2dArray(int** twoD_array, const int y, const int x)//15   The "copied twoD_array" is dynamically allocated, so deletion is must, right?
{
  for (int i = 0; i < y; ++i)
    {
      for (int j = 0; j < x; ++j)
        {
          int temp = std::stoi(getTilSpaceOrNewl());
          twoD_array[i][j] = temp;
        }
    }
  return twoD_array;
}


int** create2dScoreArray(const int numberOfScoreSets, const int numberOfArtifacts) //16
{
  int** twoD_scoreArray = create2dArray(numberOfScoreSets, numberOfArtifacts + 1);
  int** filledScoreArray = fill2dArray(twoD_scoreArray, numberOfScoreSets, numberOfArtifacts + 1);

  //....write delete twoD_scoreArray function for ^above function

  return filledScoreArray;
}

int** create2dCutPointArray(const int numberOfCuts) //17
{
  int** twoD_cutPointArray = create2dArray(numberOfCuts, 4);
  int** filledCutPointArray = fill2dArray(twoD_cutPointArray, numberOfCuts, 4);

  return filledCutPointArray;
}

double** create2dim_DoubleArray(const int y, const int x) //18
{
  double** twoD_array = new double*[y];
  for (int i = 0; i < y; ++i)
    {
      twoD_array[i] = new double[x];
    }

  return twoD_array;
}

double** fill2dim_DoubleArray(double** twoD_array, const int y, const int x)//19
{
  for (int i = 0; i < y; ++i)
    {
      for (int j = 0; j < x; ++j)
        {
          double temp = std::stod(getTilSpaceOrNewl());
          twoD_array[i][j] = temp; 
        }
    }
  return twoD_array;
}

double** create2dim_DoubleCutPointArray(const int numberOfCuts) //20
{
  double** twoD_cutPointArray = create2dim_DoubleArray(numberOfCuts, 4);
  double** filledCutPointArray = fill2dim_DoubleArray(twoD_cutPointArray, numberOfCuts, 4);

  return filledCutPointArray;
}

void delete2dArray(int** twoD_array, const int lenY) //21
{
  for (unsigned short int i = 0; i < lenY; ++i)
    {
      delete twoD_array[i];
    }
  delete [] twoD_array;
}

void delete2d_doubleArray(double** twoD_array, const int lenY) //21.5
{
  for (unsigned short int i = 0; i < lenY; ++i)
    {
      delete twoD_array[i];
    }
  delete [] twoD_array;
}
