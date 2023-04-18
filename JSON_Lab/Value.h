#pragma once
#include <iostream>
#include <list>
#include <stack>

using namespace std;


//class IterVal {
//public:
//  bool hasNext() {
//    return true;
//  };
//  int next() {
//    return -1;
//  };
//};

class ListValue {
 public: 
  string key;
  string value;
  stack<ListValue*> stack;

  list<ListValue*> list;
  ListValue();
  //IterVal* itr() { return; };
  string get_key();
  string get_Val();
};

//struct Link {
//  ListValue val;
//  Link* next;
//  Link(ListValue _val, Link* _next = nullptr) : val(_val), next(_next) {}
//};


