/* ******************************************************* 
 * Filename		:	Read_Write.h
 * Author		:	Alihan BOZKIR		
 * Date			:	14.12.2022
 * Description	:	Read_Write Class Interface
 * ******************************************************/
 
#ifndef READ_WRITE_H
#define READ_WRITE_H

#include<iostream>
#include<algorithm>
#include<vector>

#include "Feature.h"

using namespace std;

class Read_Write
{
	public:
		/// Default Constructor 
		Read_Write();
		/// Default Destructor 
		~Read_Write();
		
		/// Training functions
		/// Read file function for Training data sets
		void readFromFile_Training(void);
		/// Write file function for Training data sets
		void writeToFile_Training(void);
		
		/// Test functions
		/// Read file function for Test data sets
		void readFromFile_Test(void);
		/// Write file function for Test data sets
		void writeToFile_Test(void);
		
		/// Get functions
		/// Return Test vector that stores Feature class' objects
		vector<Feature> getTest(void) const;
		/// Return Training vector that stores Feature class' objects
		vector<Feature> getTraining(void)const;
		
	private:
		
		/// Data members
		/// Training vector that stores Feature class' objects
		vector < Feature > Training;
		/// Test vector that stores Feature class' objects
		vector < Feature > Test;
		
		
};

#endif



