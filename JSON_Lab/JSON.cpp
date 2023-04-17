#include "JSON.h"

#include <sstream>
#include <fstream>
#include <stack>


void JSon::load(string filename)
{
  string str;
  ifstream file_1(filename);
  file_1 >> str;

  int state = 0;

  stack<ListValue*> stack;
  ListValue* curr = new ListValue();
  string tmp = "";
  ListValue* new_list;
  for (int i = 0; i < str.size(); i++)
  {
    char c = str[i];
    //bool flag = false;
  
    switch (c) {
    case '{':
      stack.push(curr);
      
      new_list = new ListValue();
      curr->list.push_back(new_list);
      curr = curr->list.back();
      state = 0;
      break;
    
    case '}':
      curr->value = tmp;
      tmp = "";
      curr = stack.top();
      stack.pop();
      break;
    
    case ':':
      if (state == 0)
      {
        curr->key = tmp;
        
      }
      state = 1; //теперь записываем значение
      
      tmp = "";
      break;
    
    case ',':
      if (state == 1)
      {
        curr->value = tmp;
      }
      state = 0;
      tmp = "";
      curr = stack.top();
      new_list = new ListValue();
      curr->list.push_back(new_list);
      curr = curr->list.back();
      break;

    case 39:
      break;
    default:
       tmp += c;
       break;
    }
  }
  
  root = curr;
}
void JSon::save(string filename)
{
  stack<ListValue*> stack;
  ofstream file2(filename);

  
  ListValue* curr = root;
  string str = "";


  str = check_list(root, str, stack);
  

  str += "";
  file2 << str << endl;
};

string JSon::check_list(ListValue* curr, string str, stack<ListValue*> stack)
{
  
  if (curr->list.size() == 0)
  {
    str += "'" + curr->get_key() + "'";
    str += ":";
    str += "'" + curr->get_Val() + "'";
    curr->list.pop_front();
    curr = curr->list.front();
    str += check_list(curr, str, stack);
  }
  else
  {
    stack.push(curr);
    ListValue* new_curr = curr->list.front();
    curr->list.pop_front();
    str += check_list(new_curr, str, stack);
  }

  return str;
}
//void JSon::next() 
//{
//  if (root->list.size() != 0)
//  {
//    root = root->list.front();
//    root->list.pop_front();
//  }
//  else return;
//};
//void JSon::down() 
//{ return;};
//void JSon::back() { return; };