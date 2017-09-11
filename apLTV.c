#include<stdio.h>
#include <highgui.h>
#include <cv.h>
#include <math.h>
#include "apLTV.h"
#include "apmyDCT.h "


#define kercy 1.0e-10


double round(double r)
{
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}


/**************************************************************************
function: conduct LTV transformation
input:double **imgdata_log, int height, int width, double lamda, double dt, int MaxTimes
output:double**
*********************************************************************/
double** apLTV(double **imgdata_log, int height, int width, double lamda, double dt, int MaxTimes) 

{
	double **u, **u_next;
	double Dx, Dy, Dxy, Dxx, Dyy, Dx2, Dy2;
	double temp1, temp2, temp3;
	int i, j;
	int n = 0;

	if (imgdata_log == NULL)
	{
		printf("\n the input image is NULL");
		exit(1);
	}

	u = apCreateMatrix2Dd(height, width);
	u_next = apCreateMatrix2Dd(height, width);

	apCopyMatrix2Dd(imgdata_log, u_next, height, width);
	for (i = 0; i < width; ++i)
	{
		u_next[0][i] = u_next[1][i];
		u_next[height - 1][i] = u_next[height - 2][i];

	}
	for (i = 0; i < height; ++i)
	{
		u_next[i][0] = u_next[i][1];
		u_next[i][width - 1] = u_next[i][width - 2];

	}
	/*************************************************************/
	do {
		apCopyMatrix2Dd(u_next, u, height, width);

		for (i = 1; i < (height - 1); ++i)
		{

			for (j = 1; j < (width - 1); ++j)
			{
				// prepare parameter
				Dxx = u[i + 1][j] - 2 * u[i][j] + u[i - 1][j];
				Dx = (u[i + 1][j] - u[i - 1][j]) / 2.0;
				Dy = (u[i][j + 1] - u[i][j - 1]) / 2.0;
				Dxy = (u[i + 1][j + 1] + u[i - 1][j - 1] - u[i + 1][j - 1] - u[i - 1][j + 1]) / 4.0;
				Dyy = u[i][j + 1] - 2 * u[i][j] + u[i][j - 1];
				Dx2 = Dx*Dx;
				Dy2 = Dy*Dy;
				temp1 = Dxx*(Dy2 + kercy) - 2 * Dx*Dy*Dxy + Dyy*(Dx2 + kercy);
				temp2 = sqrt(Dx2 + Dy2 + kercy);
				temp3 = lamda*(imgdata_log[i][j] - u[i][j]) / sqrt((imgdata_log[i][j] - u[i][j])*(imgdata_log[i][j] - u[i][j]) + 1.0e-10);
				//get u_next
				u_next[i][j] = dt*(temp1 / temp2 + temp3) + u[i][j];

			}
		}
		for (i = 0; i < width; ++i)
		{
			u_next[0][i] = u_next[1][i];
			u_next[height - 1][i] = u_next[height - 2][i];

		}
		for (i = 0; i < height; ++i)
		{
			u_next[i][0] = u_next[i][1];
			u_next[i][width - 1] = u_next[i][width - 2];

		}
		++n;
	} while (n < MaxTimes); 

	apReleaseMatrix2Dd(u, height);

	return u_next;
}


/**************************************************************************
function: conduct LTV transformation (updated version)
input:double **imgdata_log,int height, int width, double lamda, double dt,double tol,int MaxTimes
output:double**
Note: one new parameter is added (double tol)
*********************************************************************/
double** apLTV_new(double **imgdata_log,int height, int width, double lamda, double dt,double tol,int MaxTimes)

{
double **u,**u_next;
double Dx,Dy,Dxy,Dxx,Dyy,Dx2,Dy2;
double temp1,temp2,temp3,delta;
int i,j;
int n=0;
double err;

if (imgdata_log == NULL)
{
	printf("\n the input image is NULL");
	exit(1);
}

u=apCreateMatrix2Dd(height,width);
u_next=apCreateMatrix2Dd(height,width);

apCopyMatrix2Dd(imgdata_log,u_next,height, width);
               		for(i=0;i<width;++i)
		{
			u_next[0][i] = u_next[1][i];
			u_next[height-1][i] = u_next[height-2][i];

		}
		for(i=0;i<height;++i)
		{
			u_next[i][0] = u_next[i][1];
			u_next[i][width-1] = u_next[i][width-2];

		}
/**************************************************************************/
        do {
            apCopyMatrix2Dd(u_next,u,height, width);
            err=0.0;
		for(i=1;i<(height-1);++i)
		{

			for( j=1;j<(width-1);++j)
			{
                   // prepare parameter
				Dxx = u[i+1][j] - 2*u[i][j] + u[i-1][j];
				Dx = ( u[i+1][j] - u[i-1][j] )/2.0;
				Dy = ( u[i][j+1] - u[i][j-1] )/2.0;
				Dxy = ( u[i+1][j+1] + u[i-1][j-1] - u[i+1][j-1] - u[i-1][j+1] )/4.0;
				Dyy = u[i][j+1]-2*u[i][j]+u[i][j-1];
				Dx2 = Dx*Dx;
				Dy2 = Dy*Dy;
				temp1 = Dxx*(Dy2+kercy)-2*Dx*Dy*Dxy+Dyy*(Dx2+kercy);
                temp2=sqrt(Dx2+Dy2+kercy);
                temp3=lamda*(imgdata_log[i][j]-u[i][j])/sqrt((imgdata_log[i][j]-u[i][j])*(imgdata_log[i][j]-u[i][j])+1.0e-10);
                //get u_next
                delta=dt*(temp1/temp2+temp3);
                u_next[i][j]=delta+u[i][j];
                err = (fabs(delta)>err) ? fabs(delta):err;
            }
        }
        		for(i=0;i<width;++i)
		{
			u_next[0][i] = u_next[1][i];
			u_next[height-1][i] = u_next[height-2][i];

		}
		for(i=0;i<height;++i)
		{
			u_next[i][0] = u_next[i][1];
			u_next[i][width-1] = u_next[i][width-2];

		}
        ++n;
            }while(n<MaxTimes && err>tol) ; 



apReleaseMatrix2Dd(u,height);


return u_next;
}

