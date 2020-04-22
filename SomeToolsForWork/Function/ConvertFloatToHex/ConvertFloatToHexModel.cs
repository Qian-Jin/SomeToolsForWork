using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SomeTools.Function.ConvertFloatToHex
{
    public class ConvertFloatToHexModel : NotificationObject
    {
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

        private string _input32BitsString = String.Empty;

        public string Input32BitsString
        {
            get { return _input32BitsString; }
            set
            {
                _input32BitsString = value;
                Convent32Bits(_input32BitsString);
                this.RaisePropertyChanged("Input32BitsString");
            }
        }

        private string _output32BitsString = String.Empty;

        public string Output32BitsString
        {
            get { return _output32BitsString; }
            set
            {
                _output32BitsString = value;
                this.RaisePropertyChanged("Output32BitsString");
            }
        }

        private string _input64BitsString = String.Empty;

        public string Input64BitsString
        {
            get { return _input64BitsString; }
            set
            {
                _input64BitsString = value;
                Convent64Bits(_input64BitsString);
                this.RaisePropertyChanged("Input64BitsString");
            }
        }

        private string _output64BitsString = String.Empty;

        public string Output64BitsString
        {
            get { return _output64BitsString; }
            set
            {
                _output64BitsString = value;
                this.RaisePropertyChanged("Output64BitsString");
            }
        }

        public void Convent32Bits(object obj)
        {
            try
            {
                var value = ConvertStringToNumber(this._input32BitsString, typeof(Int32));

                if (value is Int32)
                {
                    this.Output32BitsString = ConvertInt32ToFloat(Convert.ToInt32(value)).ToString();
                }
                else
                {
                    this.Output32BitsString = "0x" + ConvertFloatToInt32(Convert.ToSingle(value)).ToString("X");
                }
            }
            catch
            {
                this.Output32BitsString = "Error.";
            }
        }

        public void Convent64Bits(object obj)
        {
            try
            {
                var value = ConvertStringToNumber(this._input64BitsString, typeof(Int64));

                if (value is Int64)
                {
                    this.Output64BitsString = ConvertInt64ToDouble(Convert.ToInt64(value)).ToString();
                }
                else
                {
                    this.Output64BitsString = "0x" + ConvertDoubleToInt64(Convert.ToDouble(value)).ToString("X");
                }
            }
            catch
            {
                this.Output64BitsString = "Error.";
            }
        }

        private Object ConvertStringToNumber(string str, Type type)
        {
            if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
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