using System;
using System.Runtime.InteropServices;
using System.Windows;
using System.Windows.Controls;

namespace SomeTools.Function
{
    /// <summary>
    /// CalculateMotionAccelerationTime.xaml 的交互逻辑
    /// </summary>
    public partial class CalculateMotionAccelerationTime : UserControl
    {
        public CalculateMotionAccelerationTime()
        {
            InitializeComponent();
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
    }
}