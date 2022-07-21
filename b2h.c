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
            printf("4��Ʈ���� 2���� �Է� : ");

            gets(input);

            makehexa(input,result,b2h,sizeof(b2h)/sizeof(b2h[0]));

            if(result[0]=='x') {break;}

            printf("16���� ��ȯ���� => 0x%s\n\n",result);
        }
        printf("����");
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

    if((i%4)!=0) {  //4�� �ȳ��� �������� �̷���ó��
        *(rst+0)='x';
        return;
    }

    i=0;
    while(*(in+i)) {  //���� �������ٸ� ?
        for(j=0; j<4; j++) {
            *(temp+j) = *(in+i); //temp�迭�� �� ����
            i++;
        }
        temp[++j]='\0'; //���� ���� ����� ���� 1����
                        //������ �� �η� ����.

        for(j=0; j<size; j++) {
            if(strcmp((b2h+j)->bin,temp)==0) { //strcmp ����ü ���� ����
                strcat(rst,(b2h+j)->hexa);  //temp�� ���ٸ� �׿� �´�
            }                               //����ü �� 16�������� rst�� �������ش�
        }
    }
}


int main(int argc,char *argv[]) {
    
    b2hEX();

    return 0;
}
