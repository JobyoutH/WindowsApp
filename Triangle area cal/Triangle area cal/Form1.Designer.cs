namespace Triangle_area_cal
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.ina1 = new System.Windows.Forms.TextBox();
            this.inb1 = new System.Windows.Forms.TextBox();
            this.inc1 = new System.Windows.Forms.TextBox();
            this.out1 = new System.Windows.Forms.TextBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.Data = new System.Windows.Forms.GroupBox();
            this.A = new System.Windows.Forms.TextBox();
            this.B = new System.Windows.Forms.TextBox();
            this.S = new System.Windows.Forms.TextBox();
            this.C = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.Data.SuspendLayout();
            this.SuspendLayout();
            // 
            // ina1
            // 
            this.ina1.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ina1.Location = new System.Drawing.Point(0, 9);
            this.ina1.MaxLength = 8;
            this.ina1.Name = "ina1";
            this.ina1.Size = new System.Drawing.Size(100, 23);
            this.ina1.TabIndex = 0;
            this.ina1.TextChanged += new System.EventHandler(this.sTextChanged);
            this.ina1.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.num_KeyPress);
            // 
            // inb1
            // 
            this.inb1.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.inb1.Location = new System.Drawing.Point(138, 9);
            this.inb1.MaxLength = 8;
            this.inb1.Name = "inb1";
            this.inb1.Size = new System.Drawing.Size(100, 23);
            this.inb1.TabIndex = 1;
            this.inb1.TextChanged += new System.EventHandler(this.sTextChanged);
            // 
            // inc1
            // 
            this.inc1.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.inc1.Location = new System.Drawing.Point(268, 9);
            this.inc1.MaxLength = 8;
            this.inc1.Name = "inc1";
            this.inc1.Size = new System.Drawing.Size(100, 23);
            this.inc1.TabIndex = 2;
            this.inc1.TextChanged += new System.EventHandler(this.sTextChanged);
            // 
            // out1
            // 
            this.out1.Enabled = false;
            this.out1.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.out1.Location = new System.Drawing.Point(395, 9);
            this.out1.MaxLength = 11;
            this.out1.Name = "out1";
            this.out1.Size = new System.Drawing.Size(100, 23);
            this.out1.TabIndex = 3;
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.HighlightText;
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Location = new System.Drawing.Point(65, 152);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(495, 451);
            this.panel1.TabIndex = 4;
            this.panel1.Tag = "";
            this.panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.panel1_Paint);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.ina1);
            this.groupBox1.Controls.Add(this.inb1);
            this.groupBox1.Controls.Add(this.out1);
            this.groupBox1.Controls.Add(this.inc1);
            this.groupBox1.Location = new System.Drawing.Point(65, 83);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(495, 34);
            this.groupBox1.TabIndex = 5;
            this.groupBox1.TabStop = false;
            // 
            // Data
            // 
            this.Data.Controls.Add(this.A);
            this.Data.Controls.Add(this.B);
            this.Data.Controls.Add(this.S);
            this.Data.Controls.Add(this.C);
            this.Data.Location = new System.Drawing.Point(65, 28);
            this.Data.Name = "Data";
            this.Data.Size = new System.Drawing.Size(495, 34);
            this.Data.TabIndex = 6;
            this.Data.TabStop = false;
            // 
            // A
            // 
            this.A.Enabled = false;
            this.A.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.A.Location = new System.Drawing.Point(0, 9);
            this.A.MaxLength = 8;
            this.A.Name = "A";
            this.A.Size = new System.Drawing.Size(100, 23);
            this.A.TabIndex = 0;
            this.A.Text = "a";
            // 
            // B
            // 
            this.B.Enabled = false;
            this.B.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.B.Location = new System.Drawing.Point(138, 9);
            this.B.MaxLength = 8;
            this.B.Name = "B";
            this.B.Size = new System.Drawing.Size(100, 23);
            this.B.TabIndex = 1;
            this.B.Text = "b";
            // 
            // S
            // 
            this.S.Enabled = false;
            this.S.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.S.Location = new System.Drawing.Point(395, 9);
            this.S.MaxLength = 11;
            this.S.Name = "S";
            this.S.Size = new System.Drawing.Size(100, 23);
            this.S.TabIndex = 3;
            this.S.Text = "S";
            // 
            // C
            // 
            this.C.Enabled = false;
            this.C.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.C.Location = new System.Drawing.Point(268, 9);
            this.C.MaxLength = 8;
            this.C.Name = "C";
            this.C.Size = new System.Drawing.Size(100, 23);
            this.C.TabIndex = 2;
            this.C.Text = "c";
            // 
            // Form1
            // 
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(627, 642);
            this.Controls.Add(this.Data);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.panel1);
            this.Font = new System.Drawing.Font("Segoe UI", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Triangle Area Calculator";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.Data.ResumeLayout(false);
            this.Data.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion


        private System.Windows.Forms.TextBox ina1;
        private System.Windows.Forms.TextBox inb1;
        private System.Windows.Forms.TextBox inc1;
        private System.Windows.Forms.TextBox out1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox Data;
        private System.Windows.Forms.TextBox A;
        private System.Windows.Forms.TextBox B;
        private System.Windows.Forms.TextBox S;
        private System.Windows.Forms.TextBox C;
    }
}

