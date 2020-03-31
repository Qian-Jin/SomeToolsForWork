using System;
using System.Runtime.InteropServices;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

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

        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "calculate_motion_time", CallingConvention = CallingConvention.Cdecl)]
        private static extern int CalculateMotionTimeValue(double startPosition, double endPosition, double startVelocity, double maxVelocity,
            double endVelocity, double acceleration, double deceleration, double jerk,
            ref double stage1Time, ref double stage2Time, ref double stage3Time, ref double stage4Time, ref double stage5Time, ref double stage6Time,
            ref double stage7Time, ref double stage1Distance, ref double stage2Distance, ref double stage3Distance, ref double stage4Distance,
            ref double stage5Distance, ref double stage6Distance, ref double stage7Distance);

        private void CalculateButton_OnClick(object sender, RoutedEventArgs e)
        {
            double startPosition = 0;
            double endPosition = 0;
            double startVelocity = 0;
            double maxVelocity = 0;
            double endVelocity = 0;
            double acceleration = 0;
            double deceleration = 0;
            double jerk = 0;

            try
            {
                startPosition = Convert.ToDouble(StartPositionTextBox.Text);//起始位置
                endPosition = Convert.ToDouble(EndPositionTextBox.Text);//目标位置
                startVelocity = Convert.ToDouble(StartVelocityTextBox.Text);//起始速度
                maxVelocity = Convert.ToDouble(MaxVelocityTextBox.Text);//最大速度
                endVelocity = Convert.ToDouble(EndVelocityTextBox.Text);//结束速度
                acceleration = Convert.ToDouble(AccelerationTextBox.Text);//加速度
                deceleration = Convert.ToDouble(DecelerationTextBox.Text);//减速度
                jerk = Convert.ToDouble(JerkTextBox.Text);//加加速度
            }
            catch
            {
                StageTotalTimeTextBlock.Text = "Error: 数据输入格式有误";
            }

            double stage1Time = 0;
            double stage2Time = 0;
            double stage3Time = 0;
            double stage4Time = 0;
            double stage5Time = 0;
            double stage6Time = 0;
            double stage7Time = 0;
            double stage1Distance = 0;
            double stage2Distance = 0;
            double stage3Distance = 0;
            double stage4Distance = 0;
            double stage5Distance = 0;
            double stage6Distance = 0;
            double stage7Distance = 0;

            int res = CalculateMotionTimeValue(startPosition, endPosition, startVelocity, maxVelocity, endVelocity, acceleration,
                deceleration, jerk, ref stage1Time, ref stage2Time, ref stage3Time, ref stage4Time, ref stage5Time,
                ref stage6Time, ref stage7Time, ref stage1Distance, ref stage2Distance, ref stage3Distance,
                ref stage4Distance, ref stage5Distance, ref stage6Distance, ref stage7Distance);

            if (res == 0)
            {
                Stage1TimeTextBlock.Text = stage1Time.ToString();
                Stage2TimeTextBlock.Text = stage2Time.ToString();
                Stage3TimeTextBlock.Text = stage3Time.ToString();
                Stage4TimeTextBlock.Text = stage4Time.ToString();
                Stage5TimeTextBlock.Text = stage5Time.ToString();
                Stage6TimeTextBlock.Text = stage6Time.ToString();
                Stage7TimeTextBlock.Text = stage7Time.ToString();

                Stage1DistanceTextBlock.Text = stage1Distance.ToString();
                Stage2DistanceTextBlock.Text = stage2Distance.ToString();
                Stage3DistanceTextBlock.Text = stage3Distance.ToString();
                Stage4DistanceTextBlock.Text = stage4Distance.ToString();
                Stage5DistanceTextBlock.Text = stage5Distance.ToString();
                Stage6DistanceTextBlock.Text = stage6Distance.ToString();
                Stage7DistanceTextBlock.Text = stage7Distance.ToString();

                StageTotalTimeTextBlock.Text = (stage1Time + stage2Time + stage3Time + stage4Time + stage5Time + stage6Time + stage7Time).ToString();
                StageTotalDistanceTextBlock.Text = (stage1Distance + stage2Distance + stage3Distance + stage4Distance + stage5Distance + stage6Distance + stage7Distance).ToString();
            }
            else
            {
                StageTotalTimeTextBlock.Text = "Error: 计算错误，数据输入有误";
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