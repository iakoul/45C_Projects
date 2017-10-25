// HashMap.cpp
//
// ICS 45C Fall 2014
// Project #3: Maps and Legends
//
// AARON ZHONG ID:67737879
// LAST MODIFIED: 26-November-2014
// (c) All rights Reserved

#include "HashMap.hpp"

//..........Default HashFunction............
unsigned int returnDefaultHashFunctionValue(const std::string& keyString)
{
  unsigned int hash = 0; 
  for (int i = 0; i < keyString.length(); i++) 
    { 
      hash = 31*hash + keyString[i]; 
    } 
  return hash;
}

//..........HashArray Copier............
void HashMap::hashArrayCopy(Node** copyFromHere)
{
  //....1st Loop: Checking Each Bucket.....
  for ( unsigned int i = 0; i < currentHashArraySize; ++i)
    {
      if (copyFromHere[i] != nullptr)
        //....2nd Loop: If the Bucket isn't a nullptr, then.....
        {
          Node* copyFromHereTempPointer = copyFromHere[i];

          hashArray[i] = new Node{.key=copyFromHereTempPointer->key, 
                                  .value=copyFromHereTempPointer->value};         
          Node* hashArrayTempPointer = hashArray[i];
     
          while ((copyFromHereTempPointer != nullptr) and (copyFromHereTempPointer->next != nullptr))
            {
              copyFromHereTempPointer = copyFromHereTempPointer->next;
              hashArrayTempPointer->next = new Node{.key=copyFromHereTempPointer->key, 
                                                    .value=copyFromHereTempPointer->value,
                                                    .next = nullptr};
              hashArrayTempPointer = hashArrayTempPointer->next;
            }


        }//...2nd Loop END

      //....1st Loop: If it is a nullptr, then make the current element in the new 
      //hashArray a nullptr too

      else
        {
          hashArray[i] = nullptr;
        }
    }//....1st Loop END

  


  std::cout << "hashArrayCopy Finished" << std::endl;
}

//..........Constructor............
HashMap::HashMap()
  : hasher{returnDefaultHashFunctionValue},
    hashArray{new Node*[initialBucketCount]},                                      
    totalNumberOfPairs{0}, 
    currentHashArraySize{initialBucketCount}                                        
{
  for ( unsigned int i = 0; i < initialBucketCount; ++i)
    {
      hashArray[i] = nullptr;
    }
}

//..........HashFunctionSpecified Constructor............
HashMap::HashMap(HashFunction hasher)
  : hasher{hasher}, 
  hashArray{new Node*[initialBucketCount]},
  totalNumberOfPairs{0},
  currentHashArraySize{initialBucketCount} 
{
  for ( unsigned int i = 0; i < initialBucketCount; ++i)
    {
      hashArray[i] = nullptr;
    }
  std::cout << "Constructor Finished\n" << std::endl;
}

//..........Copy Constructor............
HashMap::HashMap(const HashMap& hm)
  : hasher{hm.hasher}, 
    hashArray{new Node*[hm.currentHashArraySize]},
    totalNumberOfPairs{hm.totalNumberOfPairs},  
    currentHashArraySize{hm.currentHashArraySize}
                                           
{
  hashArrayCopy(hm.hashArray);
  std::cout << "Copy Constructor Finished" << std::endl;
}

//..........Destructor............
HashMap::~HashMap()
{
  
  Node* tempPointer = hashArray[0];
  
  for (unsigned int i = 0; i < currentHashArraySize; ++i)
    {
      while (tempPointer != nullptr)
        {
          Node* nextPointer = tempPointer->next;
          delete tempPointer;
          tempPointer = nextPointer;
        }
      tempPointer = hashArray[i+1];
    }
  
  delete[] hashArray;
  std::cout << "Destructor Finished" << std::endl;

}


HashMap& HashMap::operator=(const HashMap& hm)
{
  if (this != &hm) //If not the same thing.....

    //.....First DELETE the hashArray......
    {     
      Node* tempPointer = hashArray[0];
      for (unsigned int i = 0; i < currentHashArraySize; ++i)
        {
          while (tempPointer != nullptr)
            {
              delete tempPointer;
              tempPointer = tempPointer->next;
            }
          tempPointer = hashArray[i+1];
        }
      delete hashArray;
      
      //......Set the values to the hm values.......
      totalNumberOfPairs = hm.totalNumberOfPairs;
      currentHashArraySize = hm.currentHashArraySize;

      //......Dynamically allocate another array....
      hashArray = new Node*[currentHashArraySize];

      //......Copy everything from hm into current hashArray
      //******(making  actual copies, not pointers/reference copies)  
      hashArrayCopy(hm.hashArray);
    }
  
  return *this;
  std::cout << "= Operand Finished" << std::endl;
}



//______________ Everything Else ________________________________

const unsigned int HashMap::calculateHashArrayIndex(const std::string& keyString) const
{
  return (hasher(keyString) % currentHashArraySize);
}