/**************************************************************************
function: get SmallScale image data
input:double **imgdata_log, double **dataLargeScale, int height, int width
output:double**
*********************************************************************/
double **apGetSmallScale(double **imgdata_log, double **dataLargeScale, int height, int width)
{
   double **dataSmallScale;
   int i,j;

   if (imgdata_log == NULL || dataLargeScale == NULL)
   {
	   printf("\n the input data is NULL");
	   exit(1);
   }

   dataSmallScale=apCreateMatrix2Dd(height,width);
		for(i=0;i<height;++i)
		{

			for( j=0;j<width;++j)
            {
               dataSmallScale[i][j]=imgdata_log[i][j] - dataLargeScale[i][j];
            }
        }

        return dataSmallScale;
}

/**************************************************************************
function:conduct data normalization
input:double *data,int size,double lowlimit,double uplimit
output:void
*********************************************************************/
void dataNormalization(double *data,int size,double lowlimit,double uplimit)
{
    double datamax,datamin,temp;
    int i;

	if (data == NULL)
	{
		printf("\n the input data is NULL");
		exit(1);
	}

    datamax=findmax(data,size);
    datamin=findmin(data,size);
    temp=(datamax-datamin)/(uplimit-lowlimit);
    for (i=0;i<size;i++)
    {
        data[i]=(data[i]-datamin)/temp+lowlimit;
    }

}

/**************************************************************************
function:run for test
*********************************************************************/
//void main()
//{
//	CvMat *data1;
//	double *data2;
//	double **data3;
//	double **largescale;
//	double **smallscale;
//	double *data4;
//	double *data5;
//	char *data6;
//	int i, j;
//	FILE *fp;
//
//	IplImage* img = cvLoadImage(".\\1.bmp", 0);
//	if (!img)
//	{
//		printf("can't open the image...\n");
//
//	}
//
//	//fp=fopen(".\\cvget.txt","w");
//	//for( i = 0; i < img->height; i++ )
//	// 
//	//{
//	//    for( j =0; j < img->width ; j++)
//	//      fprintf (fp,"%f\t", cvGet2D(img, i, j).val[0]);
//	//    fprintf(fp,"\n");
//	//}
//	//fclose(fp);
//
//	data1 = cvCreateMat(img->height, img->width, CV_8UC1);
//	cvConvert(img, data1);
//
//	data2 = apLogUC2_strengthened(data1->data.ptr, img->imageSize);//..........
//	data3 = ap1DTo2Dd(data2, img->height, img->width);
//	//largescale=apLTV(data3,img->height, img->width, 0.4, 0.2,100);
//	largescale = apLTV_new(data3, img->height, img->width, 0.4, 0.1, 0.01, 100);
//	apDataPrint2Dd(largescale, img->height, img->width, ".\\largescale.txt");
//	//smallscale=apGetSmallScale(data3, largescale, img->height, img->width);
//	//LQI
//	for (i = 0; i < img->height; i++)
//		for (j = 0; j < img->height; j++)
//		{
//			largescale[i][j] = data3[i][j] / largescale[i][j];
//		}
//	//apDataPrint2Dd(smallscale,img->height, img->width,".\\smallscale.txt");
//	data4 = ap2DTo1Dd(largescale, img->height, img->width);
//	data5 = apExp1D_strengthened(data4, img->imageSize);
//	//apDataPrint1Dd(data5,img->imageSize,".\\smallscale.txt");
//	//dataNormalization(data5,img->imageSize,0,255);//..........
//
//	data6 = apDtoC(data5, img->imageSize);//OK 
//
//	apCopyMatrix1Dc(data6, img->imageData, img->imageSize);
//	printf("conduct display img.....\n");
//	cvNamedWindow("Image", 1);
//	cvShowImage("Image", img);
//	cvWaitKey(0);
//	cvDestroyWindow("Image");
//	cvSaveImage(".\\Snorm.jpg", img, 0);
//
//	apReleaseMatrix1Duc(data1);
//	apReleaseMatrix1Dd(data2);
//	apReleaseMatrix2Dd(data3, img->height);
//	apReleaseMatrix2Dd(largescale, img->height);
//	apReleaseMatrix2Dd(smallscale, img->height);
//	apReleaseMatrix1Dd(data4);
//	apReleaseMatrix1Dd(data5);
//	apReleaseMatrix1Dc(data6);
//
//	cvReleaseMat(&largedct);
//	cvReleaseMat(&data1);
//	cvReleaseImage(&img);
//}