/* ******************************************************* 
 * Filename		:	KNN.h
 * Author		:	Alihan BOZKIR		
 * Date			:	14.12.2022
 * Description	:	KNN Class Interface
 * ******************************************************/
 
// prevent multiple inclusions of header
#ifndef KNN_H
#define KNN_H

#include<iostream>
#include<algorithm>
#include<vector>

#include "Containers.h"	// include definition of class Containers

#define SIZE 30				// Defining SIZE
using namespace std;

///Data Structure to hold 2 data members which takes the category and euclidean distance parameters of each index.
struct Data {
  		int Categories;			
  		double Cal_Distance;	
	};
		
class KNN
{
	
	/// Overloaded ouput stream for the Data structure
	friend ostream &operator<<(ostream &,const Data &);

	
	
	public:
		
		/// Default Constructor 
		KNN();
		
		
		/// Set functions
		/// Set k value
		void setK(int);
		/// Set Containers object
		void setContainers(Containers);
		/// Get functions
		/// Return Containers
		Containers getContainers(void)const;
		/// Return K value
		int getK(void)const;
		/// Return the catDistance vector which holds the category and euclidean distance parameters of each index
		vector<Data> getCatDistance(void) const;
		
		/// Print functions
		/// Print function to print the Vector in Category: ID: Coordinate: (x,y) format
		void print(vector <Data> &)const ;
		/// Print function to print the map after KNN algorithm
		void afterKnnPrint(void) const;
		
		/// Destructor
		~KNN();
		
		/// Predicate sort function for the vector that stores data structures.		
		static bool lessThan(const Data& , const Data&);
		
		
		
	private:
		
		/// Data members
		/// catDistance vector that stores the category and euclidean distance parameters
		vector<Data> catDistance;
		/// k parameter that stores the K value
		int k;
		/// Containers object 
		Containers v_test_train; 
		
		/// Utility functions
		/// initiate function is the main function to run the whole algorithm
		void initiate() ;
		/// euclideanDistance function calculates and returns the Euclidean distance between the Test and training data
		double euclideanDistance(const Feature &,const Feature &);
		/// classify function takes the sorted catDistance vector and decide which category will be set into the test vectors' indexes
		void classify(vector <Data> &);
		/// determine K function takes the K value from the client
		int determineK(void);
		
};

#endif


