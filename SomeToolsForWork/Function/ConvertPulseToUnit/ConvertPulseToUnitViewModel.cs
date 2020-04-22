using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SomeTools.Function.ConvertPulseToUnit
{
    internal class ConvertPulseToUnitViewModel
    {
        public DelegateCommand CalculateCommand { get; set; }

        public ConvertPulseToUnitModel Model { get; set; }

        public ConvertPulseToUnitViewModel()
        {
            this.Model = new ConvertPulseToUnitModel();
            this.CalculateCommand = new DelegateCommand();
            this.CalculateCommand.ExecuteCommand = new Action<object>(this.Model.Calculate);
        }
    }
}