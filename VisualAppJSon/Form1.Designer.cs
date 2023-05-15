namespace VisualAppJSon
{
  partial class Form1
  {
    /// <summary>
    /// Обязательная переменная конструктора.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    /// Освободить все используемые ресурсы.
    /// </summary>
    /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
    protected override void Dispose(bool disposing)
    {
      if (disposing && (components != null))
      {
        components.Dispose();
      }
      base.Dispose(disposing);
    }

    #region Код, автоматически созданный конструктором форм Windows

    /// <summary>
    /// Требуемый метод для поддержки конструктора — не изменяйте 
    /// содержимое этого метода с помощью редактора кода.
    /// </summary>
    private void InitializeComponent()
    {
      this.current = new System.Windows.Forms.TextBox();
      this.button1 = new System.Windows.Forms.Button();
      this.output = new System.Windows.Forms.TextBox();
      this.controlPanel = new System.Windows.Forms.GroupBox();
      this.but_next = new System.Windows.Forms.Button();
      this.but_prev = new System.Windows.Forms.Button();
      this.but_back = new System.Windows.Forms.Button();
      this.but_down = new System.Windows.Forms.Button();
      this.editingPanel = new System.Windows.Forms.GroupBox();
      this.newObj = new System.Windows.Forms.Button();
      this.deleteObj = new System.Windows.Forms.Button();
      this.newValue = new System.Windows.Forms.Button();
      this.loadJSON = new System.Windows.Forms.Button();
      this.input = new System.Windows.Forms.TextBox();
      this.error = new System.Windows.Forms.TextBox();
      this.controlPanel.SuspendLayout();
      this.editingPanel.SuspendLayout();
      this.SuspendLayout();
      // 
      // current
      // 
      this.current.Location = new System.Drawing.Point(11, 11);
      this.current.Margin = new System.Windows.Forms.Padding(2);
      this.current.Multiline = true;
      this.current.Name = "current";
      this.current.ScrollBars = System.Windows.Forms.ScrollBars.Both;
      this.current.Size = new System.Drawing.Size(66, 20);
      this.current.TabIndex = 0;
      this.current.TextChanged += new System.EventHandler(this.current_TextChanged);
      // 
      // button1
      // 
      this.button1.Location = new System.Drawing.Point(178, 12);
      this.button1.Margin = new System.Windows.Forms.Padding(2);
      this.button1.Name = "button1";
      this.button1.Size = new System.Drawing.Size(79, 31);
      this.button1.TabIndex = 1;
      this.button1.Text = "Output JSON";
      this.button1.UseVisualStyleBackColor = true;
      this.button1.Click += new System.EventHandler(this.button1_Click);
      // 
      // output
      // 
      this.output.AcceptsReturn = true;
      this.output.AcceptsTab = true;
      this.output.Location = new System.Drawing.Point(8, 48);
      this.output.Multiline = true;
      this.output.Name = "output";
      this.output.ScrollBars = System.Windows.Forms.ScrollBars.Both;
      this.output.Size = new System.Drawing.Size(249, 304);
      this.output.TabIndex = 2;
      // 
      // controlPanel
      // 
      this.controlPanel.Controls.Add(this.but_next);
      this.controlPanel.Controls.Add(this.but_prev);
      this.controlPanel.Controls.Add(this.but_back);
      this.controlPanel.Controls.Add(this.but_down);
      this.controlPanel.Location = new System.Drawing.Point(276, 31);
      this.controlPanel.Name = "controlPanel";
      this.controlPanel.Size = new System.Drawing.Size(274, 108);
      this.controlPanel.TabIndex = 3;
      this.controlPanel.TabStop = false;
      this.controlPanel.Text = "Control panel";
      // 
      // but_next
      // 
      this.but_next.Location = new System.Drawing.Point(29, 57);
      this.but_next.Name = "but_next";
      this.but_next.Size = new System.Drawing.Size(79, 32);
      this.but_next.TabIndex = 2;
      this.but_next.Text = "Next";
      this.but_next.UseVisualStyleBackColor = true;
      this.but_next.Click += new System.EventHandler(this.but_next_Click);
      // 
      // but_prev
      // 
      this.but_prev.Location = new System.Drawing.Point(171, 57);
      this.but_prev.Name = "but_prev";
      this.but_prev.Size = new System.Drawing.Size(79, 32);
      this.but_prev.TabIndex = 5;
      this.but_prev.Text = "Previous";
      this.but_prev.UseVisualStyleBackColor = true;
      this.but_prev.Click += new System.EventHandler(this.but_prev_Click);
      // 
      // but_back
      // 
      this.but_back.Location = new System.Drawing.Point(171, 19);
      this.but_back.Name = "but_back";
      this.but_back.Size = new System.Drawing.Size(79, 32);
      this.but_back.TabIndex = 4;
      this.but_back.Text = "Back";
      this.but_back.UseVisualStyleBackColor = true;
      this.but_back.Click += new System.EventHandler(this.but_back_Click);
      // 
      // but_down
      // 
      this.but_down.Location = new System.Drawing.Point(29, 19);
      this.but_down.Name = "but_down";
      this.but_down.Size = new System.Drawing.Size(79, 32);
      this.but_down.TabIndex = 3;
      this.but_down.Text = "Down";
      this.but_down.UseVisualStyleBackColor = true;
      this.but_down.Click += new System.EventHandler(this.but_down_Click);
      // 
      // editingPanel
      // 
      this.editingPanel.Controls.Add(this.input);
      this.editingPanel.Controls.Add(this.newObj);
      this.editingPanel.Controls.Add(this.deleteObj);
      this.editingPanel.Controls.Add(this.newValue);
      this.editingPanel.Location = new System.Drawing.Point(276, 167);
      this.editingPanel.Name = "editingPanel";
      this.editingPanel.Size = new System.Drawing.Size(274, 154);
      this.editingPanel.TabIndex = 4;
      this.editingPanel.TabStop = false;
      this.editingPanel.Text = "Editing panel";
      // 
      // newObj
      // 
      this.newObj.Location = new System.Drawing.Point(29, 102);
      this.newObj.Name = "newObj";
      this.newObj.Size = new System.Drawing.Size(79, 32);
      this.newObj.TabIndex = 2;
      this.newObj.Text = "New object";
      this.newObj.UseVisualStyleBackColor = true;
      this.newObj.Click += new System.EventHandler(this.newObj_Click);
      // 
      // deleteObj
      // 
      this.deleteObj.Location = new System.Drawing.Point(171, 102);
      this.deleteObj.Name = "deleteObj";
      this.deleteObj.Size = new System.Drawing.Size(79, 32);
      this.deleteObj.TabIndex = 1;
      this.deleteObj.Text = "Delete object";
      this.deleteObj.UseVisualStyleBackColor = true;
      this.deleteObj.Click += new System.EventHandler(this.deleteObj_Click);
      // 
      // newValue
      // 
      this.newValue.Location = new System.Drawing.Point(29, 37);
      this.newValue.Name = "newValue";
      this.newValue.Size = new System.Drawing.Size(79, 32);
      this.newValue.TabIndex = 0;
      this.newValue.Text = "New value";
      this.newValue.UseVisualStyleBackColor = true;
      this.newValue.Click += new System.EventHandler(this.newValue_Click);
      // 
      // loadJSON
      // 
      this.loadJSON.Location = new System.Drawing.Point(94, 12);
      this.loadJSON.Name = "loadJSON";
      this.loadJSON.Size = new System.Drawing.Size(79, 32);
      this.loadJSON.TabIndex = 5;
      this.loadJSON.Text = "Load JSON";
      this.loadJSON.UseVisualStyleBackColor = true;
      this.loadJSON.Click += new System.EventHandler(this.output_curr_Click);
      // 
      // input
      // 
      this.input.Location = new System.Drawing.Point(171, 37);
      this.input.Multiline = true;
      this.input.Name = "input";
      this.input.Size = new System.Drawing.Size(79, 32);
      this.input.TabIndex = 3;
      // 
      // error
      // 
      this.error.Location = new System.Drawing.Point(276, 331);
      this.error.Name = "error";
      this.error.Size = new System.Drawing.Size(274, 20);
      this.error.TabIndex = 6;
      // 
      // Form1
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(612, 364);
      this.Controls.Add(this.error);
      this.Controls.Add(this.loadJSON);
      this.Controls.Add(this.editingPanel);
      this.Controls.Add(this.button1);
      this.Controls.Add(this.controlPanel);
      this.Controls.Add(this.output);
      this.Controls.Add(this.current);
      this.Margin = new System.Windows.Forms.Padding(2);
      this.Name = "Form1";
      this.Text = "Form1";
      this.Load += new System.EventHandler(this.Form1_Load);
      this.controlPanel.ResumeLayout(false);
      this.editingPanel.ResumeLayout(false);
      this.editingPanel.PerformLayout();
      this.ResumeLayout(false);
      this.PerformLayout();

    }

    #endregion

    private System.Windows.Forms.TextBox current;
    private System.Windows.Forms.Button button1;
    private System.Windows.Forms.TextBox output;
    private System.Windows.Forms.GroupBox controlPanel;
    private System.Windows.Forms.GroupBox editingPanel;
    private System.Windows.Forms.Button but_prev;
    private System.Windows.Forms.Button but_back;
    private System.Windows.Forms.Button but_down;
    private System.Windows.Forms.Button but_next;
    private System.Windows.Forms.Button newObj;
    private System.Windows.Forms.Button deleteObj;
    private System.Windows.Forms.Button newValue;
    private System.Windows.Forms.Button loadJSON;
    private System.Windows.Forms.TextBox input;
    private System.Windows.Forms.TextBox error;
  }
}

