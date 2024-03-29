/* ******************************************************* 
 * Filename		:	Graphic.cpp
 * Author		:	Alihan BOZKIR		
 * Date			:	14.12.2022
 * Description	:	Graphic Class Implementation
 * ******************************************************/

#include "Graphic.h"


#include<iostream>
#include<algorithm>
#include<vector>

#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;



Graphic::Graphic( vector<Feature> test, vector<Feature> training)
{
	cout<<endl<<"Graphic Constructor"<<endl;
	
	setTestData(test);
	setTrainData(training);
	initiate();	
}

Graphic::~Graphic()
{
	cout<<endl<<"Graphic Destructor"<<endl;
}

void Graphic::setTestData(vector<Feature> &data)
{
	Test=data;
}
void Graphic::setTrainData(vector<Feature> &data)
{
	Train=data;
}
    
vector<Feature> Graphic::getTestData(void)const{
	return Test;
}

vector<Feature> Graphic::getTrainData(void)const{
	return Train;
}
    
void Graphic::drawAxes(int left, int top, int right, int bottom) 
{
    // draw x-axis
    line(left, (top+bottom)/2, right, (top+bottom)/2);
    // draw y-axis
    line((left+right)/2, top, (left+right)/2, bottom);
}

void Graphic::drawTicks(int left, int top, int right, int bottom) 
{
    // draw x-axis ticks
    int xInterval = (right - left) / 10;
    for (int i = 1; i < 10; i++) {
        int x = left + i * xInterval;
        line(x, (top+bottom)/2 - 5, x, (top+bottom)/2 + 5);
    }

    // draw y-axis ticks
    int yInterval = (bottom - top) / 10;
    for (int i = 1; i < 10; i++) {
        int y = top + i * yInterval;
        line((left+right)/2 - 5, y, (left+right)/2 + 5, y);
    }
}

void Graphic::drawNumbers(int left, int top, int right, int bottom) 
{
    // draw x-axis numbers
    int xInterval = (right - left) / 10;
    for (int i = 0; i <= 10; i++) {
        int x = left + i * xInterval;
        int number = i - 5;
        char text[10];
        sprintf(text, "%d", number);
        outtextxy(x - 5, (top+bottom)/2 + 15, text);
    }

    // draw y-axis numbers
    int yInterval = (bottom - top) / 10;
    for (int i = 0; i <= 10; i++) {
        int y = top + i * yInterval;
        int number = 5 - i;
        char text[10];
        sprintf(text, "%d", number);
        outtextxy((left+right)/2 + 15, y - 5, text);
    }
}

void Graphic::drawGrid(int left, int top, int right, int bottom) 
{
	
	setcolor(8);
	setlinestyle(DASHED_LINE, 0, 1);
    // draw vertical lines
    int xInterval = (right - left) / 10;
    for (int i = 1; i < 10; i++) {
    	if(i==5)continue;
        int x = left + i * xInterval;
        line(x, top, x, bottom);
    }

    // draw horizontal lines
    int yInterval = (bottom - top) / 10;
    for (int i = 1; i < 10; i++) {
    	if(i==5)continue;
        int y = top + i * yInterval;
        line(left, y, right, y);
    }
    
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
}

void Graphic::drawSamplesTrain(vector<Feature> &samples, int numSamples, int left, int top, int right, int bottom) 
{
    for (int i = 0; i < numSamples; i++) {
        double x = samples[i].getX();
        double y = samples[i].getY();
        int category = samples[i].getCat();
        // map x-coordinate to screen coordinate
        int screenX = (x - MIN_COORDINATE) * (getmaxx() - left) / (MAX_COORDINATE - MIN_COORDINATE) + left;
        // map y-coordinate to screen coordinate
        int screenY = (y - MIN_COORDINATE) * (getmaxy() - top) / (MAX_COORDINATE - MIN_COORDINATE) + top;
        // set color based on category
        if(category== 0) setcolor(2); 		// category 0 = blue
		else if(category== 1) setcolor(1);	// category 1 = green
		else if(category== 2) setcolor(4);	// category 2 = red
        
        circle(screenX, screenY, 4);
    }
}

void Graphic::drawSamplesTest(vector<Feature> &samples, int numSamples, int left, int top, int right, int bottom) 
{
	for (int i = 0; i < numSamples; i++) {
        double x = samples[i].getX();
        double y = samples[i].getY();
        int category = samples[i].getCat();
        // map x-coordinate to screen coordinate
        int screenX = (x - MIN_COORDINATE) * (getmaxx() - left) / (MAX_COORDINATE - MIN_COORDINATE) + left;
        // map y-coordinate to screen coordinate
        int screenY = (y - MIN_COORDINATE) * (getmaxy() - top) / (MAX_COORDINATE - MIN_COORDINATE) + top;
        // set color based on category
        
        // setting text and samples colors
        if (category == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        setcolor(2);
    }
    else if (category == 1)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
        setcolor(1);
    }
    else if (category == 2)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        setcolor(4);
    }

    // Print the message in the selected color
    cout << "Test[" << samples[i].getId() << "] --> Classified as category '" << category << "' to the (" << x << "," << -y << ") position of the map" <<endl;

    // Reset the console text attribute to the default color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        // draw sample as a circle
        circle(screenX, screenY, 6);
        
        
		getch();
    }
    
}

void Graphic::initiate(void)
{
	int gdriver = DETECT, gmode;
	
    cout << "Press any key to initiate the Graph" << endl;
    
	cin.get();
    
    initgraph(&gdriver, &gmode, (char*)"C:\\TURBOC3\\BGI");
    
    // set window size
    int left = 0;
    int top = 0;
    int right = getmaxx(); // set right to maximum x-coordinate of the screen
    int bottom = getmaxy(); // set bottom to maximum y-coordinate of the screen
    setviewport(left, top, right, bottom, 1);
    
    
    // set coordinate system
   // setviewport(MIN_COORDINATE, MIN_COORDINATE, MAX_COORDINATE, getmaxy(), 1);

    vector<Feature> tempTrain = getTrainData();
	vector<Feature> tempTest = getTestData();
    
	// preparing train samples
   
    srand(time(0));
    for (int i = 0; i < NUMBER_TRAIN_SAMPLES; i++) {
        tempTrain[i].setY(-tempTrain[i].getY());
    }
    
   // preparing test samples
    srand(time(0));
    for (int i = 0; i < NUMBER_TEST_SAMPLES; i++) {
        tempTest[i].setY(-tempTest[i].getY());
        
    }
    
    
    
    // draw axes
    drawAxes(left, top, right, bottom);
    // draw ticks
    drawTicks(left, top, right, bottom);
    // draw numbers
    drawNumbers(left, top, right, bottom);
    // draw grid
    drawGrid(left, top, right, bottom);
    
    // draw samples
    drawSamplesTrain(tempTrain, NUMBER_TRAIN_SAMPLES, left, top, right, bottom);
    
    cout<<endl<<""<<endl<<endl<<"Category 0 = Green"<<endl<<"Category 1 = Blue"<<endl<<"Category 2 = Red"<<endl<<endl<<""<<endl;
    
    cout<<"Press any key to print the Test data sequentially on the map"<<endl;
    getch();
    
    drawSamplesTest(tempTest, NUMBER_TEST_SAMPLES, left, top, right, bottom);
    
    cout<<"End of the map"<<endl<<"Press any key to close the program"<<endl;
    getch();
    
    closegraph();
}


