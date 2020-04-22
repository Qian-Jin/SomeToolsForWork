using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SomeTools.Function.CalculateMotionAccelerationTime
{
    internal class CalculateMotionAccelerationTimeViewModel
    {
        public DelegateCommand CalculateCommand { get; set; }

        public CalculateMotionAccelerationTimeModel Model { get; set; }

        public CalculateMotionAccelerationTimeViewModel()
        {
            this.Model = new CalculateMotionAccelerationTimeModel();

            this.CalculateCommand = new DelegateCommand();
            CalculateCommand.ExecuteCommand = new Action<object>(Model.Calculate);
        }
    }
}