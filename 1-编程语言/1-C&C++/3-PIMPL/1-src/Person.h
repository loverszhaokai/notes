#ifndef PERSON_H_
#define PERSON_H_

#include <memory>

struct PersonImpl; // ǰ��������PIMPL�Ĺؼ�

struct Person
{
 public:
  Person(const int _age);
  void print();

 private:
  std::shared_ptr<PersonImpl> pImpl; // ָ�룬���ȳ²�
};

#endif
