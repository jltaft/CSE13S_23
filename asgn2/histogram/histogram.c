#include <stdio.h>
#include <stdlib.h>
//
//input: no arguments but user will type in numbers to be included in histogram
//output: a histogram displaying number frequency
//usage: ./histogram
//Jennifer Taft, ID: 1999551, e-mail: jltaft@ucsc.edu
//	
void resizeBins(int bins[],int num_bins);
void printHistogram(int bins[],int bin_size,int num_bins);

int main(){
	int user_value;
	int num_bins = 16;
	int bin[num_bins];
	int bin_size = 1;
	int i;
	
	printf("16 bins of size 1 for range [0,16)\n");
	//while loop to check if control + D is pressed
	while(scanf("%d",&user_value) != EOF){
		//if statement to check if the input was greater than or equal to 0 (AKA positive)
		if(user_value >= 0){
			//if statement to check if the input is greater than the (num_bins * bin_size)-1 (AKA the range)
			while(user_value > (num_bins*bin_size)-1){
			//doubles the bin size if the user_value is greater than the current range
				bin_size = bin_size * 2;
				printf("16 bins of size %d for range [0,%d)\n",bin_size,(num_bins*bin_size));
				//calls resizeBins function to change the amount of * in the bins to match the new range
				resizeBins(bin,num_bins);
			} 
			for (i=0;i<num_bins;i++){  
			//if statement to check the range of each bin and adding to the bins that match the user_value
				if (user_value >= (bin_size*i) && user_value < (bin_size*i + bin_size)){
					bin[i]++;
				}
			}
			
		}
	}
	//function to display the histogram 
	printHistogram(bin,bin_size,num_bins);

	return 0;
}

void resizeBins(int bins[],int num_bins){
	int i;
	int num = 0;
	//adds the next bin's * to the previous bin's
	for (i=0; i<num_bins-1;i= i + 2){		
		bins[num] = bins[i] + bins[i+1];
		num++;
	}
	//removes half of the new bin size's amounts to create a clean slate
	for (i=0; i<num_bins;i++){
		if(i >=num_bins/2){
			bins[i] = 0;
		}
	}
}

void printHistogram(int bins[],int bin_size,int num_bins){
	int i;
	int j;
	int max = 0;
	for (i = 0; i<num_bins;i++){
		max = max + bin_size;
		printf("[%3d:%3d]",bin_size*i,max-1);
		if(bins[i] > 0){
			printf(" *");
		} 
		for (j=0; j < bins[i]-1;j++){
			printf("*");
		}
		if(bins[i] == 0){
			printf(" ");
		} 
		printf("\n");
	}

}



