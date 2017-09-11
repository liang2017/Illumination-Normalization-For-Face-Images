#include "apMatrix.h"
//#include "apReadShape.h"


/****************************************************Matirx Creation***************************************************************/

/**************************************************************************
function: create matrix (2D unsigned char)
input:int row, int col
output:unsigned char**
*********************************************************************/
unsigned char** apCreateMatrix2Duc(int row, int col)
{
	int i = 0, j = 0;
	unsigned char **data = NULL;
	data = (unsigned char**)calloc(row, sizeof(unsigned char*));

	if (data == NULL) { printf("\n matrix creation failed"); return NULL; }

	for (i = 0; i < row; i++)
	{
		data[i] = (unsigned char*)calloc(col, sizeof(unsigned char));

		if (data[i] == NULL) { printf("\n matrix creation failed"); return NULL; }
	}
	return data;
}

/**************************************************************************
function: create matrix (2D int)
input:int row, int col
output:int** 
*********************************************************************/
int** apCreateMatrix2Di(int row, int col)
{
	int i = 0, j = 0;
	int **data = NULL;
	data = (int**)calloc(row, sizeof(int*));
	if (data == NULL) { printf("\n matrix creation failed"); return NULL; }
	for (i = 0; i < row; i++)
	{
		data[i] = (int*)calloc(col, sizeof(int));
		if (data[i] == NULL) { printf("\n matrix creation failed"); return NULL; }
	}
	return data;
}

/**************************************************************************
function: create matrix (2D long)
input:int row, int col
output:long**
*********************************************************************/
long** apCreateMatrix2Dl(int row, int col)
{
	int i = 0, j = 0;
	long **data = NULL;
	data = (long**)calloc(row, sizeof(long*));
	if (data == NULL) { printf("\n matrix creation failed"); return NULL; }
	for (i = 0; i < row; i++)
	{
		data[i] = (long*)calloc(col, sizeof(long));
		if (data[i] == NULL) { printf("\n matrix creation failed"); return NULL; }
	}
	return data;
}

/**************************************************************************
function: create matrix (2D float)
input:int row, int col
output:float**
*********************************************************************/
float** apCreateMatrix2Df(int row, int col)
{
	int i = 0, j = 0;
	float **data = NULL;
	data = (float**)calloc(row, sizeof(float*));
	if (data == NULL) { printf("\n matrix creation failed"); return NULL; }
	for (i = 0; i < row; i++)
	{
		data[i] = (float*)calloc(col, sizeof(float));
		if (data[i] == NULL) { printf("\n matrix creation failed"); return NULL; }
	}
	return data;
}

/**************************************************************************
function: create matrix (2D double)
input:int row, int col
output:double **
*********************************************************************/
double **apCreateMatrix2Dd(int row, int col)
{
	double **z;
	int i, j;
	z = (double **)calloc(row, sizeof(double *));
	if (z == NULL)
	{
		printf("\n matrix creation failed");
		return NULL;
	}
	for (i = 0; i < row; i++)
	{
		z[i] = (double *)calloc(col, sizeof(double));
		if (z[i] == NULL)
		{
			printf("\n matrix creation failed");
			return NULL;
		}
	}
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			z[i][j] = 0;
	return z;
}

/**************************************************************************
function: create matrix (2D unsigned int)
input:int row, int col
output:unsigned int**
*********************************************************************/
unsigned int** apCreateMatrix2Dui(int row, int col)
{
	int i = 0, j = 0;
	unsigned int **data = NULL;
	data = (unsigned int**)calloc(row, sizeof(unsigned int*));
	if (data == NULL) { printf("\n matrix creation failed"); return NULL; }
	for (i = 0; i < row; i++)
	{
		data[i] = (unsigned int*)calloc(col, sizeof(unsigned int));
		if (data[i] == NULL) { printf("\n matrix creation failed"); return NULL; }
	}
	return data;
}

/**************************************************************************
function: create matrix (2D unsigned long)
input:int row, int col
output:unsigned long**
*********************************************************************/
unsigned long** apCreateMatrix2Dul(int row, int col)
{
	int i = 0, j = 0;
	unsigned long **data = NULL;
	data = (unsigned long**)calloc(row, sizeof(unsigned long*));
	if (data == NULL) { printf("\n matrix creation failed"); return NULL; }
	for (i = 0; i < row; i++)
	{
		data[i] = (unsigned long*)calloc(col, sizeof(unsigned long));
		if (data[i] == NULL) { printf("\n matrix creation failed"); return NULL; }
	}
	return data;
}

