using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Triangle_area_cal
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();            
        }

        private double AeraCalculator(double a, double b, double c)
        {
            double s, p = (a + b + c) / 2;

            if (a + b > c && a + c > b && b + c > a)
            {
                return s = System.Math.Sqrt(p * (p - a) * (p - b) * (p - c));
            }
            else
            {
                return s = 0;
            }
        }

        private void num_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!((e.KeyChar >= '0' && e.KeyChar <= '9') || e.KeyChar == '.' || e.KeyChar == ''))
            {
                e.Handled = true;
            }
            else
            {
                if (e.KeyChar == '.')
                {
                    string str = this.Text;
                    int num = str.IndexOf('.');
                    if (num != -1)
                    {
                        e.Handled = true;
                    }
                }
            }
        }

        private void sTextChanged(object sender, EventArgs e)
        {
            if (ina1.Text != null && inb1.Text != null && inc1.Text != null)
            {
                double a, b, c, s;

                try
                {
                    a = Double.Parse(ina1.Text);
                    b = Double.Parse(inb1.Text);
                    c = Double.Parse(inc1.Text);

                    s = AeraCalculator(a, b, c);

                    if (s == 0)
                    {
                        out1.Text = "null";
                    }
                    else
                    {
                        out1.Text = s.ToString("0.00");
                        panel1.Invalidate();
                    }  

                    out1.Show();

                }
                catch (FormatException)
                { }
            }
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            Graphics gc = e.Graphics;

            float a, b, c, x, y, a1, b1, c1, x1, y1, x2, temp;
            try
            {
                a1 = float.Parse(ina1.Text);
                b1 = float.Parse(inb1.Text);
                c1 = float.Parse(inc1.Text);

                if (a1 < b1)
                {
                    temp = a1;
                    a1 = b1;
                    b1 = temp;
                }

                if (a1 < c1)
                {
                    temp = a1;
                    a1 = c1;
                    c1 = temp;
                }

                a = 250;
                b = a / a1 * b1;
                c = a / a1 * c1;


                x1 = (2 * panel1.Left + panel1.Width - a) / 2;
                x2 = (2 * panel1.Left + panel1.Width + a) / 2;

                x = (x1 + x2 + (b * b - c * c) / (x2 - x1)) / 2;
                y1 = panel1.Top + panel1.Height / 2 - (float)Math.Sqrt(b * b - (x - x1) * (x - x1)) / 3;
                y = (float)(3 * panel1.Top + 1.5 * panel1.Height - 2 * y1);

                Pen pen = new Pen(Color.Black, 1);
                gc.DrawLine(pen, x1, y1, x2, y1);
                gc.DrawLine(pen, x2, y1, x, y);
                gc.DrawLine(pen, x, y, x1, y1);
            }
            catch (FormatException)
            { }
            
        }
    }
}
