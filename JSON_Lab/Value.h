#pragma once
#include <iostream>
#include <list>

using namespace std;

enum Type
{
  key,
  value
};

class IterVal {
public:
  bool hasNext() {
    return true;
  };
  int next() {
    return -1;
  };
};

class ListValue {
 public: 
  string key;
  string value;
  Type type;
  stack<ListValue*> stack;

  list<ListValue*> list;
  ListValue();
  Type getType();
  //IterVal* itr() { return; };
  string get_key();
  string get_Val();
};

struct Link {
  ListValue val;
  Link* next;
  Link(ListValue _val, Link* _next = nullptr) : val(_val), next(_next) {}
};


