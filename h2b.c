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
        printf("16���� �Է� :");
        gets(input);

        makebin(input,result,h2b,sizeof(h2b)/sizeof(h2b[0]));
       
        if(result[0]=='x') {break;}

        printf("2���� ��ȯ �� => %s\n\n",result);


    }
    printf("    16���� �ƴմϴ�. ���α׷� ����.");
}

void makebin(char *in, char *rst, hexa2binary *h2b, int size) {
    
    int i=0,j=0;
    char temp[10]; 

    while(*(in+i)) {
        if(toupper(*(in+i))>'F') {  //16������ �빮�� f���� �����ϱ� f���� ũ�ٸ� ����
            *(rst+0)='x';   //��Ȯ�� �����Ϸ��� �빮�� A���� Ŀ���Ѵ�. 0�� 9 ������ ������ �Ѵ�.
        }
        i++;
    }

    i=0;

    while(*(in+i)) {
        for(j=0; j<4; j++) {
            *(temp+j) = toupper(*(in+i));
            i++;
        }
        temp[++j]='\0'; //���� ���� ����� ���� 1����

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
