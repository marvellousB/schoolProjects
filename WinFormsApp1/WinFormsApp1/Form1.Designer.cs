namespace WinFormsApp1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            button2 = new Button();
            button3 = new Button();
            button4 = new Button();
            dataGridView1 = new DataGridView();
            rbtnMeeting = new RadioButton();
            rbtnTask = new RadioButton();
            txtDate = new TextBox();
            txtTime = new TextBox();
            txtSummary = new TextBox();
            txtDescription = new TextBox();
            ((System.ComponentModel.ISupportInitialize)dataGridView1).BeginInit();
            SuspendLayout();
            // 
            // button2
            // 
            button2.Location = new Point(12, 220);
            button2.Name = "button2";
            button2.Size = new Size(101, 42);
            button2.TabIndex = 1;
            button2.Text = "add";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button3
            // 
            button3.Location = new Point(520, 24);
            button3.Name = "button3";
            button3.Size = new Size(75, 114);
            button3.TabIndex = 2;
            button3.Text = "update";
            button3.UseVisualStyleBackColor = true;
            // 
            // button4
            // 
            button4.Location = new Point(520, 144);
            button4.Name = "button4";
            button4.Size = new Size(75, 118);
            button4.TabIndex = 3;
            button4.Text = "delete";
            button4.UseVisualStyleBackColor = true;
            // 
            // dataGridView1
            // 
            dataGridView1.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView1.Location = new Point(274, 24);
            dataGridView1.Name = "dataGridView1";
            dataGridView1.RowTemplate.Height = 25;
            dataGridView1.Size = new Size(240, 238);
            dataGridView1.TabIndex = 4;
            // 
            // rbtnMeeting
            // 
            rbtnMeeting.AutoSize = true;
            rbtnMeeting.Location = new Point(13, 24);
            rbtnMeeting.Name = "rbtnMeeting";
            rbtnMeeting.Size = new Size(69, 19);
            rbtnMeeting.TabIndex = 5;
            rbtnMeeting.TabStop = true;
            rbtnMeeting.Text = "Meeting";
            rbtnMeeting.UseVisualStyleBackColor = true;
            // 
            // rbtnTask
            // 
            rbtnTask.AutoSize = true;
            rbtnTask.Location = new Point(13, 49);
            rbtnTask.Name = "rbtnTask";
            rbtnTask.Size = new Size(47, 19);
            rbtnTask.TabIndex = 6;
            rbtnTask.TabStop = true;
            rbtnTask.Text = "Task";
            rbtnTask.UseVisualStyleBackColor = true;
            // 
            // txtDate
            // 
            txtDate.Location = new Point(13, 86);
            txtDate.Name = "txtDate";
            txtDate.Size = new Size(100, 23);
            txtDate.TabIndex = 7;
            txtDate.Text = "Date:";
            // 
            // txtTime
            // 
            txtTime.Location = new Point(13, 115);
            txtTime.Name = "txtTime";
            txtTime.Size = new Size(100, 23);
            txtTime.TabIndex = 8;
            txtTime.Text = "Time:";
            // 
            // txtSummary
            // 
            txtSummary.Location = new Point(13, 144);
            txtSummary.Multiline = true;
            txtSummary.Name = "txtSummary";
            txtSummary.Size = new Size(100, 70);
            txtSummary.TabIndex = 9;
            txtSummary.Text = "Summary:";
            // 
            // txtDescription
            // 
            txtDescription.Location = new Point(119, 24);
            txtDescription.Multiline = true;
            txtDescription.Name = "txtDescription";
            txtDescription.Size = new Size(149, 238);
            txtDescription.TabIndex = 10;
            txtDescription.Text = "Description:";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(614, 279);
            Controls.Add(txtDescription);
            Controls.Add(txtSummary);
            Controls.Add(txtTime);
            Controls.Add(txtDate);
            Controls.Add(rbtnTask);
            Controls.Add(rbtnMeeting);
            Controls.Add(dataGridView1);
            Controls.Add(button4);
            Controls.Add(button3);
            Controls.Add(button2);
            Name = "Form1";
            Text = "Reminders";
            Load += Form1_Load;
            ((System.ComponentModel.ISupportInitialize)dataGridView1).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Button button2;
        private Button button3;
        private Button button4;
        private DataGridView dataGridView1;
        private RadioButton rbtnMeeting;
        private RadioButton rbtnTask;
        private TextBox txtDate;
        private TextBox txtTime;
        private TextBox txtSummary;
        private TextBox txtDescription;
    }
}