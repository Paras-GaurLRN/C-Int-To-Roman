#include <stdio.h>

int cntlist[7] = {0,0,0,0,0,0,0};
// the function is used to calculate number of times each number occurs

void standard_system_cntlistfx(unsigned int CNTINTNUM){
    int CNT1000 = CNTINTNUM/1000;
    if (CNT1000 != 0){cntlist[6] = CNT1000; CNTINTNUM-=CNT1000*1000;} int CNT100 = CNTINTNUM/100; //printf("%d\n",cntlist[6]);
    if (CNT100 != 0){if(CNTINTNUM >= 500){cntlist[5] = 1; CNT100-=5; CNTINTNUM-=500;} cntlist[4] = CNT100; CNTINTNUM-=CNT100*100;} int CNT10 = CNTINTNUM/10;//printf("%d\n",cntlist[5]);printf("%d\n",cntlist[4]);
    if (CNT10 != 0){if(CNTINTNUM >= 50){cntlist[3] = 1; CNT10-=5; CNTINTNUM-=50;} cntlist[2] = CNT10; CNTINTNUM-=CNT10*10;}//printf("%d\n",cntlist[3]);printf("%d\n",cntlist[2]);
    if (CNTINTNUM){if(CNTINTNUM >= 5){cntlist[1] = 1; CNTINTNUM-=5;} cntlist[0] = CNTINTNUM;}//printf("%d\n",cntlist[1]);printf("%d\n",cntlist[0]);
}

// defaultlist = ["I","V","X","L","C","D","M"] | from which the answer is printed
// cntlist counts how much time each number is printed
// values I = 1 , V = 5 , X = 10 , L = 50 , C = 100 , D = 500 , M = 1000
// Incase value is Zero, N is printed along with stating that It is not a part of standard system, but used in Apothesis System.
// Max value by standard is 3999 according to standard Rules. V2 will include a system for number till infinity
// V3 will introduce "Firstly" Standard decimals
// V4 will introduce non-standard decimals
// V5 will introduce negative numbers29+

void main(){
    unsigned int myNum = 1;
    printf("Enter An Integer: "); scanf("%u",&myNum); if(myNum==0){printf("The Roman Representation of 0 is: N");return;}
    if(myNum>3999 || myNum<1){printf("The Input Is Not In Standard Form");return;}
    standard_system_cntlistfx(myNum);
    int index_cntlist = 0;
    char output[18];

    for(int checker = 6; checker >= 0;checker--){
    switch (checker){
    case 6:
        while(cntlist[6]){output[index_cntlist]='M'; cntlist[6]--; index_cntlist++;}
        continue;
    case 5:
        if(cntlist[5]){
            if(cntlist[4]==4){output[index_cntlist]='C'; output[index_cntlist+1]='M'; cntlist[5]--; cntlist[4]=0; index_cntlist+=2;}
            else{output[index_cntlist]='D'; cntlist[5]--; index_cntlist++;}}
        continue;
    case 4:
        if(cntlist[4]==4){output[index_cntlist]='C'; output[index_cntlist+1]='D'; cntlist[5]--; index_cntlist+=2; continue;}
        while(cntlist[4]){output[index_cntlist]='C'; cntlist[4]--; index_cntlist++;}
        continue;
    case 3:
        if(cntlist[3]){
            if(cntlist[2]==4){output[index_cntlist]='X'; output[index_cntlist+1]='C'; cntlist[3]--; cntlist[2]=0; index_cntlist+=2;}
            else{output[index_cntlist]='L'; cntlist[3]--; index_cntlist++;}}
        continue;
    case 2:
        if(cntlist[2]==4){output[index_cntlist]='X'; output[index_cntlist+1]='L'; cntlist[3]--; index_cntlist+=2; continue;}
        while(cntlist[2]){output[index_cntlist]='X'; cntlist[2]--; index_cntlist++;}
        continue;
    case 1:
        if(cntlist[1]){
            if(cntlist[0]==4){output[index_cntlist]='I'; output[index_cntlist+1]='X'; cntlist[1]--; cntlist[0]=0; index_cntlist+=2;}
            else{output[index_cntlist]='V'; cntlist[1]--; index_cntlist++;}}
        continue;
    case 0:
        if(cntlist[0]==4){output[index_cntlist]='I'; output[index_cntlist+1]='V'; cntlist[1]--; index_cntlist+=2; continue;}
        while(cntlist[0]){output[index_cntlist]='I'; cntlist[0]--; index_cntlist++;}
        continue;
        }
    }

    output[index_cntlist] = '\0';
    printf("The Roman Representation of %u is: %s", myNum, output);
}