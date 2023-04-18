#include "Value.h"
#include "JSON.h"
#include <iostream>

int main() {
  JSon json;
  json.load("JSON_load.txt");
  json.save("JSON_save.txt", json);
  return 0;
}