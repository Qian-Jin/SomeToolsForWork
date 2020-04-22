using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SomeTools.Function.ConvertStringToAscii
{
    internal class ConvertStringToAsciiViewModel
    {
        public DelegateCommand ConvertStringToAsciiCommand { get; set; }
        public DelegateCommand ConvertAsciiToStringCommand { get; set; }

        public ConvertStringToAsciiModel Model { get; set; }

        public ConvertStringToAsciiViewModel()
        {
            this.Model = new ConvertStringToAsciiModel();

            this.ConvertAsciiToStringCommand = new DelegateCommand();
            ConvertAsciiToStringCommand.ExecuteCommand = new Action<object>(this.Model.ConvertAsciiToString);

            this.ConvertStringToAsciiCommand = new DelegateCommand();
            this.ConvertStringToAsciiCommand.ExecuteCommand = new Action<object>(this.Model.ConvertStringToAscii);
        }
    }
}