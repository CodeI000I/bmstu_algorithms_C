#include <stdio.h>
#include <stdlib.h>




typedef struct {
    int Day, Month, Year;
} Date;

int compareDates(const void* a, const void* b) {
    Date* date1 = (Date*)a;
    Date* date2 = (Date*)b;

    if (date1->Year != date2->Year) {
        return date1->Year - date2->Year;
    }
    if (date1->Month != date2->Month) {
        return date1->Month - date2->Month;
    }
    return date1->Day - date2->Day;
}


int main() {
    int n;
    
    scanf("%d", &n);
    Date dates[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
    }

    qsort(dates, n, sizeof(Date), compareDates);

    
    for (int i = 0; i < n; i++) {
        printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    }

    return 0;
}
