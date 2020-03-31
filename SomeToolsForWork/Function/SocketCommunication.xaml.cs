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

        public struct combomem
        {
            public int ID { get; set; }
            public string comboMember { get; set; }
            public string ipadd { get; set; }
        }

        private NetworkInterface[] NetworkInterfaces = NetworkInterface.GetAllNetworkInterfaces();
        private List<combomem> combolist = new List<combomem>();

        private void GetNetworkInterface()
        {
            combomem combomenber = new combomem();
            int i = 0;
            foreach (NetworkInterface networkInterface in NetworkInterfaces)
            {
                combomenber.ID = i;
                i++;
                combomenber.comboMember = networkInterface.Description;
                IPInterfaceProperties IPInterfaceProperties = networkInterface.GetIPProperties();
                UnicastIPAddressInformationCollection UnicastIPAddressInformationCollection = IPInterfaceProperties.UnicastAddresses;
                foreach (UnicastIPAddressInformation UnicastIPAddressInformation in UnicastIPAddressInformationCollection)
                {
                    if (UnicastIPAddressInformation.Address.AddressFamily == AddressFamily.InterNetwork)
                    {
                        combomenber.ipadd = UnicastIPAddressInformation.Address.ToString();
                    }
                }

                combolist.Add(combomenber);
            }
        }
    }
}