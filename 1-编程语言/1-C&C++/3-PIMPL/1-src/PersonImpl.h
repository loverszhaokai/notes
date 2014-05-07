#ifndef PERSONIMPL_H_
#define PERSONIMPL_H_

struct PersonImpl
{
 public:
  PersonImpl(const int _age);
  void print();

 private:
  int age;
};

#endif
