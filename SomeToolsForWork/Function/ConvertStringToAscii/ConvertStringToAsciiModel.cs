using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SomeTools.Function.ConvertStringToAscii
{
    internal class ConvertStringToAsciiModel : NotificationObject
    {
        private string _inputString = String.Empty;

        public string InputString
        {
            get => _inputString;
            set
            {
                _inputString = value;
                this.RaisePropertyChanged("InputString");
            }
        }

        private string _outputString = "支持一般英文字符串转换到ASCII数字码；\n支持十六进制ASCII码序列，以空格隔开，不带0x，转换到字符串。";

        public string OutputString
        {
            get => _outputString;
            set
            {
                _outputString = value;
                this.RaisePropertyChanged("OutputString");
            }
        }

        public void ConvertStringToAscii(object obj)
        {
            if (_inputString.Length == 0)
            {
                return;
            }
            OutputString = "字符串长度为: " + Convert.ToString(_inputString.Length) + " \n";
            byte[] asciiArray = System.Text.Encoding.ASCII.GetBytes(_inputString);
            foreach (var variable in asciiArray)
            {
                OutputString += ("0x" + Convert.ToString(variable, 16).ToUpper() + " \t");
                OutputString += (Convert.ToString(variable, 10) + " \t");
                byte[] sBytes = { variable };
                OutputString += (System.Text.Encoding.ASCII.GetString(sBytes) + "\n");
            }
        }

        public void ConvertAsciiToString(object obj)
        {
            string hexValues = _inputString;
            if (hexValues.Length == 0)
            {
                return;
            }
            string[] hexValuesSplit = hexValues.Split(' ');
            OutputString = ("字符串长度为: " + Convert.ToString(hexValuesSplit.Length) + " \n");
            foreach (string hex in hexValuesSplit)
            {
                int value = Convert.ToInt32(hex, 16);
                string stringValue = Char.ConvertFromUtf32(value);
                char charValue = (char)value;
                OutputString += (charValue.ToString());
            }

            OutputString += ("\n");
        }
    }
}