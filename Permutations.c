//
//  Permutations.c
//  
//
//  Created by Mohammad Al-Qassim on 2022-09-17.
//

#include <stdio.h>
#include <string.h>

//**************helper function*************
// function to swap characters at two pointers
void swap(char *a, char *b){
        char temp;
        temp = *a;
        *a = *b;
        *b = temp;
}

//This function is responsible for printing the different permutations of a given string.
//In addition to the string, the function would take in two more input parameters which are
//the starting and endding indices of the string which can help in creating a base case for
//the recursive call.

void permutations(char *string, int start, int end){
    //edge case (empty set)
    if (end ==0){
        printf("∅\n");
    }
    int j;// used for the for-loop
    
    //base case
    if (end != 0){
        if(start == end){
            printf("%s\n", string);
        }
        //recursive call
        else{
            for (j = start; j<=end; j++){
                swap((string+start),(string +j));//swap
                permutations(string, start+1,end); //recursie call
                swap((string+start),(string +j)); //backtrack
            }
        }
        
    }
}
int main(){
    char str[] = "1234";// input string to print
    int n = strlen(str);
    permutations(str, 0, n-1);
    return 0;
    
}
