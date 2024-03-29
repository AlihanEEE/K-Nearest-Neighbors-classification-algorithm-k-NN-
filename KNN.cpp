/* ******************************************************* 
 * Filename		:	KNN.cpp
 * Author		:	Alihan BOZKIR		
 * Date			:	14.12.2022
 * Description	:	KNN Class Implementation
 * ******************************************************/


#include<iostream>
#include<algorithm>
#include<vector>
#include <math.h>

#include "KNN.h"			// include definition of class KNN


using namespace std;

/// Overloaded ouput stream for the Data structure
ostream &operator<<(ostream &output,const Data &temp)
{
	// The output format is: " (category , euclidean distance ) ".
    output<< "("<< temp.Categories << ", " << temp.Cal_Distance << ")  "; 
    return output;
}


/// Default Constructor 
KNN::KNN()	
{
	cout<<endl<<"KNN Constructor"<<endl;		// Display message for the Constructor
	
	initiate();									// Running the whole KNN algorithm
}

/// Set k value
void KNN::setK(int K){
	k=K;					// The k value assigns
}

/// Set Containers object
void KNN::setContainers(Containers obj){
	v_test_train = obj;
}

Containers KNN::getContainers(void) const{
	return v_test_train;
}
/// Return K value
int KNN::getK(void)const{
	return k;				// The k value returns
}


/// Return the catDistance vector which holds the category and euclidean distance parameters of each index
vector<Data> KNN::getCatDistance() const{
	return catDistance;		// The catDistance Data Set returns
}


/// Print function to print the Vector in Category: ID: Coordinate: (x,y) format		
void KNN::print(vector <Data> &distance) const{
	
	vector<Data>::iterator it = distance.begin();		// Creating an iterator that points the begining of the vector
	int i =1;											// Local variable for division with remainder
    		for (it;it!=distance.end();it++)
    		{
        		cout <<"["<<i-1<<"]: "<< *it <<"  ";	// the output format is: " [ID]: (category,euclidean distance) ".
        		if(i%5==0)cout<<endl;					// Skip to the next line every 5 iterations
        		i++;	
    		}
    		
    		cout<<endl<<endl;
}

/// Print function to print the map after KNN algorithm
void KNN::afterKnnPrint() const{
	// Generating two temporary vectors to hold test and training data sets
	
	// Display mechanism
	cout<<"After KNN the map shapes like:"<<endl<<endl;
	cout<<"<öööööööööööööööööööö Training öööööööööööööööööööö>" <<endl;
	v_test_train.printVector(v_test_train.getTraining());								// Displays training data set
	cout<<"<öööööööööööööööööööö Test öööööööööööööööööööö>" <<endl;
	v_test_train.printVector(v_test_train.getTest());									// Displays test data set
}

/// Predicate sort function for the vector that stores data structures.
bool KNN::lessThan(const Data& a, const Data& b) {
  return (a.Cal_Distance < b.Cal_Distance); 	// it sorts in order from smallest to largest
}

