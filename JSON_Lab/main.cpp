#include "Value.h"
#include "JSON.h"
#include <iostream>

int main() {
  JSon json;
  json.load("JSON_load.txt");
  json.save("JSON_save.txt");
  
  /*json.down();
  json.prev();
  json.next();
  
  json.next();
  json.prev();*/
  /*ListValue* curr = json.get_root();
  ListValue* tmp = json.find_key(curr, "q", curr);*/


  //json.save("JSON_save.txt");

  json.delete_obj("a");
  json.save("JSON_save.txt");
  
  

  return 0;
}

