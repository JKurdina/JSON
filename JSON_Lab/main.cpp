#include "Value.h"
#include "JSON.h"
#include <iostream>

int main() {
  JSon json;
  json.load("JSON_load.txt");
  json.down();
  json.next();
  //json.save("JSON_save.txt");
  json.next();
  return 0;
}

