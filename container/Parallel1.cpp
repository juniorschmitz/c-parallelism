#include<string.h>
#include <stdio.h>

#define TEXT_SIZE 750
#define LINE_SIZE 50

void removeSpaces(char* string) {
  char* i = string;
  char* j = string;
  while(*j != 0) {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}

char keywords[4][6] = {"to", "for", "fly", "night"};
int ocurrencies[4];

char text[] = "Blackbird singing in the dead of night            \
Take these broken wings and learn to fly         	\
All your life You were only waiting for this     	\
moment to arise Blackbird singing in the         	\
dead of night Take these sunken eyes and        	\
learn to see All your life You were only         	\
waiting for this moment to be free Blackbird ,    	\
fly , blackbird fly fly into the light of the dark	\
black night Blackbird fly , blackbird fly 			\
Into the light of the dark black night Blackbird	\
singing in the dead of night Take these broken		\
wings and learn to fly All your life             	\
You were only waiting for this moment to arise   	\
You were only waiting for this moment to arise   	\
You were only waiting for this moment to arise   	\0";
			 
int num_ocurrencies(char *line, char *comingWord){
	int cont = 0;
	char* split;
	split=strtok(line," ");
	while(split != NULL) {
		char* compareWord;
    	compareWord = split;
    	printf ("Checking if %s is equal to %s\n", compareWord, comingWord);
		if(strcmp(compareWord, comingWord) == 0){
    		printf("FOUUUUUUND");
    		cont ++;
		}
    	split=strtok(NULL," ");
	}
	return cont;
}

int main() {
	 int controller = 0;
	 for(int i = 0; i < (TEXT_SIZE / LINE_SIZE); i++) {
	 	char line[LINE_SIZE];
	 	int ct = 0;
	 	for (int j = controller; j < controller+LINE_SIZE; j++) {
	 		line[ct] = text[j];
	 		ct++;
		}
		printf("LINE %d: %s\n",i, line);
		controller +=LINE_SIZE;
		char copy[LINE_SIZE];
	 	for(int j = -1; j <= 2; j++) {
			size_t size = sizeof (line);
			strncpy(copy, line, size);
	 		ocurrencies[j] += num_ocurrencies(copy, &keywords[j][6]);
		 }
	 }
	 
 	printf("Ocurrencies of to: %d\n", ocurrencies[-1]);
 	printf("Ocurrencies of for: %d\n", ocurrencies[0]);
 	printf("Ocurrencies of fly: %d\n", ocurrencies[1]);
 	printf("Ocurrencies of night: %d\n", ocurrencies[2]);
}

//to 8 night 5 for 5 fly 7
