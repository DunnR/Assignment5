#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h


void mergeSort(int ar[], int left, int right)
{
    int middle = 0;
    if(left < right)
    {
        middle = (left + right) / 2;
        mergeSort(ar,left,middle);
        mergeSort(ar,middle+1,right);
        mergeArray(ar,left,middle,right);
        
    }
}

void mergeArray(int ar[], int left, int middle, int right)
{
    int numLeft;
    int numRight;
    int i;
    int j;
    int k;
    
    numLeft = middle - left + 1;
    numRight = right - middle;
    
    int leftAR[numLeft];
    int rightAR[numRight];
    
    for(i = 0; i <= numLeft; i++)
    {
        leftAR[i] = ar[left+i];
    }
    for(i = middle + 1; i <= numRight; i++)
    {
        rightAR[i] = ar[middle+1+i];
    }
    
    i = 0;
    j = 0;
    k = left;
    
    while(i < numLeft && j < numRight)
    {
        if(leftAR[i] < rightAR[j])
        {
            ar[k] = leftAR[i];
            i++;
            k++;
        }
        if(leftAR[i] > rightAR[j])
        {
            ar[k] = leftAR[i];
            j++;
            k++;
        }
    }
    while(i < numLeft)
    {
        ar[k] = leftAR[i];
        i++;
        k++;
    }
    while(j < numRight)
    {
        ar[k] = rightAR[j];
        j++;
        k++;
    }
}


int main(int argc, char** argv)
{
    srand(time(NULL));
    int num;
    int i = 0;
    int nums[10];
    for(i = 0; i < 10; i++)
    {
        nums[i] = rand()%2;
    }
    
    for(i = 0; i < 10; i++)
    {
        printf("woot: %d\n", nums[i]);
    }
    
    mergeSort(nums, 0, 9);
    for(i = 0; i < 9; i++)
    {
        printf("%d",nums[i]);
    }
    
    
    /*
    printf("About to fork...\n");
    pid_t pid = fork();
    i = 0;
    
    if(pid == 0)
    {
        for(; i < 100; i++)
        {
            printf("Parent: %d\n", i);
        }
    }
    else
    {
        for(; i < 100; i++)
        {
            printf("Child(%d): %d\n ", pid, i);
        }
    }
    */
}