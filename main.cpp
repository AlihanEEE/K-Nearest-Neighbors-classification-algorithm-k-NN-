#include<iostream>
#include<algorithm>
#include<vector>

#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <stdlib.h>
#include <time.h>

#include "Graphic.h"
#include "KNN.h"

using namespace std;

int main(){

	KNN knn;										// create a KNN object.
	knn.afterKnnPrint();							// call afterKnnPrint fuction to display the resulting map 
	
	Graphic graph((knn.getContainers().getTest()),(knn.getContainers().getTraining()));				// create an Graphic object.
	
	return 0;
}

