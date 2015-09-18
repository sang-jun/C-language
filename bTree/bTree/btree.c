#include <stdio.h>

typedef struct bTree {
	char item[20];
	struct bTree *left, *right;
}bTree;

int menu() {

	int input;

	printf("**********\n");
	printf("1: 입력\n");
	printf("2: 삭제\n");
	printf("3: 트리보기\n");
	printf("4: 전위순회\n");
	printf("5: 중위순회\n");
	printf("6: 후위순회\n");
	printf("7: 노드의 탐색\n");
	printf("8: 트리의 높이\n");
	printf("9: 노드의 개수\n");
	printf("10: 최소 키\n");
	printf("11: 최대 키\n");
	printf("12: 종료\n");
	printf("Which select ? :");

	scanf_s("%d", &input);

	return input;
}

void main() {

	int input = -1;
	char key[20];

	while (input != 12) {
		input = menu();

		printf("\n");

		switch (input) {
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;
		case 6: break;
		case 7: break;
		case 8: break;
		case 9: break;
		case 10: break;
		case 11: break;
		case 12: break;
		default: printf("잘못된 입력입니다.\n"); break;
		}
	}
}