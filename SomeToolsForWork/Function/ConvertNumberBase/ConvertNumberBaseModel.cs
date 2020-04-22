using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SomeTools.Function.ConvertNumberBase
{
    internal class ConvertNumberBaseModel : NotificationObject
    {
        private string _binNumberString = String.Empty;

        public string BinNumberString
        {
            get => _binNumberString;
            set
            {
                _binNumberString = value;
                Int64 inputValue = Convert.ToInt64(value, 2);
                _decNumberString = Convert.ToString(inputValue, 10);
                _hexNumberString = Convert.ToString(inputValue, 16).ToUpper();
                this.RaisePropertyChanged("BinNumberString");
                this.RaisePropertyChanged("DecNumberString");
                this.RaisePropertyChanged("HexNumberString");
            }
        }

        private string _decNumberString = String.Empty;

        public string DecNumberString
        {
            get => _decNumberString;
            set
            {
                _decNumberString = value;
                Int64 inputValue = Convert.ToInt64(value, 10);
                _binNumberString = Convert.ToString(inputValue, 2);
                _hexNumberString = Convert.ToString(inputValue, 16).ToUpper();
                this.RaisePropertyChanged("BinNumberString");
                this.RaisePropertyChanged("DecNumberString");
                this.RaisePropertyChanged("HexNumberString");
            }
        }

        private string _hexNumberString = String.Empty;

        public string HexNumberString
        {
            get => _hexNumberString;
            set
            {
                _hexNumberString = value;
                Int64 inputValue = Convert.ToInt64(value, 16);
                _binNumberString = Convert.ToString(inputValue, 2);
                _decNumberString = Convert.ToString(inputValue, 10);
                this.RaisePropertyChanged("BinNumberString");
                this.RaisePropertyChanged("DecNumberString");
                this.RaisePropertyChanged("HexNumberString");
            }
        }
    }
}