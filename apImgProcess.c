#include<stdio.h>
#include <highgui.h>
#include <cv.h>
#include "apImgProcess.h"
#include "apLTV.h"

/**************************************************************************
function: save image pixel values to file
input: IplImage* img, char *path
output: void
*********************************************************************/
void apImgPrint(IplImage* img, char *path)
{
	int i, j;
	int k = img->widthStep;
	FILE *fp;

	if (img == NULL) { 
		printf("\n the input image is NULL "); 
		exit(1);
	}

	fp = fopen(path, "w");

	for (i = 0; i < img->height; i++)
	{
		for (j = 0; j < img->width; j++)
		{
			fprintf(fp, "%d\t", img->imageData[i*k + j]);

		}

		fprintf(fp, "\n");
	}
	fclose(fp);
}

/**************************************************************************
function: save 2D double data to file 
input: double **data, int row, int col, char *path
output: void
*********************************************************************/
void apDataPrint2Dd(double **data, int row, int col, char *path)
{
	int i, j;

	FILE *fp;

	if (data == NULL) { 
		printf("\n the input data is NULL"); 
		exit(1);
	}

	fp = fopen(path, "w");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			fprintf(fp, "%f\t", data[i][j]);

		}

		fprintf(fp, "\n");
	}
	fclose(fp);
}

/**************************************************************************
function: save 1D double data to file
input: double *data, int len, char *path
output: void
*********************************************************************/
void apDataPrint1Dd(double *data, int len, char *path)
{
	int i;

	FILE *fp;
	if (data == NULL) 
	{
		printf("\n the input data is NULL"); 
		exit(1);
	}

	fp = fopen(path, "w");

	for (i = 0; i < len; i++)
	{
		fprintf(fp, "%f\t", data[i]);
	}
	fclose(fp);
}

/**************************************************************************
function: save 1D char data to file
input: char *data, int len, char *path
output: void
*********************************************************************/
void apDataPrint1Dc(char *data, int len, char *path)
{
	int i;

	FILE *fp;
	if (data == NULL) 
	{ 
		printf("\n the input data is NULL");
		exit(1);
	
	}

	fp = fopen(path, "w");

	for (i = 0; i < len; i++)
	{
		fprintf(fp, "%d\t", data[i]);
	}

	fclose(fp);
}

/**************************************************************************
function: transform char data to unsigned char data
input: char* imageData, int size
output: unsigned char*
*********************************************************************/
unsigned char* apCtoUC(char* imageData, int size)
{
	int i;
	unsigned char* newData;
	newData = (unsigned char*)calloc(size, sizeof(unsigned char));

	if (imageData == NULL) 
	{ 
		printf("\n the input data is NULL"); 
		exit(1);
	}

	for (i = 0; i < size; i++)

	{
		newData[i] = (unsigned char)(imageData[i]);
	}
	return newData;
}
/**************************************************************************
function: transform  unsigned char data to char data 
input: unsigned char* imageData, int size
output:char*
*********************************************************************/
char* apUCtoC(unsigned char* imageData, int size)
{
	int i;
	char* newData;
	newData = (char*)calloc(size, sizeof(char));

	if (imageData == NULL)
	{
		printf("\n the input data is NULL");
		exit(1);
	}

	for (i = 0; i < size; i++)
	{
		newData[i] = (char)(imageData[i]);
	}
	return newData;
}
/**************************************************************************
function: transform  double data to char data
input: double* imageData, int size
output:char*
*********************************************************************/
char* apDtoC(double* imageData, int size)
{
	int i;
	char* newData;
	newData = (char*)calloc(size, sizeof(char));

	if (imageData == NULL)
	{
		printf("\n the input data is NULL");
		exit(1);
	}

	for (i = 0; i < size; i++)
	{
		newData[i] = (char)(round(imageData[i]));
	}
	return newData;
}

/**************************************************************************
function: transform double data to char data with 100 times strengthened
input:double* imageData, int size
output:char*
*********************************************************************/
char* apDtoC_strengthened(double* imageData, int size)
{
	int i;
	char* newData;
	double temp;
	newData = (char*)calloc(size, sizeof(char));

	if (imageData == NULL)
	{
		printf("\n the input data is NULL");
		exit(1);
	}

	for (i = 0; i < size; i++)
	{
		temp = 100 * imageData[i];
		if (temp > 255) temp = 255;
		else if (temp < 0) temp = 0;
		newData[i] = (char)temp;

	}
	return newData;
}