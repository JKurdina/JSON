#pragma once
#include "Value.h";
#include <stack>

#include <msclr\marshal_cppstd.h>
#include <sstream>
#include <fstream>
using namespace System;


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
  void new_value(string value);
  void delete_obj(string key, string value);
  void delete_obj_list(ListValue* curr);
  void new_obj(string key, string value);
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
      string str_fn = msclr::interop::marshal_as<std::string>(filename);
      js->load(str_fn);
    }

    void save(System::String^ filename)
    {
      string str_fn = msclr::interop::marshal_as<std::string>(filename);
      js->save(str_fn);
    }

    System::String^ get_key_value() {
      string str;
      if (js->current->list.size() != 0)
      {str = "'" + js->current->get_key() + "'" + ":";}
      else { str = "'" + js->current->get_key() + "'" + ":" + "'" + js->current->get_Val() + "'"; }
      String^ str_fn = msclr::interop::marshal_as<System::String^>(str);

      String^ new_str = gcnew String(str_fn);
      MarshalString(new_str, str);

      
      return new_str;
    }



    void MarshalString(String^ s, string& os) {
      using namespace Runtime::InteropServices;
      const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
      os = chars;
      Marshal::FreeHGlobal(IntPtr((void*)chars));
    }

    void down()
    {
      js->down();

    }

    void next()
    {
      js->next();

    }

    void back()
    {
      js->back();
    }

    void prev()
    {
      js->prev();
    }

    void new_value(System::String^ str)
    {
      string str_fn = msclr::interop::marshal_as<std::string>(str);
      js->new_value(str_fn);
    }

    void new_obj(System::String^ key, System::String^ value)
    {
      string str_key = msclr::interop::marshal_as<std::string>(key);
      string str_value = msclr::interop::marshal_as<std::string>(value);
      js->new_obj(str_key, str_value);
    }

    void delete_obj(System::String^ key, System::String^ value)
    {
      string str_key = msclr::interop::marshal_as<std::string>(key);
      string str_value = msclr::interop::marshal_as<std::string>(value);
      js->delete_obj(str_key, str_value);
    }
  };
 
}