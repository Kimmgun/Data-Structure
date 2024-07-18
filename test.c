//初始化(initList) - 分配初始内存空间。
//销毁(destroyList) - 释放所有分配的内存。
//清空(clearList) - 将长度设为0，但保留内存。
//判断是否为空(isEmpty) - 检查列表长度是否为0。
//判断是否已满(isFull) - 检查列表长度是否等于容量。
//获取长度(getListLength) - 返回当前元素数量。
//按值查找(findValue) - 查找特定值的索引。
//按位查找(getValueAt) - 根据索引返回元素值。
//插入元素(insertElement) - 在指定位置插入新元素。
//删除元素(removeElement) - 删除指定位置的元素。

#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 10

typedef struct {
    int* data;
    int length;
    int capacity;
} seqList;

// 初始化列表
void initList(seqList* list) {
    list->data = (int*)malloc(INIT_SIZE * sizeof(int));
    list->length = 0;
    list->capacity = INIT_SIZE;
}

// 销毁列表
void destroyList(seqList* list) {
    free(list->data);
    list->data = NULL;
    list->length = 0;
    list->capacity = 0;
}

// 清空列表
void clearList(seqList* list) {
    list->length = 0;
}

// 判断列表是否为空
int isEmpty(const seqList* list) {
    return list->length == 0;
}

// 判断列表是否已满
int isFull(const seqList* list) {
    return list->length == list->capacity;
}

// 获取列表长度
int getListLength(const seqList* list) {
    return list->length;
}

// 按值查找
int findValue(const seqList* list, int value) {
    for (int i = 0; i < list->length; ++i) {
        if (list->data[i] == value) {
            return i;
        }
    }
    return -1; // 如果未找到，返回-1
}

// 按位查找
int getValueAt(const seqList* list, int index) {
    if (index >= 0 && index < list->length) {
        return list->data[index];
    }
    return -1; // 如果索引无效，返回-1
}

// 插入元素
void insertElement(seqList* list, int index, int value) {
    if (isFull(list)) {
        // 扩容
        list->data = (int*)realloc(list->data, (list->capacity + INIT_SIZE) * sizeof(int));
        list->capacity += INIT_SIZE;
    }
    if (index > list->length) {
        index = list->length;
    }
    for (int i = list->length; i > index; --i) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = value;
    list->length++;
}

// 删除元素
void removeElement(seqList* list, int index) {
    if (index >= 0 && index < list->length) {
        for (int i = index; i < list->length - 1; ++i) {
            list->data[i] = list->data[i + 1];
        }
        list->length--;
    }
}

// 测试函数
int main() {
    seqList list;
    initList(&list);

    insertElement(&list, 0, 1);
    insertElement(&list, 1, 2);
    insertElement(&list, 2, 3);

    printf("List length: %d\n", getListLength(&list));
    printf("Element at index 1: %d\n", getValueAt(&list, 1));

    removeElement(&list, 1);
    printf("List after removal: ");
    for (int i = 0; i < list.length; ++i) {
        printf("%d ", list.data[i]);
    }
    printf("\n");

    destroyList(&list);

    return 0;
}