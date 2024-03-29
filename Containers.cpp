/* ******************************************************* 
 * Filename		:	Containers.cpp
 * Author		:	Alihan BOZKIR		
 * Date			:	14.12.2022
 * Description	:	Containers Class Implementation
 * ******************************************************/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>

#include "Containers.h"			// include definition of class Containers 	



using namespace std;

/// Predicate function for generating Training Data Set
Feature Containers::genTra(void){
	
    static int id=0;						// id is statically defined to preserve the index and initalized to 0 
    int category;							// category to pass into Feature class
    
    if (id>=0 &&id<10)        category=0;   // Set the category to 0 for the first 10 element
    else if (id>=10 && id<20) category=1;  	// Set the category to 1 for the second 10 element
    else if (id>=20 && id<30) category=2;	// Set the category to 2 for the last 10 element
        
    Feature temp(category,id);				// Temporary Feature class' object for storing into vector
      id++;									// Increment the index

    return temp; 							// Return the temp object
}

/// Predicate function for generating Test Data Set
Feature Containers::genTest(void){
	
    static int id=30;						// id is statically defined to preserve the index and initalized to 30
    int category=-1;						// category to pass into Feature class and initialized to -1 which means unknown category

    Feature temp(category,id);				// Temporary Feature class' object for storing into vector
      id++;									// Increment the index

    return temp; 							// Return the temp object
}

/// Default Constructor
Containers::Containers(){
	srand(time(NULL));									// Initializes the random number generator.
	
	
	
	cout<<"For random data set, enter     --->  1"<<endl;
	cout<<"to specify the dataset, enter  --->  2"<<endl;
	cin>>randomOrClient;
	
	if(randomOrClient==1){
		// Set function of the Training vector
		createRandomTraining();							
	    
		// Set function of the Test vector
	    createRandomTest();
	   
   	}
   	
   	else if(randomOrClient==2){
   		
   		Read_Write readWrite;
   		
   		Test=readWrite.getTest();
   		Training=readWrite.getTraining();
   	
	}
	
	else throw invalid_argument("You have entered invalid value!");
    
    cout<<endl<<"Containers Constructor"<<endl;			// Display message for the Constructor
    
}

/// set Test Data Set
void Containers::setTest(vector < Feature > &v){
	
	Test=v;
}

/// Set Training Data Set
void Containers::setTraining(vector < Feature > &v){
	
	Training=v;						
    
}

/// Create Test Data Set
void Containers::createRandomTest(void){
	
	Test.resize(10); 									// Defining the size of Test vector
    generate(Test.begin(),Test.end(), genTest);			// Generating the Test vector by using generate algorithm
    
    cout<<"<öööööööööööööööööööö Test öööööööööööööööööööö>" <<endl;
    printVector(Test);									// Display the Test vector
}

/// Create Training Data Set
void Containers::createRandomTraining(void){
	
	Training.resize(30);								// Defining the size of Training vector	
    generate(Training.begin(),Training.end(), genTra);  // Generating the Training vector by using generate algorithm
    
    cout<<"<öööööööööööööööööööö Training öööööööööööööööööööö>" <<endl;
    printVector(Training);								// Display the Test Training
    
}

/// Return Test vector that stores Feature class' objects
vector<Feature> Containers::getTest(void) const{
	return Test;
}

/// Return Training vector that stores Feature class' objects
vector<Feature> Containers::getTraining(void)const{
	return Training;
}

/// Print Vector in Category: ID: Coordinate: (x,y) format
void Containers::printVector(vector<Feature> v)const{
	
	vector<Feature>::iterator it = v.begin();			// Creating an iterator that points the begining of the vector
	
	
    for (it;it!=v.end();it++){	
        cout<< *it <<endl;								// Loop for printing the element of vectors
    }
    
}

/// Destructor
Containers::~Containers(){
	cout<<endl<<"Containers Destructor"<<endl;			// Display message for the Destructor 
}






