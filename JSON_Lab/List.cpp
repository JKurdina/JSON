#include "Value.h"

List::List()
{
  start = new Link(0);
  end = start;
  start->next = end;
  end->next = start;
}

List::List(const List& l)
{
  ListValue* tmp_1 = new ListValue();
  start = new Link(tmp_1);
  end = start;
  start->next = start;
  Link* tmp = l.start->next;
  while (tmp != l.start) {
    addLast(tmp->listvalue);
    tmp = tmp->next;
  }
}

List::~List()
{
  while (start != end) {
    Link* new_start = start->next;
    end->next = new_start;
    delete start;
    start = new_start;
  }
  delete start;
}

List& List::operator=(const List& l)
{
  if (start->next != start) {
    while (start != end) {
      Link* new_start = start->next;
      end->next = new_start;
      delete start;
      start = new_start;
    }
    delete start;
  }

  start = new Link(0);
  end = start;
  start->next = end;
  end->next = start;
  Link* tmp = l.start->next;
  while (tmp != l.start) {
    addLast(tmp->listvalue);
    tmp = tmp->next;
  }
  return *this;
}

void List::addLast(ListValue* a)
{
  Link* tmp = new Link(a, start);
  end->next = tmp;
  end = end->next;
  end->next = start;
}

ListValue* List::back()
{
  return end->listvalue;
}

ListValue* List::front()
{
  return start->next->listvalue;
}

int List::size()
{
  int count = 0;
  Link* curr = start->next;
  while (curr != start)
  {
    count++;
    curr = curr->next;
  }
  return count;
}

IterVal List::getItr()
{
  return IterVal(start);
}

void List::delete_elem(ListValue* tmp)
{
  Link* t = start;
  Link* t_next;
  Link* t_prev;

  while (t->next->listvalue != tmp)
  {
    t = t->next;
  }
  t_prev = t;
  t = t->next;
  t_next = t->next;

  t_prev->next = t_next;

  delete t->listvalue;
  delete t;
}