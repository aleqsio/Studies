using System;
using System.Collections.Generic;
using System.Linq;
using System.Media;
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

namespace WpfApplication1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        Random r;
        int i = 0;
        public MainWindow()
        {
            r = new Random();
            InitializeComponent();
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            foo();
        }
        async void foo()
        {
            if (r.Next() % 10 + i < 18)
            {
                i++;
                await Task.Delay(400);
            }
            SystemSounds.Exclamation.Play();
            rect.Visibility = Visibility.Visible;
            await Task.Delay(900);
            rect.Visibility = Visibility.Hidden;

            // something
            await Task.Delay(1000);
            Close();
        }
    }
   
}
