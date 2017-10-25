// myOwn_sanityCheckTests.cpp
//
// ICS 45C Fall 2014
// Project #3: Maps and Legends
//
// AARON ZHONG ID:67737879
// LAST MODIFIED: 26-November-2014
// (c) All rights Reserved


#include <gtest/gtest.h>
#include <string>
#include "HashMap.hpp"



TEST(myOwn_sanityCheckTests, canConstructWithNoArguments)
{
  HashMap myHMobject; ;
}

TEST(myOwn_sanityCheckTests, canConstructWithHashMapAsArgument)
{
  HashMap myHMobject;

  HashMap myHMobject2{myHMobject};
}

TEST(myOwn_sanityCheckTests, canConstructUsingOperator)
{
  HashMap myHMobject;
  HashMap myHMobject2{myHMobject};

  HashMap myHMobject3 = myHMobject;
}

TEST(myOwn_sanityCheckTests, canAddToConstructedHashMap)
{
  HashMap myHMobject;
  HashMap myHMobject2{myHMobject};
  HashMap myHMobject3 = myHMobject;


  myHMobject3.add("SuperMan","WinsALot");
}


TEST(myOwn_sanityCheckTests, canCopyModdedHMtoNewHashMap)
{
  HashMap myHMobject;
  HashMap myHMobject2{myHMobject};
  HashMap myHMobject3 = myHMobject;
  myHMobject3.add("SuperMan","WinsALot");


  HashMap myHMobject4{myHMobject3};
}

TEST(myOwn_sanityCheckTests, canAddToNewHashMap)
{
  HashMap myHMobject;
  HashMap myHMobject2{myHMobject};
  HashMap myHMobject3 = myHMobject;
  myHMobject3.add("SuperMan","WinsALot");
  HashMap myHMobject4{myHMobject3};


  myHMobject4.add("spdier","craw");
}

TEST(myOwn_sanityCheckTests, canRemoveFromNewHashMap)
{
  HashMap myHMobject;
  HashMap myHMobject2{myHMobject};
  HashMap myHMobject3 = myHMobject;
  myHMobject3.add("SuperMan","WinsALot");
  HashMap myHMobject4{myHMobject3}; 
  myHMobject4.add("spdier","craw");


  myHMobject4.remove("spdier") ;
}

TEST(myOwn_sanityCheckTests, canDealWithNonExistentKeyFromNewHashMap)
{
  HashMap myHMobject;
  HashMap myHMobject2{myHMobject};
  HashMap myHMobject3 = myHMobject;
  myHMobject3.add("SuperMan","WinsALot");
  HashMap myHMobject4{myHMobject3}; 
  myHMobject4.add("spdier","craw");
  myHMobject4.remove("spdier") ;


  myHMobject4.remove("spdier") ;
}

TEST(myOwn_sanityCheckTests, canAutomaticallyRehashIfTooFull)
{
  HashMap myHMobject;
  HashMap myHMobject2{myHMobject};
  HashMap myHMobject3 = myHMobject;
  myHMobject3.add("SuperMan","WinsALot");
  HashMap myHMobject4{myHMobject3}; 
  myHMobject4.add("spdier","craw");
  myHMobject4.remove("spdier") ;
  myHMobject4.remove("spdier") ;


  myHMobject4.add("mokey","slowmo");
  myHMobject4.add("fingertips","wookies");
  myHMobject4.add("luis","tramps");
  myHMobject4.add("samish","damns");
  myHMobject4.add("starxgazer","wams");
  myHMobject4.add("babsitter","schniderlambs");
  myHMobject4.add("fadtty", "snorty"); 

}

