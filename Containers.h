/* ******************************************************* 
 * Filename		:	Containers.h
 * Author		:	Alihan BOZKIR		
 * Date			:	14.12.2022
 * Description	:	Containers Class Interface
 * ******************************************************/

// prevent multiple inclusions of header
#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <iostream>		
#include<algorithm>
#include<vector>
#include "Feature.h"		// include definition of class Feature						
#include "Read_Write.h"		// include definition of class Read_Write


using namespace std;

// Containers class definition
class Containers
{
	/// Friend functions
	
	
	
	public:
		/// Default Constructor	
		Containers();
		
		/// Set functions
		/// Set function for Test vector
		void setTest(vector < Feature > &);
		/// Set function for Training vector
		void setTraining(vector < Feature > &);
		
		/// Get functions
		/// Return Test vector that stores Feature class' objects
		vector<Feature> getTest(void) const;
		/// Return Training vector that stores Feature class' objects
		vector<Feature> getTraining(void)const;
		
		/// Create Test Data Set
		void createRandomTest(void);
		/// Create Training Data Set
		void createRandomTraining(void);
		
		/// Predicate function for generating Training Data Set
		static Feature genTra(void);
		/// Predicate function for generating Test Data Set
		static Feature genTest(void);
		
		/// Print Vector in Category: ID: Coordinate: (x,y) format
		void printVector(vector < Feature > ) const;
		
		/// Destructor
		~Containers();
		
	private:
		
		/// Data members
		/// Training vector that stores Feature class' objects
		vector < Feature > Training;
		/// Test vector that stores Feature class' objects
		vector < Feature > Test;
		/// To determine the Data sets 
		int randomOrClient;
		
};

#endif



