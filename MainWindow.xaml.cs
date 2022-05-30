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
using System.Drawing;
using System.Drawing.Imaging;
using OpenCvSharp;
using Microsoft.Win32;  // オープンファイル・ダイアログボックスで使用する。
using System.IO;        // ファイル操作で使用する。

namespace WpfApp1
{
    /// <summary>
    /// MainWindow.xaml の相互作用ロジック
    /// </summary>
    public partial class MainWindow : System.Windows.Window
    {
        WriteableBitmap m_processedBitmap = null;
        //        BitmapImage m_srcBitmap = null;

        public MainWindow()
        {
            InitializeComponent();
            //           test.Source = new BitmapImage(new Uri("C:/Users/RD56285/Documents/1_Dev/H2O/研修/C#演習/自由製作/WpfApp2/WpfApp2/test.png", UriKind.Relative));
            //           EnableDragDrop(image);
        }

        private void TextBox_TextChanged(object sender, TextChangedEventArgs e)
        {

        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Hello World");
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {

        }

        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {

        }

        //画像選択
        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            // オープンファイル・ダイアログボックスを設定します。
            OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
            dlg.Filter = "画像|*.jpg;*.jpeg;*.png;*.bmp";  // 左記拡張子のみフォローする。

            // ファイルを選択する
            if (dlg.ShowDialog() != true)
            {
                return;
            }

            // 選択したファイルをメモリにコピーする
            MemoryStream ms = new MemoryStream();
            using (FileStream fs = new FileStream(dlg.FileName, FileMode.Open))
            {
                fs.CopyTo(ms);      // FileStreamの内容をメモリストリームにコピーします。
            }

            // ストリームの位置をリセット
            ms.Seek(0, SeekOrigin.Begin);

            // ストリームをもとにBitmapImageを作成
            BitmapImage bmp = new BitmapImage();
            bmp.BeginInit();            // BitmapImage の初期化の開始を通知します。
            bmp.StreamSource = ms;      // BitmapImage のストリーム ソースを設定します。
            bmp.EndInit();              // BitmapImage の初期化の終了を通知します。

            // BitmapImageをSourceに指定して画面に表示する
            m_processedBitmap = new WriteableBitmap(bmp);
            test.Source = m_processedBitmap;


        }

        //画像処理
        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            if (m_processedBitmap == null)
            {
                MessageBox.Show("画像選択からやり直してください");
                return;
            }
            System.Windows.Media.PixelFormat fmt = m_processedBitmap.Format;
            int channel = 3;
            if (fmt == PixelFormats.Bgr32)
            {
                channel = 4;
            }
            else if (fmt == PixelFormats.Bgr24)
            {
                channel = 3;
            }
            else
            {
                MessageBox.Show("サポート外の画像フォーマットです");
                return;
            }
            int width = m_processedBitmap.PixelWidth;
            int height = m_processedBitmap.PixelHeight;
            int stride = m_processedBitmap.BackBufferStride;
            int res = stride - channel * width;
            m_processedBitmap.Lock();
            unsafe
            {
                byte* pBackBuffer =
                    (byte*)(void*)m_processedBitmap.BackBuffer;
                for (int y = 0; y < height; y++)
                {
                    for (int x = 0; x < width; x++)
                    {
                        byte b = pBackBuffer[0];
                        byte g = pBackBuffer[1];
                        byte r = pBackBuffer[2];

                        int gray =
                            (int)(0.3 * r + 0.59 * g + 0.11 * b);
                        if (gray > 255)
                        {
                            gray = 255;
                        }
                        if (gray < 0)
                        {
                            gray = 0;
                        }

                        pBackBuffer[0] = (byte)gray;
                        pBackBuffer[1] = (byte)gray;
                        pBackBuffer[2] = (byte)gray;

                        pBackBuffer += channel;
                    }
                    pBackBuffer += res;
                }
            }
            m_processedBitmap.AddDirtyRect(
                new Int32Rect(0, 0, width, height));
            m_processedBitmap.Unlock();
            test2.Source = m_processedBitmap;
        }


        //this.test.Source;
        //          this.test.Source = bmp;
    }

    /*
    private void EnableDragDrop(Control control)
    {
        //ドラッグ＆ドロップを受け付けられるようにする
        control.AllowDrop = true;

        //ドラッグが開始された時のイベント処理（マウスカーソルをドラッグ中のアイコンに変更）
        control.PreviewDragOver += (s, e) =>
        {
            //ファイルがドラッグされたとき、カーソルをドラッグ中のアイコンに変更し、そうでない場合は何もしない。
            e.Effects = (e.Data.GetDataPresent(DataFormats.FileDrop)) ? DragDropEffects.Copy : e.Effects = DragDropEffects.None;
            e.Handled = true;
        };

        //ドラッグ＆ドロップが完了した時の処理（ファイル名を取得し、ファイルの中身をTextプロパティに代入）
        control.PreviewDrop += (s, e) =>
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop)) // ドロップされたものがファイルかどうか確認する。
            {
                string[] paths = ((string[])e.Data.GetData(DataFormats.FileDrop));
                //--------------------------------------------------------------------
                // ここに、ドラッグ＆ドロップ受付時の処理を記述する
                //--------------------------------------------------------------------
            }
        };

    }*/


}


/*
namespace WpfApp1
{
    namespace WindowsFormsApp1
    {
        public partial class Form1 : Form
        {
            PictureBox pictureBox;
            Bitmap bitmap;
            public Form1()
            {
                this.AutoSize = true;
                this.Load += Form1_Load;
            }

            private void Form1_Load(object sender, EventArgs e)
            {
                bitmap = new Bitmap(@"test.png");

                pictureBox = new PictureBox();
                pictureBox.Location = new Point(10, 10);
                pictureBox.SizeMode = PictureBoxSizeMode.AutoSize;
                pictureBox.Image = bitmap;
                pictureBox.MouseDown += PictureBox_MouseDown;
                this.Controls.Add(pictureBox);
            }

            private void PictureBox_MouseDown(object sender, MouseEventArgs e)
            {
                Color color = bitmap.GetPixel(e.X, e.Y);
                Console.WriteLine(color.R);
                Console.WriteLine(color.G);
                Console.WriteLine(color.B);
            }
        }
    }
}
*/
