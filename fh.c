#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

int main()
{
    char *path;
    char line[MAX_LINE_LENGTH] = {0};
    unsigned int line_count = 0;
    
  
    path = "students.txt";
    float grade,upper,lower;
    
    
    printf("Enter Lower Limit : ");
    scanf("%f",&lower);
    
    printf("Enter Upper Limit : ");
    scanf("%f",&upper);
    
    
    FILE *file = fopen(path, "r");
    printf("Name\t\tLastName\tLetter\tGrade\n");
    while (fgets(line, MAX_LINE_LENGTH, file))
    {
    	int c=0;
    	char li[100];
    	strcpy(li,line);
        char * tok = strtok(line, "\t");
        while( tok != NULL ) {
        	  c+=1;
        	  if (c==4){
        	  	grade = atof(tok);
        	  	if(grade>lower && grade<upper)
        	  		printf("%s",li);
			  }
		      tok = strtok(NULL, "\t");
   		}
    }
    fclose(file);
}
