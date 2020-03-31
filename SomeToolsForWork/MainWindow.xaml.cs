using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Net.NetworkInformation;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Threading;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Threading;
using System.Xml;
using SomeTools.Function;

namespace SomeTools
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        /// <summary>
        /// 进制转换页面
        /// </summary>
        private Function.NumberBaseConversion numberBaseConversionGrid = new NumberBaseConversion();

        /// <summary>
        /// 浮点数和十六进制转换
        /// </summary>
        private Function.ConvertFloatToHex convertFloatToHex = new ConvertFloatToHex();

        /// <summary>
        /// 计算位置加速时间
        /// </summary>
        private Function.CalculateMotionAccelerationTime calculateMotionAccelerationTime = new CalculateMotionAccelerationTime();

        /// <summary>
        /// 计算位移时间
        /// </summary>
        private Function.CalculateMotionTime calculateMotionTime = new CalculateMotionTime();

        /// <summary>
        /// 转换脉冲到单元
        /// </summary>
        private Function.ConvertPulseToUnit convertPulseToUnit = new ConvertPulseToUnit();

        /// <summary>
        /// 生成曲线位置点
        /// </summary>
        private Function.GenerateCurve generateCurve = new GenerateCurve();

        /// <summary>
        /// 转换字符串和Ascii代码
        /// </summary>
        private Function.ConvertStringToAscii convertStringToAscii = new ConvertStringToAscii();

        /// <summary>
        /// 串口通讯
        /// </summary>
        private Function.SerialCommunication serialCommunication = new SerialCommunication();

        /// <summary>
        /// TCP通讯
        /// </summary>
        private Function.SocketCommunication socketCommunication = new SocketCommunication();

        /// <summary>
        /// 选择左侧选项后执行
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void FunctionMenuListBox_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (FunctionMenuListBox.SelectedItems == null)
            {
                return;
            }
            else
            {
                int index = FunctionMenuListBox.SelectedIndex;

                if (FunctionShow_Grid.Children != null)
                {
                    FunctionShow_Grid.Children.Clear();
                }

                UIElement ui;

                switch (index)
                {
                    case 0:
                        ui = numberBaseConversionGrid;
                        break;

                    case 1:
                        ui = convertFloatToHex;
                        break;

                    case 2:
                        ui = calculateMotionAccelerationTime;
                        break;

                    case 3:
                        ui = calculateMotionTime;
                        break;

                    case 4:
                        ui = convertPulseToUnit;
                        break;

                    case 5:
                        ui = generateCurve;
                        break;

                    case 6:
                        ui = convertStringToAscii;
                        break;

                    case 7:
                        ui = serialCommunication;
                        break;

                    case 8:
                        ui = socketCommunication;
                        break;

                    default:
                        ui = new Grid();
                        break;
                }

                FunctionShow_Grid.Children.Add(ui);
            }
        }
    }
}