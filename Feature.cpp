/* ******************************************************* 
 * Filename		:	Feature.cpp
 * Author		:	Alihan BOZKIR		
 * Date			:	14.12.2022
 * Description	:	Feature Class Implementation
 * ******************************************************/
 
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>  
#include<algorithm>
#include<vector>

#include "Feature.h"
using namespace std;



/// Overloaded ouput stream for the Feature class' object
ostream &operator<<(ostream &output,const Feature &obj)
{
	// the output format is: " Category: ID: Coordinate: (x,y) ".
    output << " Data[ " << obj.getId()<<" ]" << "\tCat:" << obj.getCat() << "\tFeature X and Y: (" << obj.getX() << "," << obj.getY() << ")"; 
    return output;
}

/// Default Constructor	
Feature::Feature(int cat, int id) 
	// Member initalizer list 
	:id(id),
	cat(cat)
{
	
	setX(random());				// Generating random x coordinate
	setY(random());				// Generating random y coordinate
	
	
}

// Set utility funtions

/// Set x coordinate of the sample
void Feature::setX(double X){
	x = X;
}

/// Set y coordinate of the sample
void Feature::setY(double Y){
	y = Y;
}

/// Set category of the sample
void Feature::setCat(int c){
	cat=c;
}

/// Set ID of the sample
void Feature::setId(int d){
	id=d;
}

		

//Get utility functions		

/// Return x coordinate of the sample 
double Feature::getX(void) const{
	return x;
}

/// Return y coordinate of the sample 
double  Feature::getY(void) const{
	return y;
}

/// Return y coordinate of the sample 
double Feature::getCat(void) const{
	return cat;
}

/// Return ID of the sample 
double Feature::getId(void) const{
	return id;
}
	
/// Generate random x and y coordinate between -5 to 5
double Feature::random(void) const{
	
	double tempRandom;
	tempRandom= double((double(rand()%101)/10)-5);
    return tempRandom; 
}

/// Destructor
Feature::~Feature(){
}





