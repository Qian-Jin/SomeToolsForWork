using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SomeTools.Function.CalculateMotionTime
{
    internal class CalculateMotionTimeViewModel
    {
        public DelegateCommand CalculateCommand { get; set; }

        public CalculateMotionTimeModel Model { get; set; }

        public CalculateMotionTimeViewModel()
        {
            Model = new CalculateMotionTimeModel();
            CalculateCommand = new DelegateCommand();
            CalculateCommand.ExecuteCommand = new Action<object>(Model.Calculate);
        }
    }
}