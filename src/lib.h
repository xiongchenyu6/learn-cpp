#ifndef MACROEEE

#define NUM_THREADS 5 

class increment 
{ 
private: 
    int num; 
public: 
    increment(int n) : num(n) { }
  
    // This operator overloading enables calling 
    // operator function () on objects of increment 
    int operator () (int arr_num) const;
}; 

void *wait(void *t);
void signalHandler(int signum);

void *PrintHello(void *threadid);
void* say_hello(void* args);

#endif //CRO    