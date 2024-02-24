#ifndef _THREADPOOL_H
#define _THREADPOOL_H

typedef struct ThreadPool ThreadPool;

// �����̳߳ز���ʼ��
ThreadPool *threadPoolCreate
(
    int min,
    int max,
    int queueSize
);

// �����̳߳�
int threadPoolDestroy(ThreadPool *pool);

// ���̳߳��������
void threadPoolAdd(ThreadPool *pool, void(*func)(void *), void *arg);

// ��ȡ�̳߳��ֹ������̸߳���
int threadPoolBusyNum(ThreadPool *pool);

// ��ȡ�̳߳��ֻ��ŵ��̸߳���
int threadPoolAliveNum(ThreadPool *pool);

void *worker(void *arg);

void *manager(void *arg);

void threadExit(ThreadPool *pool);
#endif // !_THREADPOOL_H