/**************************************************************************
function: create matrix (2D char)
input:int row, int col
output:char**
*********************************************************************/
char** apCreateMatrix2Dc(int row, int col)
{
	int i = 0, j = 0;
	char **data = NULL;
	data = (char**)calloc(row, sizeof(char*));
	if (data == NULL) { printf("\n matrix creation failed"); return NULL; }
	for (i = 0; i < row; i++)
	{
		data[i] = (char*)calloc(col, sizeof(char));
		if (data[i] == NULL) { printf("\n matrix creation failed"); return NULL; }
	}
	return data;
}


/****************************************************Matirx Release***************************************************************/

void apReleaseMatrix2Duc(unsigned char** data, int row)
{
	int i = 0, j = 0;
	if (data == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		free(data[i]);
	}
	free(data);
	data = NULL;
}

void apReleaseMatrix2Di(int** data, int row)
{
	int i = 0, j = 0;
	if (data == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		free(data[i]);
	}
	free(data);
	data = NULL;
}


void apReleaseMatrix2Dl(long** data, int row)
{
	int i = 0, j = 0;
	if (data == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		free(data[i]);
	}
	free(data);
	data = NULL;
}


void apReleaseMatrix2Df(float** data, int row)
{
	int i = 0, j = 0;
	if (data == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		free(data[i]);
	}
	free(data);
	data = NULL;
}


void apReleaseMatrix2Dd(double** data, int row)
{
	int i = 0;
	if (data == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		free(data[i]);
	}
	free(data);
	data = NULL;
}

void apReleaseMatrix2Dc(char** data, int row)
{
	int i = 0, j = 0;
	if (data == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		free(data[i]);
		data[i] = NULL;
	}
	free(data);
	data = NULL;
}

void apReleaseMatrix2Dui(unsigned int** data, int row)
{
	int i = 0, j = 0;
	if (data == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		free(data[i]);
		data[i] = NULL;
	}
	free(data);
	data = NULL;
}

void apReleaseMatrix2Dul(unsigned long** data, int row)
{
	int i = 0, j = 0;
	if (data == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		free(data[i]);
		data[i] = NULL;
	}
	free(data);
	data = NULL;
}

/************************************************************Matrix Copy*****************************************************************************/

void apCopyMatrix2Duc(unsigned char** source, unsigned char** dest, int row, int col)
{
	int i = 0, j = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			dest[i][j] = source[i][j];
		}
	}

}

void apCopyMatrix2Di(int** source, int** dest, int row, int col)
{
	int i = 0, j = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			dest[i][j] = source[i][j];
		}
	}

}

void apCopyMatrix2Dl(long** source, long** dest, int row, int col)
{
	int i = 0, j = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			dest[i][j] = source[i][j];
		}
	}

}

void apCopyMatrix2Df(float ** source, float** dest, int row, int col)
{
	int i = 0, j = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			dest[i][j] = source[i][j];
		}
	}

}


void apCopyMatrix2Dd(double** source, double** dest, int row, int col)
{
	int i = 0, j = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			dest[i][j] = source[i][j];
		}
	}

}


void apCopyMatrix2Dc(char** source, char** dest, int row, int col)
{
	int i = 0, j = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			dest[i][j] = source[i][j];
		}
	}

}

void apCopyMatrix2Dui(unsigned int** source, unsigned int** dest, int row, int col)
{
	int i = 0, j = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			dest[i][j] = source[i][j];
		}
	}

}

void apCopyMatrix2Dul(unsigned long** source, unsigned long** dest, int row, int col)
{
	int i = 0, j = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			dest[i][j] = source[i][j];
		}
	}

}


/*********************************************************Matrix Creation*************************************************************************/
char *apCreateMatrix1Dc(int row)
{
	char *z = NULL;
	z = (char *)calloc(row, sizeof(char));
	if (z == NULL)
	{
		printf("\n unable to create...");
		return NULL;
	}

	return z;
}

double *apCreateMatrix1Dd(int row)
{
	double *z = NULL;
	z = (double *)calloc(row, sizeof(double));
	if (z == NULL)
	{
		printf("\n unable to create...");
		return NULL;
	}

	return z;
}


float *apCreateMatrix1Df(int len)
{
	float *z = NULL;
	int i;
	z = (float *)calloc(len, sizeof(float));
	if (z == NULL)
	{
		printf("\n unable to create...");
		return NULL;
	}

	return z;
}


int *apCreateMatrix1Di(int len)
{
	int *z = NULL;
	int i;
	z = (int *)calloc(len, sizeof(int));
	if (z == NULL)
	{
		printf("\n unable to create...");
		return NULL;
	}

	return z;
}