void HashMap::addIfNodeNull(const std::string& key, const std::string& value)
{
  const unsigned int hashArrayIndex = calculateHashArrayIndex(key);
  Node* headPointer = hashArray[hashArrayIndex];

  //...First sees if the bucket is a nullptr
  if (headPointer == nullptr)
    {
      //std::cout << "running this bloody code" << std::endl;
      hashArray[hashArrayIndex] = new Node{key,value,nullptr};
      totalNumberOfPairs += 1;
      return;
    }
  //.... If bucket is a node, then "iterates" through to find the end to put the key/value pair
  while (true)
    {
      if (headPointer->next == nullptr)
        {
          headPointer->next = new Node{key,value,nullptr};
          totalNumberOfPairs += 1;
          //std::cout << "yayayayayaay: " << key  << std::endl;
          return;
        }
      else
        {   
          headPointer = headPointer->next;
        }
    }
}

void HashMap::reHashEntireHashArray() /// WRITE
{
  unsigned int oldHashArraySize = currentHashArraySize;
  currentHashArraySize  = currentHashArraySize*2+1;

  Node** oldHashArray = hashArray;
  Node* headOnOldArray; 

  hashArray  = new Node*[currentHashArraySize];


  for (unsigned int i = 0; i < oldHashArraySize; ++i)
    {
      headOnOldArray = oldHashArray[i];
      while (headOnOldArray != nullptr)
        {
          addIfNodeNull(headOnOldArray->key, headOnOldArray->value);
          
          Node* nextPointer = headOnOldArray->next;
          delete headOnOldArray;
          headOnOldArray = nextPointer; 
        }
    }

  ///........CLEAN UP CREW........

  delete[] oldHashArray;
}

void HashMap::add(const std::string& key, const std::string& value) /// FIX
{
  if (loadFactor() >= maxLoadPercentage)
    {
      reHashEntireHashArray();
    }

  addIfNodeNull(key, value);
}

bool HashMap::contains(const std::string& key) const
{
  Node* headPointer = hashArray[calculateHashArrayIndex(key)];   
  while (headPointer != nullptr)
    {
      if (headPointer->key == key)
        {
          //std::cout << "The key: " <<  key  << " is here." << std::endl;
          return true;
        }
      else
        {
          headPointer = headPointer->next;
        }
    }
  //std::cout << "Key: " << key <<" not in this hashMap" << std::endl;
  return false;
}

std::string HashMap::value(const std::string& key) const
{
  Node* headPointer = hashArray[calculateHashArrayIndex(key)];   
  while (headPointer != nullptr)
    {
      if (headPointer->key == key)
        {
          return headPointer->value;
        }
      else
        {
          headPointer = headPointer->next;
        }
    }
  return "";
}

void HashMap::remove(const std::string& key) 
{ 
  Node* headPointer;

  for (unsigned int i = 0; i < currentHashArraySize; ++i)
    {
      Node* beforeHeadPointer = nullptr;
      headPointer = hashArray[i];

      while (headPointer != nullptr)
        {
          if(headPointer->key == key)
            {             
              //ONCE the key is found, do ONE of the TWO:             
              if (beforeHeadPointer!= nullptr)
                { 
                  beforeHeadPointer->next = headPointer->next;
                  delete headPointer;
                  headPointer = nullptr;
                }
              else
                {
                  delete headPointer;
                  headPointer = nullptr;
                  hashArray[i] = nullptr;
                }
              
              totalNumberOfPairs -= 1;

              return;
            }
          beforeHeadPointer = headPointer;
          headPointer = headPointer->next;
        }     
    }
  std::cout << "Key: " << key << " was not found :(" << std::endl; 
}


unsigned int HashMap::size() const
{
  return totalNumberOfPairs;
}

unsigned int HashMap::bucketCount() const
{
  return currentHashArraySize;
}

double HashMap::loadFactor() const
{
  return totalNumberOfPairs/currentHashArraySize;
}

unsigned int HashMap::maxBucketSize() const
{
  unsigned int biggestBucketSoFar = 0;
  unsigned int currentBucketSize = 0;

  Node* headPointer;

  for (unsigned int i = 0; i < currentHashArraySize; ++i)
    {
      headPointer = hashArray[i];
      while (headPointer != nullptr)
        {
          currentBucketSize += 1;
          headPointer = headPointer->next;
        }
      if (currentBucketSize > biggestBucketSoFar)
        {
          biggestBucketSoFar = currentBucketSize;
        }
      currentBucketSize = 0;
    }
  return biggestBucketSoFar;
}


void HashMap::printHashArray()
{
    Node* headPointer;
    std::cout << "////////////////////////////" << std::endl;
    for (unsigned int i = 0; i < currentHashArraySize; ++i)
    {
      headPointer = hashArray[i];
      while (headPointer != nullptr)
        {
          std::cout << headPointer->key << " :: " << headPointer->value << ":: " << i << std::endl;
          headPointer = headPointer->next;
        }
    }
    std::cout << "////////////////////////////" << std::endl;
}

void HashMap::clearHashArray()
{
  
  for (unsigned int i = 0; i < currentHashArraySize; ++i)
    {
      Node* tempPointer = hashArray[i];
      while (tempPointer != nullptr)
        {
          Node* nextPointer = tempPointer->next;
          delete tempPointer;
          tempPointer = nextPointer;
        }
      hashArray[i] = nullptr;
    }
}
