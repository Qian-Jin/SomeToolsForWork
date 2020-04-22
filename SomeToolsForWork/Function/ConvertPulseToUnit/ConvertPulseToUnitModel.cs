using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SomeTools.Function.ConvertPulseToUnit
{
    internal class ConvertPulseToUnitModel : NotificationObject
    {
        private string _pprString = "10000";

        public string PprString
        {
            get { return _pprString; }
            set
            {
                _pprString = value;
                this.RaisePropertyChanged("PprString");
            }
        }

        private string _gearInString = "1";

        public string GearInString
        {
            get { return _gearInString; }
            set
            {
                _gearInString = value;
                this.RaisePropertyChanged("GearInString");
            }
        }

        private string _gearOutString = "1";

        public string GearOutString
        {
            get { return _gearOutString; }
            set
            {
                _gearOutString = value;
                this.RaisePropertyChanged("GearOutString");
            }
        }

        private string _setSpeedString = "10000";

        public string SetSpeedString
        {
            get { return _setSpeedString; }
            set
            {
                _setSpeedString = value;
                this.RaisePropertyChanged("SetSpeedString");
            }
        }

        private string _setMotorSpeedString = "60";

        public string SetMotorSpeedString
        {
            get { return _setMotorSpeedString; }
            set
            {
                _setMotorSpeedString = value;
                this.RaisePropertyChanged("SetMotorSpeedString");
            }
        }

        private string _motorSpeedMinString = String.Empty;

        public string MotorSpeedMinString
        {
            get { return _motorSpeedMinString; }
            set
            {
                _motorSpeedMinString = value;
                this.RaisePropertyChanged("MotorSpeedMinString");
            }
        }

        private string _motorSpeedSecString = String.Empty;

        public string MotorSpeedSecString
        {
            get { return _motorSpeedSecString; }
            set
            {
                _motorSpeedSecString = value;
                this.RaisePropertyChanged("MotorSpeedSecString");
            }
        }

        private string _unitSpeedSecString = String.Empty;

        public string UnitSpeedSecString
        {
            get { return _unitSpeedSecString; }
            set
            {
                _unitSpeedSecString = value;
                this.RaisePropertyChanged("UnitSpeedSecString");
            }
        }

        public void Calculate(object obj)
        {
            try
            {
                double ppr = Convert.ToDouble(_pprString);
                double gearin = Convert.ToDouble(_gearInString);
                double gearout = Convert.ToDouble(_gearOutString);
                double setvel = Convert.ToDouble(_setSpeedString);
                double setservovel = Convert.ToDouble(_setMotorSpeedString);

                MotorSpeedMinString = Convert.ToString(setvel / ppr * 60 / gearout * gearin);
                MotorSpeedSecString = Convert.ToString(setvel / ppr * 60 / gearout * gearin / 60);
                UnitSpeedSecString = Convert.ToString(setservovel / gearin * gearout / 60 * ppr);
            }
            catch
            {
                MotorSpeedMinString = "Error: 计算错误，数据输入有误";
                MotorSpeedSecString = "Error: 计算错误，数据输入有误";
                UnitSpeedSecString = "Error: 计算错误，数据输入有误";
            }
        }
    }
}