unsigned char* apCreateMatrix1Duc(int len)
{
	unsigned char *z = NULL;
	z = (unsigned char *)calloc(len, sizeof(unsigned char));
	if (z == NULL)
	{
		printf("\n unable to create...");
		return NULL;
	}

	return z;
}

long* apCreateMatrix1Dl(int len)
{
	long *z = NULL;
	z = (long *)calloc(len, sizeof(long));
	if (z == NULL)
	{
		printf("\n unable to create...");
		return NULL;
	}

	return z;
}


unsigned long* apCreateMatrix1Dul(int len)
{
	unsigned long *z = NULL;
	z = (unsigned long *)calloc(len, sizeof(unsigned long));
	if (z == NULL)
	{
		printf("\n unable to create...");
		return NULL;
	}

	return z;
}

unsigned int* apCreateMatrix1Dui(int len)
{
	unsigned int *z = NULL;
	z = (unsigned int *)calloc(len, sizeof(unsigned int));
	if (z == NULL)
	{
		printf("\n unable to create...");
		return NULL;
	}

	return z;
}

/************************************************************Matrix Copy******************************************************************/
void apCopyMatrix1Dc(char* source, char* dest, int len)
{
	int i = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }

	for (i = 0; i < len; i++)
	{
		dest[i] = source[i];
	}

}


void apCopyMatrix1Duc(unsigned char* source, unsigned char* dest, int len)
{
	int i = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }

	for (i = 0; i < len; i++)
	{
		dest[i] = source[i];
	}

}

void apCopyMatrix1Dd(double* source, double* dest, int len)
{
	int i = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }

	for (i = 0; i < len; i++)
	{
		dest[i] = source[i];
	}

}


void apCopyMatrix1Di(int* source, int* dest, int len)
{
	int i = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }

	for (i = 0; i < len; i++)
	{
		dest[i] = source[i];
	}

}


void apCopyMatrix1Df(float* source, float* dest, int len)
{
	int i = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }

	for (i = 0; i < len; i++)
	{
		dest[i] = source[i];
	}

}

void apCopyMatrix1Dl(long* source, long* dest, int len)
{
	int i = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }

	for (i = 0; i < len; i++)
	{
		dest[i] = source[i];
	}

}


void apCopyMatrix1Dui(unsigned int* source, unsigned int* dest, int len)
{
	int i = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }

	for (i = 0; i < len; i++)
	{
		dest[i] = source[i];
	}

}

void apCopyMatrix1Dul(unsigned long* source, unsigned long* dest, int len)
{
	int i = 0;
	if (source == NULL || dest == NULL) { printf("\n unable to copy..."); return NULL; }

	for (i = 0; i < len; i++)
	{
		dest[i] = source[i];
	}

}

/********************************************************Matric Release***************************************************************/
void apReleaseMatrix1Duc(unsigned char *data)
{
	if (data == NULL) return NULL;
	free(data);
	data = NULL;
}

void apReleaseMatrix1Dc(char *data)
{
	if (data == NULL) return NULL;
	free(data);
	data = NULL;
}

void apReleaseMatrix1Dd(double *data)
{
	if (data == NULL) return NULL;
	free(data);
	data = NULL;
}

void apReleaseMatrix1Di(int *data)
{
	if (data == NULL) return NULL;
	free(data);
	data = NULL;
}

void apReleaseMatrix1Dl(long *data)
{
	if (data == NULL) return NULL;
	free(data);
	data = NULL;
}

void apReleaseMatrix1Df(float *data)
{
	if (data == NULL) return NULL;
	free(data);
	data = NULL;
}


void apReleaseMatrix1Dui(unsigned int *data)
{
	if (data == NULL) return NULL;
	free(data);
	data = NULL;
}

void apReleaseMatrix1Dul(unsigned long *data)
{
	if (data == NULL) return NULL;
	free(data);
	data = NULL;
}

/***********************************************************Matrix Transform in Dimension******************************************************/
double **ap1DTo2Dd(double *data, int row, int col)
{
	int i = 0, j = 0;
	double **M = NULL;

	if (data == NULL) return NULL;

	M = apCreateMatrix2Dd(row, col);
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			M[i][j] = data[i*col + j];
	return M;
}

double *ap2DTo1Dd(double **data, int row, int col)
{
	int len = row*col;
	int k = 0, i = 0, j = 0;
	double *M = NULL;

	if (data == NULL) return NULL;

	M = apCreateMatrix1Dd(len);
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			M[k++] = data[i][j];
	return M;
}

