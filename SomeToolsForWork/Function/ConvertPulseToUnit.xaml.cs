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
    /// ConvertPulseToUnit.xaml 的交互逻辑
    /// </summary>
    public partial class ConvertPulseToUnit : UserControl
    {
        public ConvertPulseToUnit()
        {
            InitializeComponent();
        }

        private void CalculateButton_OnClick(object sender, RoutedEventArgs e)
        {
            try
            {
                double ppr = Convert.ToDouble(PprTextBox.Text);
                double gearin = Convert.ToDouble(GearInTextBox.Text);
                double gearout = Convert.ToDouble(GearOutTextBox.Text);
                double setvel = Convert.ToDouble(SetSpeedTextBox.Text);
                double setservovel = Convert.ToDouble(SetMotorSpeedMinTextBox.Text);

                MotorSpeedMinTextBlock.Text = Convert.ToString(setvel / ppr * 60 / gearout * gearin);
                MotorSpeedSecTextBlock.Text = Convert.ToString(setvel / ppr * 60 / gearout * gearin / 60);
                UnitSpeedTextBlock.Text = Convert.ToString(setservovel / gearin * gearout / 60 * ppr);
            }
            catch
            {
                MotorSpeedMinTextBlock.Text = "Error: 计算错误，数据输入有误";
                MotorSpeedSecTextBlock.Text = "Error: 计算错误，数据输入有误";
                UnitSpeedTextBlock.Text = "Error: 计算错误，数据输入有误";
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