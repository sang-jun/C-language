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

//������ȸ
void inorder(bTreeNode *p) {
	if (p != NULL) {
		inorder(p->left);
		printf("%s ", p->key.item);
		inorder(p->right);
	}
	else return;
}
//������ȸ
void preorder(bTreeNode *p) {
	if (p != NULL) {
		printf("%s ", p->key.item);
		preorder(p->left);		
		preorder(p->right);
	}
	else return;
}
//������ȸ
void postorder(bTreeNode *p) {
	if (p != NULL) {
		postorder(p->left);		
		postorder(p->right);
		printf("%s ", p->key.item);
	}
	else return;
}

//����
void insert_node(bTreeNode **root, element key)
{
	bTreeNode *p, *t;
	bTreeNode *n;

	t = *root;
	p = NULL;

	while (t != NULL) {
		if (compare(key, t->key) == 0) { 
			printf("���� Error!!");
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


//����
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
		printf("���� Error!!");
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

//Ž��
bTreeNode *search(bTreeNode *root, element key)
{
	bTreeNode *p = root;
	while (p != NULL) {

		printf("%s ", p->key.item);

		switch (compare(key, p->key)) {
		case -1:
			p = p->left;
			break;
		case 0:
			return p;
		case 1:
			p = p->right;
			break;
		}
	}
	printf("Ž�� Error!!");
	return p;
}

bTreeNode *search_without_log(bTreeNode *root, element key) {
	bTreeNode *p = root;
	while (p != NULL) {

		switch (compare(key, p->key)) {
		case -1:
			p = p->left;
			break;
		case 0:
			return p;
		case 1:
			p = p->right;
			break;
		}
	}
	return p;
}

//����� ����
int get_node_count(bTreeNode *root) {
	int count = 0;

	if (root != NULL)
		count = 1 + get_node_count(root->left) + get_node_count(root->right);

	return count;
}

//�ܸ� ����� ����
int get_leaf_count(bTreeNode *root) {
	int count = 0;
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) return 1;
		else
			count = get_leaf_count(root->left) + get_leaf_count(root->right);
	}
	return count;
}

//Ʈ���� ����
int get_tree_height(bTreeNode *root) {
	int height = 0;
	if (root != NULL)
		height = 1 + max(get_tree_height(root->left), get_tree_height(root->right));

	return height;
}

//�ּ� Ű���� ���ϴ� �Լ�
void search_min(bTreeNode *root) {
	if (root == NULL) {
		printf("�����");
		return;
	}
	while (root != NULL) {
		if (root->left == NULL) {
			printf("%s", root->key.item);
			break;
		}
		else root = root->left;
	}
}

//�ִ� Ű���� ���ϴ� �Լ�
void search_max(bTreeNode *root) {
	if (root == NULL) {
		printf("�����");
		return;
	}
	while (root != NULL) {
		if (root->right == NULL) {
			printf("%s", root->key.item);
			break;
		}
		else root = root->right;
	}

}

//�ش� ��带 ��Ʈ�� �ϴ� Ʈ���� ���� ���
void print_node_info(bTreeNode **root, element key) {

	bTreeNode *p = root;
	bTreeNode *s = search_without_log(*root, key);

	if (s != NULL) {
		printf("%s�� ������ : %s \n", key.item, p->key);
		printf("%s�� ��Ʈ�� �ϴ� Ʈ���� ���� : %d \n", key.item, get_tree_height(s));
		printf("%s�� ��Ʈ�� �ϴ� Ʈ���� ��� ���� : %d \n", key.item, get_node_count(s));
		printf("%s�� ��Ʈ�� �ϴ� Ʈ���� ���� ����Ʈ�� ��� ���� : %d \n", key.item, get_node_count(s->left));
		printf("%s�� ��Ʈ�� �ϴ� Ʈ���� ������ ����Ʈ�� ��� ���� : %d \n", key.item, get_node_count(s->right));
		printf("%s�� ��Ʈ�� �ϴ� Ʈ���� �ܸ� ����� ���� : %d \n", key.item, get_leaf_count(s));
	}
	else printf("�������� �ʴ� Ű");
	
}


//Ű���� �Է¹޴� �Լ�
element input_data() {
	element e;

	printf("Ű�� : ");
	gets(e.item);

	return e;
}


//�޴��� ����ϰ� ��ȣ�� �Է¹޴� �Լ�
int menu() {

	int input;

	printf("**********\n");
	printf("1: �Է�\n");
	printf("2: ����\n");	
	printf("3: ������ȸ\n");
	printf("4: ������ȸ\n");
	printf("5: ������ȸ\n");
	printf("6: ����� Ž��\n");
	printf("7: Ʈ���� ����\n");
	printf("8: ����� ����\n");
	printf("9: ����\n");
	printf("10: �ּ� Ű\n");
	printf("11: �ִ� Ű\n");
	printf("12: �ܸ� ����� ����\n");
	printf("13: ��� ����\n");
	
	printf("Which select ? :");

	scanf_s("%d", &input);
	getchar();
	return input;
}

void main() {

	bTreeNode *root = NULL;
	int input = -1;

	while (input != 9) {
		input = menu();

		printf("\n");

		switch (input) {
		case 1: insert_node(&root, input_data()); break;
		case 2: delete_node(&root, input_data()); break;
		case 3: printf("������ȸ : "); preorder(root); break;
		case 4: printf("������ȸ : "); inorder(root); break;
		case 5: printf("������ȸ : "); postorder(root); break;
		case 6: search(root, input_data()); break;
		case 7: printf("�ּ� Ű : %d",get_tree_height(root)); break;
		case 8: printf("�ִ� Ű : %d",get_node_count(root)); break;
		case 10: search_min(root); break;
		case 11: search_max(root); break;
		case 12: printf("%d",get_leaf_count(root)); break;
		case 13: print_node_info(&root, input_data()); break;
		default: printf("�߸��� �Է��Դϴ�.\n"); break;
		}

		printf("\n");
	}
}