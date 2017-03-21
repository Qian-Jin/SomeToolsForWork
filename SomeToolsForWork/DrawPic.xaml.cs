using System;
using System.Collections.Generic;
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
            
        }
        public enum typ_xy
        {
            X, Y
        };


        [DllImport("AppFun.dll", CharSet = CharSet.Unicode, EntryPoint = "outfunction", CallingConvention = CallingConvention.Cdecl)]
        public extern static double outfunction(double i, typ_xy typ, int curvetype);

        public int curvetype1 = MainWindow.Curvetype;

        protected void DrawFunLine()
        {
            const double for_time = 100;
            const double for_step = 0.1;
            for (double i = 0; i <= for_time; i = i + for_step)
            {
                double the1x = Xpos + outfunction(i, typ_xy.X, curvetype1) * Zoom ;
                double the1y = Ypos - outfunction(i, typ_xy.Y, curvetype1) * Zoom ;
                double the2x = Xpos + outfunction(i + for_step, typ_xy.X, curvetype1) * Zoom ;
                double the2y = Ypos - outfunction(i + for_step, typ_xy.Y, curvetype1) * Zoom ;
                Point the1Point = new Point(the1x,the1y);
                Point the2Point = new Point(the2x,the2y);
                DrawLine(the1Point,the2Point);
            }
            
        }


        public double Xpos;
        public double Ypos;
        public double Zoom = 5;

        public Point OldPoint;
        public Point NewPoint;

        private void DrawPic_OnLoaded(object sender, RoutedEventArgs e)
        {
            Canvas.Children.Clear();
            Xpos = Canvas.ActualWidth / 2;
            TextBoxXpos.Text = Convert.ToString(Xpos);
            Ypos = Canvas.ActualHeight / 2;
            TextBoxYpos.Text = Convert.ToString(Ypos);
            DrawCoodLine();
            DrawFunLine();
        }

        private void ButtonDrawNewPic_OnClick(object sender, RoutedEventArgs e)
        {
            Xpos = Convert.ToDouble(TextBoxXpos.Text);
            Ypos = Convert.ToDouble(TextBoxYpos.Text);
            Zoom = Convert.ToDouble(TextBoxZoom.Text);
            Canvas.Children.Clear();
            DrawCoodLine();
            DrawFunLine();
        }

        private void DrawPic_OnSizeChanged(object sender, SizeChangedEventArgs e)
        {
            Canvas.Children.Clear();
            DrawCoodLine();
            DrawFunLine();
        }


        protected void DrawCoodLine()
        {
            DrawLine(new Point(0, Ypos), new Point(Canvas.ActualWidth, Ypos));
            DrawLine(new Point(Xpos, 0), new Point(Xpos, Canvas.ActualHeight));
            DrawLine(new Point(Canvas.ActualWidth, Ypos), new Point(Canvas.ActualWidth - 10, Ypos + 10));
            DrawLine(new Point(Canvas.ActualWidth, Ypos), new Point(Canvas.ActualWidth - 10, Ypos - 10));
            DrawLine(new Point(Xpos - 10, 10), new Point(Xpos, 0));
            DrawLine(new Point(Xpos, 0), new Point(Xpos + 10, 10));
            DrawLine(new Point(Xpos, Ypos - 1 * Zoom), new Point(Xpos + 5, Ypos - 1 * Zoom));
            DrawLine(new Point(Xpos + 1 * Zoom, Ypos), new Point(Xpos + 1 * Zoom, Ypos - 5));
        }


        //底层画线函数
        protected void DrawLine(Point startPoint,Point endPoint)
        {
            LineGeometry coodLineGeometry = new LineGeometry();
            coodLineGeometry.StartPoint = startPoint;
            coodLineGeometry.EndPoint = endPoint;

            Path coodPath = new Path();
            coodPath.Stroke = Brushes.Black;
            coodPath.StrokeThickness = 1;
            coodPath.Data = coodLineGeometry;

            Canvas.Children.Add(coodPath);
        }

        private void Canvas_OnMouseWheel(object sender, MouseWheelEventArgs e)
        {
            const double zoomdelta = 5;
            MouseButtonEventArgs args = new MouseButtonEventArgs(Mouse.PrimaryDevice,0, MouseButton.Left);
            args.RoutedEvent = Button.ClickEvent;
            if (e.Delta > 0)
            {
                if (Zoom <= 0)
                {
                    ;
                }
                else
                {
                    Zoom = Zoom - zoomdelta;
                    TextBoxZoom.Text = Convert.ToString(Zoom);
                }
            }
            else
            {
                Zoom = Zoom + zoomdelta;
                TextBoxZoom.Text = Convert.ToString(Zoom);
            }
            ButtonDraw.RaiseEvent(args);
        }

        private void Canvas_OnMouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
           OldPoint = e.GetPosition(Canvas);
        }

        private void Canvas_OnMouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            NewPoint = e.GetPosition(Canvas);
            Xpos = Xpos + (NewPoint.X - OldPoint.X);
            Ypos = Ypos + (NewPoint.Y - OldPoint.Y);
            TextBoxXpos.Text = Convert.ToString(Xpos);
            TextBoxYpos.Text = Convert.ToString(Ypos);
            MouseButtonEventArgs args = new MouseButtonEventArgs(Mouse.PrimaryDevice, 0, MouseButton.Left);
            args.RoutedEvent = Button.ClickEvent;
            ButtonDraw.RaiseEvent(args);

        }
    }
}
