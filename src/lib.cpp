#include "lib.h"
#include <pthread.h>
#include <unistd.h>
#include <csignal>
#include <cstring>
#include <iostream>

using namespace std;

int increment::operator()(int arr_num) const {
    return num + arr_num;
}

void *wait(void *t) {
    int tid;
    tid = *((int *)t);
    sleep(tid);
    cout << "Sleeping in thread " << endl;
    cout << "Thread with id : " << tid << "  ...exiting " << endl;
    pthread_exit(NULL);
}

void *PrintHello(void *threadid) {
    // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
    int tid = *((int *)threadid);
    cout << "Hello Runoob! 线程 ID, " << tid << endl;
    pthread_exit(NULL);
}

void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") received.\n";

    // 清理并关闭
    // 终止程序
    exit(signum);
}

void *say_hello(void *args) {
    cout << "Hello Runoob！" << endl;
    return 0;
}
