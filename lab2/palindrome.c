#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <sys/types.h>
#include <fcntl.h>


int isPalindrome(char *word, int length){

    if(length % 2 == 0){
        return 0;
    }
    int leftSide = 0;
    int rightSide = length - 1;

    while(leftSide < rightSide){
        if(word[leftSide] != word[rightSide]){
            return 0;
        }
        leftSide++;
        rightSide--;
    }

    return 1;

}

int main(int argc, char **args){

    if(argc == 2){
        int length = strlen(args[1]);

        int isPal = isPalindrome(args[1], length);

        if(isPal){
            printf("%s is an odd palindrome\n", args[1]);
        }
        else{
            printf("%s is not an odd palindrome\n", args[1]);
        }
    }

    exit(0);
}
