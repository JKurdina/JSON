#include "JSON.h"
#include "Value.h"

#include <sstream>
#include <fstream>
#include <stack>
#include <string>

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
  //file_1 >> str;

  int state = 0;

  stack<ListValue*> stack;
  ListValue* curr = new ListValue();
  string tmp = "";
  ListValue* new_list;



  while (getline(file_1, str))
  {


    for (int i = 0; i < str.size(); i++)
    {
      char c = str[i];

      switch (c) {
      case '{':
        stack.push(curr);

        new_list = new ListValue();
        new_list->parent = curr;
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
        new_list->parent = curr;
        curr->list.addLast(new_list);
        curr = curr->list.back();
        break;

      case 39:
        break;
      case '\t':
        break;
      case ' ':
        break;
      default:
        tmp += c;
        break;
      }
    }
  }

  root = curr;
  current = curr;
}
void JSon::save(string filename)
{
  ofstream file2(filename);
  ListValue* curr;

  string str;
  int level = 0;
  curr = get_root();
  str = check_list(curr, level);

  file2 << str;
};

string JSon::check_list(ListValue* curr, int level)
{
  string str = "";
  if (curr->list.size() == 0)
  {
    str += "'" + curr->get_key() + "'";
    str += ":";
    str += "'" + curr->get_Val() + "'";
    return str;
  }
  if (curr->list.size() != 0)
  {
    if (curr->get_key() != "0")
      str += "'" + curr->get_key() + "'" + ":";
    level++;
    int j = 0;
    str += "{";
    str += "\r";
    while (j < level)
    {
      str += '\t';
      j++;
    }
  }

  IterVal tmp = curr->list.getItr();
  while (tmp.hasNext())
  {
    str += check_list(tmp.next(), level);
    if (tmp.hasNext())
      str += ",";
    int j = 0;
    str += "\r";
    while (j < level)
    {
      str += '\t';
      j++;
    }
  }
  str += "}";

  return str;
}



void JSon::next()
{
  ListValue* old_curr = stack_js.top();
  IterVal i = old_curr->stack_curr.top();

  if (current != old_curr->list.back())
  {
    current = i.next();
    old_curr->stack_curr.push(i);
    if (current != old_curr->list.back())
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

    stack_js.push(current);
    ListValue* old_curr = current;
    old_curr->stack_curr.push(i);
    current = i.next();

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

void JSon::prev()
{
  ListValue* old_curr = stack_js.top();


  if (current != old_curr->list.front())
  {
    IterVal i = old_curr->stack_curr.top();
    old_curr->stack_curr.pop();
    i = old_curr->stack_curr.top();

    current = i.next();
  }
  else
  {
    throw "The begin of list";
  }
};

ListValue* JSon::find_key(ListValue* curr, string key, ListValue* find)
{
  if (curr->get_key() == key)
  {
    return curr;
  }
  if (curr->list.size() == 0)
  {
    return curr;
  }

  IterVal tmp = curr->list.getItr();
  while (tmp.hasNext())
  {
    ListValue* t = find_key(tmp.next(), key, find);
    if (t->get_key() == key)
    {
      find = t;
    }
    else
    {
      continue;
    }
  }
  return find;
};


void JSon::new_value(string key, string value)
{
  if (key == "") throw "It is list";

  ListValue* tmp = find_key(root, key, root);
  if (tmp->get_key() == "0") throw "Does not exist this key";

  tmp->value = value;
};

void JSon::delete_obj(string key)
{
  ListValue* tmp = find_key(root, key, root);
  if (tmp->get_key() == "0") throw "Does not exist this key";

  if (tmp->list.size() != 0)
  {
    delete_obj_list(tmp);
  }

  ListValue* tmp_old = tmp->get_parent();
  tmp_old->list.delete_elem(tmp);

};

void JSon::delete_obj_list(ListValue* curr)
{
  if (curr->list.size() == 0)
  {
    delete curr;
    return;
  }

  IterVal tmp = curr->list.getItr();
  while (tmp.hasNext())
  {
    delete_obj_list(tmp.next());
  }
}


void JSon::new_obj(string key_up, string key, string value)
{
  ListValue* tmp = find_key(root, key_up, root);
  
  ListValue* tmp_test = find_key(root, key, root);
  if (tmp_test->get_key() != "0") throw "Object with this key already exist";

  ListValue* new_tmp = new ListValue();
  new_tmp->key = key;
  new_tmp->value = value;
  tmp->list.addLast(new_tmp);
}
