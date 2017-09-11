#include<stdio.h>
#include <highgui.h>
#include <cv.h>
#include "apmyDCT.h"
#include "apImgProcess.h"

/**************************************************************************
function: conduct DCT on images
input:IplImage* img
output:void
*********************************************************************/
void apmyDCT(IplImage* img)
{
	CvMat *src, *dst;
	IplImage* img_out;


	img_out = cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
	src = cvCreateMat(img->height, img->width, CV_64FC1);//
	dst = cvCreateMat(img->height, img->width, CV_64FC1);

	cvConvert(img, src);  //iplimage to cvmat
	cvDCT(src, dst, CV_DXT_FORWARD); //DCT transform

	cvConvert(dst, img_out);  //cvmat to iplimage
	cvSaveImage(".\\dctlena.jpg", img_out, 0);//save image
	//for debugging...

	cvDCT(dst, src, CV_DXT_INVERSE);
	cvConvert(src, img_out);
	cvSaveImage(".\\idctlena.jpg", img_out, 0);//save image


	cvReleaseImage(&img_out);
	cvReleaseMat(&dst);
	cvReleaseMat(&src);
}
/**************************************************************************
function: conduct DCT on images
input:IplImage* img
output:void
*********************************************************************/
void apLargeScale_DCT(IplImage* img)
{
	CvMat *src, *dst;
	IplImage* img_out;
	int i, j;

	img_out = cvCreateImage(cvSize(img->width, img->height), img->depth, 1);
	src = cvCreateMat(img->height, img->width, CV_64FC1);
	dst = cvCreateMat(img->height, img->width, CV_64FC1);

	cvConvert(img, src);  //iplimage to cvmat
	cvDCT(src, dst, CV_DXT_FORWARD); //DCT transform

	//cvConvert( dst, img_out );  //cvmat to iplimage
	//cvSaveImage(".\\dctlena.jpg",img_out ,0);//save image

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{

			CV_MAT_ELEM(*dst, double, i, j) = 0;
		}
	}
	cvConvert(dst, img_out);  //cvmat to iplimage
	cvSaveImage(".\\dctlena1.jpg", img_out, 0);//save image

	cvDCT(dst, src, CV_DXT_INVERSE);
	cvConvert(src, img_out);
	cvSaveImage(".\\idctlena1.jpg", img_out, 0);//save image


	cvReleaseImage(&img_out);
	cvReleaseMat(&dst);
	cvReleaseMat(&src);
}

/**************************************************************************
function: conduct DCT on data
input:int height,int width,double **logdata
output:void
*********************************************************************/
CvMat *apLargeScale_LogDCT(int height, int width, double **logdata)
{
	CvMat *src, *dst;
	//IplImage* img_out;
	int i, j;

	//DCT
	//img_out= cvCreateImage(cvSize(width,height), img->depth, 1); 
	src = cvCreateMat(height, width, CV_64FC1);
	dst = cvCreateMat(height, width, CV_64FC1);

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			cvmSet(src, i, j, logdata[i][j]);
		}
	}

	//cvConvert( img, src );  //iplimage to cvmat
	cvDCT(src, dst, CV_DXT_FORWARD); //DCT transform£¡£¡

	//cvConvert( dst, img_out );  //cvmat to iplimage
	//cvSaveImage(".\\dctlena.jpg",img_out ,0);//save image

	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
		{

			CV_MAT_ELEM(*dst, double, i, j) = 0;
		}
	}
	//cvConvert( dst, img_out );  //cvmat to iplimage
	//cvSaveImage(".\\dctlena1.jpg",img_out ,0);//save image

	cvDCT(dst, src, CV_DXT_INVERSE);
	//fan LOG
	//for(i=0;i<src->rows;i++)
	//{
	//    for(j=0;j<src->cols;j++)
	//    {
	//        src->data[i][j]=exp(src->data[i][j]);
	//    }
	//}

	//cvConvert( src, img_out );
	//·´log
	//apCopyMatrix1Dc(img_out->imageData,data3,img->imageSize);
	//for(i=0;i<img->imageSize;i++)//CtoD
	//{
	//    data2[i]=(double)data3[i];
	//}

	//for(i=0;i<img->imageSize;i++)//DtoC
	//{
	//    data3[i]=(char)data4[i];
	//}
	//apCopyMatrix1Dc(data3,img_out->imageData,img->imageSize);

	//cvSaveImage(".\\idctlena1.jpg",img_out ,0);//save image


	//cvReleaseImage( &img_out); 
	cvReleaseMat(&dst);
	//cvReleaseMat( &src);
	return src;
}

/**************************************************************************
function: conduct log transform
input:unsigned char* imageData,int size
output:double*
*********************************************************************/
double* apLogUC(unsigned char* imageData, int size)
{

	int i;
	double* dataLog;

	if (imageData == NULL)
	{
		printf("\n the input data is NULL");
		exit(1);
	}

	dataLog = (double*)calloc(size, sizeof(double));

	for (i = 0; i < size; i++)
	{
		dataLog[i] = log(imageData[i]);
	}

	return dataLog;
}

