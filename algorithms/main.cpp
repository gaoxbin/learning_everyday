/*
 * main.cpp
 *
 *  Created on: 2018年5月16日
 *      Author: Administrator
 */
/**
 * 大话数据结构：风清扬
 * 经典语录：
 *      1.只有真正掌握技术的人，才有可能去享受它。
 *      2.不怕苦，吃苦半辈子，怕吃苦，吃苦一辈子。
 *
 *
 */

#if 0
#include "AList.h"
#include "hashtable.h"

/// array liner table
void test_alist()
{
	AList<int> alist;

	alist.setStart();

	alist.insert(100);
	alist.insert(99);
	alist.insert(98);
	alist.insert(97);

	alist.setPos(2);

	alist.print();
}

/// hash table
/** ============================================================= */
/// 要放入哈希表中的结构体
struct Student
{
    int age;
    float score;
    char name[32];
    char data[1024 * 1024* 10];
};

// 结构体内存释放函数
static void free_student(void* stu)
{
    free(stu);
}

// 显示学生信息的函数
static void show_student(struct Student* p)
{
    printf("姓名:%s, 年龄:%d, 学分:%.2f\n", p->name, p->age, p->score);
}

int test_hashtable()
{
    // 新建一个HashTable实例
    HashTable* ht = hash_table_new();
    if (NULL == ht) {
        return -1;
    }

    // 向哈希表中加入多个学生结构体
    for (int i = 0; i < 100; i++) {
        struct Student * stu = (struct Student*)malloc(sizeof(struct Student));
        stu->age = 18 + rand()%5;
        stu->score = 50.0f + rand() % 100;
        sprintf(stu->name, "同学%d", i);
        hash_table_put2(ht, stu->name, stu, free_student);
    }

    // 根据学生姓名查找学生结构
    for (int i = 0; i < 100; i++) {
        char name[32];
        sprintf(name, "同学%d", i);
        struct Student * stu = (struct Student*)hash_table_get(ht, name);
        show_student(stu);
    }

    // 销毁哈希表实例
    hash_table_delete(ht);
    return 0;
}
/** ============================================================= */

int main(int argc, char **argv)
{
	/// test alist
//	test_alist();

	/// test hashtable
	test_hashtable();

	return 0;
}
#endif




