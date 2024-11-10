#include <stdio.h>
#include <string.h>

int main(){
    char input[256];
    char output[256];
    int key;

    printf("Prosze wprowadzic tekst: ");
    gets(input);

    for(int i = 1; i <= 26; i++){
        for (int j = 0; j < strlen(input); j++) { 
            if (input[j] >= 'A' && input[j] <= 'Z') { 
                output[j] = (input[j] - 'A' + i) % 26 + 'A'; 
            } else if (input[j] >= 'a' && input[j] <= 'z') { 
                output[j] = (input[j] - 'a' + i) % 26 + 'a'; 
            }
            else{
                output[j] = input[j];
            }
        }
        printf("Output: %s, przesuniecie %d w prawo lub przesunicie %d w lewo\n", output, i, 26-i);
    }
    return 0;
}
