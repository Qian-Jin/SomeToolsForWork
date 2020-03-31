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
    /// ConvertStringToAscii.xaml 的交互逻辑
    /// </summary>
    public partial class ConvertStringToAscii : UserControl
    {
        public ConvertStringToAscii()
        {
            InitializeComponent();
        }

        private void ConvertStringToAsciiButton_OnClick(object sender, RoutedEventArgs e)
        {
            if (InputTextBox.Text.Length == 0)
            {
                return;
            }
            OutputTextBox.Text = "字符串长度为: " + Convert.ToString(InputTextBox.Text.Length) + " \n";
            byte[] asciiarray = System.Text.Encoding.ASCII.GetBytes(InputTextBox.Text);
            foreach (var variable in asciiarray)
            {
                OutputTextBox.AppendText("0x" + Convert.ToString(variable, 16).ToUpper() + " \t");
                OutputTextBox.AppendText(Convert.ToString(variable, 10) + " \t");
                byte[] sBytes = { variable };
                OutputTextBox.AppendText(System.Text.Encoding.ASCII.GetString(sBytes) + "\n");
            }
        }

        private void ConvertAsciiToStringButton_OnClick(object sender, RoutedEventArgs e)
        {
            string hexValues = InputTextBox.Text;
            if (hexValues.Length == 0)
            {
                return;
            }
            string[] hexValuesSplit = hexValues.Split(' ');
            OutputTextBox.Text = "字符串长度为: " + Convert.ToString(hexValuesSplit.Length) + " \n";
            foreach (string hex in hexValuesSplit)
            {
                int value = Convert.ToInt32(hex, 16);
                string stringValue = Char.ConvertFromUtf32(value);
                char charValue = (char)value;
                OutputTextBox.AppendText(charValue.ToString());
            }

            OutputTextBox.AppendText("\n");
        }
    }
}