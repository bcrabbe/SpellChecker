//
//  Dictionary.cpp
//  Dictionary
//
//  Created by ben on 21/11/2014.
//  Copyright (c) 2014 ben. All rights reserved.
//
#include <string>
#include <new>
#include <algorithm>

#include "Dictionary.h"

using namespace std;


Dictionary::~Dictionary()
{
    cout << "List is being deleted" << endl;
    
    node * current = this->head;
    while(current->next!=NULL)
    {
        node * temp = current->next;
        delete current;
        --this->numberOfNodes;
        cout << "Nodes left = " << this->numberOfNodes <<  endl;
        current = temp;
    }
    
    cout << "Nodes left = " << this->numberOfNodes <<  endl;
    cout << "Done."      << endl;
    
}

Dictionary::Dictionary() : numberOfNodes(0)
{
    cout << "List is being created" << endl;
    cout << "Done." << endl;

}

bool Dictionary::isWord(string word)
{
    node * current = this->head;

    do
    {
        if( current->word == word )
        {
            return true;
        }
        else
            current = current->next;
    } while( current->next != NULL );
    
    return false;
}


void Dictionary::printList()
{
    
    cout << "list:" << endl;
    node * current = this->head;
    while(current!=NULL)
    {
        cout << current->word << endl;
        current = current->next;
    }
    cout << endl;
}

int Dictionary::readInFile(ifstream & wordFile)
{
    cout << "Reading file..." << endl;
    string newWord;
    int numberOfWordsRead=0;
    while( wordFile >> newWord )
    {   //make all charecters lowercase
        transform(newWord.begin(), newWord.end(), newWord.begin(), ::tolower);
        //if( this->insertWord(newWord) - this->numberOfNodes > 0 )
        {
            this->insertWord(newWord);
            ++numberOfWordsRead;
        }
    }
    cout << "Read" << numberOfWordsRead << endl;
    return numberOfWordsRead;
}


int Dictionary::insertWord(string newWord)
{
    node *newNode = new node;
    newNode->word = newWord;
    
    if(this->numberOfNodes==0)
    {
        this->head = newNode;
        this->tail = newNode;
        newNode->next = NULL;
    }
    else
    {
        node * nodeToInsertAfter = NULL;
        int positionInList = this->alphabeticalInsertPosition(newWord,
                                                              &nodeToInsertAfter);
        //if new first
        if(positionInList==1)
        {
            newNode->next = this->head;
            this->head = newNode;
        }//if new last:
        else if(positionInList==numberOfNodes+1)
        {
            this->tail->next = newNode;
            this->tail = newNode;
            newNode->next = NULL;
        }//if new somewhere in middle:
        else
        {
            newNode->next = nodeToInsertAfter->next;
            nodeToInsertAfter->next = newNode;
        }
    }
    
    return ++this->numberOfNodes;

}


/*  Gets the node * to the node the new word
    needs to be inserted after    
    And returns the position in the list at which
    it should be inserted.                                  */
int Dictionary::alphabeticalInsertPosition(string newWord,
                                           node ** nodeToInsertAfter)
{
    int nodesPassed = 0;
    node * current = this->head;
    //compare with first word:
    if(newWord < current->word)
    {
        //cout << newWord << " is before " << current->word << endl;
        *nodeToInsertAfter = NULL;
        return 1;//will be first node
    }
    else if(newWord >= current->word)
    {
        // cout << newWord << " is after " <<
        //current->word << endl;
        ++nodesPassed;
    }
    
    while( current->next != NULL)
    {
       
        //cout << "comparing " << newWord << " with " << current->next->word <<
        //endl;
        if(newWord < current->next->word)
        {
            /*cout << newWord << " is before " << current->next->word << endl <<
            endl;
            cout << "current->word is " << current->word <<
            " current->next->word is " << current->next->word << endl;
            cout << "number of nodes passed is " << nodesPassed << endl;
            cout << "number of nodes in list " << this->numberOfNodes << endl;
            cout << "inserting at position " << nodesPassed+1 << endl;*/
            *nodeToInsertAfter = current;
            return nodesPassed+1;
        }
        else if(newWord >= current->next->word)
        {
            //cout << newWord << " is after " <<
            //current->next->word << endl;
            current = current->next;
            ++nodesPassed;
        }
    }
    //gets to here then its last in the list:
    *nodeToInsertAfter = this->tail;
    return this->numberOfNodes+1;
}





