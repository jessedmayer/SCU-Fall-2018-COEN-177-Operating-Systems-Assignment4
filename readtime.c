#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
	double seq,ran;		//holds times for sequential and random read respectively
	clock_t start, end;	//tracks clock time before and after a section of code
	char temp;		//temporary variable to hold information read from text file
	long size, i=0;		//size holds size of input file in bytes, and i is an index for loops
	int num;		//num is a random number that determines where to move next in random read

	FILE * pFile;		//file pointer
        pFile = fopen ( "test_50000000.txt" , "r" );
	fseek (pFile, 0, SEEK_END);   // non-portable
        size = ftell (pFile);


	
	start = clock();
	for(i; i < size; i++){			//sequential read test
		fscanf(pFile,"%d", &temp);
	}
	end = clock();
	seq = ((double) (end - start)) / CLOCKS_PER_SEC;

	i = 0;
	start = clock();
	for(i; i < size; i++){			//random read test
		num = (rand() % (size + 1)); 
		fseek ( pFile , num , SEEK_SET );
		fscanf(pFile,"%d", &temp);
	}
	end = clock();
	ran = ((double) (end - start)) / CLOCKS_PER_SEC;

	fclose ( pFile );


	printf("Sequential Time = %lf, Random Time = %lf\n", seq , ran );
	return 0;
}
