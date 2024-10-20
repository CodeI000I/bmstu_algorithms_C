
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergesort(int *array, int begin, int  end){

    if (end - begin < 4){
        for(int j = begin; j < end; j++){             
            for(int i = begin+1; i <= end; i++){
                if(abs(array[i]) < abs(array[i-1])){
                    int cache = array[i];
                    array[i] = array[i-1];
                    array[i-1] = cache;
                }
            }
        }

        return;
    }


    int middle = begin + (end - begin)/2;
    mergesort(array, begin, middle);
    mergesort(array, middle+1, end);
    int newbegin = begin;
    int newmiddle = middle + 1;

    int *newarr = (int*)malloc((end+1) * sizeof(int));
    for (int step = 0; step < end - begin + 1; step++){
        if ((newmiddle > end) || ((newbegin <= middle) && (abs(array[newbegin]) <= abs(array[newmiddle])))){
            newarr[step] = array[newbegin];
            newbegin++;
        } else {
            newarr[step] = array[newmiddle];
            newmiddle++;
        }
    }

    for(int i = 0; i < end - begin +1;i ++){
        array[begin + i] = newarr[i];
    }
    free(newarr);

}


int main(){
    int len; 
    scanf("%d", &len);
    int numbers[len];
    for (int i = 0; i < len; i++){
        scanf("%d", &numbers[i]);
    }
    mergesort(numbers, 0, len-1);
    for (int i = 0; i < len; i++){
        printf("%d\t", numbers[i]);
    }
    printf("\n");
    return 0;
}