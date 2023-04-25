#pragma once
#include "Value.h";
#include <stack>

class JSon {
public:
  ListValue* root;
  stack<ListValue*>stack_js;
  ListValue* current;
  //stack<IterVal>stack_curr;
  JSon();
  //JSon(const JSon& json);
  //JSon& operator=(const JSon& json);
  //~JSon();
  void load(string filename);
  void save(string filename);
  string check_list(JSon curr);
  void next();
  void down();
  void back();
  //void prev();
  ListValue* get_root();
  ListValue* get_current();
};