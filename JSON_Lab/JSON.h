#pragma once
#include "Value.h";
#include <stack>

class JSon {
public:
  ListValue* root;
  //JSon(ListValue* _root) : root(_root) {}
  void load(string filename);
  void save(string filename);
  string check_list(ListValue* curr, string str, stack<ListValue*> stack);
  /*void next();
  void down();
  void back();*/
  //friend istream& operator>>(istream& in, ListValue& listvalue);
  //friend ostream& operator<<(ostream& out, ListValue& listvalue);
};