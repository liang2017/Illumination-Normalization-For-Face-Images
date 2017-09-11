
#include "apSmallScaleAdjust.h"

/**************************************************************************
function: find the threshold of image (to make sure 99% of pixels that have lower pixel values than threshold)
input:IplImage *src
output:char
*********************************************************************/
char apFindThreshold(IplImage *src)
{
	char threshold;

	int i, j;
	int k = src->nSize;
	char temp, *p;

	char *dst;
	dst = (char *)calloc(k, sizeof(char));
	apCopyMatrix1Duc(src->imageData, dst, k);

	p = dst;
	//sorting
	for (i = 0; i < k - 1; i++)
	{
		for (j = i + 1; j < k; j++)
		{
			if (*(p + i) > *(p + j))
			{
				temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}
	}

	threshold = dst[(int)(k*0.99)];
	apReleaseMatrix1Duc(dst);
	return threshold;
}

/**************************************************************************
function: find the threshold of image (to make sure 99% of pixels that have lower pixel values than threshold)
input:char *imageData,int size
output:char
*********************************************************************/
char apFindThreshold_data(char *imageData, int size)
{
	char threshold;
	int i, j;
	int k = size;
	char temp, *p;

	char *dst;
	dst = (char *)calloc(k, sizeof(char));
	apCopyMatrix1Duc(imageData, dst, k);

	p = dst;
	for (i = 0; i < k - 1; i++)
	{
		for (j = i + 1; j < k; j++)
		{
			if (*(p + i) > *(p + j))
			{
				temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}
	}

	threshold = dst[(int)(k*0.99)];
	apReleaseMatrix1Duc(dst);
	return threshold;
}

/**************************************************************************
function:find the middle item of input vector
input:int *p, int n
output:int
*********************************************************************/
int apSortMid(int *p, int n)
{
	int i, j;
	int temp;
	int middle;
	for (i = 0; i < n - 1; i++) // sorting starts
	{
		for (j = i + 1; j < n; j++)
		{
			if (*(p + i) > *(p + j))
			{
				temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}
	}

	middle = *(p + (n - 1) / 2);
	return (middle);

}

/**************************************************************************
function:find the middle pixel value on a specific region (centered at (x,y)) of source image; and assign it to destination image
input:IplImage *src, IplImage *dst, int x, int y
output:void
note: the filter is fixed size (3 by 3 pixels); x, y are the coordinates
*********************************************************************/
void apMidFilter(IplImage *src, IplImage *dst, int x, int y)
{
	int *p;
	int a[9];

	if (src == NULL || dst == NULL)
	{
		exit(1);
	}

	p = a;

	a[0] = src->imageData[x*src->widthStep + y];
	a[1] = src->imageData[(x + 1)*src->widthStep + y + 1];
	a[2] = src->imageData[(x - 1)*src->widthStep + y - 1];
	a[3] = src->imageData[x*src->widthStep + y + 1];
	a[4] = src->imageData[x*src->widthStep + y - 1];
	a[5] = src->imageData[(x + 1)*src->widthStep + y];
	a[6] = src->imageData[(x - 1)*src->widthStep + y];
	a[7] = src->imageData[(x - 1)*src->widthStep + y + 1];
	a[8] = src->imageData[(x + 1)*src->widthStep + y - 1];

	dst->imageData[x*src->widthStep + y] = apSortMid(p, 9);
}

/**************************************************************************
function:middle filter of images based on threshold
input:IplImage *src, IplImage *dst, int threshold
output:void
*********************************************************************/
void apMidFilter_Thre(IplImage *src, IplImage *dst, int threshold)
{
	int i, j;
	int k = src->widthStep;

	if (src == NULL || dst == NULL)
	{
		exit(1);
	}

	for (i = 1; i < src->height - 1; i++) //row
	{
		for (j = 1; j < src->width - 1; j++)//rol
		{
			if (src->imageData[i*k + j] >= threshold)
				apMidFilter(src, dst, i, j);
		}
	}
}

/**************************************************************************
function:find the average pixel value on a specific region (centered at (x,y)) of source image; and assign it to destination image
input:IplImage *src, IplImage *dst, int x, int y
output:void
note: the filter is fixed size (3 by 3 pixels); x, y are the coordinates
*********************************************************************/
void apAveFilter(IplImage *src, IplImage *dst, int x, int y)
{
	int *p;
	int a[9];

	if (src == NULL || dst == NULL)
	{
		exit(1);
	}

	p = a;

	a[0] = src->imageData[x*src->widthStep + y];
	a[1] = src->imageData[(x + 1)*src->widthStep + y + 1];
	a[2] = src->imageData[(x - 1)*src->widthStep + y - 1];
	a[3] = src->imageData[x*src->widthStep + y + 1];
	a[4] = src->imageData[x*src->widthStep + y - 1];
	a[5] = src->imageData[(x + 1)*src->widthStep + y];
	a[6] = src->imageData[(x - 1)*src->widthStep + y];
	a[7] = src->imageData[(x - 1)*src->widthStep + y + 1];
	a[8] = src->imageData[(x + 1)*src->widthStep + y - 1];

	dst->imageData[x*src->widthStep + y] = apSortMid(p, 9);
}

/**************************************************************************
function:average filter of images based on threshold
input:IplImage *src, IplImage *dst, int threshold
output:void
*********************************************************************/
void apAveFilter_Thre(IplImage *src, IplImage *dst, int threshold)
{
	int i, j;
	int k = src->widthStep;

	if (src == NULL || dst == NULL)
	{
		exit(1);
	}

	for (i = 1; i < src->height - 1; i++) //row
	{
		for (j = 1; j < src->width - 1; j++)//rol
		{
			if (src->imageData[i*k + j] >= threshold)
				apAveFilter(src, dst, i, j);
		}
	}
}
/*************************************************************************************
 run for test
  **********************************************************************/
  //void main()
  //{
  //    char threshold;
  //	IplImage *src = 0;
  //	IplImage *dst = 0;
  //
  //	src = cvLoadImage(".\\2.JPG", 0 );
  //	dst = cvCreateImage(cvGetSize(src), src->depth , src->nChannels );
  //    dst=cvCloneImage(src);
  //
  //
  //    threshold=apFindThreshold_data(src->imageData,src->nSize);
  //  //  threshold=apFindThreshold(src);
  //	apMidFilter_Thre(src,dst,threshold);
  //
  //	cvNamedWindow("src", 0 );	
  //	cvNamedWindow("dst", 0 );
  //	cvShowImage("src", src );
  //	cvShowImage("dst", dst );
  //	
  //	cvWaitKey( -1);
  //	cvDestroyWindow("src");
  //	cvDestroyWindow("dst");
  //	cvReleaseImage( &src );
  //	cvReleaseImage( &dst );
  //
  //}