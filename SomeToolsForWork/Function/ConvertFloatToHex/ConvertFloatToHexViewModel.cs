using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SomeTools.Function.ConvertFloatToHex
{
    public class ConvertFloatToHexViewModel
    {
        public DelegateCommand Convent32BitsCommand { get; set; }
        public DelegateCommand Convent64BitsCommand { get; set; }

        public ConvertFloatToHexModel Model { get; set; }

        public ConvertFloatToHexViewModel()
        {
            this.Model = new ConvertFloatToHexModel();
            this.Convent32BitsCommand = new DelegateCommand();
            this.Convent32BitsCommand.ExecuteCommand = new Action<object>(this.Model.Convent32Bits);

            this.Convent64BitsCommand = new DelegateCommand();
            this.Convent64BitsCommand.ExecuteCommand = new Action<object>(this.Model.Convent64Bits);
        }
    }
}