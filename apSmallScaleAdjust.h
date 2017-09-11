#ifndef apSmallScaleAdjust_h
#define apSmallScaleAdjust_h  
#include <cxcore.h>
#include <cv.h>
#include <highgui.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "apmatrix.h"

unsigned char apFindThreshold(IplImage *src);
char apFindThreshold_data(char *imageData,int size);
int apSortMid( int *p, int n);
void apMidFilter(IplImage *src,IplImage *dst,int x,int y );
void apMidFilter_Thre(IplImage *src,IplImage *dst,int threshold);


#endif