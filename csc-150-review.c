// CSC 250
// Michael Ettorre

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillArray (int N[], int X)
{
srand(time(NULL));
int K;
for(K = 0; K < X;K++)
{
        N[K] = rand()%1000;

}

}

void Printout (int N[], int X)
{
        int Count;
        printf("Pos   :   Val\n-------------\n");
        for(Count = 0; Count <  X; Count++)
        {
                printf("%3d   :   %3d\n", Count, N[Count]);
        }
}

int findSum(int Q[], int W)
{
        int C = 0, K;
        for(K = 0; K < W; K++)
        {
                C = C+Q[K];

        }

        return C;
}

int avg(int Q, int A)
{
        int average;
                average = A / Q;

        return average;
}

int findMax(int Q[], int A)
{
        int Max = 0, K;
        for(K = 0; K < A; K++)
        {
                if (Q[K] > Max)
                Max  = Q[K];
        }
        return Max;
}

int findMin(int Q[], int A)
{
        int Min = 1000, K;
        for(K = 0; K < A; K++)
        {
                if (Q[K] < Min)
                Min = Q[K];
        }
        return Min;
}
int main ()
{
        int Variable, array[1000], Sum, Mean, Max, Min;
        printf("Input a number from 1-1000: ");
        scanf("%d", &Variable);
        FillArray(array,Variable);
        Sum = findSum(array, Variable);
        printf("The sum is: %d\n", Sum);
        Mean = avg(Variable, Sum);
        printf("The Mean is: %d\n", Mean);
        Max = findMax(array, Variable);
        printf("The Max is: %d\n", Max);
        Min = findMin(array, Variable);
        printf("The Min is: %d\n", Min);
        Printout(array, Variable);
        return 0;
}

