#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <stdio.h>

typedef struct element {
	char item[20];
}element;

typedef struct bTreeNode {
	element key;
	struct bTreeNode *left, *right;
}bTreeNode;

int compare(element e1, element e2)
{
	return strcmp(e1.item, e2.item);
}

//중위순회
void inorder(bTreeNode *p) {
	if (p != NULL) {
		inorder(p->left);
		printf("%s ", p->key.item);
		inorder(p->right);
	}
	else return;
}
//전위순회
void preorder(bTreeNode *p) {
	if (p != NULL) {
		printf("%s ", p->key.item);
		preorder(p->left);		
		preorder(p->right);
	}
	else return;
}
//후위순회
void postorder(bTreeNode *p) {
	if (p != NULL) {
		postorder(p->left);		
		postorder(p->right);
		printf("%s ", p->key.item);
	}
	else return;
}

//삽입
void insert_node(bTreeNode **root, element key)
{
	bTreeNode *p, *t;
	bTreeNode *n;

	t = *root;
	p = NULL;

	while (t != NULL) {
		if (compare(key, t->key) == 0) { 
			printf("삽입 Error!!");
			return;
		}
		p = t;
		if (compare(key, t->key)<0) t = t->left;
		else t = t->right;
	}
	n = (bTreeNode *)malloc(sizeof(bTreeNode));
	if (n == NULL) return;
	n->key = key;
	n->left = n->right = NULL;
	if (p != NULL)
		if (compare(key, p->key)<0)
			p->left = n;
		else p->right = n;
	else *root = n;
}


//삭제
void delete_node(bTreeNode **root, element key)
{
	bTreeNode *p, *child, *succ, *succ_p, *t;

	p = NULL;
	t = *root;
	while (t != NULL && compare(t->key, key) != 0) {
		p = t;
		t = (compare(key, t->key)<0) ?
			t->left : t->right;
	}
	if (t == NULL) {
		printf("삭제 Error!!");
		return;
	}
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			if (p->left == t)
				p->left = NULL;
			else   p->right = NULL;
		}
		else
			*root = NULL;
	}

	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t) 
				p->left = child;
			else p->right = child;
		}
		else
			*root = child;
	}
	else {

		succ_p = t;
		succ = t->right;
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;
		t->key = succ->key;
		t = succ;
	}
	free(t);
}

//탐색
void search(bTreeNode *root, element key)
{
	bTreeNode *p = root;
	while (p != NULL) {

		printf("%s ", p->key.item);

		switch (compare(key, p->key)) {
		case -1:
			p = p->left;
			break;
		case 0:
			return ;
		case 1:
			p = p->right;
			break;
		}
	}
	printf("탐색 Error!!");
	return;
}

//노드의 갯수
int get_node_count(bTreeNode *node) {
	int count = 0;

	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);

	return count;
}

//트리의 높이
int get_tree_height(bTreeNode *node) {
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_tree_height(node->left), get_tree_height(node->right));

	return height;
}

//최소 키값을 구하는 함수
void search_min(bTreeNode *node) {
	if (node == NULL) {
		printf("비었음");
		return;
	}
	while (node != NULL) {
		if (node->left == NULL) {
			printf("%s", node->key.item);
			break;
		}
		else node = node->left;
	}
}

//최대 키값을 구하는 함수
void search_max(bTreeNode *node) {
	if (node == NULL) {
		printf("비었음");
		return;
	}
	while (node != NULL) {
		if (node->right == NULL) {
			printf("%s", node->key.item);
			break;
		}
		else node = node->right;
	}

}

//키값을 입력받는 함수
element input_data() {
	element e;

	printf("키값 : ");
	gets(e.item);

	return e;
}


//메뉴를 출력하고 번호를 입력받는 함수
int menu() {

	int input;

	printf("**********\n");
	printf("1: 입력\n");
	printf("2: 삭제\n");	
	printf("3: 전위순회\n");
	printf("4: 중위순회\n");
	printf("5: 후위순회\n");
	printf("6: 노드의 탐색\n");
	printf("7: 트리의 높이\n");
	printf("8: 노드의 개수\n");
	printf("9: 최소 키\n");
	printf("10: 최대 키\n");
	printf("0: 종료\n");
	printf("Which select ? :");

	scanf_s("%d", &input);
	getchar();
	return input;
}

void main() {

	bTreeNode *root = NULL;
	int input = -1;

	while (input != 0) {
		input = menu();

		printf("\n");

		switch (input) {
		case 1: insert_node(&root, input_data()); break;
		case 2: delete_node(&root, input_data()); break;
		case 3: printf("전위순회 : "); preorder(root); break;
		case 4: printf("중위순회 : "); inorder(root); break;
		case 5: printf("후위순회 : "); postorder(root); break;
		case 6: search(root, input_data()); break;
		case 7: printf("최소 키 : %d",get_tree_height(root)); break;
		case 8: printf("최대 키 : %d",get_node_count(root)); break;
		case 9: search_min(root); break;
		case 10:search_max(root); break;
		default: printf("잘못된 입력입니다.\n"); break;
		}

		printf("\n");
	}
}