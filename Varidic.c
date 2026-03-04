
int  sum (int count,...) {
    int sumx =0;
    va_list listt;
    va_start(listt,count);
    
    for(int i = 0 ;i<count;i++){
        sumx += va_arg(listt,int);
        
    }
    va_end(listt);
    return sumx;
}

int min(int count,...) {
    int* least_count;
    int intialleast = 0;
    least_count= (int*)malloc(count*(sizeof(int)));
    va_list listt;
    va_start(listt,count);
    
    for(int i = 0;i<count;i++){
        least_count[i] = va_arg(listt,int);
        if(least_count[i] <= intialleast){
            intialleast = least_count[i];
        }
    }
    va_end(listt);
    free(least_count);
    least_count = NULL;
    
    return intialleast;
}

int max(int count,...) {
    int* max_count;
    int intialleast = 0;
    max_count= (int*)malloc(count*(sizeof(int)));
    va_list listt;
    va_start(listt,count);
    
    for(int i = 0;i<count;i++){
        max_count[i] = va_arg(listt,int);
        if(max_count[i] >= intialleast){
            intialleast = max_count[i];
        }
    }
    va_end(listt);
    free(max_count);
    max_count = NULL;
    
    return intialleast;
}

