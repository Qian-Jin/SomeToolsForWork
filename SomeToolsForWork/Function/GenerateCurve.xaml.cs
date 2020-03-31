using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
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
    /// GenerateCurve.xaml 的交互逻辑
    /// </summary>
    public partial class GenerateCurve : UserControl
    {
        public GenerateCurve()
        {
            InitializeComponent();
        }

        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "gcodefileoutput", CallingConvention = CallingConvention.Cdecl)]
        public extern static void gcodefileoutput(int curvetype);

        private void GcodeSave_OnClick(object sender, RoutedEventArgs e)
        {
            if (ComboBoxCurveType.SelectedIndex == -1)
            {
                TextBox_GText.Text = "请选择曲线类型";
            }
            else
            {
                gcodefileoutput(ComboBoxCurveType.SelectedIndex);
                TextBox_GText.Text = "生成成功，文件位于E:\\TextOut\\G_code.txt\n具体文件如下：\n";
                TextBox_GText.AppendText(File.ReadAllText("E:\\TextOut\\G_code.txt"));
                ButtonOpenFile.Visibility = Visibility.Visible;
            }
        }

        private void OpenGcodeFile_OnClick(object sender, RoutedEventArgs e)
        {
            System.Diagnostics.Process.Start(@"E:\TextOut\G_code.txt");
        }

        private void DrawPic_OnClick(object sender, RoutedEventArgs e)
        {
        }
    }
}