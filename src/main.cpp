#include <stdio.h>

#include <iostream>

class Base1 {
 public:
  virtual void f1() {}
  int x;
};
class Base2 {
 public:
  virtual void f2() {}
  int y;
};
class Derived : public Base1, public Base2 {
 public:
  virtual void f1() override {}
  virtual void f3() {}
  int z;
};

int main() {
  Derived* d = new Derived();
  Base1* p1 = d;  // 隐式向上转型
  Base2* p2 = d;  // 隐式向上转型，此时底层必须发生 +16 偏移

  printf("sizeof(Derived) = %zu\n", sizeof(Derived));

  // 强制打印最原始的物理内存地址
  printf("d  的地址: %p\n", (void*)d);
  printf("p1 的地址: %p\n", (void*)p1);
  printf("p2 的地址: %p\n", (void*)p2);  // 必须比 d 大 16 (0x10)

#if 0
sizeof(Derived) = 32
d  的地址: 0xaaaaf3fdceb0
p1 的地址: 0xaaaaf3fdceb0
p2 的地址: 0xaaaaf3fdcec0
#endif

  return 0;
}