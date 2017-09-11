#ifndef apLTV_h
#define apLTV_h  

#include "apImgProcess.h"
#include "apMatrix.h"
double round(double r);
double** apLTV(double **imgdata_log,int height, int width, double lamda, double dt,int MaxTimes); 
double** apLTV_new(double **imgdata_log,int height, int width, double lamda, double dt,double tol,int MaxTimes);

double **apGetSmallScale(double **imgdata_log, double **dataLargeScale, int height, int width);
void dataNormalization(double *data,int size,double lowlimit,double uplimit);

#endif