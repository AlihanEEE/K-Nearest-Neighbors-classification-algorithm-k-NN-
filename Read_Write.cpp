/* ******************************************************* 
 * Filename		:	Read_Write.cpp
 * Author		:	Alihan BOZKIR		
 * Date			:	14.12.2022
 * Description	:	Read_Write Class Implementation
 * ******************************************************/

#include "Read_Write.h"
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <cstdlib> // for exit function
#include <stdexcept>

#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

// This program reads values from the file 'example.dat'
// and echoes them to the display until a negative value
// is read.


Read_Write::Read_Write()
{
	writeToFile_Training();
   	writeToFile_Test();
   		
   	readFromFile_Test();
   	readFromFile_Training();
}

Read_Write::~Read_Write()
{
}


void Read_Write::readFromFile_Training(void){
	
	
	ifstream indata; // indata is like cin
   	double num; // variable for input value
   	double number[3] = {0.0,0.0,0.0};
	
	indata.open("Train_From_Client.dat"); // opens the file
   	if(!indata) { // file couldn't be opened
      	cerr << "Error: file could not be opened" << endl;
      	exit(1);
   	}
   
   	Training.resize(30);
  		
	
	
   	for(int i=0; i<30; i++){
    	if (indata >> num) {
        	number[0] = num;
            if (indata >> num) {
                number[1] = num;
                if (indata >> num) {
                    number[2] = num;
                }
                else {
                    cerr << "Error: Could not read value from file" << endl;
                    break;
                }
            }
            else {
                cerr << "Error: Could not read value from file" << endl;
                break;
            }
        }
        else {
            cerr << "Error: Could not read value from file" << endl;
            break;
        }
        Training[i].setCat(number[0]);
        Training[i].setId(i);
        Training[i].setX(number[1]);
        Training[i].setY(number[2]);
    }
   indata.close();
   
   
}

void Read_Write::writeToFile_Training(void){
	
	ofstream outdata; // outdata is like cin
    int i; // loop index
   	double num[90] = {0.0};
   	
   	
   	outdata.open("Train_From_Client.dat"); // opens the file
    if( !outdata ) { // file couldn't be opened
      	cerr << "Error: file could not be opened" << endl;
      	exit(1);
  	}
  	
  	
  	cout<<"Please enter the 30 sample Training data in the following order"<<endl;
    cout<<"1.Category:    2-3.Coordinates: (X,Y)"<<endl; 
    
    for(int i=0;i<90;i++){
			cin>>num[i];
			if(i%3==0){
				if(num[i]!=0 && num[i]!=1 && num[i]!=2)
				throw invalid_argument("You've entered invalid value inputs should be 0, 1 or 2'!");
			}
			else if(num[i]>5 ||num[i]<-5)
    		throw invalid_argument("You've entered invalid value inputs should be in the range of -5 , 5'!");
	}
	
    for(int j=0;j<90;j++){
    	outdata <<num[j]<<endl;
	}
	
    // list of output values

   	outdata.close();
 	
}

void Read_Write::readFromFile_Test(void){
	
	
	ifstream indata; // indata is like cin
   	double num; // variable for input value
   	double number[2] = {0.0,0.0};
	indata.open("Test_From_Client.dat"); // opens the file
   	if(!indata) { // file couldn't be opened
      	cerr << "Error: file could not be opened" << endl;
      	exit(1);
   	}
   	cout << "1" << endl;
   
   	Test.resize(10);
  	
  	
   	for(int i=0; i<10; i++){
        if (indata >> num) {
            number[0] = num;
            if (indata >> num) {
                number[1] = num;
                
                }
                else {
                    cerr << "Error: Could not read value from file" << endl;
                    break;
                }
            }
            else {
                cerr << "Error: Could not read value from file" << endl;
                break;
            }
        

        Test[i].setCat(-1);
        Test[i].setId(i+30);
        Test[i].setX(number[0]);
        Test[i].setY(number[1]);
    }
    
   indata.close();
   
   
}

void Read_Write::writeToFile_Test(void){
	
	ofstream outdata; // outdata is like cin
    int i; // loop index
   	double num[20] = {0.0};
   	
   	outdata.open("Test_From_Client.dat"); // opens the file
    if( !outdata ) { // file couldn't be opened
      	cerr << "Error: file could not be opened" << endl;
      	exit(1);
  	}
  	
  	
  	
	cout<<"Please enter the 10 sample Test data in the following order"<<endl;
	cout<<"Coordinates: (X,Y)"<<endl;
	  
	for(int i=0;i<20;i++){
    	cin>>num[i];
    	if(num[i]>5 ||num[i]<-5)
    		throw invalid_argument("You've entered invalid value inputs should be in the range of -5 , 5'!");
	}
    for(int j=0;j<20;j++){
    	outdata <<num[j]<<endl;
	}
	
    // list of output values

   	outdata.close();
 	
}

/// Return Test vector that stores Feature class' objects
vector<Feature> Read_Write::getTest(void) const{
	return Test;
}

/// Return Training vector that stores Feature class' objects
vector<Feature> Read_Write::getTraining(void)const{
	return Training;
}



