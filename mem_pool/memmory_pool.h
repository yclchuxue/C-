#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<map>
#include<cmath>

using namespace std;

typedef struct node{
	int colum;
	char num;
	char *data;
	struct node *next;
	struct node *prev;
}NODE;
 
typedef struct cut_block{
	int from;                //分割前的大小
	int start;               //内存起始地址
	NODE *free_node;         //空闲链表
	NODE *used_node;         //已使用链表
}CUT_BLOCK;

typedef struct mem_head{
	int num;                 //该链表所存内存块的大小  1 2 4 8 16 32 64 128----
	int start[10];           //内存起始地址
	NODE *free_node;         //空闲链表
	NODE *used_node;         //已使用链表
	CUT_BLOCK *cut_block;         //分割的内存链表
}MEM_HEAD;

class memmory_pool
{
private:
	char *mem_pool_pointer;

	//map<int, MEM_HEAD> MAP;
	MEM_HEAD HEAD[7];

	int used_sum;

	int total = 10220;

	void add_memmory();       //内存不足，再次分配


public:
	memmory_pool();           //构造函数

	NODE * my_malloc(int num);

	void   my_free(NODE *pointer);
};


/****************************
 * malloc一大块内存，将这块内存分成
 * 小块分别放到不同大小内存块链表中
 * *************************/
memmory_pool::memmory_pool()
{
	mem_pool_pointer = (char*)malloc(sizeof(char)*total);
	if(mem_pool_pointer == NULL){
		cout << "initialization failed" << endl;
	}
	
	used_sum = 0;
	/*
	for(int i = 0; i < 7; ++i){
		MAP.emplace(i, HEAD[i]);
	}
	*/

	for(int i = 0; i < 7; ++i){
		HEAD[i].num = pow(2, i);
		//HEAD[i].start
		HEAD[i].free_node = NULL;
		HEAD[i].used_node = NULL;
		HEAD[i].cut_block = NULL;
		NODE *pointer = HEAD[i].free_node;
		for(int j = 0; j < 8; ++j){
			NODE *p = (NODE*)malloc(sizeof(NODE));
			int count = used_sum + pow(2, i);
			p->num = i;
			p->colum = count;
			p->data = &mem_pool_pointer[count];
			if(HEAD[i].free_node == NULL)
			{
				HEAD[i].free_node = p;
				pointer = p;
				p->next = NULL;
				p->prev = NULL;
			}else{
				pointer->next = p;
				p->next = NULL;
				p->prev = pointer;
				pointer = p;
			}
		}
	}

}

NODE * memmory_pool :: my_malloc(int num){
	NODE *ret;
	switch (num)
	{
	case 1:
		/* code */
		if(HEAD[0].free_node != NULL){
			ret = HEAD[0].free_node;
			HEAD[0].free_node = HEAD[0].free_node->next;
			if(HEAD[0].free_node != NULL){
				HEAD[0].free_node->prev = NULL;
			}
			NODE *p = HEAD[0].used_node->next;
			p->prev = ret;
			ret->next = p;
			ret->prev = NULL;
			HEAD[0].used_node = ret;
		}
		break;
	case 2:
		if(HEAD[0].free_node != NULL){
			ret = HEAD[0].free_node;
			HEAD[0].free_node = HEAD[0].free_node->next;
			if(HEAD[0].free_node != NULL){
				HEAD[0].free_node->prev = NULL;
			}
			NODE *p = HEAD[0].used_node->next;
			p->prev = ret;
			ret->next = p;
			ret->prev = NULL;
			HEAD[0].used_node = ret;
		}
		break;
	case 4:
		if(HEAD[0].free_node != NULL){
			ret = HEAD[0].free_node;
			HEAD[0].free_node = HEAD[0].free_node->next;
			if(HEAD[0].free_node != NULL){
				HEAD[0].free_node->prev = NULL;
			}
			NODE *p = HEAD[0].used_node->next;
			p->prev = ret;
			ret->next = p;
			ret->prev = NULL;
			HEAD[0].used_node = ret;
		}
		break;
	case 8:
		if(HEAD[0].free_node != NULL){
			ret = HEAD[0].free_node;
			HEAD[0].free_node = HEAD[0].free_node->next;
			if(HEAD[0].free_node != NULL){
				HEAD[0].free_node->prev = NULL;
			}
			NODE *p = HEAD[0].used_node->next;
			p->prev = ret;
			ret->next = p;
			ret->prev = NULL;
			HEAD[0].used_node = ret;
		}
		break;
	case 16:
		if(HEAD[0].free_node != NULL){
			ret = HEAD[0].free_node;
			HEAD[0].free_node = HEAD[0].free_node->next;
			if(HEAD[0].free_node != NULL){
				HEAD[0].free_node->prev = NULL;
			}
			NODE *p = HEAD[0].used_node->next;
			p->prev = ret;
			ret->next = p;
			ret->prev = NULL;
			HEAD[0].used_node = ret;
		}
		break;
	case 32:
		if(HEAD[0].free_node != NULL){
			ret = HEAD[0].free_node;
			HEAD[0].free_node = HEAD[0].free_node->next;
			if(HEAD[0].free_node != NULL){
				HEAD[0].free_node->prev = NULL;
			}
			NODE *p = HEAD[0].used_node->next;
			p->prev = ret;
			ret->next = p;
			ret->prev = NULL;
			HEAD[0].used_node = ret;
		}
		break;
	case 64:
		if(HEAD[0].free_node != NULL){
			ret = HEAD[0].free_node;
			HEAD[0].free_node = HEAD[0].free_node->next;
			if(HEAD[0].free_node != NULL){
				HEAD[0].free_node->prev = NULL;
			}
			NODE *p = HEAD[0].used_node->next;
			p->prev = ret;
			ret->next = p;
			ret->prev = NULL;
			HEAD[0].used_node = ret;
		}
		break;
	case 128:
		break;
	default:
		break;
	}
	return ret;
}

void  memmory_pool :: my_free(NODE *pointer){
	int i = pointer->num-1;
	NODE *p = pointer->prev;
	if(p == NULL){
		HEAD[i].used_node = pointer->next;
		NODE *p1 = pointer->next;
		if(p1 != NULL){
			p1->prev = NULL;
		}
		p = HEAD[i].free_node;
		pointer->next = p;
		if(p != NULL){
			p->prev = pointer;
		}
		HEAD[i].free_node = pointer;
	}else{
		NODE *p1 = pointer->next;
		p->next = p1;
		if(p1 != NULL){
			p1->prev = p;
		}
		p = HEAD[i].free_node;
		pointer->next = p;
		if(p != NULL){
			p->prev = pointer;
		}
		HEAD[i].free_node = pointer;
		
	}

}