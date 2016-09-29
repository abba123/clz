# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <time.h>

# include "clz.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0
#define loop 1000000
#define times 50


void clz_time(int num,FILE *fp)
{

    struct timespec start = {0, 0};
    struct timespec end = {0, 0};


    clock_gettime(CLOCK_ID, &start);
    for(int i=0; i<loop; i++) {
        clz_iteration(num);
    }
    clock_gettime(CLOCK_ID,&end);
    fprintf(fp,"%lf ",(double)(end.tv_sec - start.tv_sec)+(end.tv_nsec - start.tv_nsec)/ONE_SEC);


    clock_gettime(CLOCK_ID, &start);
    for(int i=0; i<loop; i++) {
        clz_binary_search(num);
    }
    clock_gettime(CLOCK_ID,&end);
    fprintf(fp,"%lf ",(double)(end.tv_sec - start.tv_sec)+(end.tv_nsec - start.tv_nsec)/ONE_SEC);

    clock_gettime(CLOCK_ID, &start);
    for(int i=0; i<loop; i++) {
        clz_byte_shift(num);
    }
    clock_gettime(CLOCK_ID,&end);
    fprintf(fp,"%lf ",(double)(end.tv_sec - start.tv_sec)+(end.tv_nsec - start.tv_nsec)/ONE_SEC);

    clock_gettime(CLOCK_ID, &start);
    for(int i=0; i<loop; i++) {
        clz_recursive(num,16);
    }
    clock_gettime(CLOCK_ID,&end);
    fprintf(fp,"%lf ",(double)(end.tv_sec - start.tv_sec)+(end.tv_nsec - start.tv_nsec)/ONE_SEC);

    clock_gettime(CLOCK_ID, &start);
    for(int i=0; i<loop; i++) {
        clz_harley(num);
    }
    clock_gettime(CLOCK_ID,&end);
    fprintf(fp,"%lf \n",(double)(end.tv_sec - start.tv_sec)+(end.tv_nsec - start.tv_nsec)/ONE_SEC);
}
int main(int argc,char *argv[])
{


    FILE *fp=fopen("output.txt","w");
    if (argc < 2) {
        printf("please input a number");
        return 0;
    }
    int num=atoi(argv[1]);
    for(int i=0; i<times; i++)
        clz_time(num,fp);
    return 0;
    fclose(fp);
}


