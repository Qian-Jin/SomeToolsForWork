using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.NetworkInformation;
using System.Net.Sockets;
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
using Comm.Socket;

namespace SomeTools.Function
{
    /// <summary>
    /// SocketCommunication.xaml 的交互逻辑
    /// </summary>
    public partial class SocketCommunication : UserControl
    {
        public SocketCommunication()
        {
            InitializeComponent();
        }

        private void SocketCommunication_OnLoaded(object sender, RoutedEventArgs e)
        {
            InitNetworkInterface();
        }

        private Comm.Socket.TransportTcpSocket transportTcpSocket;

        private void InitNetworkInterface()
        {
            NetworkInterface[] networkInterfaces = NetworkInterface.GetAllNetworkInterfaces();

            foreach (NetworkInterface networkInterface in networkInterfaces)
            {
                foreach (UnicastIPAddressInformation unicastIpAddressInformation in networkInterface.GetIPProperties()
                    .UnicastAddresses)
                {
                    if (unicastIpAddressInformation.Address.AddressFamily == AddressFamily.InterNetwork)
                    {
                        ComboBoxItem comboBoxItem = new ComboBoxItem();
                        comboBoxItem.Content = networkInterface.Name + ":::::" +
                                               unicastIpAddressInformation.Address.ToString();
                        NetworkInterfaceComboBox.Items.Add(comboBoxItem);
                    }
                }
            }

            NetworkInterfaceComboBox.SelectedIndex = 0;
        }

        private void TcpConnectButton_OnClick(object sender, RoutedEventArgs e)
        {
            string remoteIpAndPort = TcpIpTextBox.Text;

            string[] remoteIpAndPortStrings = remoteIpAndPort.Split(':');

            string localIp = NetworkInterfaceComboBox.Text.Substring(NetworkInterfaceComboBox.Text.IndexOf(":::::") + 5);

            transportTcpSocket = new TransportTcpSocket(remoteIpAndPortStrings[0], Convert.ToInt32(remoteIpAndPortStrings[1]), localIp, 0);

            transportTcpSocket.TransportOpen();
        }

        private void TcpDisconnectButton_OnClick(object sender, RoutedEventArgs e)
        {
            if (transportTcpSocket != null)
            {
                transportTcpSocket.TransportClose();
            }
        }

        private void TcpSendButton_OnClick(object sender, RoutedEventArgs e)
        {
            string sendData = TcpSendTextBox.Text.Replace(" ", "");

            List<byte> sendBytes = Comm.Convert.ConvertHexStringToBytes(sendData).ToList();

            transportTcpSocket.Transport(ref sendBytes, out var receiveData);

            string receiveString = Comm.Convert.ConvertBytesToHexString(receiveData.ToArray());

            TcpReceiveTextBox.AppendText(receiveString);
        }
    }
}