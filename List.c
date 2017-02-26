#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	char *data;
	struct node *next;	 // 다음 노드의 주소를 저장할 필드.
						 // 자신과 동일한 구조체에 대한 포인터를 멤버로 가진다는 
						 // 의미에서 "자기참조형 구조체" 부른다. 
}Node;

// typedef struct node Node;  // truct node 를 한단어로 Node 라고 부르겠다.


// head가 global variable 로 선언 되어있을때는 아무데서나 접근가능..
// Node *head = NULL;

int main() {
	Node *head = NULL;
	
	if (head == NULL) {
		Node *head;
	}
	else {
		
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->data = "Jason";
		temp->next = head;
		head = temp;
	}
	
}

//연결리스트의 맨앞에 새로운 노드 삽입하기
//1. 새로운 노드를 만들고 추가할 데이타를 저장한다.
//2. 새로운 노드의 next 필드가 현재의 head노드를 가리키도록 한다. 
//3. 새로운 노드를 새로운 head 노드라 한다. 


// 연결리스트의 맨앞에 새로운 노드 삽입하기1
// **ptr_head: 포인터 변수 head의 주소를 매개변수로 받는다. 
// void add_first(Node **ptr_head, char *item) {
// 	Node *temp = (Node *)malloc(sizeof(Node));
// 	temp->data = item;
// 	temp->next = *ptr_head;
// 	*ptr_head = temp;	// 바뀐 head노드의 주소를 포인터를 이용하여 변수 head에 쓴다.
// }
// // 호출할때
// add_first(&head, item_to_store);

//연결리스트의 맨앞에 새로운 노드 삽입하기2	
Node *add_first(Node *head, char *item) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = item;
	temp->next = head;
	return temp;	// 새로운 head 노드의 주소를 return한다. 
}
// 호출할때
// head = add_first(head, itme_to_store);


// 어떤 노드뒤에 새로운 노드 삽입하기
// 1. 새로운 노드를 만들고 데이터를 저장한다.
// 2. 새로운 노드의 next 필드가 prev의 다음 노드르 가리키도록 한다. 
// 3. 새로운 노드를 prev의 다음 노드로 만든다.

int add_after(Node *prev, char *item) {
	if (prev == NULL)
		return 0;

	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = item;
	temp->next = prev->next;
	prev->next = temp;

	return 1;
}


// 첫번째 노드의 삭제 
// head = head->next

Node *remove_first() {
	if (head == NULL) {
		return NULL;
	}
	else {
		Node *temp = head;
		head = head->next;
		return temp;
	}
}

// 어떤 노드의 다음 노드 삭제하기
// prev->next = prev->next->next

Node *remove_after(Node *prev) {
	Node *temp = prev->next;
	if (temp == NULL) {
		return NULL;
	}
	else {
		prev->next = temp->next;
		return temp; 
	}
}

//연결리스트 순회하기
Node *find(char *word) {
	Node *p = head;
	while (p != NULL) {
		if (strcmp(p->data, word) == 0) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// 연결리스트 순회하기
Node *get_node(int index) {
	if(index<0)
		return NULL;
	Node *p = head;
	for (int i=0; i < index && p! = NULL; i++)
		p = p->next;
	return p;
}

// 연결리스트의 index번째 위치에 새로운 노드를 만들어서 삽입한다. 
int add(int index, char *item) {
	if (index < 0)
		return 0;

	if (index == 0) {
		add_first(item);
		return 1;
	}

	Node *prev = get_node(index -1);
	if(prev != NULL) {
		add_after(prev, item);
		return 1;
	}
	return 0;
}

// index번쨰 노드를 삭제하고, 그 노드에 저장된 데이터를 반환한다.
Node *remove(int index) {
	if(index <0) {
		return NULL:
	}
	if (index == 0) {
		return remove_first();
	}

	Node *prev = get_node(index-1);
	if(prev == NULL) {
		return NULL;
	}
	else {
		return remove_after(prev);
	}
}	

Node *remove(char *item) {
	Node *p = head;
	Node *q = NULL;
	while (p!=NULL && strcmp(p->data, item)!=0)
		q = p;
		p = p->next;
	}
	if (p==NULL)
		return NULL;
	if (q==NULL)
		return remove_first();
	else
		return remove_after(q);

}
