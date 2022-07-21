#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

struct binary2hexa
{
    char hexa[2];
    char bin[5];
};
typedef struct binary2hexa binary2hexa;

void b2hEX() {
    
    char input[50];
    char result[10];

    binary2hexa b2h[] = {
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
            printf("4비트씩의 2진수 입력 : ");

            gets(input);

            makehexa(input,result,b2h,sizeof(b2h)/sizeof(b2h[0]));

            if(result[0]=='x') {break;}

            printf("16진수 변환값은 => 0x%s\n\n",result);
        }
        printf("종료");
        return 0;
}
    


void makehexa(char *in, char *rst, binary2hexa *b2h, int size) {
    
    int i=0,j=0;
    char temp[5]="";

     while(*(in+i)) {
        if(*(in+i)<'0' || *(in+i)>'1') {
            *(rst+0)='x';
            return;
        }
        i++;
    }

    if((i%4)!=0) {  //4로 안나눠 떨어지면 이렇게처리
        *(rst+0)='x';
        return;
    }

    i=0;
    while(*(in+i)) {  //나눠 떨어진다면 ?
        for(j=0; j<4; j++) {
            *(temp+j) = *(in+i); //temp배열에 값 복사
            i++;
        }
        temp[++j]='\0'; //만약 오류 생기면 여기 1순위
                        //마지막 값 널로 포장.

        for(j=0; j<size; j++) {
            if(strcmp((b2h+j)->bin,temp)==0) { //strcmp 구조체 안의 값이
                strcat(rst,(b2h+j)->hexa);  //temp랑 같다면 그에 맞는
            }                               //구조체 속 16진수값을 rst로 복붙해준다
        }
    }
}


int main(int argc,char *argv[]) {
    
    b2hEX();

    return 0;
}
