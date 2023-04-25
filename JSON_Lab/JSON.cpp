#include "JSON.h"
#include "Value.h"

#include <sstream>
#include <fstream>
#include <stack>

JSon::JSon()
{
  root = nullptr;
  current = nullptr;
}

//JSon::JSon(const JSon& json)
//{
//  this->root = new ListValue();
//  this->current = root;
//
//
//  ListValue* curr = new ListValue();
//  bool flag = true;
//
//  JSon new_json;
//  new_json = json;
//
//
//  stack<ListValue*>st;
//  ListValue* tmp;
//  while (curr != json.root)
//  {
//    try
//    {
//      if (flag)
//      {
//        while (!new_json.current->stack_curr.empty())
//          new_json.current->stack_curr.pop();
//
//        new_json.down();
//        tmp = new ListValue();
//
//        tmp->key = new_json.current->get_key();
//        tmp->value = new_json.current->get_Val();
//
//        this->current->list.addLast(tmp);
//        st.push(this->current);
//        this->current = tmp;
//        curr = new_json.get_current();
//      }
//      else throw - 1;
//
//    }
//
//    catch (...)
//    {
//      try
//      {
//        new_json.next();
//
//        tmp = new ListValue();
//        tmp->key = new_json.current->get_key();
//        tmp->value = new_json.current->get_Val();
//
//        this->current = st.top();
//        this->current->list.addLast(tmp);
//
//        this->current = tmp;
//        curr = new_json.get_current();
//        flag = true;
//      }
//      catch (...)
//      {
//        new_json.back();
//        flag = false;
//        this->current = st.top();
//        st.pop();
//        curr = new_json.get_current();
//      }
//    }
//  }
//}

//JSon& JSon::operator=(const JSon& json)
//{
//  ListValue* curr = new ListValue();
// /* while (curr != root)
//  {
//    try
//    {
//      down();
//      curr = current;
//    }
//    catch (...)
//    {
//      try
//      {
//        next();
//        curr = current;
//      }
//      catch (...)
//      {
//        while (!current->stack_curr.empty())
//          current->stack_curr.pop();
//        delete current;
//        back();
//        curr = current;
//      }
//    }
//  }
//  while (!current->stack_curr.empty())
//    current->stack_curr.pop();
//  delete current;
//  delete root;*/
//  ///
//  this->root = new ListValue();
//  this->current = root;
//  /* while (!current->stack_curr.empty())
//     current->stack_curr.pop();*/
//
//  //ListValue* curr = new ListValue();
//  bool flag = true;
//
//  JSon new_json;
//  new_json.root = json.root;
//  new_json.current = new_json.root;
//
//  this->root->key = new_json.current->get_key();
//  this->root->value = new_json.current->get_Val();
//
//
//  stack<ListValue*>st;
//  ListValue* tmp;
//  while (curr != json.root)
//  {
//    try
//    {
//      if (flag)
//      {
//        while (!new_json.current->stack_curr.empty())
//          new_json.current->stack_curr.pop();
//
//        new_json.down();
//        tmp = new ListValue();
//
//        tmp->key = new_json.current->get_key();
//        tmp->value = new_json.current->get_Val();
//
//        this->current->list.addLast(tmp);
//        st.push(this->current);
//        this->current = tmp;
//        curr = new_json.get_current();
//      }
//      else throw - 1;
//
//    }
//
//    catch (...)
//    {
//      try
//      {
//        new_json.next();
//
//        tmp = new ListValue();
//        tmp->key = new_json.current->get_key();
//        tmp->value = new_json.current->get_Val();
//
//        this->current = st.top();
//        this->current->list.addLast(tmp);
//
//        this->current = tmp;
//        curr = new_json.get_current();
//        flag = true;
//      }
//      catch (...)
//      {
//        new_json.back();
//        flag = false;
//        this->current = st.top();
//        st.pop();
//        curr = new_json.get_current();
//      }
//    }
//  }
//
//  return *this;
//}
//
//JSon::~JSon()
//{
//  ListValue* curr = new ListValue();
//  while (curr != root)
//  {
//    try
//    {
//      down();
//      curr = current;
//    }
//    catch (...)
//    {
//      try
//      {
//        next();
//        curr = current;
//      }
//      catch (...)
//      {
//        while (!current->stack_curr.empty())
//          current->stack_curr.pop();
//        delete current;
//        back();
//        curr = current;
//      }
//    }
//  }
//  while (!current->stack_curr.empty())
//    current->stack_curr.pop();
//  delete current;
//  delete root;
//}

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
void JSon::save(string filename)
{
  ofstream file2(filename);

  string str;

  /* JSon new_json;
   new_json.root = json.get_root();

   new_json.current = new_json.get_root();

   while (!new_json.current->stack_curr.empty())
     new_json.current->stack_curr.pop();*/

  
  /*bool flag = true;

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
  }*/

  file2 << str;
};

string JSon::check_list(JSon new_json)
{
  /*JSon new_json;
  new_json.root = json.get_root();

  new_json.current = new_json.get_root();

  while (!new_json.current->stack_curr.empty())
    new_json.current->stack_curr.pop();*/


  ListValue* curr = new ListValue();
  string str = "";

  //bool flag = false;
  while (curr != new_json.get_root())
  {

    try
    {
      new_json.down();
      str += "{";
      str += "'" + new_json.get_current()->get_key() + "'";
      str += ":";
      curr = new_json.get_current();
    }
    catch (...)
    {
      try
      {
        if (new_json.get_current()->get_Val() != "")
          str += "'" + new_json.get_current()->get_Val() + "'";
        new_json.next();
        str += ",";
        str += "'" + new_json.get_current()->get_key() + "'";
        str += ":";
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
  ListValue* old_curr = stack_js.top();
  /**IterVal i = curr_up->list.getItr(); */
  IterVal i = old_curr->stack_curr.top();

  if (current != old_curr->list.back())
  {
    current = i.next();
    old_curr->stack_curr.push(i);
    if(current != old_curr->list.back())
      current = i.next();

  }
  else
  {
    throw "The end of list";
  }

};
void JSon::down()
{
  if (current->list.size() != 0) {
    IterVal i = current->list.getItr();
    if (!current->stack_curr.empty())
    {
      i = current->stack_curr.top();
    }

    /*if (i.hasNext())
    {*/
    stack_js.push(current);
    ListValue* old_curr = current;
    old_curr->stack_curr.push(i);
    current = i.next();
    /*}*/
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