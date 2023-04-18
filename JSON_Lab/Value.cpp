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

Type ListValue::getType() {
  return type;
}

//istream& operator>>(istream& in, ListValue& list)
//{
//  string str;
//  in >> str;
//
//  int st = 0; //будет обозначать записываем мы ключ или значение
//  string t = "";
//  for (int i = 0; i < str.size(); i++) {
//
//    if (str[i] == '{') {
//      continue;
//    }
//    if (str[i] == '"')
//    {
//      while (str[i + 1] != '"') {
//        t += str[i + 1];
//        i++;
//      }
//    }
//    if (str[i] == ':') {
//      st = 1; // value
//    }
//    if (st == 0) {
//      list.get_key() = t;
//      t = "";
//    }
//    if (st == 1) {
//      list.get_Val() = t;
//      t = "";
//      st = 0;
//    }
//  }
//
//  return in;
//}