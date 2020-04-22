using System;
using System.Runtime.InteropServices;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace SomeTools.Function.CalculateMotionAccelerationTime
{
    /// <summary>
    /// CalculateMotionAccelerationTimeView.xaml 的交互逻辑
    /// </summary>
    public partial class CalculateMotionAccelerationTimeView : UserControl
    {
        public CalculateMotionAccelerationTimeView()
        {
            InitializeComponent();

            this.DataContext = new CalculateMotionAccelerationTimeViewModel();
        }

        private void TextBoxKeyDownEventSetter_OnHandler(object sender, KeyEventArgs e)
        {
            e.Handled = !((e.Key >= Key.D0 && e.Key <= Key.D9)
                            || e.Key == Key.Decimal
                            || (e.Key >= Key.NumPad0 && e.Key <= Key.NumPad9));
        }
    }
}