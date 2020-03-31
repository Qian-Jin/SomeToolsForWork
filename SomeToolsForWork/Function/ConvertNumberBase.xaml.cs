using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace SomeTools.Function
{
    /// <summary>
    /// NumberBaseConversion.xaml 的交互逻辑
    /// </summary>
    public partial class NumberBaseConversion : UserControl
    {
        public NumberBaseConversion()
        {
            InitializeComponent();
        }

        private void DecTextBox_OnTextChanged(object sender, TextChangedEventArgs e)
        {
            try
            {
                Int64 value = Convert.ToInt64(DecTextBox.Text);

                HexTextBox.Text = Convert.ToString(value, 16).ToUpper();
                BinTextBox.Text = Convert.ToString(value, 2);
            }
            catch
            {
                HexTextBox.Text = "Error.";
                BinTextBox.Text = "Error.";
            }
        }

        private void HexTextBox_OnTextChanged(object sender, TextChangedEventArgs e)
        {
            try
            {
                Int64 value = Convert.ToInt64(HexTextBox.Text, 16);

                DecTextBox.Text = Convert.ToString(value, 10);
                BinTextBox.Text = Convert.ToString(value, 2);
            }
            catch
            {
                DecTextBox.Text = "Error.";
                BinTextBox.Text = "Error.";
            }
        }

        private void BinTextBox_OnTextChanged(object sender, TextChangedEventArgs e)
        {
            try
            {
                Int64 value = Convert.ToInt64(BinTextBox.Text, 2);

                DecTextBox.Text = Convert.ToString(value, 10);
                HexTextBox.Text = Convert.ToString(value, 16).ToUpper();
            }
            catch
            {
                HexTextBox.Text = "Error.";
                DecTextBox.Text = "Error.";
            }
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