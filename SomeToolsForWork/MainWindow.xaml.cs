using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
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

namespace SomeToolsForWork
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void program_exit(object sender, RoutedEventArgs e)
        {
            Environment.Exit(0);
        }

        private void MainWindow_OnLoaded(object sender, RoutedEventArgs e)
        {
            ListBox0.SelectedIndex = 0;
            ComboBox8_1.SelectedIndex = 0;
        }

        private void ListBox_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (ListBox0.SelectedItems == null)
            {
                return;
            }
            else
            {
                var itemnum = ListBox0.SelectedIndex;
                switch (itemnum)
                {
                    case 0:
                        grid0.Visibility = Visibility.Visible;
                        grid1.Visibility = Visibility.Hidden;
                        grid2.Visibility = Visibility.Hidden;
                        grid3.Visibility = Visibility.Hidden;
                        grid4.Visibility = Visibility.Hidden;
                        grid5.Visibility = Visibility.Hidden;
                        grid6.Visibility = Visibility.Hidden;
                        grid7.Visibility = Visibility.Hidden;
                        break;
                    case 1:
                        grid0.Visibility = Visibility.Hidden;
                        grid1.Visibility = Visibility.Visible;
                        grid2.Visibility = Visibility.Hidden;
                        grid3.Visibility = Visibility.Hidden;
                        grid4.Visibility = Visibility.Hidden;
                        grid5.Visibility = Visibility.Hidden;
                        grid6.Visibility = Visibility.Hidden;
                        grid7.Visibility = Visibility.Hidden;
                        break;
                    case 2:
                        grid0.Visibility = Visibility.Hidden;
                        grid1.Visibility = Visibility.Hidden;
                        grid2.Visibility = Visibility.Visible;
                        grid3.Visibility = Visibility.Hidden;
                        grid4.Visibility = Visibility.Hidden;
                        grid5.Visibility = Visibility.Hidden;
                        grid6.Visibility = Visibility.Hidden;
                        grid7.Visibility = Visibility.Hidden;
                        break;
                    case 3:
                        grid0.Visibility = Visibility.Hidden;
                        grid1.Visibility = Visibility.Hidden;
                        grid2.Visibility = Visibility.Hidden;
                        grid3.Visibility = Visibility.Visible;
                        grid4.Visibility = Visibility.Hidden;
                        grid5.Visibility = Visibility.Hidden;
                        grid6.Visibility = Visibility.Hidden;
                        grid7.Visibility = Visibility.Hidden;
                        break;
                    case 4:
                        grid0.Visibility = Visibility.Hidden;
                        grid1.Visibility = Visibility.Hidden;
                        grid2.Visibility = Visibility.Hidden;
                        grid3.Visibility = Visibility.Hidden;
                        grid4.Visibility = Visibility.Visible;
                        grid5.Visibility = Visibility.Hidden;
                        grid6.Visibility = Visibility.Hidden;
                        grid7.Visibility = Visibility.Hidden;
                        break;
                    case 5:
                        grid0.Visibility = Visibility.Hidden;
                        grid1.Visibility = Visibility.Hidden;
                        grid2.Visibility = Visibility.Hidden;
                        grid3.Visibility = Visibility.Hidden;
                        grid4.Visibility = Visibility.Hidden;
                        grid5.Visibility = Visibility.Visible;
                        grid6.Visibility = Visibility.Hidden;
                        grid7.Visibility = Visibility.Hidden;
                        break;
                    case 6:
                        grid0.Visibility = Visibility.Hidden;
                        grid1.Visibility = Visibility.Hidden;
                        grid2.Visibility = Visibility.Hidden;
                        grid3.Visibility = Visibility.Hidden;
                        grid4.Visibility = Visibility.Hidden;
                        grid5.Visibility = Visibility.Hidden;
                        grid6.Visibility = Visibility.Visible;
                        grid7.Visibility = Visibility.Hidden;
                        break;
                    case 7:
                        grid0.Visibility = Visibility.Hidden;
                        grid1.Visibility = Visibility.Hidden;
                        grid2.Visibility = Visibility.Hidden;
                        grid3.Visibility = Visibility.Hidden;
                        grid4.Visibility = Visibility.Hidden;
                        grid5.Visibility = Visibility.Hidden;
                        grid6.Visibility = Visibility.Hidden;
                        grid7.Visibility = Visibility.Visible;
                        break;
                    default:
                        grid0.Visibility = Visibility.Hidden;
                        grid1.Visibility = Visibility.Hidden;
                        grid2.Visibility = Visibility.Hidden;
                        grid3.Visibility = Visibility.Hidden;
                        grid4.Visibility = Visibility.Hidden;
                        grid5.Visibility = Visibility.Hidden;
                        grid6.Visibility = Visibility.Hidden;
                        grid7.Visibility = Visibility.Hidden;
                        break;
                }
            }
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
                    finally
                    {
                        TextBox1_1.Text = Convert.ToString(binNum, 10);
                        TextBox1_2.Text = Convert.ToString(binNum, 16).ToUpper();
                    }
                }
            }
        }

        //浮点数转换
        [StructLayoutAttribute(LayoutKind.Explicit,Size = 4)]
        public struct real_udint
        {
            [FieldOffsetAttribute(0)]
            public float real;
            [FieldOffsetAttribute(0)]
            public Int32 udint;
        }
        [StructLayoutAttribute(LayoutKind.Explicit, Size = 8)]
        public struct lreal_ulint
        {
            [FieldOffsetAttribute(0)]
            public double lreal;
            [FieldOffsetAttribute(0)]
            public Int64 ulint;
        }
        private void Button2_1_OnClick(object sender, RoutedEventArgs e)
        {
            int transmode = 0;
            if (RadioButton2_1.IsChecked==true && RadioButton2_2.IsChecked == false)
            {
                if (RadioButton2_3.IsChecked==true && RadioButton2_4.IsChecked==false)
                {
                    transmode = 1;
                }
                if (RadioButton2_4.IsChecked==true && RadioButton2_3.IsChecked==false)
                {
                    transmode = 2;
                }
             
            }
            if (RadioButton2_1.IsChecked == false && RadioButton2_2.IsChecked == true)
            {
                if (RadioButton2_3.IsChecked == true && RadioButton2_4.IsChecked == false)
                {
                    transmode = 3;
                }
                if (RadioButton2_4.IsChecked == true && RadioButton2_3.IsChecked == false)
                {
                    transmode = 4;
                }
            }
            
            switch (transmode)
            {
                case 1:
                    real_udint real_udint1;
                    real_udint1.udint = 0;
                    real_udint1.real = (float)(Convert.ToDouble(TextBox2_1.Text));
                    TextBox2_2.Text = Convert.ToString(real_udint1.udint, 16).ToUpper();
                    break;
                case 2:
                    real_udint real_udint2;
                    real_udint2.real = 0.0F;
                    real_udint2.udint = (Convert.ToInt32(TextBox2_1.Text,16));
                    TextBox2_2.Text = Convert.ToString(real_udint2.real);
                    break;
                case 3:
                    lreal_ulint lreal_ulint1;
                    lreal_ulint1.ulint = 0;
                    lreal_ulint1.lreal = (Convert.ToDouble(TextBox2_1.Text));
                    TextBox2_2.Text = Convert.ToString(lreal_ulint1.ulint, 16).ToUpper();
                    break;
                case 4:
                    lreal_ulint lreal_ulint2;
                    lreal_ulint2.lreal = 0.0;
                    lreal_ulint2.ulint = (Convert.ToInt64(TextBox2_1.Text, 16));
                    TextBox2_2.Text = Convert.ToString(lreal_ulint2.lreal);
                    break;
                default:
                    break;
                    
            }

        }


        private void open_About(object sender, RoutedEventArgs e)
        {
            About newAboutWindow = new About();
            newAboutWindow.Title = "关于";
            newAboutWindow.Show();
        }
    }
}
