/* ******************************************************* 
 * Filename		:	Graphic.h
 * Author		:	Alihan BOZKIR		
 * Date			:	14.12.2022
 * Description	:	Graphic Class Interface
 * ******************************************************/

#ifndef GRAPHIC_H
#define GRAPHIC_H
#include "Feature.h"

#include<iostream>
#include<algorithm>
#include<vector>

#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUMBER_TRAIN_SAMPLES = 30;
const int NUMBER_TEST_SAMPLES = 10;
const int NUM_CATEGORIES = 3;
const int MIN_COORDINATE = -5;
const int MAX_COORDINATE = 5;


class Graphic {
public:
	/// Default Constructor 
    Graphic( vector<Feature> , vector<Feature> );
	/// Default Destructor 
	~Graphic();
	
	/// Set Functions
	/// Set Test Data function
	void setTestData(vector<Feature> &);
	/// Set Training Data function
	void setTrainData(vector<Feature> &);
    
    /// Get Functions
    /// Get Test Data function
    vector<Feature> getTestData(void)const;
    /// Get Training Data function
    vector<Feature> getTrainData(void)const;
    
    /// Graph functions
    /// The function that drawing the axes on the screen
    void drawAxes(int left, int top, int right, int bottom);
    /// The function that drawing the coordinate number intervals on the screen
    void drawTicks(int left, int top, int right, int bottom);
    /// The function that drawing the coordinate numbers on the screen
    void drawNumbers(int left, int top, int right, int bottom);
    /// The function that drawing the grids on the screen
    void drawGrid(int left, int top, int right, int bottom);
    /// The function that drawing the Train data sets on the screen
    void drawSamplesTrain(vector<Feature> &, int numSamples, int left, int top, int right, int bottom);
    /// The function that drawing the Test data sets on the screen
    void drawSamplesTest(vector<Feature> &, int numSamples, int left, int top, int right, int bottom);
    /// The function that runs the whole algorithm
    void initiate(void);
    
    
    private:
    	/// Data members
    	/// Test vector data member
    	vector<Feature> Test;
    	/// Training vector data member
    	vector<Feature> Train;
};


#endif



