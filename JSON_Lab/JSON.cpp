#include "JSON.h"

#include <sstream>
#include <fstream>
#include <stack>

ListValue* JSon::get_root()
{
  return root;
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
void JSon::save(string filename, JSon json)
{
  ofstream file2(filename);


  stack<ListValue*> stack;
  ListValue* end = json.get_root()->list.back();
  string str = "";

  str = check_list(json);
  bool flag = true;

  string new_str = "";
  int i = 0;
  /*while (i != str.size() - 2)
  {
    if (str[i] == '}')
    {
      if (str[i + 1] == ',' || str[i + 1] == '}')
      {
        new_str += str[i];
        continue;
      }
      else
      {
        i++;
      }
    }
    new_str += str[i];
    i++;
  }*/




  file2 << str;
};

string JSon::check_list(JSon json)
{
  ListValue* curr = json.get_root();
  stack<ListValue*> stack;
  string str = "";

  bool flag = false;
  while (!flag)
  {

    try
    {
      ListValue* new_elem = json.get_root();
      json.down();
      str += "'" + new_elem->get_key() + "'";
      str += ":";
      str += "{";
      //stack.push(json.get_root());
      curr = json.get_root();
    }
    catch (...)
    {
      try
      {
        str += "'" + json.get_root()->get_key() + "'";
        str += ":";
        str += "'" + json.get_root()->get_Val() + "'";
        json.next();
        curr = json.get_root();
        str += ",";
        //stack.push(json.get_root());
      }
      catch (...)
      {
        str += "}";
        json.back();
        json.get_root()->list.clear();
        curr = json.get_root();
        if (curr->get_key() == "0") flag = true;
      }
    }
  }
  //stack.push(end);
  return str;
}
/*if (curr == end)
{

}
try
{
  stack.push(json.get_root());
  json.down();
  check_list(json, stack, end);
}
catch (...)
{
  stack.push(json.get_root());
  try
  {
    stack.push(json.get_root());
    json.next();
    check_list(json, stack, end);
  }
  catch (...)
  {
    json.back();
    try
    {
      json.next();
      check_list(json, stack, end);
    }
    catch (...)
    {
      json.back();
      check_list(json, stack, end);
    }
  }
}*/






/*if (curr->list.size() == 0)
{
  str += "'" + json.get_root()->get_key() + "'";
  str += ":";
  str += "'" + json.get_root()->get_Val() + "'";
  try
  {
    json.next();
  }
  catch (...)
  {
    json.back();
    json.next();
    check_list(json, str);
  }
  check_list(json, str);
}
else
{
  json.down();
  check_list(json, str);
}*/




void JSon::next()
{
  stack<ListValue*>stack_list;
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
  }
};
void JSon::down()
{
  if (root->list.size() != 0)
  {
    stack_js.push(root);
    root = root->list.front();
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
    root = stack_js.top();
    stack_js.pop();
  }
  else
  {
    throw("You are in begin");
  }

};