unsigned int *ap2DTo1Dui(unsigned int **data, int row, int col)
{
	int len = row*col;
	int k = 0, i = 0, j = 0;
	unsigned int *M = NULL;

	if (data == NULL) return NULL;

	M = apCreateMatrix1Dui(len);
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			M[k++] = data[i][j];
	return M;
}

int *ap2DTo1Di(int **data, int row, int col)
{
	int len = row*col;
	int k = 0, i = 0, j = 0;
	int *M = NULL;

	if (data == NULL) return NULL;

	M = apCreateMatrix1Di(len);
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			M[k++] = data[i][j];
	return M;
}

long *ap2DTo1Dl(long **data, int row, int col)
{
	int len = row*col;
	int k = 0, i = 0, j = 0;
	long *M = NULL;

	if (data == NULL) return NULL;

	M = apCreateMatrix1Dl(len);
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			M[k++] = data[i][j];
	return M;
}


unsigned long *ap2DTo1Dul(unsigned long **data, int row, int col)
{
	int len = row*col;
	int k = 0, i = 0, j = 0;
	unsigned long *M = NULL;

	if (data == NULL) return NULL;

	M = apCreateMatrix1Dul(len);
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			M[k++] = data[i][j];
	return M;
}

float *ap2DTo1Df(float **data, int row, int col)
{
	int len = row*col;
	int k = 0, i = 0, j = 0;
	float *M = NULL;

	if (data == NULL) return NULL;

	M = apCreateMatrix1Df(len);
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			M[k++] = data[i][j];
	return M;
}


unsigned char *ap2DTo1Duc(unsigned char **data, int row, int col)
{
	int len = row*col;
	int k = 0, i = 0, j = 0;
	unsigned char *M = NULL;

	if (data == NULL) return NULL;

	M = apCreateMatrix1Duc(len);
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			M[k++] = data[i][j];
	return M;
}

/*********************************************************Display Matrix****************************************************************/
void apDisMatrix2Di(int **p, int row, int col)
{
	int i, j;

	if (p == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		printf("row=%d\n", i);
		for (j = 0; j < col; j++)
			printf("%d\t", p[i][j]);
	}
}

void apDisMatrix2Dd(double **p, int row, int col)
{
	int i, j;

	if (p == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		printf("row=%d\n", i);
		for (j = 0; j < col; j++)
			printf("%f\t", p[i][j]);
	}
}

void apDisMatrix2Df(float **p, int row, int col)
{
	int i, j;

	if (p == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		printf("row=%d\n", i);
		for (j = 0; j < col; j++)
			printf("%f\t", p[i][j]);
	}
}

void apDisMatrix2Duc(unsigned char **p, int row, int col)
{
	int i, j;

	if (p == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		printf("row=%d\n", i);
		for (j = 0; j < col; j++)
			printf("%d\t", p[i][j]);
	}
}


void apDisMatrix2Dl(long **p, int row, int col)
{
	int i, j;

	if (p == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		printf("row=%d\n", i);
		for (j = 0; j < col; j++)
			printf("%ld\t", p[i][j]);
	}
}

void apDisMatrix1Di(int *p, int len)
{
	int i;

	if (p == NULL) return NULL;

	printf("len=%d\n", len);
	for (i = 0; i < len; i++)
	{
		printf("%i\t", p[i]);
	}
}

void apDisMatrix2Dui(unsigned int **p, int row, int col)
{
	int i, j;

	if (p == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		printf("row=%d\n", i);
		for (j = 0; j < col; j++)
			printf("%f\t", p[i][j]);
	}
}

void apDisMatrix2Dul(unsigned long **p, int row, int col)
{
	int i, j;

	if (p == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		printf("row=%d\n", i);
		for (j = 0; j < col; j++)
			printf("%f\t", p[i][j]);
	}
}

void apDisMatrix2Dc(char **p, int row, int col)
{
	int i, j;

	if (p == NULL) return NULL;

	for (i = 0; i < row; i++)
	{
		if (p[i] == NULL) continue;
		printf("row=%d\n", i);
		for (j = 0; j < col; j++)
			printf("%c\t", p[i][j]);
	}
}

//one demension
void apDisMatrix1Dd(double *p, int len)
{
	int i;
	if (p == NULL) return NULL;

	printf("len=%d\n", len);
	for (i = 0; i < len; i++)
	{
		printf("%f\t", p[i]);
	}
}

void apDisMatrix1Df(float *p, int len)
{
	int i;
	if (p == NULL) return NULL;

	printf("len=%d\n", len);
	for (i = 0; i < len; i++)
	{
		printf("%f\t", p[i]);
	}
}

