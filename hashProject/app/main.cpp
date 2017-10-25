//main.cpp
//
// ICS 45C Fall 2014
// Project #3: Maps and Legends
//
// AARON ZHONG ID:67737879
// LAST MODIFIED: 26-November-2014
// (c) All rights Reserved

#include <iostream>

#include <inputHandle.hpp>


int main()
{

  HashMap hm;

  while(true)
    {
      if (masterInputHandler(hm) == "QUIT")
        {
          return 0;
        }
    }
}




























/*

 [DEPRECATED] Lots OF String Test







*/
  /*
  HashMap myHMobject;

  HashMap myHMobject2{myHMobject};

  HashMap myHMobject3 = myHMobject;

  myHMobject3.add("SuperMan","WinsALot");
  HashMap myHMobject4{myHMobject3};
  myHMobject4.add("spdier","craw");
  myHMobject4.remove("spdier") ;

   return 0;
} 
  myHMobject4.printHashArray();


  myHMobject4.add("mokey","slowmo");
  myHMobject4.add("fingertips","wookies");
  myHMobject4.add("luis","tramps");
  myHMobject4.add("samish","damns");
  myHMobject4.add("starxgazer","wams");
  myHMobject4.add("babsitter","schniderlambs");

  myHMobject4.remove("spider") ;
  myHMobject4.add("fadtty", "snorty"); 

  //std::cout << "slammy" << myHMobject4.hashArray[5]->value << std::endl;
  //std::cout << "slammy" << myHMobject3.hashArray[5]->next << std::endl;
  //std::cout << "1: " <<myHMobject.loadFactor() << " 2: " << myHMobject2.loadFactor()  
  //<< " 3: " << myHMobject3.loadFactor() << " 4: " << myHMobject4.loadFactor() 
  //<< std::endl;

  //std::cout << myHMobject4.value("babsitter") << std::endl;
  //std::cout << myHMobject4.value("spider") << std::endl;
  //std::cout << myHMobject4.maxBucketSize() << std::endl;

  //myHMobject4.printHashArray();
  myHMobject4.add("wonktank","fighter");
  //myHMobject4.printHashArray();
  myHMobject4.add("coppernicus","duper");
  //myHMobject4.add("slowdo","duper");
  //myHMobject4.printHashArray();
  std::cout << "EVERYTHING DONE" << std::endl;
test junk:
  //std::cout << "VVVVV" << myHMobject4.currentHashArraySize << std::endl;
  //myHMobject4.hashArray[5]->key = "SumtinBiggot";
  
  babsitter :: shinider::3
SuperMan :: WinsALot::9
luis :: fighter::10
stargazer :: fighter::11
samish :: fighter::15
fingertips :: fighter::1
  babsitter :: shinider::2
SuperMan :: WinsALot::5
fingertips :: fighter::5
luis :: fighter::5
samish :: fighter::5
stargazer :: fighter::5
wonktank :: fighter::7
mokey :: fighter::9*/
 //  ./run gtest --memcheck

  //cin test
  /*int a;
  std::string b;
  std::cin >> a;
  std::cout << a << std::endl;
  std::cin >> b;
  std::cout << b << std::endl;
  std::cin >> b;
  std::cout << b << std::endl;*/

