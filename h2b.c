#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>


struct hexa2binary
{
    char hexa[2];
    char binary[5];
};
typedef struct hexa2binary hexa2binary;

void h2bEX() {

    char input[50];
    char result[10];

    hexa2binary h2b[] = {
        "0","0000",
        "1","0001",
        "2","0010",
        "3","0011",
        "4","0100",
        "5","0101",
        "6","0110",
        "7","0111",
        "8","1000",
        "9","1001",
        "A","1010",
        "B","1011",
        "C","1100",
        "D","1101",
        "E","1110",
        "F","1111"
    };

    while(1) {

        result[0]='\0';
        printf("16진수 입력 :");
        gets(input);

        makebin(input,result,h2b,sizeof(h2b)/sizeof(h2b[0]));
       
        if(result[0]=='x') {break;}

        printf("2진수 변환 값 => %s\n\n",result);
 

    }
    printf("    16진수 아닙니다. 프로그램 종료.");
}

void makebin(char *in, char *rst, hexa2binary *h2b, int size) {
    
    int i=0,j=0;
    char temp[10]; 

    while(*(in+i)) {
        if(toupper(*(in+i))>'F') {  //16진수는 대문자 f에서 끝나니까 f보다 크다면 오류
            *(rst+0)='x';   //정확히 구분하려면 대문자 A보다 커야한다. 0과 9 사이의 수여야 한다.
        }
        i++;
    }

    i=0;

    while(*(in+i)) {
        for(j=0; j<4; j++) {
            *(temp+j) = toupper(*(in+i));
            i++;
        }
        temp[++j]='\0'; //만약 오류 생기면 여기 1순위

        for(j=0; j<size; j++) {
            if(strcmp((h2b+j)->hexa,temp)==0) {
                strcat(rst,(h2b+j)->binary);
            }
        }
    }
}

int main(int argc,char *argv[]) {
    
    h2bEX();
    
    return 0;
}