/**************************************************************************
function: conduct log transform (updated version, more robust)
input:unsigned char* imageData,int size
output:double*
*********************************************************************/
double* apLogUC2(unsigned char* imageData, int size)
{
	int i;
	double *dataLog;
	double *map;
	double dTemp;

	if (imageData == NULL)
	{
		printf("\n the input data is NULL");
		exit(1);
	}

	dataLog = (double*)calloc(size, sizeof(double));
	map = (double *)calloc(256, sizeof(double));

	for (i = 0; i < 256; i++)
	{
		dTemp = log((double)i + 1.0);

		if (dTemp < 0)   dTemp = 0.0;
		else if (dTemp > 255)   dTemp = 255;

		map[i] = dTemp;
	}
	for (i = 0; i < size; i++)
	{
		dataLog[i] = map[(int)imageData[i]];
	}

	free(map);
	return dataLog;
}
/**************************************************************************
function: conduct log transform with 30 times strengthened input
input:unsigned char* imageData,int size
output:double*
*********************************************************************/
double* apLogUC2_strengthened(unsigned char* imageData, int size)
{
	int i;
	double *dataLog;
	double *map;
	double dTemp;

	if (imageData == NULL)
	{
		printf("\n the input data is NULL");
		exit(1);
	}

	dataLog = (double*)calloc(size, sizeof(double));
	map = (double *)calloc(256, sizeof(double));

	for (i = 0; i < 256; i++)
	{
		dTemp = 30 * log((double)i + 1.0);

		if (dTemp < 0)   dTemp = 0.0;
		else if (dTemp > 255)   dTemp = 255;

		map[i] = dTemp;
	}
	for (i = 0; i < size; i++)
	{
		dataLog[i] = map[(int)imageData[i]];
	}

	free(map);
	return dataLog;
}
/**************************************************************************
function: conduct exponential transform
input:double* imageData,int size
output:double*
*********************************************************************/
double* apExp1D(double* imageData, int size)
{

	int i;
	double* dataExp;

	if (imageData == NULL)
	{
		printf("\n the input data is NULL");
		exit(1);
	}

	dataExp = (double*)calloc(size, sizeof(double));
	for (i = 0; i < size; i++)

	{
		dataExp[i] = exp(imageData[i]);
		if (dataExp[i] < 0) dataExp[i] = 0;
		else if (dataExp[i] > 255) dataExp[i] = 255;
	}

	return dataExp;
}
/**************************************************************************
function: conduct exponential transform
input:double* imageData,int size
output:void
*********************************************************************/
void apExp1D_1(double* imageData, int size)
{
	int i;

	if (imageData == NULL)
	{
		printf("\n the input data is NULL");
		exit(1);
	}

	for (i = 0; i < size; i++)

	{
		imageData[i] = exp(imageData[i]);
		if (imageData[i] < 0) imageData[i] = 0;
		else if (imageData[i] > 255) imageData[i] = 255;
	}

}

/*********************************************************************************************************
function: conduct exponential transform, and then increase the output 100 times for display purpose
input:double* imageData,int size
output:double*
************************************************************************************************************/
double* apExp1D_strengthened(double* imageData, int size)
{
	int i;
	double* dataExp;

	if (imageData == NULL)
	{
		printf("\n the input data is NULL");
		exit(1);
	}

	dataExp = (double*)calloc(size, sizeof(double));
	for (i = 0; i < size; i++)

	{
		dataExp[i] = 100 * exp(imageData[i]);
		if (dataExp[i] < 0) dataExp[i] = 0;
		else if (dataExp[i] > 255) dataExp[i] = 255;
	}

	return dataExp;
}

/************************************************************************************
function: conduct exponential transform
input:double** imageData,int row,int col
output:double**
**************************************************************************************/
double** apExp2D(double** imageData, int row, int col)
{
	int i, j;
	double** dataExp;

	if (imageData == NULL)
	{
		printf("\n the input data is NULL");
		exit(1);
	}

	dataExp = apCreateMatrix2Dd(row, col);
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)

		{
			dataExp[i][j] = exp(imageData[i][j]);
			if (dataExp[i][j] < 0) dataExp[i][j] = 0;
			else if (dataExp[i][j] > 255) dataExp[i][j] = 255;
		}

	return dataExp;
}
/*************************************************************************************
 run for test
 **********************************************************************/
//void main()
//{
//	int i, j;
//	iplimage* img_out, *img_uc;
//	unsigned char* datauc;
//	double* datalog;
//	double* dataexp;
//	cvmat *src, *dst;
//
//	iplimage* img = cvloadimage(".\\large.jpg", 0);
//	if (!img)
//	{
//		printf("can't open the image...\n");
//
//	}
//
//	//img_uc=cvcreateimage(cvgetsize(img),ipl_depth_8u,1);
//	//cvconvert(img,img_uc);
//	//apimgprint(img_uc,".\\1.txt");
//
//	//aplargescele_dct(img);
//	//apmydct(img);
//		//datauc=apctouc( img->imagedata,img->imagesize);
//
//		//datalog=aploguc(datauc,img->imagesize);
//
//		//dataexp=apexpuc(datalog,img->imagesize);
//
//
//	//display.....
//	//        cvnamedwindow( "image", 1 );
//	//        cvshowimage( "image", img_uc );
//	//cvwaitkey(0); 
//	//	cvdestroywindow("image");
//	aplargescale_logdct(img);
//	//free( datauc);
//	//free( datalog);
//	//free( dataexp);
//	cvreleaseimage(&img);
//	//cvreleaseimage( &img_uc); 
//	system("pause");
//}