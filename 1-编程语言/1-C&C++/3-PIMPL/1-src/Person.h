#ifndef PERSON_H_
#define PERSON_H_

#include <memory>

struct PersonImpl; // 前置声明，PIMPL的关键

struct Person
{
 public:
  Person(const int _age);
  void print();

 private:
  std::shared_ptr<PersonImpl> pImpl; // 指针，暗度陈仓
};

#endif
