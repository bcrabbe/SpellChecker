//
//  main.cpp
//  list
//
//  Created by ben on 21/11/2014.
//  Copyright (c) 2014 ben. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Dictionary.h"



void testWord(Dictionary Dict);

#define CHECK_WORD 1

using namespace std;

int main(int argc, const char * argv[])
{

    Dictionary Dict;
    if(argc>1)
    {
        ifstream wordFile;
        wordFile.open( argv[1], ifstream::in);
        cout << "file is " << (wordFile.good() ? " open" : " not open") << endl;
        if(wordFile.good())
        {
            Dict.readInFile(wordFile);
            Dict.printList();
        }
        wordFile.close();
        
        if(CHECK_WORD)
        {
            testWord(Dict);
        }
    }
    
    return 0;
}

void testWord(Dictionary Dict)
{
    string userWord;
    cout << "Enter a Word: (Press n to quit)" << endl;
    cin >> userWord;
    if( userWord.at(0)=='n' )
    {
        return;
    }
    if(Dict.isWord( userWord ))
    {
        cout << userWord << " is a word" << endl << endl;
    }
    else{
        cout << userWord << " is not a word" << endl << endl;
    }
   
    testWord(Dict);
}
