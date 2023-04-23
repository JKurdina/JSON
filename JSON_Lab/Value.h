#pragma once
#include <iostream>
#include <list>
#include <stack>
#include "List.h"

using namespace std;


class ListValue;
class IterVal;
struct Link
{
  ListValue* listvalue;
  Link* next;
  Link(ListValue* _listvalue, Link* _next = nullptr) : listvalue(_listvalue), next(_next) {}
};

class List
{
  Link* start;
  Link* end;
  Link* curr;
public:
  List();
  List(const List& l);
  ~List();

  List& operator = (const List& l);

  void addLast(ListValue* a);

  void clear() {
    Link* tmp;// = start;
    while (start->next != start) {
      tmp = start->next;
      start->next = tmp->next;
      delete tmp;
    }
  }

  ListValue* back();
  ListValue* front();
  int size();
  IterVal getItr();

  //friend ostream& operator<<(ostream& out, List& list) {
  //  Link* tmp = list.start->next;
  //  while (tmp != list.start) {
  //    out << tmp->listvalue << " ";
  //    tmp = tmp->next;
  //  }

  //  out << "$";
  //  return out;
  //}

  //friend istream& operator>>(istream& in, List& list) {
  //  list.clear();
  //  string tmp;
  //  in >> tmp;
  //  string sep = "$";
  //  while (tmp != sep) {
  //    list.add(atoi(tmp.c_str()));
  //    in >> tmp;
  //  }
  //  return in;
  //}
};

struct Link;
class List;
class ListValue {
public: 
  string key;
  string value;
  stack<ListValue*> stack;
  List list;
  //list<ListValue*> list;
  ListValue();
  //IterVal* itr() { return; };
  string get_key();
  string get_Val();
};

class IterVal {
  Link* curr;
  Link* head;
public:
  IterVal(Link* head);
  bool hasNext();
  ListValue* next();
};


