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

namespace SomeTools.Function.ConvertPulseToUnit
{
    /// <summary>
    /// ConvertPulseToUnitView.xaml 的交互逻辑
    /// </summary>
    public partial class ConvertPulseToUnitView : UserControl
    {
        public ConvertPulseToUnitView()
        {
            InitializeComponent();

            this.DataContext = new ConvertPulseToUnitViewModel();
        }

        private void TextBoxKeyDownEventSetter_OnHandler(object sender, KeyEventArgs e)
        {
            e.Handled = !((e.Key >= Key.D0 && e.Key <= Key.D9)
                          || e.Key == Key.Decimal
                          || (e.Key >= Key.NumPad0 && e.Key <= Key.NumPad9));
        }
    }
}