void apDisMatrix1Dl(long *p, int len)
{
	int i;
	if (p == NULL) return NULL;

	printf("len=%d\n", len);
	for (i = 0; i < len; i++)
	{
		printf("%ld\t", p[i]);
	}
}


void apDisMatrix1Dui(unsigned int *p, int len)
{
	int i;
	if (p == NULL) return NULL;

	printf("len=%d\n", len);
	for (i = 0; i < len; i++)
	{
		printf("%d\t", p[i]);
	}
}


void apDisMatrix1Dul(unsigned long *p, int len)
{
	int i;
	if (p == NULL) return NULL;

	printf("len=%d\n", len);
	for (i = 0; i < len; i++)
	{
		printf("%ld\t", p[i]);
	}
}

void apDisMatrix1Duc(unsigned char *p, int len)
{
	int i;
	if (p == NULL) return NULL;

	printf("len=%d\n", len);
	for (i = 0; i < len; i++)
	{
		printf("%d\t", p[i]);
	}
}


void apDisMatrix1Dc(char *p, int len)
{
	int i;
	if (p == NULL) return NULL;

	printf("len=%d\n", len);
	for (i = 0; i < len; i++)
	{
		printf("%c\t", p[i]);
	}
}

/********************************************************Matrix Link************************************************************************/
int *apMatrixLink1Di(int *matrix1, int len1, int *matrix2, int len2)
{
	int *finaldata = NULL;
	int i = 0;
	if (matrix1 == NULL) { printf("\nplease check the matrix. The first pointer is NULL\n"); return NULL; }
	if (matrix2 == NULL) { printf("\nplease check the matrix. The second pointer is NULL\n"); return NULL; }
	finaldata = (int *)calloc(len1 + len2, sizeof(int));
	if (finaldata == NULL)
	{
		printf("\n矩阵连接过程中内存分配失败\n");
		return NULL;
	}
	for (i = 0; i < len1; i++)
	{
		finaldata[i] = matrix1[i];
	}
	for (i = 0; i < len2; i++)
		finaldata[i + len1] = matrix2[i];
	return finaldata;
}


long *apMatrixLink1Dl(long *matrix1, int len1, long *matrix2, int len2)
{
	long *finaldata = NULL;
	int i = 0;
	if (matrix1 == NULL) { printf("\nplease check the matrix. The first pointer is NULL\n"); return NULL; }
	if (matrix2 == NULL) { printf("\nplease check the matrix. The second pointer is NULL\n"); return NULL; }
	finaldata = (long *)calloc(len1 + len2, sizeof(long));
	if (finaldata == NULL)
	{
		printf("\nThe memory allocation failed in the process of matrix linkage\n");
		return NULL;
	}
	for (i = 0; i < len1; i++)
	{
		finaldata[i] = matrix1[i];
	}
	for (i = 0; i < len2; i++)
		finaldata[i + len1] = matrix2[i];
	return finaldata;
}

double *apMatrixLink1Dd(double *matrix1, int len1, double *matrix2, int len2)
{
	double *finaldata = NULL;
	int i = 0;
	if (matrix1 == NULL) { printf("\nplease check the matrix. The first pointer is NULL\n"); return NULL; }
	if (matrix2 == NULL) { printf("\nplease check the matrix. The second pointer is NULL\n"); return NULL; }
	finaldata = (double *)calloc(len1 + len2, sizeof(double));
	if (finaldata = NULL)
	{
		printf("\nThe memory allocation failed in the process of matrix linkage\n");
		return NULL;
	}
	for (i = 0; i < len1; i++)
	{
		finaldata[i] = matrix1[i];
	}
	for (i = 0; i < len2; i++)
		finaldata[i + len1] = matrix2[i];
	return finaldata;
}


float *apMatrixLink1Df(float *matrix1, int len1, float *matrix2, int len2)
{
	float *finaldata = NULL;
	int i = 0;
	if (matrix1 == NULL) { printf("\nplease check the matrix. The first pointer is NULL\n"); return NULL; }
	if (matrix2 == NULL) { printf("\nplease check the matrix. The second pointer is NULL\n"); return NULL; }
	finaldata = (float *)calloc(len1 + len2, sizeof(float));
	if (finaldata = NULL)
	{
		printf("\nThe memory allocation failed in the process of matrix linkage\n");
		return NULL;
	}
	for (i = 0; i < len1; i++)
	{
		finaldata[i] = matrix1[i];
	}
	for (i = 0; i < len2; i++)
		finaldata[i + len1] = matrix2[i];
	return finaldata;
}


