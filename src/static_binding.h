#ifndef STATICBINDING
#define STATICBINDING

class StaticBinding {
 public:
  void do_sth();
  virtual void test();
  static void printA(StaticBinding* a);
};

class B : public StaticBinding {
 public:
  void do_sth();
  virtual void test();
  static void run_test();
};

#endif  // STATICBINDING
