#include <stdlib.h>
#include <math.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for the result (at most intervalsSize + 1)
    int** result = (int**)malloc((intervalsSize + 1) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((intervalsSize + 1) * sizeof(int));
    int count = 0;
    int i = 0;

    // 1. Add all intervals that end before the newInterval starts
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[count] = (int*)malloc(2 * sizeof(int));
        result[count][0] = intervals[i][0];
        result[count][1] = intervals[i][1];
        (*returnColumnSizes)[count] = 2;
        count++;
        i++;
    }

    // 2. Merge all overlapping intervals with newInterval
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = (intervals[i][0] < newInterval[0]) ? intervals[i][0] : newInterval[0];
        newInterval[1] = (intervals[i][1] > newInterval[1]) ? intervals[i][1] : newInterval[1];
        i++;
    }
    // Add the merged newInterval
    result[count] = (int*)malloc(2 * sizeof(int));
    result[count][0] = newInterval[0];
    result[count][1] = newInterval[1];
    (*returnColumnSizes)[count] = 2;
    count++;

    // 3. Add all remaining intervals
    while (i < intervalsSize) {
        result[count] = (int*)malloc(2 * sizeof(int));
        result[count][0] = intervals[i][0];
        result[count][1] = intervals[i][1];
        (*returnColumnSizes)[count] = 2;
        count++;
        i++;
    }

    *returnSize = count;
    return result;
}
