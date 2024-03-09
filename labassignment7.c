#include <stdbool.h>
#include <stdio.h>

int count = 0;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void bubbleSort(int array[], int n, int original[]){
    count = 0;
    int i, j, k, swaps[n];
    bool statement;

    for (i = 0; i < n; i++){
      swaps[i] = 0;
    }

    for (i = 0; i < n - 1; i++) {
        statement = false;

        for (j = 0; j < n - i - 1; j++) {

            if (array[j] > array[j + 1]){
                swap(&array[j], &array[j + 1]);

                for(k = 0; k < n; k++){
                    if(array[j] == original[k]){
                        swaps[k]++;
                    }
                    if(array[j+1] == original[k]){
                        swaps[k]++;
                    }
                }
                statement = true;
                count++;
            }
        }

        if (statement == false){
            break;
        }
    }
    for (k = 0; k < n; k++){
        printf("%d: ", array[k]);

        for(i = 0; i < n; i++){
            if(array[k] == original[i]){
                printf("%d\n", swaps[i]);
            }
        }
    }
}

void selectionSort(int array[], int n, int original[]) 
{ 
    int i, j, k, minNumber, swaps[n]; 
    count = 0;

    for (i = 0; i < n; i++){
        swaps[i] = 0;
    }

    for (i = 0; i < n-1; i++) { 
        minNumber = i;

        for (j = i+1; j < n; j++){ 
            if (array[j] < array[minNumber]){ 
                minNumber = j;
            }
        } 
  
        if(minNumber != i){ 
            swap(&array[minNumber], &array[i]);

            for(k = 0; k < n; k++){
                if(array[minNumber] == original[k]){
                    swaps[k]++;
                }
                if(array[i] == original[k]){
                    swaps[k]++;
                }
            }
            count++;
        }
    }

    for (k = 0; k < n; k++){
        printf("%d: ", array[k]);

        for(i = 0; i < n; i++){
            if(array[k] == original[i]){
                printf("%d\n", swaps[i]);
            }
        }
    } 
}

int main() {
    int array[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int original[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int original2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int original3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};

    int n = sizeof(array) / sizeof(array[0]);
    printf("array1 bubble sort: \n");
    bubbleSort(array, n, original);
    printf("%d\n\n", count);

    printf("array2 bubble sort: \n");
    bubbleSort(array2, n, original2);
    printf("%d\n\n", count);

    printf("array1 selection sort: \n");
    selectionSort(original, n, original3);
    printf("%d\n\n", count);

    printf("array2 selection sort: \n");
    selectionSort(original2, n, original2);
    printf("%d\n\n", count);

    return 0;
}