using SomeTools.Function;
using SomeTools.Function.ConvertFloatToHex;
using SomeTools.Function.ConvertNumberBase;
using SomeTools.Function.ConvertPulseToUnit;
using System.Windows;
using System.Windows.Controls;

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
        private Function.ConvertNumberBase.ConvertNumberBaseView convertNumberBase = new ConvertNumberBaseView();

        /// <summary>
        /// 浮点数和十六进制转换
        /// </summary>
        private Function.ConvertFloatToHex.ConvertFloatToHexView convertFloatToHex = new ConvertFloatToHexView();

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
        private Function.ConvertPulseToUnit.ConvertPulseToUnitView convertPulseToUnit = new ConvertPulseToUnitView();

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

                if (FunctionShowGrid.Children != null)
                {
                    FunctionShowGrid.Children.Clear();
                }

                UIElement ui;

                switch (index)
                {
                    case 0:
                        ui = convertNumberBase;
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
                        ui = convertStringToAscii;
                        break;

                    case 6:
                        ui = serialCommunication;
                        break;

                    case 7:
                        ui = socketCommunication;
                        break;

                    default:
                        ui = new Grid();
                        break;
                }

                FunctionShowGrid.Children.Add(ui);
            }
        }

        private void MainWindow_OnLoaded(object sender, RoutedEventArgs e)
        {
            FunctionMenuListBox.SelectedIndex = 0;
        }
    }
}