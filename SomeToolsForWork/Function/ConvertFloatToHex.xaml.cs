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
    /// ConvertFloatToHex.xaml 的交互逻辑
    /// </summary>
    public partial class ConvertFloatToHex : UserControl
    {
        public ConvertFloatToHex()
        {
            InitializeComponent();
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
            if (RadioButton2_1.IsChecked == true && RadioButton2_2.IsChecked == false)
            {
                if (RadioButton2_3.IsChecked == true && RadioButton2_4.IsChecked == false)
                {
                    transmode = 1;
                }
                if (RadioButton2_4.IsChecked == true && RadioButton2_3.IsChecked == false)
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
    }
}