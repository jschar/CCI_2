#include "../../Helper/Queue.cpp"
#include "Animal.h"
#include <memory>

template class Queue<int>;
template class Queue<Cat>;
template class Queue<Dog>;
template class Queue<shared_ptr<Dog>>;