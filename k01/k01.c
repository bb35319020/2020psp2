#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val,double ave,int n);
extern double var_online(double val,double ave,double square_ave,int n);


int main(void)
{
    double val,ave=0,square_ave=0,average=0,variance=0,estvariance=0;
    char fname[FILENAME_MAX];
    char buf[256];
    int n;
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
        n=1;

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        
        average=ave_online(val,ave,n);
        variance=var_online(val,ave,square_ave,n);
        square_ave=ave_online(val*val,square_ave,n); 
        ave=average;
        n=n+1;
    }
        estvariance=n*variance/(n-1);

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("mean:%f\n",ave);
    printf("variance:%f\n",variance);
    printf("population mean(estimated):%f\n",average);
    printf("population variance(estima):%f\n",estvariance);
    return 0;
}

double ave_online(double val,double ave,int n){
    return(n-1)*ave/n+val/n;
}
double var_online(double val,double ave,double square_ave,int n){
    return((n-1)*square_ave/n+val*val/n)-(ave*(n-1)/n+val/n)*(ave*(n-1)/n+val/n);
}