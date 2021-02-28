/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: tingyan
 * Modified: wingning
 *
 * Created on October 30, 2018, 1:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include "Linkedlist.h"

using namespace std;

/* 
 * detailed points allocation removed.
 * but if your program pass all the test cases here
 * you will get 70/80 points allocated for correctness, efficiecy, 
 * design, and testing.
 *
 */
int main(int argc, char** argv) {

    cout  << "1. *----Testing constructor and check function-----* \n";
    Linkedlist testList (4);
    testList.check();
    testList.rcheck();


    
   
    cout << "original link list intialization" << endl;
    list <int> ll;
    ll.push_front(0);
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    cout << "----------Check---------" << endl;
    for (list<int>::iterator i = ll.begin(); i != ll.end(); i++)
        cout << *i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
  
    
   

    //pushfront
    cout << endl;
    cout << "*---------Testing push front--------*" << endl;
    testList.push_front(7);
    cout << "after push front:" << endl;
    testList.check();
    testList.rcheck();
  


    ll.push_front(7);
    cout << "test-case push_front" << endl;
    for (list<int>::iterator i = ll.begin(); i != ll.end(); i++)
        cout << *i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    

    //pushback
    cout  << "3. ---Testing push back  -1 \n";
    cout << "before push back: " << endl;
    testList.check();
    cout << "afer push back:" << endl;
    testList.push_back(-1);
    testList.check();
    testList.rcheck();
    cout << "--------------------------------------\n\n" ;
    cout  << "test case--push back  -1 \n";
    ll.push_back(-1);
    for (list<int>::iterator i = ll.begin(); i != ll.end(); i++)
        cout << *i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;




    
    cout  << "4. ---Testing insert 5 at position 2  \n";
    cout << "before insert: " << endl;
    testList.check();
    testList.insert(2, 5);
    cout << "after insert: " << endl;
    testList.check();
    testList.rcheck();
    cout << "--------------------------------------\n\n" ;



    cout << "test-case:insert" << endl;
    list<int>::iterator it;
    it = ll.begin();
    advance (it,1);
   
    ll.insert(it, 5);
    for (list<int>::iterator i = ll.begin(); i != ll.end(); i++)
        cout << *i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;


    cout << "----Testing pop front------" << endl;
    cout << "before pop front" << endl;
    testList.check();
    cout << "after pop front" << endl;
    testList.pop_front();
    testList.check();
    testList.rcheck();
   

    cout << "pop front test comparision" << endl;
    ll.pop_front();
    for (list<int>::iterator i = ll.begin(); i != ll.end(); i++)
        cout << *i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;


    cout << "----Testing pop back------" << endl;
    cout << "before pop back" << endl;
    testList.check();
    cout << "after pop back" << endl;
    testList.pop_back();
    testList.check();
    testList.rcheck();
   

    cout << "pop back test comparision" << endl;
    ll.pop_back();
    for (list<int>::iterator i = ll.begin(); i != ll.end(); i++)
        cout << *i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;


    
    cout  << "5. ---Testing front  \n";
    cout << testList.front() << endl;
    testList.front() = 1234;
    cout << testList.front() << endl;
    testList.check();
    testList.rcheck();



    cout << "--------------------------------------\n\n" ;
     cout  << "Test--case front () \n";
     cout << ll.front() << endl;
     ll.front() = 1234;
     cout << ll.front() << endl;
     for (list<int>::iterator i = ll.begin(); i != ll.end(); i++)
        cout << *i << " ";
    cout << endl;

    cout << "----------------------------------------------------------------------------------------" << endl;





    
    cout  << "6. ---Testing back  \n";
    cout << testList.back() << endl;
    testList.back()  = 5678;
    cout << testList.back() << endl;
    testList.check();
    testList.rcheck();


    cout << "--------------------------------------\n\n" ;
    cout  << "---Test case-back()--- \n";
    cout << ll.back() << endl;
    ll.back() = 5678;
    cout << ll.back() << endl;
    for (list<int>::iterator i = ll.begin(); i != ll.end(); i++)
        cout << *i << " ";
    cout << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;




    cout  << "7. ---Testing sort  \n";
    cout << "before sort: " << endl;
    testList.check();
    testList.sort();
    cout << "after sort: " << endl;
    testList.check();
    testList.rcheck();
    cout << "--------------------------------------\n\n" ;
    cout << "test-case sort()" << endl;
    ll.sort();
    for (list<int>::iterator i = ll.begin(); i != ll.end(); i++)
        cout << *i << " ";
     cout << endl;


    

    cout << "testing erase" << endl;
    cout << "before erase" << endl;
    testList.check();
    testList.rcheck();

    cout << "after erase" << endl;
    testList.erase(2);
    
    testList.check();
    
    testList.rcheck();
    cout << "--------------------------------------\n\n" ;

    cout << "case where pos is equal to one" << endl;
    testList.erase(1);
    testList.check();
    

    cout << "case where the pos is equal to the last node" << endl;
    testList.erase(3);
    testList.check();
    testList.rcheck();
    

    cout << "case where the pos greater than the size" << endl;
    testList.erase(3);
    testList.check();


    
    cout << " 8----Testing bool empty----- \n";
    if (testList.empty() == true)
        cout << "empty returns true and the list is empty" << endl;
    else
    {
        cout << "empty returns false and list is not empty" << endl;
    }

    cout << "9----Testing clear ----\n";
    testList.clear();
    if (testList.empty() == true)
        cout << "empty returns true and the list is empty" << endl;
    else
    {
        cout << "empty returns false and list is not empty" << endl;
    }
    

     //Operator overload
    cout << "Testing operator overload" << endl;
    cout << "before operation:" << endl;
    testList.check();
    testList.rcheck();

    Linkedlist testList_2 (3);
    cout << "testList" << endl;
    int node = 3;
    for (int i = 0; i<node; i++)
        testList_2.push_back(i);
    testList_2.check();
    
    testList = testList_2;
    cout << "after operation: " << endl;
    testList.check();
    testList.rcheck();
   
   return 0;
} 