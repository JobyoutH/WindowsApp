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
            this.ina1 = new System.Windows.Forms.TextBox();
            this.inb1 = new System.Windows.Forms.TextBox();
            this.inc1 = new System.Windows.Forms.TextBox();
            this.out1 = new System.Windows.Forms.TextBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // ina1
            // 
            this.ina1.Location = new System.Drawing.Point(384, 49);
            this.ina1.MaxLength = 8;
            this.ina1.Name = "ina1";
            this.ina1.Size = new System.Drawing.Size(100, 21);
            this.ina1.TabIndex = 0;
            this.ina1.TextChanged += new System.EventHandler(this.sTextChanged);
            this.ina1.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.num_KeyPress);
            // 
            // inb1
            // 
            this.inb1.Location = new System.Drawing.Point(517, 49);
            this.inb1.MaxLength = 8;
            this.inb1.Name = "inb1";
            this.inb1.Size = new System.Drawing.Size(100, 21);
            this.inb1.TabIndex = 1;
            this.inb1.TextChanged += new System.EventHandler(this.sTextChanged);
            // 
            // inc1
            // 
            this.inc1.Location = new System.Drawing.Point(659, 49);
            this.inc1.MaxLength = 8;
            this.inc1.Name = "inc1";
            this.inc1.Size = new System.Drawing.Size(100, 21);
            this.inc1.TabIndex = 2;
            this.inc1.TextChanged += new System.EventHandler(this.sTextChanged);
            // 
            // out1
            // 
            this.out1.Location = new System.Drawing.Point(789, 49);
            this.out1.MaxLength = 11;
            this.out1.Name = "out1";
            this.out1.Size = new System.Drawing.Size(100, 21);
            this.out1.TabIndex = 3;
            this.out1.Visible = false;
            // 
            // panel1
            // 
            this.panel1.Location = new System.Drawing.Point(16, 27);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(353, 436);
            this.panel1.TabIndex = 4;
            this.panel1.Paint += new System.Windows.Forms.PaintEventHandler(this.panel1_Paint);
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(901, 497);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.out1);
            this.Controls.Add(this.inc1);
            this.Controls.Add(this.inb1);
            this.Controls.Add(this.ina1);
            this.Name = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox ina1;
        private System.Windows.Forms.TextBox inb1;
        private System.Windows.Forms.TextBox inc1;
        private System.Windows.Forms.TextBox out1;
        private System.Windows.Forms.Panel panel1;
    }
}

