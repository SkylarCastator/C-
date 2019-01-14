using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Speech.Synthesis;
using System.IO;

namespace text_to_speech
{
    public partial class Form1 : Form
    {
        SpeechSynthesizer reader;
        SpeechSynthesizer reader2;
        public Form1()
        {
            InitializeComponent();

        }
        private void Form1_Load(object sender, EventArgs e)
        {
            reader = new SpeechSynthesizer();
            reader2 = new SpeechSynthesizer();
            button2.Enabled = false;
            button3.Enabled = false;
            button4.Enabled = false;
            textBox1.ScrollBars = ScrollBars.Both;
        }

        //SPEAK TEXT
        private void button1_Click(object sender, EventArgs e)
        {
            reader.Dispose();
            reader2.Dispose();
            if (textBox1.Text != "")
            {
                reader2 = new SpeechSynthesizer();
                reader = new SpeechSynthesizer();

                //reader.Rate = -2;

                PromptBuilder pb1 = new PromptBuilder();
                string high = "<prosody pitch=\"+4200Hz\"> " + textBox1.Text + " </prosody >";
                pb1.AppendSsmlMarkup(high);

                PromptBuilder pb2 = new PromptBuilder();
                string Low = "<prosody pitch=\"-4200Hz\"> "+ textBox1.Text + " </prosody >";
                pb2.AppendSsmlMarkup(Low);

                reader.SpeakAsync(pb1);
                reader2.SpeakAsync(pb2);

                label2.Text = "SPEAKING";
                button2.Enabled = true;
                button4.Enabled = true;
                reader.SpeakCompleted += new EventHandler<SpeakCompletedEventArgs>(reader_SpeakCompleted);
            }
            else
            {
                MessageBox.Show("Please enter some text in the textbox", "Message", MessageBoxButtons.OK);
            }
        }

        void reader_SpeakCompleted(object sender, SpeakCompletedEventArgs e)
        {
            label2.Text = "IDLE";
        }

        //PAUSE
        private void button2_Click(object sender, EventArgs e)
        {
            if (reader != null)
            {
                if (reader.State == SynthesizerState.Speaking)
                {
                    reader.Pause();
                    label2.Text = "PAUSED";
                    button3.Enabled = true;

                }
            }
        }

        //RESUME
        private void button3_Click(object sender, EventArgs e)
        {
            if (reader != null)
            {
                if (reader.State == SynthesizerState.Paused)
                {
                    reader.Resume();
                    label2.Text = "SPEAKING";
                }
                button3.Enabled = false;
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (reader != null)
            {
                reader.Dispose();
                label2.Text = "IDLE";
                button2.Enabled = false;
                button3.Enabled = false;
                button4.Enabled = false;
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            openFileDialog1.ShowDialog();
        }

        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {
            textBox1.Text =  File.ReadAllText(openFileDialog1.FileName.ToString());

        }

   

     

     
    }
}
