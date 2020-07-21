#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct DATE{
    int gender;
    double heights;
    double ID;
}
int main (void)
{
    int i=0,n=0,ID,gender;
    double heights;
    char fname1[FILENAME_MAX];
    char fname2[FILENAME_MAX];
    char buf1[256];
    char buf2[256];
    FILE *fp1;
    FILE *fp2;
    struct DATE date[14]

    printf("input the filename of sample: ");
    fgets(fname1,sizeof(fname1),stdin);
    fname1[strlen(fname1)-1]='\0';
    printf("the filename of sample :%s\n",fname1);

    printf("input the filename of sample: ");
    fgets(fname2,sizeof(fname2),stdin);
    fname2[strlen(fname2)-1]='\0';
    printf("the filename of sample :%s\n",fname2);
    
    fp1=fopen(fname1,"r");
    if(fp1==NULL){
        fputs("File open error\n",stdin);
        exit(EXIT_FAILURE);
    }

    fp2=fopen(fname2,"r");
    if(fp2==NULL){
        fputs("File open error\n",stdin);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf1,sizeof(buf1),fp1)!=NULL){
        sscan(buf1,"%d",&date[i].gender);
        sscan(buf1,"%.lf",&date[i].heights);
        i=i+1;
    }

    if(fclose(fp1)==EOF)
    
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    i=0;
    
    while(fgets(buf2,sizeof(buf2),fp2)!=NULL{
        sscan(buf2,"%d",&date[i].ID);
        date[i].ID=ID;
        i=i+1;
    }

    printf("whici ID's do you want?:");
    scanf("%d",&ID);
    printf("---");
    for(i=0;i<15,i++)
    {
        if(date[i].ID==ID)
        {
            printf("ID:%lf\n",date[i].date);
            if(date[i].gender==1)
            {
                printf("male\n");
            }
            else
            {
                printf("female\n");
            }
        printf("heights:,%.lf\n",&date[i].heights);
        n=n+1;
        }
        if(n==0)
        {
            printf("No date");
        }
    }

return 0;
 }