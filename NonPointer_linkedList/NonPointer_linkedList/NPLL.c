#include <stdio.h>

#define Memory_size 10

typedef struct Node {
	int data;
	int next;
	char linked;
}node;

node Memory[Memory_size] = {0};

int head = 0;
int tail = 0;

void Init() {
	Memory[0].data = -999999;
	Memory[0].next = -1;
	Memory[0].linked = 1;
}

void Insert() {
	int blink = 1;
	while (Memory[blink].linked != 0 && blink < Memory_size) {
		blink++;
	}
	if (blink < Memory_size) {
		printf("������ ������ = ");
		scanf("%d", &(Memory[blink].data));
		//Memory[blink].data = rand() % 10;
		//printf("%d\n", Memory[blink].data);
		Memory[blink].next = -1;
		Memory[blink].linked = 1;
		Memory[tail].next = blink;
		tail = blink;
	}
	else {
		printf("�޸𸮿� �� ������ �����ϴ�\n�����͸� �����ϰų� ���α׷��� �������ּ���\n");
	}
}

void Delete() {
	int del_data;
	int temp = head;
	printf("������ ������ = ");
	scanf("%d", &del_data);
	while (Memory[Memory[temp].next].data != del_data && Memory[temp].next != tail) {
		temp = Memory[temp].next;
	}
	if (Memory[Memory[temp].next].data == del_data) {
		if (Memory[temp].next == tail) {
			Memory[temp].next = -1;
			Memory[tail].linked = 0;
			tail = temp;
		}
		else {
			int temp_2 = Memory[temp].next;
			Memory[temp].next = Memory[temp_2].next;
			Memory[temp_2].linked = 0;
		}
	}
	else {
		printf("������ �����Ͱ� �����ϴ�\n");
	}
}

void Display() {
	int temp = Memory[head].next;
	if (temp > 0) {
		printf("head = %d, tail = %d\n", head, tail);
		printf("[");
		while (Memory[temp].next != -1) {
			printf("%d ", Memory[temp].data);
			temp = Memory[temp].next;
		}
		printf("%d]\n", Memory[temp].data);
	}
	else {
		printf("����� �����Ͱ� �����ϴ�\n");
	}
}

void DetailDisplay() {
	int temp = Memory[head].next;
	if (temp > 0) {
		printf("head = %d | tail = %d\n", head, tail);
		while (temp != tail) {
			printf("index = %4d | data = %3d | next = %4d\n", temp, Memory[temp].data, Memory[temp].next);
			temp = Memory[temp].next;
		}
		printf("index = %4d | data = %3d | next = %4d\n", temp, Memory[temp].data, Memory[temp].next);
	}
	else {
		printf("����� �����Ͱ� �����ϴ�\n");
	}
}

void main() {
	Init();
	int work = 999;
	while (work != 0) {
		printf("1�� = ������ ����\n2�� = ������ ����\n3�� = ������ ���\n4�� = �� ������ ���\n0�� = ����\n");
		printf("�۾��� �����ϼ��� = ");
		scanf("%d", &work);
		if (work < 0 || work > 4) {
			printf("�۾��� �ٽ� �����ϼ���\n");
			printf("-----------------------\n");
			continue;
		}
		else {
			if (work == 0) {
				break;
			}
			else {
				switch (work) {
				case 1:
					Insert();
					printf("-----------------------\n");
					break;
				case 2:
					Delete();
					printf("-----------------------\n");
					break;
				case 3:
					Display();
					printf("-----------------------\n");
					break;
				case 4:
					DetailDisplay();
					printf("-----------------------\n");
					break;
				}
			}
		}
	}
}