#include "JSON.h"
#include "Value.h"

#include <sstream>
#include <fstream>
#include <stack>

ListValue* JSon::get_root()
{
  return root;
}

ListValue* JSon::get_current()
{
  return current;
}

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

    switch (c) {
    case '{':
      stack.push(curr);

      new_list = new ListValue();
      curr->list.addLast(new_list);
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
      curr->list.addLast(new_list);
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
  current = curr;
}
void JSon::save(string filename, JSon json)
{
  ofstream file2(filename);

  string str;


  str = check_list(json);
  bool flag = true;

  string new_str = "";
  int i = 4;

  while (i != str.size())
  {
    
    if (str[i] == 39)
    {
      if (str[i - 1] == '}') {
        flag = false;
      }
    }
    if (str[i] == ',' || str[i] == '}') flag = true;
    if (flag == true)
    {
      new_str += str[i];
    }
    i++;
  }

  file2 << new_str;
};

string JSon::check_list(JSon json)
{
  JSon new_json = json;
  new_json.current = new_json.get_root();
  while (!new_json.stack_curr.empty()) 
    new_json.stack_curr.pop();
  while (!new_json.stack_js.empty()) 
    new_json.stack_js.pop();

  ListValue* curr = new ListValue();
  string str = "";

  //bool flag = false;
  while (curr != new_json.get_root())
  {

    try
    {
      new_json.down();
      str += "'" + new_json.get_current()->get_key() + "'";
      str += ":";
      curr = new_json.get_current();
    }
    catch (...)
    {
      try
      {
        str += "'" + new_json.get_current()->get_Val() + "'";
        new_json.next();
        str += ",";
        str += "'" + new_json.get_current()->get_key() + "'";
        curr = new_json.get_current();
      }
      catch (...)
      {
        str += "}";
        new_json.back();
        new_json.get_current()->list.clear();
        curr = new_json.get_current();
      }
    }
  }
  return str;
}

  
void JSon::next()
{
  /*ListValue* curr_up = stack_js.top();
  IterVal i = curr_up->list.getItr();*/
  IterVal i = stack_curr.top();
  if (i.hasNext())
  {
    current = i.next();
    stack_curr.push(i);
  }
  else
  {
    throw "The end of list";
  }
  
  /*stack<ListValue*>stack_list;
  ListValue* elem = root;
  root = stack_js.top();
  if (elem != root->list.back())
  {
    while (root->list.front() != elem)
    {
      stack_list.push(root->list.front());
      root->list.pop_front();

    }
    stack_list.push(root->list.front());
    root->list.pop_front();
    ListValue* new_root = root->list.front();

    while (!stack_list.empty())
    {
      root->list.push_front(stack_list.top());
      stack_list.pop();
    }
    root = new_root;
  }
  else
  {
    throw "The end of list";
  }*/
};
void JSon::down()
{
  if (!current->list.size() == 0) {
    IterVal i = current->list.getItr();
    if (!stack_curr.empty())
    {
      i = stack_curr.top();
    }

    if (i.hasNext())
    {
      stack_js.push(current);
      current = i.next();
      stack_curr.push(i);
    }
  }
  else
  {
    throw("The list is empty");
  }

};
void JSon::back()
{
  if (!stack_js.empty())
  {
    current = stack_js.top();
    stack_js.pop();
    stack_curr.pop();
  }
  else
  {
    throw("You are in begin");
  }

};

//void JSon::prev()
//{
//  if (!stack_curr.empty())
//  {
//    
//  }
//}