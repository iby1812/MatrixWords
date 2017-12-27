
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MATRIX_SIZE 4

int counterwords=0;

bool isWord(char s[]) {

return (!strcmp(s, "CAT") | !strcmp(s, "CATS") | !strcmp(s, "TRAM") |
		!strcmp(s, "TRAMS") | !strcmp(s, "TAME") | !strcmp(s, "CAR") | !strcmp(s, "CARS") |
		!strcmp(s, "RAT") | !strcmp(s, "RATS") | !strcmp(s, "RAMP") | !strcmp(s, "ART") |
		!strcmp(s, "CART") | !strcmp(s, "STAMP") | !strcmp(s, "TAKEN") |
		!strcmp(s, "MEN") | !strcmp(s, "MAKE") | !strcmp(s, "TAKE") |
		!strcmp(s, "ATE") | !strcmp(s, "SELL") | !strcmp(s, "STEEL") | !strcmp(s, "RAKE"));
}

void count()
{
    counterwords++;
}

void printWords(char matrixword[MATRIX_SIZE][MATRIX_SIZE],int i,int j,char word[],int checkposition[MATRIX_SIZE][MATRIX_SIZE])
{
    char tempword[16]={'\0'};
    strcpy(tempword,word);
    int matpos[4][4]={0};
    memcpy(matpos,checkposition,4*4*sizeof(int));
    if(!matpos[i][j]&&(i>-1&&j>-1&&i<MATRIX_SIZE&&j<MATRIX_SIZE))
        {
        char letter[2]={matrixword[i][j],'\0'};
        strcat(tempword,letter);
        if(isWord(tempword))
        {
            printf("%s\n",tempword);
            count();
        }

        int loweri=i-1;
        int upperi=i+1;
        int lowerj=j-1;
        int upperj=j+1;
        matpos[i][j]=1;

        printWords(matrixword,loweri,j,tempword,matpos);
        printWords(matrixword,upperi,j,tempword,matpos);
        printWords(matrixword,i,lowerj,tempword,matpos);
        printWords(matrixword,i,upperj,tempword,matpos);

        }
}

int main()
{

    char matrix[MATRIX_SIZE][MATRIX_SIZE]={{'C','A','R','T'},{'E','T','A','K'},{'E','S','M','E'},{'L','L','P','N'}};


     for(int i=0;i<MATRIX_SIZE;i++)
        {
            for(int j=0; j<MATRIX_SIZE; j++)
            {
                    char word[16]={'\0'};
                    int checkposition[MATRIX_SIZE][MATRIX_SIZE]={0};
                    printWords(matrix,i,j,word,checkposition);
            }
        }
        printf("\nFOUNND WORDS: %d",counterwords);
}


