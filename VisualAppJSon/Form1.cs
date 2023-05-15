using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Security;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;



namespace VisualAppJSon
{
  public partial class Form1 : Form
  {
    JSonLib.JSonNet s;
    string path_curr = "C:\\Users\\kurdi\\Desktop\\CURRENT.txt";

    public Form1()
    {
      InitializeComponent();
    }

    private void Form1_Load(object sender, EventArgs e)
    {
      s = new JSonLib.JSonNet();



    }


    private void button1_Click(object sender, EventArgs e)
    {

      output.Text = "";
      string path_sv = "C:\\Users\\kurdi\\Desktop\\SAVE.txt";


      s.save(path_sv);
      using (StreamReader sr = new StreamReader(path_sv, Encoding.Default))
      {
        string line;
        while ((line = sr.ReadLine()) != null)
        {
          output.Text += line + Environment.NewLine;

        }
      }
    }

    private void but_down_Click(object sender, EventArgs e)
    {
      try
      {
        s.down();
        current.Text = s.get_key_value();
      }
      catch
      {
        error.Text = "Pardon, the list is empty!";
      }
    }

    private void current_TextChanged(object sender, EventArgs e)
    {

    }

    private void output_curr_Click(object sender, EventArgs e)
    {
      
      string path_ld = "C:\\Users\\kurdi\\Desktop\\LOAD.txt";
      
      s.load(path_ld);
      current.Text = s.get_key_value();
    }

    private void but_next_Click(object sender, EventArgs e)
    {
      try
      {
        s.next();
        current.Text = s.get_key_value();
      }
      catch
      {
        error.Text = "Lo siento, the end of list!";
      }
    }

    private void but_back_Click(object sender, EventArgs e)
    {
      try
      {
        s.back();
        current.Text = s.get_key_value();
      }
      catch
      {
        error.Text = "Mi scusi, per favore, there is no turning back!";
      }
    }

    private void but_prev_Click(object sender, EventArgs e)
    {
      try
      {
        s.prev();
        current.Text = s.get_key_value();
      }
      catch
      {
        error.Text = "Verzeihung, the begin of list!";
      }
    }

    private void newValue_Click(object sender, EventArgs e)
    {
      string str = input.Text;
      s.new_value(str);
      current.Text = s.get_key_value();
    }

    private void newObj_Click(object sender, EventArgs e)
    {
      string str = input.Text;
      string key = "";
      string value = "";
      bool flag = true;
      for (int i = 0; i < str.Length; i++)
      {
        if (str[i] == ':') { flag = false; continue; }
        if (flag)
        { key += str[i]; }
        else
        { value += str[i]; }
      }

      s.new_obj(key,value);
      current.Text = s.get_key_value();
    }

    private void deleteObj_Click(object sender, EventArgs e)
    {
      string str = input.Text;
      string key = "";
      string value = "";
      bool flag = true;
      for (int i = 0; i < str.Length; i++)
      {
        if (str[i] == ':') flag = false;
        if (flag)
        { key += str[i]; }
        else
        { value += str[i]; }
      }
      try
      {
        s.delete_obj(key, value);
        current.Text = s.get_key_value();
      }
      catch
      {
        error.Text = "对不起，请原谅, the key is not exist!";
      }
    }
  }
}
