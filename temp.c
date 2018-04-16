#include <time.h> 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
float temp=0;
int  readTemperature(){
        FILE *fp;
        fp=fopen("/sys/class/thermal/thermal_zone0/temp","r");
	if(fp){
                fscanf(fp,"%f",&temp);
                fclose(fp);
       }
return 0;
}

int writeTemperature(){
	FILE *fw;
	time_t t;
	time(&t);
	fw=fopen("temperature.txt","a");
	fprintf(fw,"Temperature: %f à %s\n",temp/1000, ctime(&t));
	fclose(fw);
	return 0;
}

int main(int argc, char* argv[]){
        while(1){
        	readTemperature();
		writeTemperature();	
               	printf("la temp est : %f \n",temp/1000);
                time_t t;
		time(&t);
		printf("%s\n",ctime(&t));
		sleep(120);
        }
	return 0;
}