char *apMatrixLink1Dc(char *matrix1, int len1, char *matrix2, int len2)
{
	char *finaldata = NULL;
	int i = 0;
	if (matrix1 == NULL) { printf("\nplease check the matrix. The first pointer is NULL\n"); return NULL; }
	if (matrix2 == NULL) { printf("\nplease check the matrix. The second pointer is NULL\n"); return NULL; }
	finaldata = (char *)calloc(len1 + len2, sizeof(char));
	if (finaldata = NULL)
	{
		printf("\nThe memory allocation failed in the process of matrix linkage\n");
		return NULL;
	}
	for (i = 0; i < len1; i++)
	{
		finaldata[i] = matrix1[i];
	}
	for (i = 0; i < len2; i++)
		finaldata[i + len1] = matrix2[i];
	return finaldata;
}


unsigned char *apMatrixLink1Duc(unsigned char *matrix1, int len1, unsigned char *matrix2, int len2)
{
	unsigned char *finaldata = NULL;
	int i = 0;
	if (matrix1 == NULL) { printf("\nplease check the matrix. The first pointer is NULL\n"); return NULL; }
	if (matrix2 == NULL) { printf("\nplease check the matrix. The second pointer is NULL\n"); return NULL; }
	finaldata = (unsigned char *)calloc(len1 + len2, sizeof(unsigned char));
	if (finaldata = NULL)
	{
		printf("\nThe memory allocation failed in the process of matrix linkage\n");
		return NULL;
	}
	for (i = 0; i < len1; i++)
	{
		finaldata[i] = matrix1[i];
	}
	for (i = 0; i < len2; i++)
		finaldata[i + len1] = matrix2[i];
	return finaldata;
}


unsigned int *apMatrixLink1Dui(unsigned int *matrix1, int len1, unsigned int *matrix2, int len2)
{
	unsigned int *finaldata = NULL;
	int i = 0;
	if (matrix1 == NULL) { printf("\nplease check the matrix. The first pointer is NULL\n"); return NULL; }
	if (matrix2 == NULL) { printf("\nplease check the matrix. The second pointer is NULL\n"); return NULL; }
	finaldata = (unsigned int *)calloc(len1 + len2, sizeof(unsigned int));
	if (finaldata = NULL)
	{
		printf("\nThe memory allocation failed in the process of matrix linkage\n");
		return NULL;
	}
	for (i = 0; i < len1; i++)
	{
		finaldata[i] = matrix1[i];
	}
	for (i = 0; i < len2; i++)
		finaldata[i + len1] = matrix2[i];
	return finaldata;
}

unsigned long *apMatrixLink1Dul(unsigned long *matrix1, int len1, unsigned long *matrix2, int len2)
{
	unsigned long *finaldata = NULL;
	int i = 0;
	if (matrix1 == NULL) { printf("\nplease check the matrix. The first pointer is NULL\n"); return NULL; }
	if (matrix2 == NULL) { printf("\nplease check the matrix. The second pointer is NULL\n"); return NULL; }
	finaldata = (unsigned long *)calloc(len1 + len2, sizeof(unsigned long));
	if (finaldata = NULL)
	{
		printf("\nThe memory allocation failed in the process of matrix linkage\n");
		return NULL;
	}
	for (i = 0; i < len1; i++)
	{
		finaldata[i] = matrix1[i];
	}
	for (i = 0; i < len2; i++)
		finaldata[i + len1] = matrix2[i];
	return finaldata;
}

/**********************************************************Create Point List**************************************************************************/
ApPointsList2Dd apCreatePointsList2Dd(int sampleNum, int pointsNum)
{
	int i;
	ApPointsList2Dd dataList;
	dataList.sampleNum = sampleNum;
	dataList.pointsNum = pointsNum;
	dataList.data = (ApPoint2Dd**)calloc(sampleNum, sizeof(ApPoint2Dd*));
	if (dataList.data == NULL)
	{
		printf("\n point list creation failed...");
		return NULL;
	}

	for (i = 0; i < sampleNum; i++)
	{
		dataList.data[i] = (ApPoint2Dd*)calloc(pointsNum, sizeof(ApPoint2Dd));
		if (dataList.data[i] == NULL)
		{
			printf("\n point list creation failed...");
			return NULL;
		}
	}
	return dataList;
}

ApPointsList2Di apCreatePointsList2Di(int sampleNum, int pointsNum)
{
	int i;
	ApPointsList2Di dataList;
	dataList.sampleNum = sampleNum;
	dataList.pointsNum = pointsNum;
	dataList.data = (ApPoint2Di**)calloc(sampleNum, sizeof(ApPoint2Di*));
	if (dataList.data == NULL)
	{
		printf("\n point list creation failed...");
		return NULL;
	}

	for (i = 0; i < sampleNum; i++)
	{
		dataList.data[i] = (ApPoint2Di*)calloc(pointsNum, sizeof(ApPoint2Di));
		if (dataList.data[i] == NULL)
		{
			printf("\n point list creation failed...");
			return NULL;
		}
	}
	return dataList;
}

