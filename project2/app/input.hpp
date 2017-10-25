// input.hpp
//
// AARON ZHONG ID:67737879
// ICS 45C Fall 2014
// LAST MODIFIED: 11/07/14
// (C) All rights Reserved

#ifndef INPUT_HPP
#define INPUT_HPP
#include <iostream>
#include <string>

std::string getTilSpaceOrNewl(); //10
std::string getTilNewl(); //11
int returnNumberFromLine(); //12
int* createDataArray(int artifactNumber); //13

int** create2dArray(const int y, const int x); //14
int** fill2dArray(int** twoD_array, const int y, const int x); //15

int** create2dScoreArray(const int numberOfScoreSets, const int numberOfArtifacts); //16
int**create2dCutPointArray(const int numberOfCuts); //17

double** create2dim_DoubleArray(const int y, const int x); //18
double** fill2dim_DoubleArray(double** twoD_array, const int y, const int x); //19
double** create2dim_DoubleCutPointArray(const int numberOfCuts); //20


void  delete2dArray(int** twoD_array, const int lenY); //21
void delete2d_doubleArray(double** twoD_array, const int lenY); //21.5

#endif // INPUT_HPP

