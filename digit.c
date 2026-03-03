#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

  int array[10] = {0};
int c = getchar();
while( c != EOF){
    if(c >= '0' && c <= '9'){
        array[c-'0'] ++;
    }
    c = getchar();
}
for(int i=0;i<10;i++){
    printf("%d ",array[i]);
}
return 0;
}
