#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<map>
#include "list.h"
#include<cmath>

#define u64 unsigned long long
#define data_size 2

struct node {
	/* Free list */
	struct list_head node;
	/* Whether the correspond physical page is free now. */
	int allocated;
	/* The order of the memory chunck that this page belongs to. */
	int order;
	/* Used for ChCore slab allocator. */
	void *slab;
};

struct free_list {
	struct list_head free_list;
	u64 nr_free;
};

/* Disjoint physical memory can be represented by several phys_mem_pool. */
class mem_pool {
	/*
	 * The start virtual address (for used in kernel) of
	 * this physical memory pool.
	 */
	u64 pool_start_addr;
	u64 node_start_addr;
	u64 pool_mem_size;

	char *mem_pool_pointer;
	char *mem_node_pointer;

	/*
	 * This field is only used in ChCore unit test.
	 * The number of (4k) physical pages in this physical memory pool.
	 */
	u64 pool_phys_page_num;

	/*
	 * The start virtual address (for used in kernel) of
	 * the metadata area of this pool.
	 */
	struct page *page_metadata;

	/* The free list of different free-memory-chunk orders. */
	struct free_list free_lists[14];

	mem_pool();       //构造函数
	
	void buddy_free_node(struct node *pointer);

	struct node *merge_node(struct node *pointer);

	struct node *split_node(struct node *pointer, int order);

	struct node *get_buddy_node(struct node *pointer);

	void *my_malloc(int size);

};

mem_pool :: mem_pool()
{
	mem_pool_pointer = (char *)malloc(sizeof(char)*1024);
	mem_node_pointer = (char *)malloc(sizeof(char)*1024);

	pool_start_addr = (u64)mem_pool_pointer;

	int order, node_idx, node_num = 10;
	u64 node_size = sizeof(node);
	node *pointer;

	for(order = 0; order < 14 ; ++order)
	{
		free_lists[order].nr_free = 0;
		init_list_head(&(free_lists[order].free_list));
	}

	for(node_idx = 0; node_idx < node_num; ++node_idx)
	{
		pointer = (node*)(node_start_addr + node_idx*node_size);
		pointer->allocated = 1;
		pointer->order = 1;      //最小块为2字节
	}

	for(node_idx = 0; node_idx < node_num; ++node_idx)
	{
		pointer = (node*)(node_start_addr + node_idx*node_size);
		buddy_free_node(pointer);
	}


}

void mem_pool::buddy_free_node(struct node *pointer)
{
	// <lab2>
	if(pointer->allocated) {
		pointer->allocated = 0;
		list_add(&pointer->node, &(free_lists[pointer->order].free_list));
		free_lists[pointer->order].nr_free++;

		merge_node(pointer);
	}
	// </lab2>
}

struct node * mem_pool::merge_node(struct node *pointer)
{
	struct node *Merge_node = NULL;

	if(pointer->allocated == 0)
	{
		Merge_node = pointer;
		list_del(&Merge_node->node);
		--free_lists[Merge_node->order].nr_free;

		int i = 1;
		//while(Merge_page->order < 14-1) 
		while(i == 1){
			struct node *buddy_node = get_buddy_node(Merge_node);

			if(buddy_node != NULL
					&& buddy_node->allocated == 0
						&& buddy_node->order == Merge_node->order)
			{
				if(Merge_node > buddy_node)
				{
					struct node *tem = Merge_node;
					Merge_node = buddy_node;
					buddy_node = tem;
				}
				list_del(&Merge_node->node);
				--free_lists[Merge_node->order].nr_free;

				++Merge_node->order;
				buddy_node->allocated = 1;
			}else{
				break;
			}
			
			--i;     //先不循环
		}
		list_add(&Merge_node->node, &(free_lists[Merge_node->order].free_list));
		++free_lists[Merge_node->order].nr_free;
	}

	return Merge_node;
}

struct node * mem_pool::split_node(struct node *pointer, int order)
{
	struct node *split_node = NULL;

	if(pointer->allocated == 0)
	{
		split_node = pointer;
		list_del(&(split_node->node));
		free_lists[split_node->order].nr_free--;

		while(split_node->order > order)
		{
			split_node->order--;
			
		}
	}
}

struct node *get_buddy_node(struct node *pointer) //返回伙伴node
{

}

void *mem_pool::my_malloc(int size)
{
	//应添加处理非2整数倍情况
	int order;
	int oorder;
	struct node *pointer;

	if(free_lists[order].nr_free > 0)
	{
		pointer = (struct node *)&(free_lists[order].free_list); //获得node

		list_del(&pointer->node);
		free_lists[order].nr_free--;
		pointer->allocated = 1;
	} else{
		while(free_lists[oorder].nr_free <= 0 && oorder < 14)
			oorder++;
		
		pointer = (struct node *)&(free_lists[order].free_list);


	}

	return pointer->slab;
}