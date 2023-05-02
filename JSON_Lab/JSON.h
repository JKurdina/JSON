#pragma once
#include "Value.h";
#include <stack>

#include <msclr\marshal_cppstd.h>


class JSon {
public:
  ListValue* root;
  stack<ListValue*>stack_js;
  ListValue* current;
  JSon();
  //JSon(const JSon& json);
  //JSon& operator=(const JSon& json);
  //~JSon();
  void load(string filename);
  void save(string filename);
  string check_list(ListValue* curr, int level);
  void next();
  void down();
  void back();
  void prev();
  ListValue* get_root();
  ListValue* get_current();
  ListValue* find_key(ListValue* curr, string key, ListValue* find);
  void new_value(string key, string value);
  void delete_obj(string key);
  void delete_obj_list(ListValue* curr);
  void new_obj(string key_up, string key, string value);
};


namespace JSonLib
{
  public ref class JSonNet {
    JSon* js;

  public:
    JSonNet() {
      js = new JSon;
    }

    void load(System::String^ filename) {
      //   js->load(filename);
      string str_fn = msclr::interop::marshal_as<std::string>(filename);
      js->load(str_fn);

    }
  };
  //מאמאןנ
}