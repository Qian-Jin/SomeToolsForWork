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

        private void OnClick_strTrans(object sender, RoutedEventArgs e)
        {
            TextBox_outputstr.Text = "字符串长度为: " + Convert.ToString(TextBox_inputstr.Text.Length) + " \n";
            byte[] asciiarray = System.Text.Encoding.ASCII.GetBytes(TextBox_inputstr.Text);
            foreach (var VARIABLE in asciiarray)
            {
                TextBox_outputstr.AppendText("0x" + Convert.ToString(VARIABLE, 16).ToUpper() + " \t");
                TextBox_outputstr.AppendText(Convert.ToString(VARIABLE, 10) + " \t");
                byte[] sBytes = { VARIABLE };
                TextBox_outputstr.AppendText(System.Text.Encoding.ASCII.GetString(sBytes) + "\n");
            }
        }
    }
}