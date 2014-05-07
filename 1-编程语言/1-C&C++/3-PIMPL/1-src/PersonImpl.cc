#include "PersonImpl.h"

#include <iostream>

PersonImpl::PersonImpl(const int _age)
    : age(_age)
{}

void
PersonImpl::print()
{
  std::cout << "PersonImpl::print::age=" << age << std::endl;
}
