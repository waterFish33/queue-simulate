#pragma once
#include "Queue.h"
// 初始化队列 
void QueueInit(Queue* q) {
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
	q->size = 0;

}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data) {
	assert(q);
	if (QueueEmpty(q)) {
		QNode* tmp = (QNode*)malloc(sizeof(QNode));
		tmp->_next = NULL;
		tmp->_data = data;
		q->_front = tmp;
		q->_rear = tmp;
		q->size++;
	}
	else {
		q->_rear->_next= (QNode*)malloc(sizeof(QNode));
		q->_rear = q->_rear->_next;
		q->_rear->_data = data;
		q->_rear->_next = NULL;
		q->size++;
	}
}
// 队头出队列 
void QueuePop(Queue* q) {
	assert(q);
	if (q->size == 1) {
		QNode* tmp = q->_front;
		q->_front = NULL;
		q->_rear = NULL;
		free(tmp);
		q->size--;
	}else
	{
		QNode* tmp = q->_front;
		q->_front = q->_front->_next;
		free(tmp);
		q->size--;

	}
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q){
	assert(q);
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q) {
	assert(q);
	return q->_rear->_data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q) {
	assert(q);
	return q->size;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q) {
	assert(q);
	return !q->size;
}
// 销毁队列 
void QueueDestroy(Queue* q) {
	assert(q);
	while(q->size){
		QueuePop(q);
	}
	
}