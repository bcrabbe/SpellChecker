//
//  Dictionary.h
//  Dictionary
//
//  Created by ben on 21/11/2014.
//  Copyright (c) 2014 ben. All rights reserved.
//

#ifndef __Dictionary__Dictionary__
#define __Dictionary__Dictionary__

#include <iostream>
#include <fstream>
#include <stdio.h>
struct node;
typedef struct node node;
typedef class Dictionary Dictionary;

using namespace std;

class Dictionary
{
private:
    struct node {
        string word;
        node *next;
    };
    node * tail;
    node * head;
    unsigned int numberOfNodes;

public:
    Dictionary();
    ~Dictionary();
    int readInFile(ifstream & wordFile);
    int insertWord(string newWord);
    int alphabeticalInsertPosition(string newWord, node ** nodeToInsertAfter);
    void printList();
    bool isWord(string word);
    
};

#endif /* defined(__Dictionary__Dictionary__) */
