#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//
//input: temperature, temperature and wind speed, or neither
//output: the calculated coolness
//usage: ./coolness <temperature> <wind_speed>
//Jennifer Taft, ID: 1999551, e-mail: jltaft@ucsc.edu
//
void noParameters(void);
void oneParameter(float t);
void twoParameters(float t, float v);

int main(int argc, char *argv[]){
//argc will always equal 1 if there is no argument being passed
//when argc == 0, that means even the program name was not passed
	float T = 0;
	float V = 0;
	if(argc <= 1){
		noParameters();
	} else if(argc == 2){
		//checks to see if the temperature argument fits the specified range, if it doesn't then raise an error
		if(-99 <= atof(argv[1]) && atof(argv[1]) <= 50){
			T = atof(argv[1]);
		} else{
			printf("Error: Coolness. Acceptable input values are -99<=T<=50 and 0.5<=V.\n");
			exit(1);
		}
		//calls the oneParameter function to print out the coolness
		oneParameter(T);
	} else if(argc == 3){
		//checks to see if the temperature and wind speed arguments fits the specified ranges. 
		//If it doesn't then raise an error
		if(-99 <= atof(argv[1]) && atof(argv[1]) <= 50){
			T = atof(argv[1]);
		} else{
			printf("Error: Coolness. Acceptable input values are -99<=T<=50 and 0.5<=V.\n");
			exit(1);
		}
		if(0.5 <= atof(argv[2])){
			V = atof(argv[2]);
		} else{
			printf("Error: Coolness. Acceptable input values are -99<=T<=50 and 0.5<=V.\n");
			exit(1);
		}
		//calls the twoParameter function to print out the coolness
		twoParameters(T,V);
	} else if(argc > 3){
		//if the number of arguments exceeds 2, then raise an error
		printf("Usage: ./coolness [temperature] [wind speed]\n");
		exit(1);
	}
	exit(0);
}
void noParameters(){
	float t;
	float v;	
	float coolness = 0;
	printf("Temp\tWind\tCoolness\n");
	//outer for loop manages temperature while inner for loop manages wind speed
	for(t=-10;t<=40;t = t + 10){
		for(v=5;v<=15; v = v + 5){
			coolness = 35.74 + (0.6215 * t) - (35.75 * (pow(v,0.16))) + (0.4275 * t) * pow(v,0.16);
			printf("%.1f\t%.1f\t%.1f\n",t,v,coolness);
		}
		if(t!=40){
		printf("\n");
		}
	}
}

void oneParameter(float t){
	float v;
	float coolness = 0;
	printf("Temp\tWind\tCoolness\n");
	//for loop manages wind speed
	for(v=5;v<=15;v = v + 5){
		coolness = 35.74 + (0.6215 * t) - (35.75 * (pow(v,0.16))) + (0.4275 * t) * pow(v,0.16);
		printf("%.1f\t%.1f\t%.1f\n",t,v,coolness);
	}
}

void twoParameters(float t, float v){
	printf("Temp\tWind\tCoolness\n");
	float coolness = 35.74 + (0.6215 * t) - (35.75 * (pow(v,0.16))) + (0.4275 * t) * pow(v,0.16);
	printf("%.1f\t%.1f\t%.1f\n",t,v,coolness);
}
