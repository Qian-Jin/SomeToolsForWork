using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace SomeTools.Function.CalculateMotionTime
{
    internal class CalculateMotionTimeModel : NotificationObject
    {
        private string _startPositionString = String.Empty;

        public string StartPositionString
        {
            get => _startPositionString;
            set
            {
                _startPositionString = value;
                this.RaisePropertyChanged("StartPositionString");
            }
        }

        private string _endPositionString = String.Empty;

        public string EndPositionString
        {
            get => _endPositionString;
            set
            {
                _endPositionString = value;
                this.RaisePropertyChanged("EndPositionString");
            }
        }

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

        private string _endVelocityString = String.Empty;

        public string EndVelocityString
        {
            get => _endVelocityString;
            set
            {
                _endVelocityString = value;
                this.RaisePropertyChanged("EndVelocityString");
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

        private string _decelerationString = String.Empty;

        public string DecelerationString
        {
            get => _decelerationString;
            set
            {
                _decelerationString = value;
                this.RaisePropertyChanged("DecelerationString");
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

        private string _stage4TimeString = String.Empty;

        public string Stage4TimeString
        {
            get => _stage4TimeString;
            set
            {
                _stage4TimeString = value;
                this.RaisePropertyChanged("Stage4TimeString");
            }
        }

        private string _stage5TimeString = String.Empty;

        public string Stage5TimeString
        {
            get => _stage5TimeString;
            set
            {
                _stage5TimeString = value;
                this.RaisePropertyChanged("Stage5TimeString");
            }
        }

        private string _stage6TimeString = String.Empty;

        public string Stage6TimeString
        {
            get => _stage6TimeString;
            set
            {
                _stage6TimeString = value;
                this.RaisePropertyChanged("Stage6TimeString");
            }
        }

        private string _stage7TimeString = String.Empty;

        public string Stage7TimeString
        {
            get => _stage7TimeString;
            set
            {
                _stage7TimeString = value;
                this.RaisePropertyChanged("Stage7TimeString");
            }
        }

        private string _stage1DistanceString = String.Empty;

        public string Stage1DistanceString
        {
            get => _stage1DistanceString;
            set
            {
                _stage1DistanceString = value;
                this.RaisePropertyChanged("Stage1DistanceString");
            }
        }

        private string _stage2DistanceString = String.Empty;

        public string Stage2DistanceString
        {
            get => _stage2DistanceString;
            set
            {
                _stage2DistanceString = value;
                this.RaisePropertyChanged("Stage2DistanceString");
            }
        }

        private string _stage3DistanceString = String.Empty;

        public string Stage3DistanceString
        {
            get => _stage3DistanceString;
            set
            {
                _stage3DistanceString = value;
                this.RaisePropertyChanged("Stage3DistanceString");
            }
        }

        private string _stage4DistanceString = String.Empty;

        public string Stage4DistanceString
        {
            get => _stage4DistanceString;
            set
            {
                _stage4DistanceString = value;
                this.RaisePropertyChanged("Stage4DistanceString");
            }
        }

        private string _stage5DistanceString = String.Empty;

        public string Stage5DistanceString
        {
            get => _stage5DistanceString;
            set
            {
                _stage5DistanceString = value;
                this.RaisePropertyChanged("Stage5DistanceString");
            }
        }

        private string _stage6DistanceString = String.Empty;

        public string Stage6DistanceString
        {
            get => _stage6DistanceString;
            set
            {
                _stage6DistanceString = value;
                this.RaisePropertyChanged("Stage6DistanceString");
            }
        }

        private string _stage7DistanceString = String.Empty;

        public string Stage7DistanceString
        {
            get => _stage7DistanceString;
            set
            {
                _stage7DistanceString = value;
                this.RaisePropertyChanged("Stage7DistanceString");
            }
        }

        private string _stageTotalTimeString = String.Empty;

        public string StageTotalTimeString
        {
            get => _stageTotalTimeString;
            set
            {
                _stageTotalTimeString = value;
                this.RaisePropertyChanged("StageTotalTimeString");
            }
        }

        private string _stageTotalDistanceString = String.Empty;

        public string StageTotalDistanceString
        {
            get => _stageTotalDistanceString;
            set
            {
                _stageTotalDistanceString = value;
                this.RaisePropertyChanged("StageTotalDistanceString");
            }
        }

        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "calculate_motion_time", CallingConvention = CallingConvention.Cdecl)]
        private static extern int CalculateMotionTimeValue(double startPosition, double endPosition, double startVelocity, double maxVelocity,
            double endVelocity, double acceleration, double deceleration, double jerk,
            ref double stage1Time, ref double stage2Time, ref double stage3Time, ref double stage4Time, ref double stage5Time, ref double stage6Time,
            ref double stage7Time, ref double stage1Distance, ref double stage2Distance, ref double stage3Distance, ref double stage4Distance,
            ref double stage5Distance, ref double stage6Distance, ref double stage7Distance);

        public void Calculate(object obj)
        {
            double startPosition = 0;
            double endPosition = 0;
            double startVelocity = 0;
            double maxVelocity = 0;
            double endVelocity = 0;
            double acceleration = 0;
            double deceleration = 0;
            double jerk = 0;

            try
            {
                startPosition = Convert.ToDouble(_startPositionString);//起始位置
                endPosition = Convert.ToDouble(_endPositionString);//目标位置
                startVelocity = Convert.ToDouble(_startVelocityString);//起始速度
                maxVelocity = Convert.ToDouble(_maxVelocityString);//最大速度
                endVelocity = Convert.ToDouble(_endVelocityString);//结束速度
                acceleration = Convert.ToDouble(_accelerationString);//加速度
                deceleration = Convert.ToDouble(_decelerationString);//减速度
                jerk = Convert.ToDouble(_jerkString);//加加速度
            }
            catch
            {
                StageTotalTimeString = "Error: 数据输入格式有误";
            }

            double stage1Time = 0;
            double stage2Time = 0;
            double stage3Time = 0;
            double stage4Time = 0;
            double stage5Time = 0;
            double stage6Time = 0;
            double stage7Time = 0;
            double stage1Distance = 0;
            double stage2Distance = 0;
            double stage3Distance = 0;
            double stage4Distance = 0;
            double stage5Distance = 0;
            double stage6Distance = 0;
            double stage7Distance = 0;

            int res = CalculateMotionTimeValue(startPosition, endPosition, startVelocity, maxVelocity, endVelocity, acceleration,
                deceleration, jerk, ref stage1Time, ref stage2Time, ref stage3Time, ref stage4Time, ref stage5Time,
                ref stage6Time, ref stage7Time, ref stage1Distance, ref stage2Distance, ref stage3Distance,
                ref stage4Distance, ref stage5Distance, ref stage6Distance, ref stage7Distance);

            if (res == 0)
            {
                Stage1TimeString = stage1Time.ToString();
                Stage2TimeString = stage2Time.ToString();
                Stage3TimeString = stage3Time.ToString();
                Stage4TimeString = stage4Time.ToString();
                Stage5TimeString = stage5Time.ToString();
                Stage6TimeString = stage6Time.ToString();
                Stage7TimeString = stage7Time.ToString();

                Stage1DistanceString = stage1Distance.ToString();
                Stage2DistanceString = stage2Distance.ToString();
                Stage3DistanceString = stage3Distance.ToString();
                Stage4DistanceString = stage4Distance.ToString();
                Stage5DistanceString = stage5Distance.ToString();
                Stage6DistanceString = stage6Distance.ToString();
                Stage7DistanceString = stage7Distance.ToString();

                StageTotalTimeString = (stage1Time + stage2Time + stage3Time + stage4Time + stage5Time + stage6Time + stage7Time).ToString();
                StageTotalDistanceString = (stage1Distance + stage2Distance + stage3Distance + stage4Distance + stage5Distance + stage6Distance + stage7Distance).ToString();
            }
            else
            {
                StageTotalTimeString = "Error: 计算错误，数据输入有误";
            }
        }
    }
}