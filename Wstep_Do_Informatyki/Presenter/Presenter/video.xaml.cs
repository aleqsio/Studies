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

namespace Presenter
{
    /// <summary>
    /// Interaction logic for video.xaml
    /// </summary>
    public partial class video : Window
    {
        bool fullScreen = true;
        MainWindow mainwindow;
        bool freshrun = true;
       public int pausepos;
        public System.Windows.Threading.DispatcherTimer dispatcherTimer;
        public video()
        {
            InitializeComponent();
            resize();
        }
        public void startvideo(Uri videosource)
        {
          dispatcherTimer = new System.Windows.Threading.DispatcherTimer();
            dispatcherTimer.Tick += dispatcherTimer_Tick;
            dispatcherTimer.Interval = new TimeSpan(0, 0,0, 0 , 30);
            dispatcherTimer.Start();
            mediaElement.ScrubbingEnabled = true;

            mediaElement.LoadedBehavior = MediaState.Manual;
            mediaElement.UnloadedBehavior = MediaState.Manual;

          

            mediaElement.Source = videosource;

        }
        public void dispatcherTimer_Tick(object sender, EventArgs e)
        {
            if (mainwindow.pos > pausepos)
            {
        
                if (mainwindow.previewenabled)
                {
                    mainwindow.mediaElement.LoadedBehavior = MediaState.Manual;
                    mainwindow.mediaElement.UnloadedBehavior = MediaState.Manual;

                    mainwindow.mediaElement.Play();
                }
                pausepos = int.MaxValue;
                mediaElement.Play();
            }
            if(mediaElement.Position.CompareTo(MainWindow.timemax)>0)
            {
                if (mainwindow.keyframes[mainwindow.pos].type == 'L')
                {
                    mediaElement.Position = mainwindow.keyframes[mainwindow.pos - 1].pos;
                    if (mainwindow.previewenabled)
                        mainwindow.mediaElement.Position = mainwindow.keyframes[mainwindow.pos - 1].pos;
                }else if (mainwindow.keyframes[mainwindow.pos].type == 'C')
                {
                    if(mainwindow.pos<mainwindow.keyframes.Count-1)
                    mainwindow.pos++;
                    mainwindow.updatepos();
                }
                else if (mainwindow.keyframes[mainwindow.pos].type == 'P')
                {
                    pausepos = mainwindow.pos;
                    mediaElement.Position = mainwindow.keyframes[mainwindow.pos].pos;
                    mediaElement.Pause();
                    if (mainwindow.previewenabled)
                    {
                        mainwindow.mediaElement.Position = mainwindow.keyframes[mainwindow.pos].pos;

                        mainwindow.mediaElement.LoadedBehavior = MediaState.Manual;
                        mainwindow.mediaElement.UnloadedBehavior = MediaState.Manual;
                        mainwindow.mediaElement.Pause();
                    }
                    mainwindow.updatepos();
                }
            }
        }
        public void resize()
        {
            if (!fullScreen)
            {
                this.Background = new SolidColorBrush(Colors.Black);
                this.WindowStyle = WindowStyle.None;
                this.WindowState = WindowState.Maximized;
                this.SizeToContent = SizeToContent.Manual;
                this.Cursor = Cursors.None;
                label.Visibility = Visibility.Collapsed;
                label1.Visibility = Visibility.Collapsed;
                
            }
            else
            {
                this.Cursor = Cursors.Arrow;
                this.Background = new SolidColorBrush(Colors.White);
                this.WindowStyle = WindowStyle.None;
                this.WindowState = WindowState.Normal;
                this.Height = 250;
                this.SizeToContent = SizeToContent.Width;
                if (freshrun)
                {
                
                this.Top = System.Windows.SystemParameters.PrimaryScreenHeight - 350;
                this.Left = System.Windows.SystemParameters.PrimaryScreenWidth - this.Width - 100;
                    freshrun = false;
                }
            }
            fullScreen = !fullScreen;
        }

        internal void setref(MainWindow mainWindow)
        {
            mainwindow = mainWindow;
        }

        private void mediaElement_MouseDown(object sender, MouseButtonEventArgs e)
        { 
            if (e.ClickCount == 2)
            {
                resize();
                return;
            }
            if (e.ChangedButton == MouseButton.Left)
                this.DragMove();
           // resize();
        }

        private void Window_Deactivated_1(object sender, EventArgs e)
        {
            Window window = (Window)sender;
            window.Topmost = true;

        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            mediaElement.LoadedBehavior = MediaState.Manual;
            mediaElement.UnloadedBehavior = MediaState.Manual;

            mediaElement.Stop();
            mainwindow.vidscreenclosed();
        }

        private void Window_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key.Equals(Key.Left))
            {
                mainwindow.prevpos();
            }
            if (e.Key.Equals(Key.Right) || e.Key.Equals(Key.Space))
            {
                mainwindow.nextpos();
            }
            e.Handled = true;
        }
    }
}
