#include <stdio.h>

typedef struct bTree {
	char item[20];
	struct bTree *left, *right;
}bTree;

int menu() {

	int input;

	printf("**********\n");
	printf("1: �Է�\n");
	printf("2: ����\n");
	printf("3: Ʈ������\n");
	printf("4: ������ȸ\n");
	printf("5: ������ȸ\n");
	printf("6: ������ȸ\n");
	printf("7: ����� Ž��\n");
	printf("8: Ʈ���� ����\n");
	printf("9: ����� ����\n");
	printf("10: �ּ� Ű\n");
	printf("11: �ִ� Ű\n");
	printf("12: ����\n");
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
		default: printf("�߸��� �Է��Դϴ�.\n"); break;
		}
	}
}