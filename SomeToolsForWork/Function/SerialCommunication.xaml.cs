using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Comm.Serial;

namespace SomeTools.Function
{
    /// <summary>
    /// SerialCommunication.xaml 的交互逻辑
    /// </summary>
    public partial class SerialCommunication : UserControl
    {
        public SerialCommunication()
        {
            InitializeComponent();
        }

        private void SerialCommunication_OnLoaded(object sender, RoutedEventArgs e)
        {
            InitCommPortInfo();
        }

        private void OpenCommButton_OnClick(object sender, RoutedEventArgs e)
        {
            string portName = CommPortComboBox.Text;
            int baudRate = new Func<int, int>(
                    (index)
                        =>
                    {
                        switch (index)
                        {
                            case 0:
                                return 9600;

                            case 1:
                                return 19200;

                            case 2:
                                return 38400;

                            case 3:
                                return 57600;

                            case 4:
                                return 115200;

                            default:
                                return 9600;
                        }
                    })
                (BaudRateComboBox.SelectedIndex);

            int dataBits = new Func<int, int>(
                    (index)
                        =>
                    {
                        switch (index)
                        {
                            case 0:
                                return 7;

                            case 1:
                                return 8;

                            default:
                                return 7;
                        }
                    })
                (DataBitsComboBox.SelectedIndex);

            Parity parity = new Func<int, Parity>(
                    (index)
                        =>
                    {
                        switch (index)
                        {
                            case 0:
                                return Parity.Odd;

                            case 1:
                                return Parity.Even;

                            case 2:
                                return Parity.None;

                            default:
                                return Parity.Even;
                        }
                    })
                (ParityComboBox.SelectedIndex);

            StopBits stopBits = new Func<int, StopBits>(
                    (index)
                        =>
                    {
                        switch (index)
                        {
                            case 0:
                                return StopBits.None;

                            case 1:
                                return StopBits.One;

                            default:
                                return StopBits.One;
                        }
                    })
                (StopBitsComboBox.SelectedIndex);

            if (ModeComboBox.SelectedIndex == 0)
            {
                TransportAscii(portName, baudRate, dataBits, parity, stopBits);
            }
            else
            {
                TransportRtu(portName, baudRate, dataBits, parity, stopBits);
            }
        }

        private void InitCommPortInfo()
        {
            string[] commPortNames = System.IO.Ports.SerialPort.GetPortNames();

            foreach (string commPortName in commPortNames)
            {
                ComboBoxItem port = new ComboBoxItem();
                port.Content = commPortName;
                CommPortComboBox.Items.Add(port);
            }

            CommPortComboBox.SelectedIndex = 0;
        }

        private void TransportAscii(string portName, int baudRate, int dataBits, Parity parity, StopBits stopBits)
        {
            Comm.Serial.TransportSerialAscii transportSerialAscii = new TransportSerialAscii(portName, baudRate, dataBits, parity, stopBits);

            string sendString = InputTextBlock.Text;
            transportSerialAscii.Transport(ref sendString, out var receiveData);
            OutputTextBlock.AppendText(receiveData + "\n");
        }

        private void TransportRtu(string portName, int baudRate, int dataBits, Parity parity, StopBits stopBits)
        {
            Comm.Serial.TransportSerialByte transportSerialByte = new TransportSerialByte(portName, baudRate, dataBits, parity, stopBits);

            string sendString = InputTextBlock.Text;
            byte[] sendBytes = Comm.Convert.ConvertHexStringToBytes(sendString);
            transportSerialByte.Transport(ref sendBytes, out var receiveData);
            string receiveString = Comm.Convert.ConvertBytesToHexString(receiveData);
            OutputTextBlock.AppendText(receiveString + "\n");
        }
    }
}