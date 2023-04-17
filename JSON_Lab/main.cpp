#include "Value.h"
#include "JSON.h"
#include <iostream>

int main() {
  JSon json;
  json.load("JSON_load.txt");
  //json.save("JSON_save.txt");
  //ListValue* curr;
  json.save("JSON_save.txt", json);
  /*json.down();
  json.next();
  json.next();
  json.back();
  json.down();*/
  return 0;
}