
// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>


float topsis(float decicionMatrix[][4], float weights[], char criterias[], int a, int c) {
    
    //scale the decicion matrix
    for(int j = 0; j < c; j++) {    
        float vectorSum = 0;
        for(int i = 0; i < a; i++)
            vectorSum += decicionMatrix[i][j] * decicionMatrix[i][j];
        
        vectorSum = sqrt(vectorSum);
        
        for(int i = 0; i < a; i++)
            decicionMatrix[i][j] /= vectorSum;
    }
    
    /*
    //print decision matrix
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < c; j++) {
            printf("%f    ", decicionMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    */
    
    // multiply matrix with weights
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < c; j++) {
            decicionMatrix[i][j] *= weights[j];
        }
    }
    
    
    float positiveA[c];
    float negativeA[c];
    
    for(int j = 0; j < c; j++) {
        float max = decicionMatrix[0][j], min = decicionMatrix[0][j];
        
        for(int i = 1; i < a; i++) {
            if(decicionMatrix[i][j] > max) {
                max = decicionMatrix[i][j];
            }
            if(decicionMatrix[i][j] < min) {
                min = decicionMatrix[i][j];
            }
        }
        
        if(criterias[j] == 'b') {
            positiveA[j] = max;
            negativeA[j] = min;
        }
        else if(criterias[j] == 'c') {
            positiveA[j] = min;
            negativeA[j] = max;
        }
    }
    
    //print idioms
    
    for(int j = 0; j < c; j++) {
        printf("positive: %f    negative: %f \n", positiveA[j], negativeA[j]);
    }
    
    
    
    
    float positiveS[a];
    float negativeS[a]; 
    for(int i = 0; i < a; i++) {
           
        
        float vectorSumPositive = 0, vectorSumNegative = 0;
        
        //positive S
        for(int j = 0; j < c; j++) {
            float val = decicionMatrix[i][j];
           
            //positive Si
            vectorSumPositive += (val - positiveA[j]) * (val - positiveA[j]);
            
            //negative Si
            vectorSumNegative +=  (val - negativeS[j]) * (val - negativeS[j]);
        }
        
        vectorSumPositive = sqrt(vectorSumPositive);
        positiveS[i] = vectorSumPositive;
        
        vectorSumNegative = sqrt(vectorSumNegative);
        negativeS[i] = vectorSumNegative;
    }
    
    float results[a];
    
    for(int i = 0; i < a; i++) 
        results[i] = negativeS[i] / (negativeS[i] + positiveS[i]);
    
    for(int i = 0; i < a; i++) 
        printf("%f ", positiveS[i]);
}
int main() {
    // Write C code here
    float weights[] = {0.25, 0.25, 0.25, 0.25};
    
    char criterias[] = {'c', 'b', 'b', 'b'};
    float decicionMatrix[][4] = {
        {30,425,0.5,5},
        {40,380,0.75,1},
        {65,400,0.25,9},
        {95,250,1,5}
    };
   topsis(decicionMatrix, weights, criterias, 4,4);
    
    return 0;
}
