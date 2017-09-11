#ifndef apImgProcess_h
#define apImgProcess_h  

void apImgPrint(IplImage *img,char *path);
void apDataPrint2Dd(double **data,int row, int col,char *path);
void apDataPrint1Dd(double *data,int len,char *path);
void apDataPrint1Dc(char *data,int len,char *path);
unsigned char* apCtoUC(char* imageData, int size);
char* apUCtoC(unsigned char* imageData, int size);
char* apDtoC(double* imageData, int size);
char* apDtoC_strengthened(double* imageData, int size);

#endif