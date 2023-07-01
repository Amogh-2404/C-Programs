//
//  main.c
//  Hashing_assignment
//
//  Created by R.AMOGH on 04/06/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
struct node{
    char* word;
    struct node * next;
};

void lowerCase(char *string,unsigned long size){
    for(unsigned long i=0;i<=size;i++){
        string[i] = tolower(string[i]);
    }
}

int compare(const void*a,const void*b){
return *(char*)a - *(char*)b;
}

void insertToTable(struct node* table[],char* string,int index){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->word = (char*)malloc(sizeof(char)*(strlen(string)+1));
    strcpy(temp->word,string);
    temp->next = table[index];
    table[index] = temp;
}

int hashFunction(char *string){
    int sum = 0;
    for(int k =0;k<=strlen(string);k++){
        sum += toascii(string[k]);
    }
    return sum;
}

void printHashTable(struct node *table[],int index,FILE *output,char *sortedString){
    if(table[index]!=NULL){
        int someNumber = 0;
        struct node *temp = table[index];
        while (temp!=NULL) {
            char checkingVariable[1000];
            strcpy(checkingVariable,temp->word);
            qsort(checkingVariable, strlen(checkingVariable), sizeof(char), compare);
            
            if(strcmp(checkingVariable, sortedString)==0){
                if(someNumber==0){fprintf(output,"%s",temp->word);
                    someNumber++;
                }
                else{
                    fprintf(output," %s",temp->word);
                }
            }
            temp = temp->next;
        }
    }
}

    int main(int argc, const char * argv[]) {
        //Reading necessary inputs
        FILE *wordsFile = fopen(argv[1],"r");
        FILE *queryFile = fopen(argv[3],"r");
        FILE * outputFile = fopen("anagrams.txt","w+");
        const int hashTableSize = atoi(argv[2]);
        if (wordsFile == NULL || queryFile == NULL || outputFile == NULL) {
            printf("Error: Could not open input/output files!\n");
            exit(1);
        }
        //Declaring some important variables
        char tempWord[100] = "\0";
        char tempWord2[100] = "\0";
        char tempWord3[100] = "\0";
        char tempWord4[100] = "\0";
        char dummy[100] = "\0";

        //Declaring hashtable
        struct node* hashTable[hashTableSize];
        //Intitalizing array
        for(int i = 0;i<hashTableSize;i++){
            hashTable[i] = NULL;
        }
                     
        int numberOfQuesryWords = 0;
        //Reading from the queryFile one by one
        while(fscanf(queryFile, "%s",tempWord)==1){
            numberOfQuesryWords++;
            strcpy(tempWord2,tempWord);
            qsort(tempWord2, strlen(tempWord2), sizeof(char), compare);
            int indexHash =  hashFunction(tempWord)%hashTableSize;
            //Now reading all the words in the words file one by one
            while(fscanf(wordsFile, "%s",tempWord3)==1){
                strcpy(tempWord4, tempWord3);
                qsort(tempWord4, strlen(tempWord4), sizeof(char), compare);  //Inserting strings which match only the sorted order to avoid unwanted strings being chained
                if(strcmp(tempWord4, tempWord2)==0){
                    insertToTable(hashTable, tempWord3, indexHash);
                }
            }
            rewind(wordsFile);
        }
        rewind(queryFile);
        //Printing the anagrams obtained
        int newLineCount = 0;
        while (fscanf(queryFile, "%s",tempWord)==1) {
//            if(newLineCount!=0){
//                fprintf(outputFile,"\n");
//            }
//            else{
//                newLineCount++;}
            strcpy(tempWord2,tempWord);
            qsort(tempWord2, strlen(tempWord2), sizeof(char), compare);
            int index = hashFunction(tempWord)%hashTableSize;
            printHashTable(hashTable, index, outputFile,tempWord2);
            fprintf(outputFile,"\n");
        }
        
        fclose(outputFile);
        fclose(wordsFile);
        fclose(queryFile);
        return 0;
    }
