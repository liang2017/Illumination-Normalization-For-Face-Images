//These functions are about the memory operations such as allocation, release, copy, link and display

#ifndef apMatrix_h
#define apMatrix_h  

#ifdef __cplusplus
extern "C" {
#endif
#include <malloc.h>
#include <stdio.h>

	typedef struct ApPointd
{   
	int dim;
	double *data; }ApPointd;

typedef struct ApPointi
{   
	int dim;
	int *data;
}ApPointi;

typedef struct ApPointl
{   
	int dim;
	long *data;
}ApPointl;


typedef struct ApPointf
{   
	int dim;
	float *data;
}ApPointf;


typedef struct ApPoint2Dd
{
	double x;
	double y;
}ApPoint2Dd;

typedef struct ApPointsList2Dd
{
	int sampleNum;
	int pointsNum;
	ApPoint2Dd **data;
}ApPointsList2Dd;

typedef struct ApPoint2Di
{
	int x;
	int y;
}ApPoint2Di;

typedef struct ApPointsList2Di
{
	int sampleNum;
	int pointsNum;
	ApPoint2Di **data;
}ApPointsList2Di;

typedef struct ApPoint2Dl
{
	long x;
	long y;
}ApPoint2Dl;

typedef struct ApPointsList2Dl
{
	int sampleNum;
	int pointsNum;
	ApPoint2Dl **data;
}ApPointsList2Dl;

typedef struct ApPoint2Df
{
	float x;
	float y;
}ApPoint2Df;

typedef struct ApPointsList2Df
{
	int sampleNum;
	int pointsNum;
	ApPoint2Df **data;
}ApPointsList2Df;

typedef struct ApPoint2Duc
{
	unsigned char x;
	unsigned char y;
}ApPoint2Duc;

typedef struct ApPointsLists2Duc
{
	int sampleNum;
	int pointsNum;
	ApPoint2Duc **data;
}ApPointsList2Duc;

typedef struct ApPoint2Dui
{
	unsigned int x;
	unsigned int y;
}ApPoint2Dui;
typedef struct ApPointsList2Dui
{
	int sampleNum;
	int pointsNum;
	ApPoint2Dui **data;
}ApPointsList2Dui;

typedef struct ApPoint2Dul
{
	unsigned long x;
	unsigned long y;
}ApPoint2Dul;

typedef struct ApPointsList2Dul
{
	int sampleNum;
	int pointsNum;
	ApPoint2Dul **data;
}ApPointsList2Dul;


ApPointsList2Dl apCreatePointsList2Dl(int sampleNum, int pointsNum);
ApPointsList2Di apCreatePointsList2Di(int sampleNum, int pointsNum);
ApPointsList2Dd apCreatePointsList2Dd(int sampleNum, int pointsNum);
ApPointsList2Df apCreatePointsList2Df(int sampleNum, int pointsNum);

void apReleasePointsList2Dd(ApPointsList2Dd pointsList);
void apReleasePointsList2Df(ApPointsList2Df pointsList);
void apReleasePointsList2Di(ApPointsList2Di pointsList);
void apReleasePointsList2Dl(ApPointsList2Dl pointsList);


unsigned char** apCreateMatrix2Duc(int row, int col); 
int** apCreateMatrix2Di(int row, int col); 
long** apCreateMatrix2Dl(int row, int col); 
float** apCreateMatrix2Df(int row, int col); 
double **apCreateMatrix2Dd(int row,int col); 
unsigned int** apCreateMatrix2Dui(int row, int col); 
unsigned long** apCreateMatrix2Dul(int row, int col);
char** apCreateMatrix2Dc(int row, int col); 


double *apCreateMatrix1Dd(int row);
float *apCreateMatrix1Df(int len);
int *apCreateMatrix1Di(int len);
unsigned char* apCreateMatrix1Duc(int len);
long* apCreateMatrix1Dl(int len);
unsigned long* apCreateMatrix1Dul(int len);
unsigned int* apCreateMatrix1Dui(int len);
char* apCreateMatrix1Dc(int len);


void apReleaseMatrix2Duc(unsigned char** data, int row);
void apReleaseMatrix2Di(int** data, int row);
void apReleaseMatrix2Dl(long** data, int row);
void apReleaseMatrix2Df(float** data, int row);
void apReleaseMatrix2Dd(double** data, int row);
void apReleaseMatrix2Dc(char** data, int row);
void apReleaseMatrix2Dul(unsigned long** data, int row);
void apReleaseMatrix2Dui(unsigned int** data, int row);


void apReleaseMatrix1Duc(unsigned char *data);
void apReleaseMatrix1Dd(double *data);
void apReleaseMatrix1Di(int *data);
void apReleaseMatrix1Dl(long *data);
void apReleaseMatrix1Dc(char *data);
void apReleaseMatrix1Dul(unsigned long *data);
void apReleaseMatrix1Dui(unsigned int *data);
void apReleaseMatrix1Df(float *data);

void apCopyMatrix2Duc(unsigned char** source,unsigned char** dest,int row, int col);
void apCopyMatrix2Di(int** source,int** dest,int row, int col);
void apCopyMatrix2Dl(long** source,long** dest,int row, int col);
void apCopyMatrix2Df(float** source,float** dest,int row, int col);
void apCopyMatrix2Dd(double** source,double** dest,int row, int col);
void apCopyMatrix2Dc(char** source,char** dest,int row, int col);
void apCopyMatrix2Dui(unsigned int** source,unsigned int** dest,int row, int col);
void apCopyMatrix2Dul(unsigned long** source,unsigned long** dest,int row, int col);


void apCopyMatrix1Duc(unsigned char* source,unsigned char* dest,int len);
void apCopyMatrix1Di(int* source,int* dest,int len);
void apCopyMatrix1Dl(long* source,long* dest,int len);
void apCopyMatrix1Df(float* source,float* dest,int len);
void apCopyMatrix1Dd(double* source,double* dest,int len);
void apCopyMatrix1Dc(char* source,char* dest,int len);
void apCopyMatrix1Dui(unsigned int* source,unsigned int* dest,int len);
void apCopyMatrix1Dul(unsigned long* source,unsigned long* dest,int len);

double **ap1DTo2Dd(double *data,int row,int col);
double *ap2DTo1Dd(double **data,int row,int col);
float *ap2DTo1Df(float **data,int row,int col);
int *ap2DTo1Di(int **data,int row,int col);
long *ap2DTo1Dl(long **data,int row,int col);
unsigned int *ap2DTo1Dui(unsigned int **data,int row,int col);
unsigned long *ap2DTo1Dul(unsigned long **data,int row,int col);
unsigned char *ap2DTo1Duc(unsigned char **data,int row,int col);
char *ap2DTo1Dc(char **data,int row,int col);

int *apMatrixLink1Di(int *matrix1,int len1,int *matrix2,int len2);
long *apMatrixLink1Dl(long *matrix1,int len1,long *matrix2,int len2);
double *apMatrixLink1Dd(double *matrix1,int len1,double *matrix2,int len2);
float *apMatrixLink1Df(float *matrix1,int len1,float *matrix2,int len2);
char *apMatrixLink1Dc(char *matrix1,int len1,char *matrix2,int len2);
unsigned int *apMatrixLink1Dui(unsigned int *matrix1,int len1,unsigned int *matrix2,int len2);
unsigned long *apMatrixLink1Dul(unsigned long *matrix1,int len1,unsigned long *matrix2,int len2);
unsigned char *apMatrixLink1Duc(unsigned char *matrix1,int len1,unsigned char *matrix2,int len2);

void apDisMatrix2Di(int **p,int row,int col);
void apDisMatrix2Dd(double **p,int row,int col);
void apDisMatrix2Df(float **p,int row,int col);
void apDisMatrix2Dl(long **p,int row,int col);
void apDisMatrix2Dc(char **p,int row,int col);
void apDisMatrix2Duc(unsigned char **p,int row,int col);
void apDisMatrix2Dui(unsigned int **p,int row,int col);
void apDisMatrix2Dul(unsigned long **p,int row,int col);


void apDisMatrix1Di(int *p,int len);
void apDisMatrix1Dd(double *p,int len);
void apDisMatrix1Df(float *p,int len);
void apDisMatrix1Dl(long *p,int len);
void apDisMatrix1Dc(char *p,int len);
void apDisMatrix1Duc(unsigned char *p,int len);
void apDisMatrix1Dui(unsigned int *p,int len);
void apDisMatrix1Dul(unsigned long *p,int len);


double **apReverseMatrix2Dd(double **data,int row, int col);
float **apReverseMatrix2Df(float **data,int row, int col);
int **apReverseMatrix2Di(int **data,int row, int col);
long **apReverseMatrix2Dl(long **data,int row, int col);
char **apReverseMatrix2Dc(char **data,int row, int col);
unsigned char **apReverseMatrix2Duc(unsigned char **data,int row, int col);
unsigned int **apReverseMatrix2Dui(unsigned int **data,int row, int col);
unsigned long **apReverseMatrix2Dul(unsigned long **data,int row, int col);


void apMatrixcopy1Dd(double *dest,double *source,int dimension);

double **apIvnMatrix2Dd(double **a,int row);
double **apMulMatrix2Dd(double **x,int rowx,int colx,double **y,int rowy,int coly);
void apMatrixInvert(double **dest,double **src, int src_row,int src_col);

double findmax(double *data,int size);
double findmin(double *data,int size);

#ifdef __cplusplus
}
#endif
#endif