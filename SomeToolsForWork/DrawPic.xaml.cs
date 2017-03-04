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
using System.Windows.Shapes;

namespace SomeTools
{
    /// <summary>
    /// DrawPic.xaml 的交互逻辑
    /// </summary>
    public partial class DrawPic : Window
    {
        public DrawPic()
        {
            InitializeComponent();
            DrawCoodLine();
        }

        public void DrawCoodLine()
        {
            LineGeometry coodLineGeometry = new LineGeometry();
            coodLineGeometry.StartPoint = new Point(0,this.Height/2);
            coodLineGeometry.EndPoint = new Point(this.Width,this.Height/2);

            Path coodPath = new Path();
            coodPath.Stroke = Brushes.Black;
            coodPath.StrokeThickness = 1;
            coodPath.Data = coodLineGeometry;
        }
    }
}
