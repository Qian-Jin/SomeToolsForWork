using System;
using System.Collections.Generic;
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

namespace SomeTools.Function
{
    /// <summary>
    /// ConvertPulseToUnit.xaml 的交互逻辑
    /// </summary>
    public partial class ConvertPulseToUnit : UserControl
    {
        public ConvertPulseToUnit()
        {
            InitializeComponent();
        }

        private void Cal_motionvel(object sender, RoutedEventArgs e)
        {
            double ppr = Convert.ToDouble(TextBox5_1.Text);
            double gearin = Convert.ToDouble(TextBox5_2.Text);
            double gearout = Convert.ToDouble(TextBox5_3.Text);
            double setvel = Convert.ToDouble(TextBox5_4.Text);
            double setservovel = Convert.ToDouble(TextBox5_7.Text);

            TextBox5_5.Text = Convert.ToString(setvel / ppr * 60 / gearout * gearin);
            TextBox5_6.Text = Convert.ToString(setvel / ppr * 60 / gearout * gearin / 60);
            TextBox5_8.Text = Convert.ToString(setservovel / gearin * gearout / 60 * ppr);
        }
    }
}