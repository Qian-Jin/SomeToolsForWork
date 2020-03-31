using System;
using System.Runtime.InteropServices;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

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

        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "calculate_acceleration_time", CallingConvention = CallingConvention.Cdecl)]
        private static extern int CalculateAccelerationTime(double velStart, double velMax, double velAcc, double velJerk, ref double totalTime, ref double firstTime, ref double secondTime, ref double thirdTime);

        private void CalculateButton_OnClick(object sender, RoutedEventArgs e)
        {
            double velStart = 0, velMax = 0, acceleration = 0, jerk = 0;
            try
            {
                velStart = Convert.ToDouble(StartVelocityTextBox.Text);//起始速度
                velMax = Convert.ToDouble(MaxVelocityTextBox.Text);//最大速度
                acceleration = Convert.ToDouble(MaxAccelerationTextBox.Text);//加速度
                jerk = Convert.ToDouble(MaxJerkTextBox.Text);//加加速度
            }
            catch
            {
                TotalTimeTextBlock.Text = "Error: 数据输入格式有误";
            }

            double totalTime = 0, firstTime = 0, secondTime = 0, thirdTime = 0;

            int res = CalculateAccelerationTime(velStart, velMax, acceleration, jerk, ref totalTime, ref firstTime,
                ref secondTime, ref thirdTime);

            if (res == 0)
            {
                TotalTimeTextBlock.Text = totalTime.ToString();
                FirstStageTextBox.Text = firstTime.ToString();
                SecondStageTextBlock.Text = secondTime.ToString();
                ThirdStageTextBlock.Text = thirdTime.ToString();
            }
            else
            {
                TotalTimeTextBlock.Text = "Error: 计算错误，数据输入有误";
            }
        }

        private void TextBoxKeyDownEventSetter_OnHandler(object sender, KeyEventArgs e)
        {
            e.Handled = !((e.Key >= Key.D0 && e.Key <= Key.D9)
                            || e.Key == Key.Decimal
                            || (e.Key >= Key.NumPad0 && e.Key <= Key.NumPad9));
        }
    }
}