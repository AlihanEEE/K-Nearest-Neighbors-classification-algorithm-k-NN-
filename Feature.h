/* ******************************************************* 
 * Filename		:	Feature.h
 * Author		:	Alihan BOZKIR		
 * Date			:	14.12.2022
 * Description	:	Feature Class Interface
 * ******************************************************/

// prevent multiple inclusions of header
#ifndef FEATURE_H
#define FEATURE_H

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Feature class definition
class Feature
{
	/// Overloaded ouput stream for the Feature class' object
	friend ostream &operator<<(ostream &,const Feature &);
	
	public:
		/// Default Constructor	
		Feature(int=0,int=0);
		
		/// Set functions
		/// Set x coordinate of the sample
		void setX(double);
		/// Set y coordinate of the sample
		void setY(double);
		/// Set category of the sample
		void setCat(int);
		/// Set ID of the sample
		void setId(int);
		
		/// Get functions
		/// Return x coordinate of the sample 		
		double getX(void) const;
		/// Return y coordinate of the sample 
		double getY(void) const;
		/// Return category of the sample
		double getCat(void) const;
		/// Return ID of the sample 
		double getId(void) const;	
		
		/// Destructor
		~Feature();
		
		
	private:
		/// Data members
		/// Store category of the sample
		int cat;
		/// Store ID of the sample
		int id;
		/// Store x coordinate of the sample
		double x;
		/// Store y coordinate of the sample 
		double y; 
		
		/// Utility functions
		/// Generate random x and y coordinate between -5 to 5
		double random(void) const;
		
};

#endif


