//inputHandle.cpp
//
// ICS 45C Fall 2014
// Project #3: Maps and Legends
//
// AARON ZHONG ID:67737879
// LAST MODIFIED: 26-November-2014
// (c) All rights Reserved

#include "inputHandle.hpp"

//........... Master Caller Function

bool debugSwitch = false;

const std::string masterInputHandler(HashMap& hm)
{

  std::string firstWord;
  std::cin >> firstWord;

  if (firstWord == "CREATE" || firstWord == "LOGIN" || firstWord == "REMOVE")
    {

      std::string userName;
      std::cin >> userName;

      if (firstWord == "CREATE" || firstWord == "LOGIN")
        {

          if (userName == "COUNT")
            {
              loginCount(hm);
            }
          else
            {
              std::string passWord;
              std::cin >> passWord;
        
              if (firstWord == "CREATE")
                {
                  create(hm,userName,passWord);
                }

              else
                {
                  login(hm,userName,passWord);                  
                }

            }
        }
      else
        {
          remove(hm, userName);
        }
    }

  else if (firstWord == "CLEAR")
    {
      clear(hm);
    }

  else if (firstWord == "DEBUG")
    {
      std::string onOff;
      std::cin >> onOff;

      if (debugSwitch && onOff == "ON")
        {
          std::cout << "ALREADY ON" << std::endl;
        }
      else if (not debugSwitch && onOff == "OFF")
        {
          std::cout << "ALREADY OFF" << std::endl;
        }
          
      else
        {
          if (onOff == "ON")
            {
              debugSwitch = true;
              std::cout << "ON NOW" << std::endl;
            }
          else if (onOff == "OFF")
            {             
              debugSwitch = false;
              std::cout << "OFF NOW" << std::endl;
            }
        }

    }

  else if (firstWord == "QUIT")
    {
      std::cout << "GOODBYE!" << std::endl;
      return "QUIT";
    }
  
  else
    {
      std::string restOfTheString;
      std::getline(std::cin, restOfTheString);
      
      std::string fullString = firstWord + restOfTheString;

      if (fullString == "BUCKET COUNT")
        {
          bucketCount(hm);
        }
      else if(fullString == "MAX BUCKET SIZE")
        {
          maxBucketSize(hm);
        }
      else if (fullString == "LOAD FACTOR")
        {
          loadFactor(hm);
        }
      else
        {
          std::cout << "INVALID" << std::endl;
        }
           
    }

  return "";

}

void create(HashMap& hm, std::string userName, std::string passWord)
{

  if (hm.contains(userName))
    {
      std::cout << "EXISTS" << std::endl;
    }
  else
    {
      hm.add(userName, passWord);
      std::cout << "CREATED" << std::endl;
    }
}

void login(HashMap& hm, std::string userName, std::string passWord)
{
  if (hm.contains(userName) && hm.value(userName) == passWord)
    {
      std::cout << "SUCCESS" << std::endl;
    }
  else
    {
      std::cout << "FAILURE" <<std::endl;
    }
};

void remove(HashMap& hm, std::string userName)
{
  if (hm.contains(userName))
    {
      hm.remove(userName);
      std::cout << "REMOVED" << std::endl;
    }
  else
    {
      std::cout << "NONEXISTENT" << std::endl;
    }
  
}
void clear(HashMap& hm)
{
  hm.clearHashArray();
  std::cout << "DATABASE CLEARED" << std::endl;
}

void loginCount(const HashMap& hm)
{
  std::cout << hm.size() << std::endl;
}

//...............................
void bucketCount(const HashMap& hm)
{  
  if(debugSwitch)
    {
      std::cout << hm.bucketCount() << std::endl;
    }
  else
    {
      std::cout << "INVALID" << std::endl;
    }
}

void loadFactor(const HashMap& hm)
{  
  if(debugSwitch)
    {
      std::cout << hm.loadFactor() << std::endl;
    }
  else
    {
      std::cout << "INVALID" << std::endl;
    }
}

void maxBucketSize(const HashMap& hm)
{  
  if(debugSwitch)
    {
      std::cout << hm.maxBucketSize() << std::endl;
    }
  else
    {
      std::cout << "INVALID" << std::endl;
    }
}

