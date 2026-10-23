#include <stdio.h>
#include <stdlib.h>



struct item {
	int data;
	struct item* next;
};




struct item* inster_at(struct iten* head, int position, int value) {
	if (position < 1) {
		return head;
	}

	struct item* node = malloc(sizeof(struct item));
	node->data = value;
	//вставка в начало
	if (position == 1) {
		node->next = head;
		return node;
	}

	//вставка в середину или конец

	struct item* previous = head;
	int i = 1;

	while (previous != NULL && i < position - 1) {
		previous = previous->next;
		i++;
	}


	//если previous == null, т.е позиция больше длины списка +1. Пытаемся на 6 место вставить число, а оно больше длины списка. Цепочка рвется
	if (previous == NULL) {
		free(node);
		return head;
	}


	node->next = previous->next;
	previous->next = node;

	return head;










}



struct item* remove_at(struct item* head, int position) {

	if (position < 1) {
		return head;
	}
	//если список пустой - удалять нам нечего
	if (head == NULL) {
		return NULL;
	}

	//удаляем первый узел (вариация 1)

	if (position == 1) {
		struct item* next = head->next;
		free(head);
		return next;
	}

	//удаляем узел в середине или последний (вариация 2)
	struct item* previous = head; //клеим бирку на предыдущий узел
	struct item* current = head->next; //клеим бирку на текущий узел
	int i = 2;

	//теперь нужно идти вперед, ибо не дошли до нужной позиции или же конца списка 
	while (current != NULL&&i<position) {
		previous = current;
		current = current->next;
		i++;
	}

	//но если current = NULL, значит позиция больше длины самого списка
	if (current!= NULL) {
		previous->next = current->next;
		free(current);
	
	}
	return head;



}
void free_list(struct item* head) {
	struct item* p = head;
	while (p != NULL) {
		struct item* next = p->next;
		free(p);
		p = next;

	}
	printf("Список очищен");


}

void print_list(struct item* head) {

	struct item* p = head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}


struct item* create_list(int n) {
	struct item* head = NULL;
	struct item* tail = NULL;
	
	for (int i = 1; i <= n;i++) {
		struct item* node = malloc(sizeof(struct item));
		node->data = i; //число = счетчику
		node->next = NULL; //Новый узел пока что последний
		if (head == NULL) {
			head = node;
		}
		else
		{
			tail->next = node;
		}
		tail = node;

	}
	return head;
}



int main(void) {
	struct item* head = create_list(5);
	print_list(head);              // 1 2 3 4 5
	head = remove_at(head, 1);     // удаляем первый
	print_list(head); // 2 3 4 5 
	head = inster_at(head, 1, 3);
	print_list(head); //3 2 3 4 5 

}






























//struct item {
//	int data;
//	struct item* next;
//};









//int main(void) {
//	struct item* x = malloc(sizeof(struct item));
//	struct item* y = malloc(sizeof(struct item));
//
//	x->data = 1;
//	x->next = y;
//	y->data = 2;
//	y->next = NULL;
//
//	printf("%d %d\n", x->data, x->next->data);
//
//	free(x);
//	free(y);
//
//	return 0;
//
//
//
//
//
//
//}