ApPointsList2Df apCreatePointsList2Df(int sampleNum, int pointsNum)
{
	int i;
	ApPointsList2Df dataList;
	dataList.sampleNum = sampleNum;
	dataList.pointsNum = pointsNum;
	dataList.data = (ApPoint2Df**)calloc(sampleNum, sizeof(ApPoint2Df*));
	if (dataList.data == NULL)
	{
		printf("\n point list creation failed...");
		return NULL;
	}

	for (i = 0; i < sampleNum; i++)
	{
		dataList.data[i] = (ApPoint2Df*)calloc(pointsNum, sizeof(ApPoint2Df));
		if (dataList.data[i] == NULL)
		{
			printf("\n point list creation failed...");
			return NULL;
		}
	}
	return dataList;
}

ApPointsList2Dl apCreatePointsList2Dl(int sampleNum, int pointsNum)
{
	int i;
	ApPointsList2Dl dataList;
	dataList.sampleNum = sampleNum;
	dataList.pointsNum = pointsNum;
	dataList.data = (ApPoint2Dl**)calloc(sampleNum, sizeof(ApPoint2Dl*));
	if (dataList.data == NULL)
	{
		printf("\n point list creation failed...");
		return NULL;
	}

	for (i = 0; i < sampleNum; i++)
	{
		dataList.data[i] = (ApPoint2Dl*)calloc(pointsNum, sizeof(ApPoint2Dl));
		if (dataList.data[i] == NULL)
		{
			printf("\n point list creation failed...");
			return NULL;
		}
	}
	return dataList;
}

/****************************************************************Release Point List********************************************************************/
void apReleasePointsList2Dl(ApPointsList2Dl pointsList)
{
	int i = 0;
	if (pointsList.data == NULL) return;
	for (i = 0; i < pointsList.sampleNum; i++)
	{
		free(pointsList.data[i]);
		pointsList.data[i] = NULL;
	}
	free(pointsList.data);
	pointsList.data = NULL;
}

void apReleasePointsList2Di(ApPointsList2Di pointsList)
{
	int i = 0;
	if (pointsList.data == NULL) return;
	for (i = 0; i < pointsList.sampleNum; i++)
	{
		if (pointsList.data[i] != NULL)
			free(pointsList.data[i]);
		pointsList.data[i] = NULL;
	}
	free(pointsList.data);
	pointsList.data = NULL;
}

void apReleasePointsList2Dd(ApPointsList2Dd pointsList)
{
	int i = 0;
	if (pointsList.data == NULL) return;
	for (i = 0; i < pointsList.sampleNum; i++)
	{
		if (pointsList.data[i] != NULL)
			free(pointsList.data[i]);
		pointsList.data[i] = NULL;
	}
	free(pointsList.data);
	pointsList.data = NULL;
}

void apReleasePointsList2Df(ApPointsList2Df pointsList)
{
	int i = 0;
	if (pointsList.data == NULL) return;
	for (i = 0; i < pointsList.sampleNum; i++)
	{
		if (pointsList.data[i] != NULL)
			free(pointsList.data[i]);
		pointsList.data[i] = NULL;
	}
	free(pointsList.data);
	pointsList.data = NULL;
}

/************************************************************Reverse Matrix***************************************************************************/
double **apReverseMatrix2Dd(double **data, int row, int col)
{
	double **result = NULL;
	int i = 0, j = 0;
	if (data == NULL) { printf("\n The matrix for reverse is NULL\n"); return NULL; }
	result = apCreateMatrix2Dd(row, col);
	for (i = 0; i < row; i++)
	{
		if (result[i] == NULL) { printf("\n The matrix[%d] for reverse is NULL\n", i); return NULL; }
		for (j = 0; j < col; j++)
		{
			result[i][j] = data[j][i];
		}
	}
	return result;
}

int **apReverseMatrix2Di(int **data, int row, int col)
{
	int **result = NULL;
	int i = 0, j = 0;

	if (data == NULL) { printf("\n The matrix for reverse is NULL\n"); return NULL; }
	result = apCreateMatrix2Di(row, col);
	for (i = 0; i < row; i++)
	{
		if (result[i] == NULL) { printf("\n The matrix[%d] for reverse is NULL\n", i); return NULL; }
		for (j = 0; j < col; j++)
		{
			result[i][j] = data[j][i];
		}
	}
	return result;
}

