using System;
using System.Runtime.InteropServices;
using System.Windows.Controls;

namespace SomeTools.Function.ConvertFloatToHex
{
    /// <summary>
    /// ConvertFloatToHex.xaml 的交互逻辑
    /// </summary>
    public partial class ConvertFloatToHexView : UserControl
    {
        public ConvertFloatToHexView()
        {
            InitializeComponent();

            this.DataContext = _dataContext;
        }

        private ConvertFloatToHexViewModel _dataContext = new ConvertFloatToHexViewModel();
    }
}