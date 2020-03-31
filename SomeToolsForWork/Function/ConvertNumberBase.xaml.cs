using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace SomeTools.Function
{
    /// <summary>
    /// NumberBaseConversion.xaml 的交互逻辑
    /// </summary>
    public partial class NumberBaseConversion : UserControl
    {
        public NumberBaseConversion()
        {
            InitializeComponent();
        }

        //进制转换——十进制
        private void DecText_Change(object sender, TextChangedEventArgs e)
        {
            if (TextBox1_1.IsFocused)
            {
                string decText = TextBox1_1.Text;
                if (decText == "")
                {
                    TextBox1_2.Text = "0";
                    TextBox1_3.Text = "0";
                }
                else
                {
                    long decNum = 0;
                    try
                    {
                        decNum = Convert.ToInt64(decText, 10);
                        Label1_4.Visibility = Visibility.Hidden;
                    }
                    catch (FormatException)
                    {
                        decNum = 0;
                        Label1_4.Visibility = Visibility.Visible;
                    }
                    catch (OverflowException)
                    {
                        decNum = 0;
                        Label1_4.Visibility = Visibility.Visible;
                    }
                    finally
                    {
                        TextBox1_2.Text = Convert.ToString(decNum, 16).ToUpper();
                        TextBox1_3.Text = Convert.ToString(decNum, 2);
                    }
                }
            }
        }

        //进制转换——十六进制
        private void HexText_Change(object sender, TextChangedEventArgs e)
        {
            if (TextBox1_2.IsFocused)
            {
                string hexText = TextBox1_2.Text;

                if (hexText == "")
                {
                    TextBox1_1.Text = "0";
                    TextBox1_3.Text = "0";
                }
                else
                {
                    long hexNum = 0;
                    try
                    {
                        hexNum = Convert.ToInt64(hexText, 16);
                        Label1_4.Visibility = Visibility.Hidden;
                    }
                    catch (FormatException)
                    {
                        hexNum = 0;
                        Label1_4.Visibility = Visibility.Visible;
                    }
                    catch (OverflowException)
                    {
                        hexNum = 0;
                        Label1_4.Visibility = Visibility.Visible;
                    }
                    finally
                    {
                        TextBox1_1.Text = Convert.ToString(hexNum, 10);
                        TextBox1_3.Text = Convert.ToString(hexNum, 2);
                    }
                }
            }
        }

        //进制转换——二进制
        private void BinText_Change(object sender, TextChangedEventArgs e)
        {
            if (TextBox1_3.IsFocused)
            {
                string binText = TextBox1_3.Text;
                if (binText == "")
                {
                    TextBox1_1.Text = "0";
                    TextBox1_2.Text = "0";
                }
                else
                {
                    long binNum = 0;
                    try
                    {
                        binNum = Convert.ToInt64(binText, 2);
                        Label1_4.Visibility = Visibility.Hidden;
                    }
                    catch (FormatException)
                    {
                        binNum = 0;
                        Label1_4.Visibility = Visibility.Visible;
                    }
                    catch (OverflowException)
                    {
                        binNum = 0;
                        Label1_4.Visibility = Visibility.Visible;
                    }
                    finally
                    {
                        TextBox1_1.Text = Convert.ToString(binNum, 10);
                        TextBox1_2.Text = Convert.ToString(binNum, 16).ToUpper();
                    }
                }
            }
        }
    }
}