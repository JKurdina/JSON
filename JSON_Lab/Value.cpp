#include "Value.h"
#include <sstream>
#include <fstream>

ListValue::ListValue() {
  key = "0";
  value = "0";

}
string ListValue::get_key() {
  return key;
}

string ListValue::get_Val() {
  return value;
}

IterVal::IterVal(Link* head)
{
  curr = head->next;
  this->head = head;
}

bool IterVal::hasNext()
{
  return curr != head;
}

ListValue* IterVal::next()
{
  if (!hasNext()) throw - 1;
  ListValue* tmp = curr->listvalue;
  curr = curr->next;
  return tmp;
}



