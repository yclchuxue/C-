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
	unsigned long start;
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

	unsigned long long start_malloc;
	unsigned long long start_node;

	int total = 10220;

	void add_memmory();       //内存不足，再次分配

public:
	memmory_pool();           //构造函数

	~memmory_pool();         //析构函数

	NODE * my_malloc(int num);

	char *m_malloc(int num);

	void   my_free(NODE *pointer);

	void   m_free(void *pointer);
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
	printf("start = %p\n", mem_pool_pointer);
	cout << "start_malloc = " << (unsigned long long)mem_pool_pointer<< endl;

	start_malloc = (unsigned long long)mem_pool_pointer;
	
	used_sum = -1;
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
		int size = 1;
		for(int j = 0; j < 8; ++j){
			NODE *p = (NODE*)malloc(sizeof(NODE));
			if(i == 0 && j == 0){
				start_node = (unsigned long long)p;
			}
			size = pow(2, i);
			int count = used_sum + size;
			used_sum += size;
			p->num = i;
			p->colum = count;
			p->data = &mem_pool_pointer[count];

			//cout << i << "\t" << j << endl;
			if(i == 0 && j == 0){
			cout << "start_NODE = " << (unsigned long long)p << endl;
			cout << "malloc = " << (unsigned long long)&mem_pool_pointer[count] << endl;
			}
			
			if(i == 2 && j == 0){
				printf("%p\t%p\n", &mem_pool_pointer[count], p);
				cout << "NODE = " << (unsigned long long)p << endl;
			}
			/*
			if(i == 0 && j == 1){
				printf("%p\t%p\n", &mem_pool_pointer[count], p);
				cout << (unsigned long long)p << endl;
			}
			
			if(i == 1 && j == 1){
				printf("%p\t%d\n", &mem_pool_pointer[count], count);
			}
			*/
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
		used_sum -= size;
	}

}

NODE * memmory_pool :: my_malloc(int num){
	NODE *ret;
	int n = 0;
	if(num == 1){
		n = 0;
	}else if(num == 2){
		n = 1;
	}else if(num > 2 && num <= 4){
		n = 2;
	}else if(num > 4 && num <= 8){
		n = 3;
	}else if(num > 8 && num <= 16){
		n = 4;
	}else if(num > 16 && num <= 32){
		n = 5;
	}else if(num > 32 && num <= 64){
		n = 6;
	}else if(num > 64){
		cout << "malloc fail!!!" << endl;
		return NULL;
	}
	if(HEAD[n].free_node != NULL){
			ret = HEAD[n].free_node;
			HEAD[n].free_node = HEAD[n].free_node->next;
			if(HEAD[n].free_node != NULL){
				HEAD[n].free_node->prev = NULL;
			}
			NODE *p;
			if(HEAD[n].used_node == NULL){
				p = NULL;
				ret->prev = NULL;
				ret->next = NULL;
				HEAD[n].used_node = ret;
 			}else{
				p = HEAD[n].used_node;
				p->prev = ret;
				ret->next = p;
				HEAD[n].used_node = ret;
				ret->prev = NULL;
			}
	}

	return ret;
}


char *memmory_pool :: m_malloc(int num){
	NODE *ret;
	char *ret1;
	int n = 0;
	if(num == 1){
		n = 0;
	}else if(num == 2){
		n = 1;
	}else if(num > 2 && num <= 4){
		n = 2;
	}else if(num > 4 && num <= 8){
		n = 3;
	}else if(num > 8 && num <= 16){
		n = 4;
	}else if(num > 16 && num <= 32){
		n = 5;
	}else if(num > 32 && num <= 64){
		n = 6;
	}else if(num > 64){
		cout << "malloc fail!!!" << endl;
		//return NULL;
	}
	if(HEAD[n].free_node != NULL){
			ret = HEAD[n].free_node;
			HEAD[n].free_node = HEAD[n].free_node->next;
			if(HEAD[n].free_node != NULL){
				HEAD[n].free_node->prev = NULL;
			}
			NODE *p;
			if(HEAD[n].used_node == NULL){
				p = NULL;
				ret->prev = NULL;
				ret->next = NULL;
				HEAD[n].used_node = ret;
 			}else{
				p = HEAD[n].used_node;
				p->prev = ret;
				ret->next = p;
				HEAD[n].used_node = ret;
				ret->prev = NULL;
			}
	}else{
		cout << "don't have" << n << endl;
		return NULL;
	}

	//cout << (unsigned long long)ret << endl;
	//printf("NODE = %p\t%d\n", ret, sizeof(int));

	return ret->data;
}

void  memmory_pool :: my_free(NODE *pointer){

	cout << (unsigned long long)pointer << endl;
	cout << "pointer->data = " << *(int *)pointer->data << endl; 
	
	int i = pointer->num;
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
		pointer->prev = NULL;
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
		pointer->prev = NULL;
	}
	cout << "AAAAAAA = " << (unsigned long long)HEAD[i].free_node  << i << endl;
	//pointer = NULL;
}


void  memmory_pool :: m_free(void *pointer){
	unsigned long long point = (unsigned long long)pointer;
	cout << "point = " << point << endl;
	unsigned long long sum = point - start_malloc;
	cout << "- = " << sum << endl;
	int count = 0;
	for(int i = 0; i < 7; i++)
	{
		if(sum == 0)
		{
			break;
		}
		for(int j = 0; j < 8; j++)
		{
			if(sum == 0)
			{
				break;
			}
			sum = sum - pow(2, i);
			count++;
		}
	}
	cout << "count = " << count << endl;

	unsigned long long end = start_node + 48*count;

	cout << "end = " << end << endl;

	cout << "size = " << sizeof(NODE) << endl;

	NODE *p = (NODE *)end;

	my_free(p);

}

memmory_pool::~memmory_pool()
{
	free(mem_pool_pointer);
}