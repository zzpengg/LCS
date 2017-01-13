#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char input1[100];
char input2[100];
int lcs[100][100]={0};
int direction[100][100] = {0}; // 左上1  左方2  上方3 
char answer[100];
int count=0;

void print_LCS(int i, int j)
{
    // 第一個或第二個序列為空集合就停止
    if (i==0 || j==0) return;
 
    if (direction[i][j] == 1)
    {
        print_LCS(i-1, j-1);
        printf("%c ", input1[i-1]);  // 印出LCS的元素
    }
    else if (direction[i][j] == 3)
        print_LCS(i-1, j);
    else if (direction[i][j] == 2)
        print_LCS(i, j-1);
}

int main(){
	printf("input the first string : ");
	scanf("%s",input1);
	printf("input the second string : ");
	scanf("%s",input2);
	int input1_length = strlen(input1);
	int input2_length = strlen(input2);
	for(int i=0;i<input1_length;i++){
		for(int j=0;j<input2_length;j++){
			if(input1[i] == input2[j]){
				lcs[i+1][j+1] = lcs[i][j] + 1;
				direction[i+1][j+1] = 1;
			}else{
				if (lcs[i][j+1] < lcs[i+1][j])
                {
                    lcs[i+1][j+1] = lcs[i+1][j];
                    direction[i+1][j+1] = 2;
                }
                else
                {
                    lcs[i+1][j+1] = lcs[i][j+1];
                    direction[i+1][j+1] = 3;
                }				
			}
		}
	}
	printf("LCS的長度是%d\n", lcs[input1_length][input2_length]) ;
    printf("LCS是\n");
    print_LCS(input1_length, input2_length);
	
} 
