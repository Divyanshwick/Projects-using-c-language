#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
// driver code
int main()
{
    time_t s, val = 1;
    struct tm* current_time;

    // time in seconds
    s = time(NULL);

    // to get current time
    current_time = localtime(&s);

    // print time in minutes,
    // hours and seconds
    // printf("%02d:%02d:%02d",
    //       current_time->tm_hour,
    //       current_time->tm_min,
    //      current_time->tm_sec);
    int min_ist;
    while(1){
        system("clear");
        min_ist=current_time->tm_min+30;
        if(min_ist >= 60){
            min_ist-=60;
             printf("\033[1;36m");
        printf("%02d:%02d:%02d",
           current_time->tm_hour+6,
           min_ist,
           current_time->tm_sec);
            
        }
        else{
             printf("\033[1;36m");
        printf("%02d:%02d:%02d",
           current_time->tm_hour+5,
           current_time->tm_min+30,
           current_time->tm_sec);
        }
         fflush(stdout);

        current_time->tm_sec++;
         if(current_time->tm_sec == 60){
            current_time->tm_min+=1;
            current_time->tm_sec=0;
        }
        if(current_time->tm_min == 60){
            current_time->tm_hour+=1;
            current_time->tm_min=0;
        }
        if(current_time->tm_hour == 18 && current_time->tm_min == 30){
            current_time->tm_hour=0;
            current_time->tm_min=0;
            current_time->tm_sec=0;
        } 

        sleep(1);

    }

    return 0;
}

       
