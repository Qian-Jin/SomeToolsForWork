using System;
using System.Runtime.InteropServices;
using System.Windows.Controls;

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
        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "convert_int32_to_float",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern float ConvertInt32ToFloat(Int32 value);

        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "convert_float_to_int32",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern Int32 ConvertFloatToInt32(float value);

        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "convert_int64_to_double",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern double ConvertInt64ToDouble(Int64 value);

        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "convert_double_to_int64",
            CallingConvention = CallingConvention.Cdecl)]
        private static extern Int64 ConvertDoubleToInt64(double value);

        private void Bit32FloatTextBox_OnTextChanged(object sender, TextChangedEventArgs e)
        {
            try
            {
                var value = ConvertStringToNumber(Bit32FloatTextBox.Text, typeof(Int32));

                if (value is Int32)
                {
                    Bit32FloatTextBlock.Text = ConvertInt32ToFloat(Convert.ToInt32(value)).ToString();
                }
                else
                {
                    Bit32FloatTextBlock.Text = "0x" + ConvertFloatToInt32(Convert.ToSingle(value)).ToString("X");
                }
            }
            catch
            {
                Bit32FloatTextBlock.Text = "Error.";
            }
        }

        private void Bit64FloatTextBox_OnTextChanged(object sender, TextChangedEventArgs e)
        {
            try
            {
                var value = ConvertStringToNumber(Bit64FloatTextBox.Text, typeof(Int64));

                if (value is Int64)
                {
                    Bit64FloatTextBlock.Text = ConvertInt64ToDouble(Convert.ToInt64(value)).ToString();
                }
                else
                {
                    Bit64FloatTextBlock.Text = "0x" + ConvertDoubleToInt64(Convert.ToDouble(value)).ToString("X");
                }
            }
            catch
            {
                Bit64FloatTextBlock.Text = "Error.";
            }
        }

        private Object ConvertStringToNumber(string str, Type type)
        {
            if (str[0] == '0' && str[1] == 'x')
            {
                if (!str.Contains("."))
                {
                    if (type == typeof(Int32))
                    {
                        try
                        {
                            Int32 value = Int32.Parse(str.Substring(2), System.Globalization.NumberStyles.HexNumber);
                            return value;
                        }
                        catch
                        {
                            throw;
                        }
                    }
                    else if (type == typeof(Int64))
                    {
                        try
                        {
                            Int64 value = Int64.Parse(str.Substring(2), System.Globalization.NumberStyles.HexNumber);
                            return value;
                        }
                        catch
                        {
                            throw;
                        }
                    }
                    else
                    {
                        throw new ArgumentException(nameof(type));
                    }
                }
                else
                {
                    throw new ArgumentException(nameof(str));
                }
            }
            else
            {
                if (type == typeof(Int32))
                {
                    try
                    {
                        float value = Convert.ToSingle(str);
                        return value;
                    }
                    catch
                    {
                        throw;
                    }
                }
                else if (type == typeof(Int64))
                {
                    try
                    {
                        double value = Convert.ToDouble(str);
                        return value;
                    }
                    catch
                    {
                        throw;
                    }
                }
                else
                {
                    throw new ArgumentException(nameof(type));
                }
            }
        }
    }
}