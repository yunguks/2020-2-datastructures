#define _CRT_SECURE_NO_WARNINGS
#include "Stack_Array.h"
#include <string.h>
#include <stdlib.h>


bool isOperater(char s) {
	if (s == '*' || s == '/' || s == '+' || s == '-') return true;

	else return false;
}

int main(void) {
	char str1[100], str2[100], str3[100], post[100];
	char *token;
	char k;
	int i = 0, len = 0;
	Stack *stack = createStack(100);

	printf("Arithmetic Expression : ");
	scanf("%s", str1);
	printf("Input : %s\n", str1);

	token = strtok(str1," ");
	

	while (token != NULL) {
		strcat(str2, token);
		printf("%c\n", str2);
		token = strtok(NULL," ");
	}// 공백 없애주기 

	while(str2[len] != '\0'){
		printf("%c", str2[len]);
		len++;
	}


	while (len >= i) {//postfix 하기
		if (len == i) {
			while (countStackItem(stack) != -1) {
				token = pop(stack);
				strcat(post, token);
			}
		}
		else {
			if (str2[i] == '*' || str2[i] == '/') {
				//top의 오퍼레이터가 있으면 다꺼내서 옮긴다.
				while (countStackItem(stack) != -1) {
					token = pop(stack);
					strcat(post, token);
				}

				push(stack, str2[i]);
			}

			else if (str2[i] == '+' || str2[i] == '-') {
				if (top(stack) == '+' || top(stack) == '-') {
					while (countStackItem(stack) != -1) {
						token = top(stack);
						strcat(post, token);
					}
				}
				push(stack, str2[i]);
			}

			else if (len == i) {
				while (countStackItem(stack) != -1) {
					token = pop(stack);
					strcat(post, token);
				}
			}

			else {
				token = str2[i];
				strcat(post, token);
			}
		}

		i++;
	}

	printf("%s", post);
	destroyStack(stack);
	return 0;
}