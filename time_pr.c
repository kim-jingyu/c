#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

clock_t startTime, endTime;

int main (void) {
    srand(time(NULL));
    
    startTime = clock();
    printf("startTime = %ld \n", startTime/1000);

    // sleep(1000);

    endTime = clock();
    printf("endTime = %ld \n", endTime);

    long totalTime = (long)endTime - startTime;

    printf("%ld", totalTime);
}