float **apReverseMatrix2Df(float **data, int row, int col)
{
	float **result = NULL;
	int i = 0, j = 0;

	if (data == NULL) { printf("\n The matrix for reverse is NULL\n"); return NULL; }
	result = apCreateMatrix2Df(row, col);
	for (i = 0; i < row; i++)
	{
		if (result[i] == NULL) { printf("\n The matrix[%d] for reverse is NULL\n", i); return NULL; }
		for (j = 0; j < col; j++)
		{
			result[i][j] = data[j][i];
		}
	}
	return result;
}


long **apReverseMatrix2Dl(long **data, int row, int col)
{
	long **result = NULL;
	int i = 0, j = 0;

	if (data == NULL) { printf("\n The matrix for reverse is NULL\n"); return NULL; }
	result = apCreateMatrix2Dl(row, col);
	for (i = 0; i < row; i++)
	{
		if (result[i] == NULL) { printf("\n The matrix[%d] for reverse is NULL\n", i); return NULL; }
		for (j = 0; j < col; j++)
		{
			result[i][j] = data[j][i];
		}
	}
	return result;
}


char **apReverseMatrix2Dc(char **data, int row, int col)
{
	char **result = NULL;
	int i = 0, j = 0;

	if (data == NULL) { printf("\n The matrix for reverse is NULL\n"); return NULL; }
	result = apCreateMatrix2Dc(row, col);
	for (i = 0; i < row; i++)
	{
		if (result[i] == NULL) { printf("\n The matrix[%d] for reverse is NULL\n", i); return NULL; }
		for (j = 0; j < col; j++)

		{
			result[i][j] = data[j][i];
		}
	}
	return result;
}

unsigned char **apReverseMatrix2Duc(unsigned char **data, int row, int col)
{
	unsigned char **result = NULL;
	int i = 0, j = 0;

	if (data == NULL) { printf("\n The matrix for reverse is NULL\n"); return NULL; }
	result = apCreateMatrix2Duc(row, col);
	for (i = 0; i < row; i++)
	{
		if (result[i] == NULL) { printf("\n The matrix[%d] for reverse is NULL\n", i); return NULL; }
		for (j = 0; j < col; j++)
		{
			result[i][j] = data[j][i];
		}
	}
	return result;
}


unsigned int **apReverseMatrix2Dui(unsigned int **data, int row, int col)
{
	unsigned int **result = NULL;
	int i = 0, j = 0;

	if (data == NULL) { printf("\n The matrix for reverse is NULL\n"); return NULL; }
	result = apCreateMatrix2Dui(row, col);
	for (i = 0; i < row; i++)
	{
		if (result[i] == NULL) { printf("\n The matrix[%d] for reverse is NULL\n", i); return NULL; }
		for (j = 0; j < col; j++)
		{
			result[i][j] = data[j][i];
		}
	}
	return result;
}


unsigned long **apReverseMatrix2Dul(unsigned long **data, int row, int col)
{
	unsigned long **result = NULL;
	int i = 0, j = 0;

	if (data == NULL) { printf("\n The matrix for reverse is NULL\n"); return NULL; }
	result = apCreateMatrix2Dul(row, col);
	for (i = 0; i < row; i++)
	{
		if (result[i] == NULL) { printf("\n The matrix[%d] for reverse is NULL\n", i); return NULL; }
		for (j = 0; j < col; j++)
		{
			result[i][j] = data[j][i];
		}
	}
	return result;
}


void apMatrixcopy1Dd(double *dest, double *source, int dimension)
{
	int i;
	if (source == NULL || dest == NULL)
		printf("cannot perform copy");

	for (i = 0; i < dimension; i++)
		dest[i] = source[i];

}

void apMatrixInvert(double **dest, double **src, int src_row, int src_col)
{
	int i, j;
	if (src == NULL || dest == NULL)
		printf("cannot perform invert");

	for (i = 0; i < src_row; i++)
		for (j = 0; j < src_col; j++)
		{
			dest[j][i] = src[i][j];
		}
}

double findmax(double *data, int size)
{
	int i;
	double tempmax;
	tempmax = data[0];
	for (i = 1; i < size; i++)
	{
		if (tempmax < data[i])
			tempmax = data[i];
	}
	return tempmax;
}

double findmin(double *data, int size)
{
	int i;
	double tempmin;
	tempmin = data[0];
	for (i = 1; i < size; i++)
	{
		if (tempmin > data[i])
			tempmin = data[i];
	}
	return tempmin;
}