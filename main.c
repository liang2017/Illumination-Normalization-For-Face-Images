#include<stdio.h>
#include <highgui.h>
#include <cv.h>
#include <math.h>
#include "apLTV.h"
#include "apmyDCT.h "
#include "apImgProcess.h"
#include "apSmallScaleAdjust.h"


void main()
{
	/********************************************************************************************************
	test: image decomposition (one source image decompose to one small-scale image and one large-scale image)
   *********************************************************************************************************/
   //unsigned char* data1;
   //double* data2;
   //double **data3;
   //double *data4;
   //double *data5;
   //char *data6;
   //double **largescale;
   //double **smallscale;
   //int i;

   ////read in

   //IplImage* img = cvLoadImage(".\\1.bmp",0);
   //if( !img )  
   //{  
   //    printf("can't open the image...\n");  

   //} 

   //data1=apCtoUC(img->imageData, img->imageSize);

   //data2=apLogUC2(data1,img->imageSize);
   //data3=ap1DTo2Dd(data2,img->height,img->width);

   //printf("conduct LTV.....\n");

   //largescale=apLTV(data3,img->height, img->width, 0.4, 0.1,100);
   //smallscale=apGetSmallScale(data3, largescale, img->height, img->width);

   //data4=ap2DTo1Dd(smallscale,img->height, img->width);
   //data5=apExp1D_strengthened(data4,img->imageSize);
   //data6=apDtoC(data5,img->imageSize);

   //apCopyMatrix1Dc(data6,img->imageData,img->imageSize);
   //printf("conduct display img.....\n");
   //cvNamedWindow( "Image", 1 );
   //cvShowImage( "Image", img );
   //cvWaitKey(0); 
   //cvDestroyWindow("Image");
   //cvSaveImage(".\\small.jpg",img,0);

   //apReleaseMatrix1Duc(data1);
   //apReleaseMatrix1Dd(data2);
   //apReleaseMatrix2Dd(data3,img->height);
   //apReleaseMatrix2Dd(largescale,img->height);
   //apReleaseMatrix2Dd(smallscale,img->height);
   //apReleaseMatrix1Dd(data4);
   //apReleaseMatrix1Dd(data5);
   //apReleaseMatrix1Dc(data6);

   //cvReleaseImage( &img);

/******************************************************************
test: adjust small-scale images
**********************************************************************/
//char threshold;
//IplImage *src = 0;
//IplImage *dst = 0;

//src = cvLoadImage(".\\small_s3.jpg", 0);
//dst = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
//dst = cvCloneImage(src);


//threshold = apFindThreshold_data(src->imageData, src->nSize);
////  threshold=apFindThreshold(src);
//apMidFilter_Thre(src, dst, threshold);

//cvNamedWindow("src", 0);
//cvNamedWindow("dst", 0);
//cvShowImage("src", src);
//cvShowImage("dst", dst);

//cvWaitKey(-1);
//cvDestroyWindow("src");
//cvDestroyWindow("dst");
//cvSaveImage(".\\smalladjust.jpg", dst, 0);
//cvReleaseImage(&src);
//cvReleaseImage(&dst);

//void smallAdjust(double **data, int row, int col)
//{
//	threshold = apFindThreshold_data(src->imageData, src->nSize);
//	apMidFilter_Thre(src, dst, threshold);
//}


/******************************************************************
test: illumination normalization on the large-scale images
**********************************************************************/
//unsigned char* data1;
//double* data2;
//double **data3;
//double *data5;
//char *data6;
//double **largescale;
//int i;
//CvMat *largedct;

//IplImage* img = cvLoadImage(".\\1.bmp", 0);
//if (!img)
//{
//	printf("can't open the image...\n");

//}

//data1 = apCtoUC(img->imageData, img->imageSize);

//data2 = apLogUC2(data1, img->imageSize);
//data3 = ap1DTo2Dd(data2, img->height, img->width);

//printf("conduct LTV.....\n");

//largescale = apLTV(data3, img->height, img->width, 0.4, 0.1, 100);
////conduct logDCT
//largedct = apLargeScale_LogDCT(img->height, img->width, largescale);//largescale logDCT
////exp
//data5 = apExp1D_strengthened(largedct->data.db, img->imageSize);
//// double to char

//data6 = apDtoC(data5, img->imageSize);

//printf("conduct new img.....\n");
//apCopyMatrix1Dc(data6, img->imageData, img->imageSize);

//printf("conduct display img.....\n");
//cvNamedWindow("Image", 1);
//cvShowImage("Image", img);
//cvWaitKey(0);
//cvDestroyWindow("Image");
//cvSaveImage(".\\Snorm.jpg", img, 0);

//apReleaseMatrix1Duc(data1);
//apReleaseMatrix1Dd(data2);
//apReleaseMatrix2Dd(data3, img->height);
//apReleaseMatrix2Dd(largescale, img->height);
//apReleaseMatrix1Dd(data5);
//apReleaseMatrix1Dc(data6);
//cvReleaseMat(&largedct);
//cvReleaseImage(&img);
/*****************************************************************************************
test: image fuse of the adjusted small-scale image and the normalized large-scale image
*****************************************************************************************/
//IplImage *smallscale ;
//IplImage *large ;
//IplImage *img_out;
//CvMat* Msmall;
//CvMat* Mlarge;
//CvMat* Msum;
//int i,j;
//double t;
//smallscale = cvLoadImage(".\\smalladjust.jpg", 0 );
//large = cvLoadImage(".\\Snorm_s3.jpg", 0 );
//img_out=cvCreateImage(cvSize(smallscale->width,smallscale->height), smallscale->depth, 1);
//
//Msmall = cvCreateMat(smallscale->height,smallscale->width,CV_32SC1);
//Mlarge = cvCreateMat(large->height,large->width,CV_32SC1);
//Msum = cvCreateMat(large->height,large->width,CV_32SC1);
//cvConvert( smallscale, Msmall); 
//cvConvert( large, Mlarge); 
//cvMul(Msmall,Mlarge, Msum,1);
//
////for(i=0;i<large->height;i++)
////for(j=0;j<large->width;j++)
////{
////    t = cvmGet(Msum,i,j); // Get M(i,j) 
////    
////   // cvmSet(Msum,i,j,100+t); // Set M(i,j)
////}
////cvCrossProduct(Msmall,Mlarge, Msum);
//cvConvert( Msum, img_out);
//
//cvSaveImage(".\\sum.jpg",img_out,0);
//cvReleaseImage( &smallscale);
//cvReleaseImage( &large);
//cvReleaseImage( &img_out);
//cvReleaseMat(&Msmall);  
//cvReleaseMat(&Mlarge);  
//cvReleaseMat(&Msum);  

/******************************************************************************************************************
test: whole system (image decomposation + adjust small-scale image + normalize large-scale image + image fusing)
*******************************************************************************************************************/
	unsigned char* data1;
	double* data2;
	double **data3;
	double *data4;
	double *data5;
	char *data6;
	double **largescale;
	double **smallscale;
	int i;
	CvMat *largedct, smallAdjust, *img_re;

	IplImage* img = cvLoadImage(".\\test_image.bmp", 0);
	if (!img)
	{
		printf("can't open the image...\n");

	}
	/*****image decomposition************/
	data1 = apCtoUC(img->imageData, img->imageSize);

	data2 = apLogUC2(data1, img->imageSize);
	data3 = ap1DTo2Dd(data2, img->height, img->width);

	printf("conduct LTV.....\n");//decompose source image to a small-scale image and a large-scale image

	largescale = apLTV(data3, img->height, img->width, 0.4, 0.1, 100);

	smallscale = apGetSmallScale(data3, largescale, img->height, img->width);
	//  apDataPrint2Dd(smallscale,img->height, img->width,".\\1.txt");

	/*************image process******************/
	largedct = apLargeScale_LogDCT(img->height, img->width, largescale); // normalize large-scale image


	/************image reconstruction*************/
	data2 = apExp1D(largedct->data.fl, img->imageSize);//large

	data3 = apExp2D(smallscale, img->height, img->width);//small
	data4 = ap2DTo1Dd(data3, img->height, img->width);
	//apDataPrint2Dd(data3,img->height, img->width,".\\1.txt");

	for (i = 0; i < img->imageSize; i++)
	{
		data4[i] = data2[i] * data4[i];
	}
	data6 = apDtoC_strengthened(data4, img->imageSize);

	/****************image display and save************/
	apCopyMatrix1Dc(data6, img->imageData, img->imageSize);
	printf("conduct display img.....\n");
	cvNamedWindow("Image", 1);
	cvShowImage("Image", img);
	cvWaitKey(0);
	cvDestroyWindow("Image");
	cvSaveImage(".\\small.jpg", img, 0);

	apReleaseMatrix1Duc(data1);
	apReleaseMatrix1Dd(data2);
	apReleaseMatrix2Dd(data3, img->height);
	apReleaseMatrix2Dd(largescale, img->height);
	apReleaseMatrix2Dd(smallscale, img->height);
	apReleaseMatrix1Dd(data4);
	//apReleaseMatrix1Dd(data5);
	apReleaseMatrix1Dc(data6);

	cvReleaseMat(&largedct);
	cvReleaseImage(&img);
}