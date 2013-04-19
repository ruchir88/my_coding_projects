//
//  main.cpp
//  TestProgram
//
//  Created by Ruchir on 3/12/13.
//  Copyright (c) 2013 Ruchir. All rights reserved.
//
// Did it for just one digit need to do it for the others as well

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mainHeader.h"
using namespace std;

long lockAndSay (long num) {
    string numToBeCountedString;
    string countOfSameNumString;
    string resultString;
    
    int numToBeCounted;
    long tempnum;
    int tempnumNext;
    int totalCount = 0;
    int countOfSameNum = 0;
    int resultInt;
    
    tempnum = num;
    resultString = "";
    
    while (tempnum !=0) {
        totalCount++;
        tempnum = tempnum/10;
    }
    
    numToBeCounted = num / pow(10, (totalCount - 1));
    tempnumNext = numToBeCounted;
          
    while (totalCount != 0) {
        while (tempnumNext == numToBeCounted) {
            tempnumNext = (num - (numToBeCounted * pow(10, totalCount - 1))) / pow(10, totalCount - 2);
            num = num - (numToBeCounted * pow(10, totalCount - 1));
            totalCount--;
            countOfSameNum++;
        }
        countOfSameNumString = to_string(countOfSameNum);
        numToBeCountedString = to_string(numToBeCounted);
        resultString = resultString + countOfSameNumString + numToBeCountedString;
        
        numToBeCounted = tempnumNext;
        countOfSameNum = 0;
    }

    resultInt = atoi(resultString.c_str());
    
    cout<<"Result in String = "<<resultString<<endl;
    
    globalCount++;
    
    while (globalCount != 9) {
        lockAndSay(resultInt);
    }

    return resultInt;
}

int main(int argc, const char * argv[]) {
    long num;
    long finalResult;
    cout<<"Enter the Number you want to generate a sequence with:"<<endl;
    cin>>num;
    
    finalResult = lockAndSay(num);
    cout<<"The Final Resutl in string for the first number is : "<<finalResult<<endl;
}

