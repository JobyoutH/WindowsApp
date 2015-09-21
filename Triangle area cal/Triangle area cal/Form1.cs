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

                }
                catch (FormatException)
                { }
            }
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            Graphics gc = e.Graphics;

            double a, b, c, x, y, a1, b1, c1, x1, y1, x2, temp;

            String A = "A", B = "B", C = "C", T;
            try
            {
                a1 = double.Parse(ina1.Text);
                b1 = double.Parse(inb1.Text);
                c1 = double.Parse(inc1.Text);

                if (a1 < b1)
                {
                    temp = a1;
                    a1 = b1;
                    b1 = temp;
                    T = A.Clone().ToString();
                    A = B.Clone().ToString();
                    B = T.Clone().ToString();

                }

                if (a1 < c1)
                {
                    temp = a1;
                    a1 = c1;
                    c1 = temp;
                    T = A.Clone().ToString();
                    A = C.Clone().ToString();
                    C = T.Clone().ToString();
                }

                a = 250.0;
                b = a / a1 * b1;
                c = a / a1 * c1;


                x1 = (panel1.Width - a) / 2.0;
                x2 = (panel1.Width + a) / 2.0;

                x = (x1 + x2 + (b * b - c * c) / (x2 - x1)) / 2.0;
                y1 = panel1.Height / 2 + Math.Sqrt(b * b - (x - x1) * (x - x1)) / 2.0;
                y = panel1.Height - y1;

                Pen pen = new Pen(Color.Black, 1);
                gc.DrawLine(pen, (float)x1, (float)y1, (float)x2, (float)y1);
                gc.DrawLine(pen, (float)x2, (float)y1, (float)x, (float)y);
                gc.DrawLine(pen, (float)x, (float)y, (float)x1, (float)y1);

                Font ff = new Font("微软雅黑", 16, FontStyle.Regular);
                Color col = new Color();
                col = Color.Black;

                Brush bru = new SolidBrush(col);

                gc.DrawString(A, ff, bru, (float)(panel1.Width / 2.0 - 8), (float)y1 + 10);
                gc.DrawString(B, ff, bru, (float)((x1 + x) / 2.0 - 40), (float)((y1 + y) / 2.0 - 18));
                gc.DrawString(C, ff, bru, (float)((x2 + x) / 2.0 + 20), (float)((y1 + y) / 2.0 - 18));
            }
            catch (FormatException)
            { }
            
        }
    }
}
