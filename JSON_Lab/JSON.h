#pragma once
#include "Value.h";
#include <stack>

class JSon {
public:
  ListValue* root;
  stack<ListValue*>stack_js;
  ListValue* current;
  //stack<IterVal>stack_curr;
  void load(string filename);
  void save(string filename, JSon json);
  string check_list(JSon curr);
  void next();
  void down();
  void back();
  //void prev();
  ListValue* get_root();
  ListValue* get_current();
};