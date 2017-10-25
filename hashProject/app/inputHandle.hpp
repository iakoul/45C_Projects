//inputHandle.hpp
//
// ICS 45C Fall 2014
// Project #3: Maps and Legends
//
// AARON ZHONG ID:67737879
// LAST MODIFIED: 26-November-2014
// (c) All rights Reserved

#ifndef HANDLEINPUT_HPP
#define HANDLEINPUT_HPP  

#include <functional>
#include <iostream>
#include <string>

#include <HashMap.hpp>


const std::string  masterInputHandler(HashMap& hm);

void create(HashMap& hm, std::string userName, std::string passWord);
void login(HashMap& hm, std::string userName, std::string passWord);
void remove(HashMap& hm, std::string userName);
void clear(HashMap& hm);

void loginCount(const HashMap& hm);
void bucketCount(const HashMap& hm);
void loadFactor(const HashMap& hm);
void maxBucketSize(const HashMap& hm);


#endif
