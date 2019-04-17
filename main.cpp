//
//  main.cpp
//  recordsAssignmentOne
//
//  Created by Pierce Findlay on 2/7/19.
//  Copyright © 2019 Pierce Findlay. All rights reserved.
//  Pierce Findlay
//  Section 2

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <cstring>
using namespace std;

struct  PERSON
{
    char  Name[20];
    float Balance;
};

void Display(PERSON arrPtr[], int N);
void FindRichest(PERSON arrPtr[], int N);
void NewCopy(string inData, PERSON arrPtr[], int N);
void Deposit(string customer, PERSON arrPtr[], int N);
int Counter(string file);
PERSON * readData(int N);

int main()
{
    string customer = "";
    int N =  Counter("data.txt");
    
    PERSON * arrPtr = readData(N);
    
    int choice;
    bool programOn = true;
    
    
    while (programOn != false)  
    {
        cout << "\n";
        cout << "*******************************\n";
        cout << " 1 - Display All Records\n";
        cout << " 2 - Find Richest\n";
        cout << " 3 - Deposit\n";
        cout << " 4 - Exit.\n";
        cout << " Enter your choice and press return: ";
        
        cin >> choice;
        
        
        switch (choice)
        {
            case 1:
                cout << "\n";
                cout << "Name        Balance\n";
                cout << "-----------------------\n";
                
                Display(arrPtr, N);
                
                break;
            case 2:
                cout << "\n";
                cout << "The customer with maximum balance is: " ;
                FindRichest(arrPtr, N);
                break;
            case 3:
                
                cout << "Enter your full name to deposit money: ";
                cin.ignore();
                getline(cin, customer);
                Deposit(customer, arrPtr, N);
                
                break;
            case 4:
                cout << "End of Program. Have a nice day!\n";
                programOn = false;
                break;
            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin >> choice;
                break;
        }
        
    }
    delete [] arrPtr;
    return 0;
}

void Display(PERSON arrPtr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << arrPtr[i].Name << " " << fixed << setprecision(2) << arrPtr[i].Balance << endl;
    }
    cout << endl;
}

void NewCopy(string inData, PERSON arrPtr[], int N)
{
    ofstream writeData;
    writeData.open(inData);
    
    for (int i = 0; i < N; i++)
    {
        writeData << arrPtr[i].Name << " " << fixed << setprecision(2) << arrPtr[i].Balance << endl;
    }
    writeData.close();
}

void FindRichest(PERSON arrPtr[], int N)
{
    int slotrichest = 0;
    
    for (int i = 1; i < N; i++)
    {
        if (arrPtr[slotrichest].Balance < arrPtr[i].Balance)
        {
            slotrichest = i;
        }
    }
    cout << arrPtr[slotrichest].Name << endl;
}


void Deposit(string customer, PERSON arrPtr[], int N)
{
    float deposit = 0.00;
    cout << customer << ", how much would you like to deposit? ";
    cin >> deposit;
    for (int i = 0; i < N; i++)
    {
        if (customer == arrPtr[i].Name)
        {
            arrPtr[i].Balance += deposit;
            cout << "Now your new balance is " << fixed << setprecision(2) << arrPtr[i].Balance << endl;
            NewCopy("data.txt", arrPtr, N);
        }
    }
}

int Counter(string file)
{
    int N = 0;
    string readLine;
    ifstream readData2;
    readData2.open(file);
    while(readData2)
    {
        getline(readData2, readLine);
        N++;
    }
    N--;
    readData2.close();
    return N-1;
}


PERSON * readData(int N)
{
    PERSON *arr = new PERSON[N];
    PERSON obj;
    string fname, lname, name;
    ifstream inData;
    inData.open("data.txt");
    
    for (int i = 0; i < N; i++)
    {
        inData >> fname;
        inData >> lname;
        inData >> obj.Balance;
        name = fname + " " + lname;
        strcpy(obj.Name, name.c_str());
        arr[i] = obj;
    }
    inData.close();
    
    return arr;
}
