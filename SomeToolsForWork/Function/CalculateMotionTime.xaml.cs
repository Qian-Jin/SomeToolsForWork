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

namespace SomeTools.Function
{
    /// <summary>
    /// CalculateMotionTime.xaml 的交互逻辑
    /// </summary>
    public partial class CalculateMotionTime : UserControl
    {
        public CalculateMotionTime()
        {
            InitializeComponent();
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
    }
}