/// This function is the main function to run the whole KNN algorithm
void KNN::initiate() {
	
	
	double Distance;											// local Distance variable that stores the calculated euclidean distance value
	int cat;													// local cat variable that stores the category in training data sets' category values
	vector<Data> tempCatDistance= getCatDistance();				// Temporary vector for the catDistance vector
	
	setK(determineK());											// The client is asked which k value to choose and this value is assigned into k.
	
	for (int i=0;i<10;i++){										// The loop for the test vectors' indexes
		cout<<"For the Test "<<i+1<<":"<<endl<<endl;					
		tempCatDistance.clear();								// Clearing proccess for the next datas
		for(int j=0;j<30;j++){									// The loop for the training vectors' indexes
			
			Distance = euclideanDistance((v_test_train.getTest())[i],(v_test_train.getTraining())[j]);	// By calling the euclideanDistance function, it calculates and returns the euclidean distance value and assigns it to the Distance variable.
			cat=(v_test_train.getTraining())[j].getCat();							// Storing the categories of the training vectors	
			tempCatDistance.push_back((Data){cat,Distance});	// A Data structure is created together with the calculated euclidean distance value and the category value. And this Data structure is stored in the tempCatDistance vector.

		}

    	sort(tempCatDistance.begin(), tempCatDistance.end(), lessThan);		// STL sort algorithm sorts the data structure in order to euclidean distance values
    	
    	print(tempCatDistance);												// Display the sorted data set
    	
    	classify(tempCatDistance);											// Passing the tempCatDistance vector to the 'classify' function									
    	
		cout<<endl<<"----------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	}
}

/// euclideanDistance function calculates and returns the Euclidean distance between the Test and training data		
double KNN::euclideanDistance(const Feature &Test,const Feature &Training){
	// Generating temporary variables to store x and y values of Test and Training data sets
	double test_Y=Test.getY();
	double test_X=Test.getX();
	double train_Y=Training.getY();
	double train_X=Training.getX();
	
	
	double eucDist= sqrt(pow((test_Y-train_Y),2)+pow((test_X-train_X),2)); 	// euclidean distance calculating algorithm

	return eucDist;															// The euclidean distance value returns
}

/// classify function takes the sorted catDistance vector and decide which category will be set into the test vectors' indexes
void KNN::classify(vector <Data> &sorted){
	static int index=0;			// index is statically defined to preserve the index and initalized to 0 
	
	int temp_cat; 				// temporary category varible to store data structures' categories
	int cat[]={0,0,0}; 			// cat array to count categories
	int random;					// random local variable to store random category numbers where needed
	
	// According to the k value, the first k categories are stored in this Loop.

	for(int i=0;i<k;i++){
	 	temp_cat=(sorted[i].Categories);	// store data structures' categories into temp_cat
	 	
	 	if(temp_cat==0)			cat[0]++;	//	counting category 0
	 	else if(temp_cat==1)	cat[1]++;	//	counting category 1
	 	else if(temp_cat==2)	cat[2]++;	//	counting category 2
	}
	
	// Display information message
	cout<<"k="<<getK()<<" "<<endl
	<<"Category 0: "<<cat[0]<<"\tCategory 1: "
	<<cat[1]<<"\tCategory 2: "<<cat[2]<<endl<<endl;
	
	
	//test[index].setCat(0);			// Sets the category to the indexes of the test data					
	int max = cat[0];
	int maxIndex = 0;
	
	// Find the index of the maximum category
	for (int l = 0; l < 3; l++) {
	  if (cat[l] > max) {
	    max = cat[l];
	    maxIndex = l;
	  }
	}
	
	vector <Feature> TempTest=v_test_train.getTest(); //Generating temporary vector to manipulate original test data vector
	
	// Set the category of the test to the index of the maximum category
	TempTest[index].setCat(maxIndex);
	
	// If there are multiple categories with the maximum count, randomly select one of those categories
	if (cat[maxIndex] == cat[(maxIndex + 1) % 3] && cat[(maxIndex + 1) % 3] == cat[(maxIndex + 2) % 3 ])  {
	  	random = rand() %3;
	 	TempTest[index].setCat(random);
	}
	// If cat 0 and cat 1 OR cat 1 and cat 2 are the maximum categories it classify the category randomly 0 or 1 OR 1 or 2
	else if (cat[maxIndex] == cat[(maxIndex + 1) % 3 ] )  {
	random = rand() % 3;
  		while (random == ((maxIndex + 2) % 3) ) {
    		random = rand() % 3;
		}
		TempTest[index].setCat(random);
	}
	// If cat 0 and cat 2 are the maximum categories it classify the category randomly 0 or 2
	else if (cat[maxIndex] == cat[(maxIndex + 2) % 3 ]  ){
	  	random = rand() % 3;
	  	while (random == (maxIndex +1)%3) {
	    	random = rand() % 3;
	  	}
	  	TempTest[index].setCat(random);
	}


	v_test_train.setTest(TempTest); 					// set original test vector
	v_test_train.printVector(v_test_train.getTest()); 	// displaying original test vector
	index++;											// increase the index to move to the next index for the next iteration.
	
}

/// determineK function takes the K value from the client
int KNN::determineK(void){
	
	int local_K;
	cout<<"\nPlease determine the K value in the range of [1,30]. Only integer values allowed:";	// Information message
	cin>>local_K;																					// Requests the value of k from the user.
	
	// Exception handling mechanism
	while(1){
		if(local_K>=1 && local_K<=30)																// Checks that the k value in the range of [1,30] 
		break;
		
		else{
			cout<<"Invalid value of K, Please re-enter the K in the range of [1,30]: ";				// Exceptional warning message
			cin>>local_K;																			// Requests the value of k from the user.
		}
	}
}

/// Destructor
KNN::~KNN(){
	cout<<endl<<"KNN Destructor"<<endl;				// Display message for the Destructor 
}



