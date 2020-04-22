using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SomeTools.Function.CalculateMotionAccelerationTime
{
    internal class CalculateMotionAccelerationTimeModel : NotificationObject
    {
        private string _startVelocityString = String.Empty;

        public string StartVelocityString
        {
            get => _startVelocityString;
            set
            {
                _startVelocityString = value;
                this.RaisePropertyChanged("StartVelocityString");
            }
        }

        private string _maxVelocityString = String.Empty;

        public string MaxVelocityString
        {
            get => _maxVelocityString;
            set
            {
                _maxVelocityString = value;
                this.RaisePropertyChanged("MaxVelocityString");
            }
        }

        private string _accelerationString = String.Empty;

        public string AccelerationString
        {
            get => _accelerationString;
            set
            {
                _accelerationString = value;
                this.RaisePropertyChanged("AccelerationString");
            }
        }

        private string _jerkString = String.Empty;

        public string JerkString
        {
            get => _jerkString;
            set
            {
                _jerkString = value;
                this.RaisePropertyChanged("JerkString");
            }
        }

        private string _totalTimeString = String.Empty;

        public string TotalTimeString
        {
            get => _totalTimeString;
            set
            {
                _totalTimeString = value;
                this.RaisePropertyChanged("TotalTimeString");
            }
        }

        private string _stage1TimeString = String.Empty;

        public string Stage1TimeString
        {
            get => _stage1TimeString;
            set
            {
                _stage1TimeString = value;
                this.RaisePropertyChanged("Stage1TimeString");
            }
        }

        private string _stage2TimeString = String.Empty;

        public string Stage2TimeString
        {
            get => _stage2TimeString;
            set
            {
                _stage2TimeString = value;
                this.RaisePropertyChanged("Stage2TimeString");
            }
        }

        private string _stage3TimeString = String.Empty;

        public string Stage3TimeString
        {
            get => _stage3TimeString;
            set
            {
                _stage3TimeString = value;
                this.RaisePropertyChanged("Stage3TimeString");
            }
        }

        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "calculate_acceleration_time", CallingConvention = CallingConvention.Cdecl)]
        private static extern int CalculateAccelerationTime(double velStart, double velMax, double velAcc, double velJerk, ref double totalTime, ref double firstTime, ref double secondTime, ref double thirdTime);

        public void Calculate(Object obj)
        {
            double velStart = 0, velMax = 0, acceleration = 0, jerk = 0;
            try
            {
                velStart = Convert.ToDouble(_startVelocityString);//起始速度
                velMax = Convert.ToDouble(_maxVelocityString);//最大速度
                acceleration = Convert.ToDouble(_accelerationString);//加速度
                jerk = Convert.ToDouble(_jerkString);//加加速度
            }
            catch
            {
                TotalTimeString = "Error: 数据输入格式有误";
            }

            double totalTime = 0, firstTime = 0, secondTime = 0, thirdTime = 0;

            int res = CalculateAccelerationTime(velStart, velMax, acceleration, jerk, ref totalTime, ref firstTime,
                ref secondTime, ref thirdTime);

            if (res == 0)
            {
                TotalTimeString = totalTime.ToString();
                Stage1TimeString = firstTime.ToString();
                Stage2TimeString = secondTime.ToString();
                Stage3TimeString = thirdTime.ToString();
            }
            else
            {
                TotalTimeString = "Error: 计算错误，数据输入有误";
            }
        }
    }
}