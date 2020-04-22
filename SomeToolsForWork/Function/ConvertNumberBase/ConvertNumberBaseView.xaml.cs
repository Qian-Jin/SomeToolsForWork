using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace SomeTools.Function.ConvertNumberBase
{
    /// <summary>
    /// NumberBaseConversion.xaml 的交互逻辑
    /// </summary>
    public partial class ConvertNumberBaseView : UserControl
    {
        public ConvertNumberBaseView()
        {
            InitializeComponent();

            this.DataContext = new ConvertNumberBaseViewModel();
        }

        private void DecTextBox_OnKeyDown(object sender, KeyEventArgs e)
        {
            e.Handled = !((e.Key >= Key.D0 && e.Key <= Key.D9)
                         || (e.Key >= Key.NumPad0 && e.Key <= Key.NumPad9));
        }

        private void HexTextBox_OnKeyDown(object sender, KeyEventArgs e)
        {
            e.Handled = !((e.Key >= Key.D0 && e.Key <= Key.D9)
                          || (e.Key >= Key.NumPad0 && e.Key <= Key.NumPad9)
                          || (e.Key == Key.A) || (e.Key == Key.B) || (e.Key == Key.C) || (e.Key == Key.D)
                          || (e.Key == Key.E) || (e.Key == Key.F));
        }

        private void BinTextBox_OnKeyDown(object sender, KeyEventArgs e)
        {
            e.Handled = !(e.Key == Key.D0 || e.Key == Key.D1
                          || e.Key == Key.NumPad0 || e.Key == Key.NumPad1);
        }
    }
}