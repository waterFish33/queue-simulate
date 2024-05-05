#pragma once
#include "Queue.h"
// ��ʼ������ 
void QueueInit(Queue* q) {
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
	q->size = 0;

}
// ��β����� 
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
// ��ͷ������ 
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
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q){
	assert(q);
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q) {
	assert(q);
	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q) {
	assert(q);
	return q->size;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q) {
	assert(q);
	return !q->size;
}
// ���ٶ��� 
void QueueDestroy(Queue* q) {
	assert(q);
	while(q->size){
		QueuePop(q);
	}
	
}