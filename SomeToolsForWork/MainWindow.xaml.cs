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
            ComboBox8_2.SelectedIndex = 0;
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

        private void Cal_mc_movevelocity(object sender, RoutedEventArgs e)
        {
            double vel_start = Convert.ToDouble(TextBox3_1.Text);//起始速度
            double vel_max = Convert.ToDouble(TextBox3_2.Text);//最大速度
            double vel_acc = Convert.ToDouble(TextBox3_3.Text);//加速度
            double vel_jerk = Convert.ToDouble(TextBox3_4.Text);//加加速度

            double del_v, v_1;
            double vel_time, vel_t1, vel_t2, vel_t3;
            del_v = vel_max - vel_start;
            vel_t1 = vel_acc / vel_jerk;
            v_1 = vel_jerk * Math.Pow(vel_t1, 2);
            if (v_1 >= del_v)
            {
                vel_t1 = Math.Sqrt(del_v / vel_jerk);
                vel_t2 = 0;
                vel_time = 2 * vel_t1;
                vel_t3 = vel_t1;
                TextBox3_5.Text = Convert.ToString(vel_time);
                TextBox3_6.Text = Convert.ToString(vel_t1);
                TextBox3_7.Text = Convert.ToString(vel_t2);
                TextBox3_8.Text = Convert.ToString(vel_t3);
            }
            else
            {
                vel_t2 = (del_v - v_1) / vel_acc;
                vel_time = (del_v - v_1) / vel_acc + 2 * vel_t1;
                vel_t3 = vel_t1;
                TextBox3_5.Text = Convert.ToString(vel_time);
                TextBox3_6.Text = Convert.ToString(vel_t1);
                TextBox3_7.Text = Convert.ToString(vel_t2);
                TextBox3_8.Text = Convert.ToString(vel_t3);
            }
        }


        private void Cal_mc_moverelative(object sender, RoutedEventArgs e)
        {
            double pos_start = Convert.ToDouble(TextBox4_1.Text);//起始位置
            double pos_end = Convert.ToDouble(TextBox4_2.Text);//目标位置
            double vel_start = Convert.ToDouble(TextBox4_3.Text);//起始速度
            double vel_max = Convert.ToDouble(TextBox4_4.Text);//最大速度
            double vel_end = Convert.ToDouble(TextBox4_5.Text);//结束速度
            double vel_acc = Convert.ToDouble(TextBox4_6.Text);//加速度
            double vel_dec = Convert.ToDouble(TextBox4_7.Text);//减速度
            double vel_jerk = Convert.ToDouble(TextBox4_8.Text);//加加速度
            double pos_time, pos_t1, pos_t2, pos_t3, pos_t4, pos_t5, pos_t6, pos_t7;
            double pos_d1, pos_d2, pos_d3, pos_d4, pos_d5, pos_d6, pos_d7;
            double del_acc_vel, del_dec_vel,del_pos;
            double pos_v1,pos_v2,pos_v3,pos_v4,pos_v5,pos_v6,pos_v7;

            start:
            del_acc_vel = vel_max - vel_start;
            del_dec_vel = vel_max - vel_end;
            del_pos = pos_end - pos_start;
            pos_t1 = vel_acc / vel_jerk;
            pos_v1 = vel_jerk * Math.Pow(pos_t1, 2);
            if (pos_v1 > del_acc_vel)
            {
                //加速运动没有到达最高加速度
                pos_t1 = Math.Sqrt(del_acc_vel / vel_jerk);
                pos_t2 = 0;
                pos_t3 = pos_t1;
            }
            else
            {
                //加速运动到达最高速度加速度
                pos_t1 = 0 + pos_t1;
                pos_t2 = (del_acc_vel - pos_v1) / vel_acc;
                pos_t3 = pos_t1;
            }

            pos_t7 = vel_dec / vel_jerk;
            pos_v7 = vel_jerk * Math.Pow(pos_t7, 2);
            if (pos_v7>=del_dec_vel)
            {
                pos_t5 = Math.Sqrt(del_dec_vel / vel_jerk);
                pos_t6 = 0;
                pos_t7 = pos_t5;
            }
            else
            {
                pos_t5 = pos_t7;
                pos_t6 = (del_dec_vel - pos_v7) / vel_dec;
                pos_t7 = 0 + pos_t7;
            }
            pos_v1 = pos_start + vel_jerk * Math.Pow(pos_t1, 2) / 2;
            pos_v2 = pos_v1 + vel_acc * pos_t2;
            pos_v3 = pos_v2 + vel_acc * pos_t3 - vel_jerk * Math.Pow(pos_t3, 2) / 2;
            pos_v4 = vel_max;
            pos_v7 = vel_end + vel_jerk * Math.Pow(pos_t7, 2) / 2;
            pos_v6 = pos_v7 + vel_dec * pos_t6;
            pos_v5 = pos_v6 + vel_dec * pos_t5 - vel_jerk * Math.Pow(pos_t5, 2) / 2;

            pos_d1 = vel_start * pos_t1 + vel_jerk * Math.Pow(pos_t1, 3) / 6;
            pos_d2 = pos_v1 * pos_t2 + vel_acc * Math.Pow(pos_t2, 2) / 2;
            pos_d3 = pos_v2 * pos_t3 + vel_acc * Math.Pow(pos_t3, 2) / 2 - vel_jerk * Math.Pow(pos_t3, 3) / 6;
            pos_d7 = vel_end * pos_t7 + vel_jerk * Math.Pow(pos_t7, 3) / 6;
            pos_d6 = pos_v7 * pos_t6 + vel_dec * Math.Pow(pos_t6, 2) / 2;
            pos_d5 = pos_v6 * pos_t5 + vel_dec * Math.Pow(pos_t5, 2) / 2 - vel_jerk * Math.Pow(pos_t5, 3) / 6;
            pos_d4 = del_pos - pos_d1 - pos_d2 - pos_d3 - pos_d5 - pos_d6 - pos_d7;
            if (pos_d4 == 0.0)
            {
                pos_t4 = 0;
                pos_time = pos_t1 + pos_t2 + pos_t3 + pos_t4 + pos_t5 + pos_t6 + pos_t7;
            }
            else
            {
                if (pos_d4<0)
                {
                    vel_max = vel_max - 0.1;
                    goto start;
                }
                else
                {
                    pos_t4 = pos_d4 / vel_max;
                    pos_time = pos_t1 + pos_t2 + pos_t3 + pos_t4 + pos_t5 + pos_t6 + pos_t7;
                }
            }
            TextBox4_11.Text = Convert.ToString(pos_time);
            TextBox4_12.Text = Convert.ToString(pos_t1);
            TextBox4_13.Text = Convert.ToString(pos_t2);
            TextBox4_14.Text = Convert.ToString(pos_t3);
            TextBox4_15.Text = Convert.ToString(pos_t4);
            TextBox4_16.Text = Convert.ToString(pos_t5);
            TextBox4_17.Text = Convert.ToString(pos_t6);
            TextBox4_18.Text = Convert.ToString(pos_t7);
            TextBox4_22.Text = Convert.ToString(pos_d1);
            TextBox4_23.Text = Convert.ToString(pos_d2);
            TextBox4_24.Text = Convert.ToString(pos_d3);
            TextBox4_25.Text = Convert.ToString(pos_d4);
            TextBox4_26.Text = Convert.ToString(pos_d5);
            TextBox4_27.Text = Convert.ToString(pos_d6);
            TextBox4_28.Text = Convert.ToString(pos_d7);

        }

        private void Cal_motionvel(object sender, RoutedEventArgs e)
        {
            double ppr = Convert.ToDouble(TextBox5_1.Text);
            double gearin = Convert.ToDouble(TextBox5_2.Text);
            double gearout = Convert.ToDouble(TextBox5_3.Text);
            double setvel = Convert.ToDouble(TextBox5_4.Text);
            double setservovel = Convert.ToDouble(TextBox5_7.Text);

            TextBox5_5.Text = Convert.ToString(setvel / ppr * 60 / gearout * gearin);
            TextBox5_6.Text = Convert.ToString(setvel / ppr * 60 / gearout * gearin / 60);
            TextBox5_8.Text = Convert.ToString(setservovel / gearin * gearout / 60 * ppr);
        }

        private void motionstatesearch(object sender, TextChangedEventArgs e)
        {
            int state;
            try
            {
                state = Convert.ToInt32(TextBox7_1.Text);
            }
            catch (FormatException)
            {
                TextBox7_1.Text = "";
                state = 100;
            }
            finally
            {
                ;
            }
             
            switch (state)
            {
                case 0:
                    TextBox7_2.Text = Convert.ToString("Disable");
                    break;
                case 1:
                    TextBox7_2.Text = Convert.ToString("Standstill");
                    break;
                case 2:
                    TextBox7_2.Text = Convert.ToString("ErrStop");
                    break;
                case 3:
                    TextBox7_2.Text = Convert.ToString("Stopping");
                    break;
                case 4:
                    TextBox7_2.Text = Convert.ToString("Homing");
                    break;
                case 5:
                    TextBox7_2.Text = Convert.ToString("DiscMotion");
                    break;
                case 6:
                    TextBox7_2.Text = Convert.ToString("ContMotion");
                    break;
                case 7:
                    TextBox7_2.Text = Convert.ToString("CAMMotion");
                    break;
                case 8:
                    TextBox7_2.Text = Convert.ToString("GearMotion");
                    break;
                case 9:
                    TextBox7_2.Text = Convert.ToString("CootMotion");
                    break;
                case 10:
                    TextBox7_2.Text = Convert.ToString("RotaryCut");
                    break;
                case 11:
                    TextBox7_2.Text = Convert.ToString("GearMotion");
                    break;
                case 12:
                    TextBox7_2.Text = Convert.ToString("CamMotion");
                    break;
                case 13:
                    TextBox7_2.Text = Convert.ToString("FlyingShear");
                    break;
                case 14:
                    TextBox7_2.Text = Convert.ToString("SetTorque");
                    break;
                case 15:
                    TextBox7_2.Text = Convert.ToString("ContMotion");
                    break;
                case 16:
                    TextBox7_2.Text = Convert.ToString("CamMotion");
                    break;
                case 17:
                    TextBox7_2.Text = Convert.ToString("GearMotion");
                    break;
                case 18:
                    TextBox7_2.Text = Convert.ToString("CombineMotion");
                    break;
                default:
                    TextBox7_2.Text = Convert.ToString("输入值不正确");
                    break;
            }
        }

        private void Cal_modbus(object sender, RoutedEventArgs e)
        {
            int mwidx = ComboBox8_1.SelectedIndex;
            int ixidx = ComboBox8_2.SelectedIndex;
            uint mwvalue = Convert.ToUInt32(TextBox8_1.Text, 10);
            string mwvalue16;
            switch (mwidx)
            {
                case 0:
                    mwvalue16 = Convert.ToString(mwvalue, 16).ToUpper();
                    switch (mwvalue16.Length)
                    {
                        case 1:
                            TextBox8_2.Text = "0x000" + mwvalue16;
                            break;
                        case 2:
                            TextBox8_2.Text = "0x00" + mwvalue16;
                            break;
                        case 3:
                            TextBox8_2.Text = "0x0" + mwvalue16;
                            break;
                        default:
                            TextBox8_2.Text = "0x" + mwvalue16;
                            break;
                    }
                    break;
                case 1:
                    mwvalue16 = Convert.ToString(mwvalue + 0x8000, 16).ToUpper();
                    TextBox8_2.Text = "0x" + mwvalue16;
                    break;
                case 2:
                    mwvalue16 = Convert.ToString(mwvalue + 0xA000, 16).ToUpper();
                    TextBox8_2.Text = "0x" + mwvalue16;
                    break;
            }
            uint ixvalue = Convert.ToUInt32(TextBox8_3.Text) * 8 + Convert.ToUInt32(TextBox8_4.Text);
            switch (ixidx)
            {
                case 0:
                    TextBox8_5.Text = "0x" + Convert.ToString(ixvalue + 0x6000, 16).ToUpper();
                    break;
                case 1:
                    TextBox8_5.Text = "0x" + Convert.ToString(ixvalue + 0xA000, 16).ToUpper();
                    break;
            }
        }
    }
}
