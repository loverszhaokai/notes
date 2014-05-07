#include "Person.h"

#include "PersonImpl.h"

Person::Person(const int _age)
    : pImpl(new PersonImpl(_age))
{}

void
Person::print()
{
  pImpl->print();
}
