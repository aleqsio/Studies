using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
namespace Presenter
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public List<keyframe> keyframes;
        public Uri videouri;
        public Uri keyframeuri;
        public video vidscreen;
        public int pos = 1;
        public static TimeSpan timemax;
        public bool previewenabled = false;
        public bool ispresenting = false;
        public MainWindow()
        {
            keyframes = new List<keyframe>();
            InitializeComponent();
            updatepos();

        }

        public void beginpresenting()
        {
            pos = 1;
            updatepos();
            ispresenting = true;
            button2.Content = "End presentation";
            if (null != vidscreen)
            {
                vidscreen.Close();
            }
            vidscreen = new video();
            vidscreen.Show();
            vidscreen.setref(this);
            vidscreen.startvideo(videouri);
            togglepreview();
        }

        private void button3_Click(object sender, RoutedEventArgs e)
        {
            loadvid();
            loadkey();
        }
        void loadvid()
        {
            //video
            Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
            dlg.Title = "Choose video file:";
            Nullable<bool> result = dlg.ShowDialog();
            if (result == true)
            {
                string filename = dlg.FileName;
                Uri.TryCreate(filename, UriKind.RelativeOrAbsolute, out videouri);
                vidbutton.Content = System.IO.Path.GetFileName(filename);
            }
        }
        void loadkey()
        {
            //keyframe
            Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
            dlg.Title = "Choose keyframes file:";
            Nullable<bool> result = dlg.ShowDialog();
            if (result == true)
            {
                string filename = dlg.FileName;
                Uri.TryCreate(filename, UriKind.RelativeOrAbsolute, out keyframeuri);
                keybutton.Content = System.IO.Path.GetFileName(filename);
                keyframesparse(filename);
               
                updatepos();
            }

        }
        private void button_Click(object sender, RoutedEventArgs e)
        {
            loadvid();
        }

        private void keybutton_Click(object sender, RoutedEventArgs e)
        {
            loadkey();
        }

        private void keyframesparse(string filename)
        {

            System.IO.StreamReader str = new System.IO.StreamReader(filename);
            int fps = 30;
            keyframes.Clear();
            keyframe frame2 = new keyframe();
            frame2.pos = TimeSpan.FromMilliseconds(0);
            frame2.n = 0;
            frame2.type = 'C';
            keyframes.Add(frame2);
            try
            {
                int mypos = 0;
                int count = 0;
                keyframe frame = new keyframe();
                while (true)
                {
                    string line = str.ReadLine();
                    if (line == null)
                    {
                        frame.n = count;
                        keyframes.Add(frame);
                        break;
                    }
                    if (line.Equals("$>>>$") && mypos != 0)
                    {
                        frame.n = count;
                        count++;
                        keyframes.Add(frame);
                        count++;
                        frame = new keyframe();
                        mypos = 0;
                    }
                    if (mypos == 1)
                    {
                        int[] s = new int[4];
                        for (int i = 0; i < 4; i++)
                        {
                            int ms;
                            int.TryParse(line.Split(';')[i], out ms);
                            if (i == 3)
                                ms = (ms * 1000) / fps;
                            s[i] = ms;
                        }

                        TimeSpan ts = new TimeSpan(0, s[0], s[1], s[2], s[3]);
                        frame.pos = ts;
                    }
                    if (mypos == 2)
                    {
                        frame.type = line[0];
                        char[] posibles = { 'C', 'L', 'P' };
                        if(!posibles.Contains<char>(line[0]))
                            {
                            Exception e = new Exception("Keyframe identifier invalid");
                            throw  e;
                        }
                    }
                    if (mypos == 3)
                    {
                        frame.title = line;
                    }
                    if (mypos > 3)
                    {
                        if (frame.desc != null)
                        {
                            frame.desc += System.Environment.NewLine;
                        }
                        frame.desc += line;
                    }
                    mypos++;
                }
                bigcanvas.Visibility = Visibility.Visible;

            }
            catch (Exception e)
            {
                System.Windows.MessageBox.Show("Reading keyframes failed:  " + e.Message);
                keyframes.Clear();
                bigcanvas.Visibility = Visibility.Hidden;
                
            }

        }
        public struct keyframe
        {
            public string title;
            public string desc;
            public int n;
            public char type;
            public TimeSpan pos;
        }
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            Application.Current.Shutdown();
        }

        private void button2_Click(object sender, RoutedEventArgs e)
        {
            if (!ispresenting)
            {
                canvas.IsEnabled = false;
                checkBox.IsChecked = false;
                checkBox.Visibility = Visibility.Visible;
                beginpresenting();

            }
            else
            {
                if ((bool)checkBox.IsChecked)
                {
                    checkBox.Visibility = Visibility.Hidden;
                    canvas.IsEnabled = true;

                    ispresenting = false;
                    if (null != vidscreen)
                    {
                        vidscreen.Close();
                    }
                }

            }
        }

        internal void vidscreenclosed()
        {
            previewenabled = false;
            togglepreview();
            button2.Content = "Begin presentation";
        }

        public void togglepreview()
        {
            previewenabled = !previewenabled;

            if (previewenabled && ispresenting)
            {
                if (vidscreen.pausepos == pos)
                {
                    mediaElement.UnloadedBehavior = MediaState.Pause;
                    mediaElement.LoadedBehavior = MediaState.Pause;

                }
                else
                {
                    mediaElement.UnloadedBehavior = MediaState.Play;
                    mediaElement.LoadedBehavior = MediaState.Play;
                }
                mediaElement.Source = videouri;
                mediaElement.Position = vidscreen.mediaElement.Position;
            }
            else
            {
                mediaElement.UnloadedBehavior = MediaState.Manual;
                mediaElement.LoadedBehavior = MediaState.Manual;
                mediaElement.Close();
            }
        }


        private void Canvas_MouseDown(object sender, MouseButtonEventArgs e)
        {
            togglepreview();
        }

        private void button_Click_1(object sender, RoutedEventArgs e)
        {
            nextpos();
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            prevpos();
        }

        public void updatepos()
        {
            label_Copy.Content = "/" + (keyframes.Count - 1);
            label.Content = pos;
            if (keyframes.Count > 1)
            {
                progressbar.Value = pos;
                timemax = keyframes[pos].pos;
                progressbar.Maximum = (keyframes.Count - 1);
                label1.Content = keyframes[pos].title;
                label1_Copy.Content = keyframes[pos].desc;
            }
            else
            {
                progressbar.Value = 0;

            }

        }
       public void nextpos()
        {
            if (pos < keyframes.Count - 1)
            {
                pos++;
                updatepos();
            }
        }
       public void prevpos()
        {
            if (pos > 1)
            {
                pos--;
                updatepos();
            }
        }
      
        private void Window_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key.Equals(Key.Left))
            {
                prevpos();
            }
            if (e.Key.Equals(Key.Right) || e.Key.Equals(Key.Space))
            {
                nextpos();
            }
            e.Handled = true;
        }

    }
}
