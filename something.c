#include <stdio.h>
#include <stdlib.h>  

int amountOfNums(size_t count);
void print_array(const int *numbers, size_t count);
double calculate_average(const int *numbers, size_t count);
int find_minimum(const int *numbers, size_t count);
int find_maximum(const int *numbers, size_t count);


int main(void) {   
    FILE *file = fopen("numbers.txt", "r");

    if (file == NULL) {
        perror("Could not open file");
        return 1;
    }

    int number;
    size_t count = 0;


    while (fscanf(file, "%d", &number) == 1) {
        count++;
    }

    int *numbers = malloc(count * sizeof(*numbers));

    if (numbers == NULL) {
        fclose(file);
        return 1;
    }

    rewind(file);

    size_t used = 0;

    while (used < count &&
        fscanf(file, "%d", &numbers[used]) == 1) {
        used++;
    }-

    amountOfNums(count);
    print_array(numbers, count);
    calculate_average(numbers, count);
    find_minimum(numbers, count);
    find_maximum(numbers, count);

    return 0;      
}



int amountOfNums(size_t count){
    printf("The amount of numbers in the file is %d.\n", 
    count);
}

void print_array(const int *numbers, size_t count){
    printf("The numbers in this file are:\n");
    
    for(size_t i = 0; i < count; i++){
        printf("%d\n", numbers[i]);
    }
}

double calculate_average(const int *numbers, size_t count){
    double sum = 0;

    for(size_t i = 0; i < count; i++){
        sum += numbers[i];
    }

    double average = sum / count;
    printf("The average of these numbers is: %.2f\n", average);
    
}

int find_minimum(const int *numbers, size_t count){
    int minimum = numbers[0];
    
    for(size_t i = 0; i < count; i++){
        if(minimum < numbers[i]){
            minimum = numbers[i];
        }
    }

    printf("The minimum number is: %d\n", minimum);
}

int find_maximum(const int *numbers, size_t count){
    int max = numbers[0];
    
    for(size_t i = 0; i < count; i++){
        if(max > numbers[i]){
            max = numbers[i];
        }
    }

    printf("The max number is: %d\n", max);
}

