using System;
using System.Collections.Generic;
using System.IO;
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
using System.Windows.Threading;
using System.Net;
using System.Net.NetworkInformation;
using System.Net.Sockets;
using System.Threading;

namespace SomeTools
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
            ListBox0.SelectedIndex = 8;
            ComboBox8_1.SelectedIndex = 0;
            ComboBox8_2.SelectedIndex = 0;
            LanuchTimer();
            GetNetworkInterface();
            ComboBoxNetworkInterface.ItemsSource = combolist;
            ComboBoxNetworkInterface.SelectedIndex = 0;
        }

        private void MainWindow_OnClosed(object sender, EventArgs e)
        {
            Environment.Exit(0);
        }

        private void open_About(object sender, RoutedEventArgs e)
        {
            About newAboutWindow = new About();
            newAboutWindow.Title = "关于";
            newAboutWindow.Show();
        }

        private void TimerTick(object sender, EventArgs e)
        {
            Timer.Content = DateTime.Now.ToLongDateString() +" " + DateTime.Now.ToLongTimeString();
        }

        private void LanuchTimer()
        {
            DispatcherTimer innerTimer = new DispatcherTimer(TimeSpan.FromSeconds(1.0),DispatcherPriority.Loaded, new EventHandler(this.TimerTick), this.Dispatcher);
            innerTimer.Start();
        }

        public struct combomem
        {
            public int ID { get; set; }
            public string comboMember { get; set; }
            public string ipadd { get; set; }
        }

        private NetworkInterface[] NetworkInterfaces = NetworkInterface.GetAllNetworkInterfaces();
        List<combomem> combolist = new List<combomem>();

        private void GetNetworkInterface()
        {
            
            combomem combomenber = new combomem();
            int i = 0;
            foreach (NetworkInterface networkInterface in NetworkInterfaces)
            {
                combomenber.ID = i;
                i++;
                combomenber.comboMember = networkInterface.Description;
                IPInterfaceProperties IPInterfaceProperties = networkInterface.GetIPProperties();
                UnicastIPAddressInformationCollection UnicastIPAddressInformationCollection = IPInterfaceProperties.UnicastAddresses;
                foreach (UnicastIPAddressInformation UnicastIPAddressInformation in UnicastIPAddressInformationCollection)
                {
                    if (UnicastIPAddressInformation.Address.AddressFamily == AddressFamily.InterNetwork)
                    {
                        combomenber.ipadd = UnicastIPAddressInformation.Address.ToString();
                    }
                }

                combolist.Add(combomenber);
            }
        
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
                        grid8.Visibility = Visibility.Hidden;
                        grid9.Visibility = Visibility.Hidden;
                        grid10.Visibility = Visibility.Hidden;
                        grid11.Visibility = Visibility.Hidden;
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
                        grid8.Visibility = Visibility.Hidden;
                        grid9.Visibility = Visibility.Hidden;
                        grid10.Visibility = Visibility.Hidden;
                        grid11.Visibility = Visibility.Hidden;

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
                        grid8.Visibility = Visibility.Hidden;
                        grid9.Visibility = Visibility.Hidden;
                        grid10.Visibility = Visibility.Hidden;
                        grid11.Visibility = Visibility.Hidden;

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
                        grid8.Visibility = Visibility.Hidden;
                        grid9.Visibility = Visibility.Hidden;
                        grid10.Visibility = Visibility.Hidden;
                        grid11.Visibility = Visibility.Hidden;

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
                        grid8.Visibility = Visibility.Hidden;
                        grid9.Visibility = Visibility.Hidden;
                        grid10.Visibility = Visibility.Hidden;
                        grid11.Visibility = Visibility.Hidden;

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
                        grid8.Visibility = Visibility.Hidden;
                        grid9.Visibility = Visibility.Hidden;
                        grid10.Visibility = Visibility.Hidden;
                        grid11.Visibility = Visibility.Hidden;

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
                        grid8.Visibility = Visibility.Hidden;
                        grid9.Visibility = Visibility.Hidden;
                        grid10.Visibility = Visibility.Hidden;
                        grid11.Visibility = Visibility.Hidden;

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
                        grid8.Visibility = Visibility.Hidden;
                        grid9.Visibility = Visibility.Hidden;
                        grid10.Visibility = Visibility.Hidden;
                        grid11.Visibility = Visibility.Hidden;

                        break;
                    case 8:
                        grid0.Visibility = Visibility.Hidden;
                        grid1.Visibility = Visibility.Hidden;
                        grid2.Visibility = Visibility.Hidden;
                        grid3.Visibility = Visibility.Hidden;
                        grid4.Visibility = Visibility.Hidden;
                        grid5.Visibility = Visibility.Hidden;
                        grid6.Visibility = Visibility.Hidden;
                        grid7.Visibility = Visibility.Hidden;
                        grid8.Visibility = Visibility.Visible;
                        grid9.Visibility = Visibility.Hidden;
                        grid10.Visibility = Visibility.Hidden;
                        grid11.Visibility = Visibility.Hidden;

                        break;
                    case 9:
                        grid0.Visibility = Visibility.Hidden;
                        grid1.Visibility = Visibility.Hidden;
                        grid2.Visibility = Visibility.Hidden;
                        grid3.Visibility = Visibility.Hidden;
                        grid4.Visibility = Visibility.Hidden;
                        grid5.Visibility = Visibility.Hidden;
                        grid6.Visibility = Visibility.Hidden;
                        grid7.Visibility = Visibility.Hidden;
                        grid8.Visibility = Visibility.Hidden;
                        grid9.Visibility = Visibility.Visible;
                        grid10.Visibility = Visibility.Hidden;
                        grid11.Visibility = Visibility.Hidden;

                        break;
                    case 10:
                        grid0.Visibility = Visibility.Hidden;
                        grid1.Visibility = Visibility.Hidden;
                        grid2.Visibility = Visibility.Hidden;
                        grid3.Visibility = Visibility.Hidden;
                        grid4.Visibility = Visibility.Hidden;
                        grid5.Visibility = Visibility.Hidden;
                        grid6.Visibility = Visibility.Hidden;
                        grid7.Visibility = Visibility.Hidden;
                        grid8.Visibility = Visibility.Hidden;
                        grid9.Visibility = Visibility.Hidden;
                        grid10.Visibility = Visibility.Hidden;
                        grid11.Visibility = Visibility.Hidden;

                        break;
                    case 11:
                        grid0.Visibility = Visibility.Hidden;
                        grid1.Visibility = Visibility.Hidden;
                        grid2.Visibility = Visibility.Hidden;
                        grid3.Visibility = Visibility.Hidden;
                        grid4.Visibility = Visibility.Hidden;
                        grid5.Visibility = Visibility.Hidden;
                        grid6.Visibility = Visibility.Hidden;
                        grid7.Visibility = Visibility.Hidden;
                        grid8.Visibility = Visibility.Hidden;
                        grid9.Visibility = Visibility.Hidden;
                        grid10.Visibility = Visibility.Hidden;
                        grid11.Visibility = Visibility.Visible;

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
                        grid8.Visibility = Visibility.Hidden;
                        grid9.Visibility = Visibility.Hidden;
                        grid10.Visibility = Visibility.Hidden;
                        grid11.Visibility = Visibility.Hidden;

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
        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "trans_int32_float",
            CallingConvention = CallingConvention.Cdecl)]
        public extern static float trans_int32_float(Int32 value);

        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "trans_float_int32",
            CallingConvention = CallingConvention.Cdecl)]
        public extern static Int32 trans_float_int32(float value);

        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "trans_int64_double",
            CallingConvention = CallingConvention.Cdecl)]
        public extern static double trans_int64_double(long value);

        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "trans_double_int64",
            CallingConvention = CallingConvention.Cdecl)]
        public extern static long trans_double_int64(double value);

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
                    float real = (float)(Convert.ToDouble(TextBox2_1.Text));
                    TextBox2_2.Text = Convert.ToString(trans_float_int32(real), 16).ToUpper();
                    break;
                case 2:
                    Int32 udint = (Convert.ToInt32(TextBox2_1.Text, 16));
                    TextBox2_2.Text = Convert.ToString(trans_int32_float(udint));
                    break;
                case 3:
                    double lreal = (Convert.ToDouble(TextBox2_1.Text));
                    TextBox2_2.Text = Convert.ToString(trans_double_int64(lreal), 16).ToUpper();
                    break;
                case 4:
                    long ulint = (Convert.ToInt64(TextBox2_1.Text, 16));
                    TextBox2_2.Text = Convert.ToString(trans_int64_double(ulint));
                    break;
                default:
                    break;
                    
            }

        }



        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "cal_acc_time",
                CallingConvention = CallingConvention.Cdecl)]
        public extern static double cal_acc_time(double vel_start, double vel_max, double vel_acc, double vel_jerk, int what_return);

        private void Cal_mc_movevelocity(object sender, RoutedEventArgs e)
        {
            double vel_start = Convert.ToDouble(TextBox3_1.Text);//起始速度
            double vel_max = Convert.ToDouble(TextBox3_2.Text);//最大速度
            double vel_acc = Convert.ToDouble(TextBox3_3.Text);//加速度
            double vel_jerk = Convert.ToDouble(TextBox3_4.Text);//加加速度
            
            TextBox3_5.Text = Convert.ToString(cal_acc_time(vel_start, vel_max, vel_acc, vel_jerk, 0));
            TextBox3_6.Text = Convert.ToString(cal_acc_time(vel_start, vel_max, vel_acc, vel_jerk, 1));
            TextBox3_7.Text = Convert.ToString(cal_acc_time(vel_start, vel_max, vel_acc, vel_jerk, 2));
            TextBox3_8.Text = Convert.ToString(cal_acc_time(vel_start, vel_max, vel_acc, vel_jerk, 3));
        }

        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "cal_move_time",
            CallingConvention = CallingConvention.Cdecl)]
        public extern static double cal_move_time(double pos_start, double pos_end, double vel_start, double vel_max,
            double vel_end, double vel_acc, double vel_dec, double vel_jerk, int what_return);
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

            TextBox4_11.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 0));
            TextBox4_12.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 1));
            TextBox4_13.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 2));
            TextBox4_14.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 3));
            TextBox4_15.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 4));
            TextBox4_16.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 5));
            TextBox4_17.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 6));
            TextBox4_18.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 7));
            TextBox4_22.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 8));
            TextBox4_23.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 9));
            TextBox4_24.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 10));
            TextBox4_25.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 11));
            TextBox4_26.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 12));
            TextBox4_27.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 13));
            TextBox4_28.Text = Convert.ToString(cal_move_time(pos_start, pos_end, vel_start, vel_max, vel_end, vel_acc, vel_dec, vel_jerk, 14));

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

        private void OnClick_strTrans(object sender, RoutedEventArgs e)
        {
            TextBox_outputstr.Text = "字符串长度为: " + Convert.ToString(TextBox_inputstr.Text.Length) + " \n";
            byte[] asciiarray = System.Text.Encoding.ASCII.GetBytes(TextBox_inputstr.Text);
            foreach (var VARIABLE in asciiarray)
            {
                TextBox_outputstr.AppendText("0x" + Convert.ToString(VARIABLE, 16).ToUpper() + " \t");
                TextBox_outputstr.AppendText(Convert.ToString(VARIABLE, 10) + " \n");
            }
        }



        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "gcodefileoutput",CallingConvention = CallingConvention.Cdecl)]
        public extern static void gcodefileoutput(int curvetype);

        private void GcodeSave_OnClick(object sender, RoutedEventArgs e)
        {
            if (ComboBoxCurveType.SelectedIndex == -1)
            {
                TextBox_GText.Text = "请选择曲线类型";
            }
            else
            {
                gcodefileoutput(ComboBoxCurveType.SelectedIndex);
                TextBox_GText.Text = "生成成功，文件位于E:\\TextOut\\G_code.txt\n具体文件如下：\n";
                TextBox_GText.AppendText(File.ReadAllText("E:\\TextOut\\G_code.txt"));
                ButtonOpenFile.Visibility = Visibility.Visible;
            }
        }


        private void OpenGcodeFile_OnClick(object sender, RoutedEventArgs e)
        {
            System.Diagnostics.Process.Start(@"E:\TextOut\Gcode.txt");
        }

        public static int Curvetype;

        private void DrawPic_OnClick(object sender, RoutedEventArgs e)
        {
            Curvetype = ComboBoxCurveType.SelectedIndex;
            DrawPic drawPic = new DrawPic();
            drawPic.Show();

        }

        public Socket client;
        public Thread MyThread;
        public String recvdata;
        public IPEndPoint ie;
        public bool isclose;

        public delegate void MyInvoke(string str, string str1);

        public void Initsocket()
        {
            string ipadd = TextBoxModbusTcpipaddr.Text;//IP
            int port = 502;//port

            //make a socket
            ie = new IPEndPoint(IPAddress.Parse(ipadd), port);
            client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            IPEndPoint bindip = new IPEndPoint(IPAddress.Parse(combolist[ComboBoxNetworkInterface.SelectedIndex].ipadd), port);
            if (client.IsBound == false)
            {
                client.Bind(bindip);
            }
        }
        public void ConnectTcp()
        {

            byte[] data = new byte[1024];

            //connect
            try
            {
                client.Connect(ie);
            }
            catch (SocketException e)
            {
                MessageBox.Show("Connect Fail \n" + e.Message);
                return;
            }

            ThreadStart myThreaddelegate = new ThreadStart(ReceiveMsg);
            MyThread = new Thread(myThreaddelegate);
            MyThread.Start();
            TextBoxModbusTcprecv.AppendText("连接成功\n");
        }

        public void SendTcp()
        {
            string senddata = TextBoxModbusTcpsend.Text;
            senddata = senddata.Replace(" ", "");
            byte[] data = new byte[senddata.Length/2];
            ushort[] dataUshort = new ushort[senddata.Length / 2];
            for (int i = 0; i < data.Length; i++)
            {
                char str1 = senddata[i * 2];
                char str2 = senddata[i * 2 + 1];
                string str = str1.ToString() + str2.ToString();
                dataUshort[i] = Convert.ToUInt16(str);
                data[i] = Convert.ToByte(dataUshort[i]);
            }

                //new byte[] { 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x01, 0x03, 0x00, 0x00, 0x00, 0x01 };
            if (client == null)
            {
                ;
            }
            else
            {
                client.Send(data);
            }
        }
        public void ReceiveMsg()
        {
            while (isclose)
            {
                byte[] data = new byte[1024];
                client.Receive(data);
                int length = data[5];
                Byte[] datashow = new byte[length + 6];
                for (int i = 0; i <= length + 5; i++)
                {
                    datashow[i] = data[i];
                }
                recvdata = "";
                string temp;
                for (int i = 0; i <= length + 5; i++)
                {
                    temp = Convert.ToString(datashow[i], 16);
                    switch (temp.Length)
                    {
                        case 1:
                            temp = "0" + temp;
                            break;
                        default:
                            break;
                    }
                    recvdata = recvdata + temp.ToUpper() + " ";
                }
                recvdata = recvdata + "\n";

                string numvalue = "Receive value: " +
                Convert.ToString(
                        Convert.ToUInt16((Convert.ToString(datashow[9], 16) + Convert.ToString(datashow[10], 16)), 16)) +"\n";


                ShowTcpMsg(recvdata, numvalue);
            }
        }

        public void ShowTcpMsg(string msg, string num)
        {
            if (TextBoxModbusTcpsend.CheckAccess() && TextBoxModbusTcprecv.CheckAccess())
            {
                TextBoxModbusTcprecv.AppendText(msg);
                TextBoxModbusTcprecv.ScrollToEnd();
            }
            else
            {
                MyInvoke _myInvoke = new MyInvoke(ShowTcpMsg);
                this.Dispatcher.Invoke(_myInvoke, new object[] { msg, num });

            }
        }




        private void ButtonModbusTcpConnent_OnClick(object sender, RoutedEventArgs e)
        {
            isclose = true;
            Initsocket();
            ConnectTcp();
        }


        private void ButtonModbusTcpSend_OnClick(object sender, RoutedEventArgs e)
        {
            SendTcp();
        }

        private void ComboBoxNetworkInterface_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ;
        }
    }
}
