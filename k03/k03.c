#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#ifdef CONST_SEED
#define RAND_SEED 2020
#else
#include <time.h>
#define RAND_SEED ((unsigned) time(NULL))
#endif

extern double r_unif(void);
extern double r_stdnorm(void);

int main(int argc, char* argv[])
{
    int num_dummy;
    double mu;
    double sigma;
    int i;
    double dummy;

    if(argc<4)
    {
        return 1;

    }
    else
    {
        return 0;
    }
    

    sscanf(argv[3],"%d",&num_dummy);
    sscanf(argv[2],"%lf",&sigma);
    sscanf(argv[1],"%lf",&mu);


    printf("============================================\n");
    printf("template mean: %4.1lf\n",mu);
    printf("template standard deviation: %3.2lf\n",sigma);
    printf("Num of dummy data: %d\n",num_dummy);
    printf("============================================\n");

    srand(RAND_SEED);
    for(i=0;i<num_dummy;i=i+1)
    {
        /* r_stdnormを使って，1人のデータを捏造 */
        dummy =r_stdnorm()*sigma+mu;
        printf("%5.2lf\n",dummy);
    }

    return EXIT_SUCCESS;
}

double r_unif(void)                        /*平均０、分散１の標準正規乱数生成関数（box_mullr法）*/
{
    return (double)(rand()+1)/(RAND_MAX+2);
}

double r_stdnorm(void)                      /*新しいＡ県の5人の身長*/
{
    return sqrt( -2.0*log(r_unif()) ) * sin( 2.0* M_PI *r_unif() );
}
