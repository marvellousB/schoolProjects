using System.ComponentModel;
using static WinFormsApp1.Form1;

namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        public interface IReminder
        {
            int ID { get; set; }
            string UserEmail { get; set; }
            string Title { get; set; }
            string Summary { get; set; }
            string Description { get; set; }
            DateTime StartDate { get; set; }
            DateTime EndDate { get; set; }
        }

        public class MeetingReminder : IReminder
        {
            public int ID { get; set; }
            public string UserEmail { get; set; }
            public string Title { get; set; }
            public string Summary { get; set; }
            public string Description { get; set; }
            public DateTime StartDate { get; set; }
            public DateTime EndDate { get; set; }
            public TimeSpan StartTime { get; set; }
            public TimeSpan EndTime { get; set; }
        }

        public class TaskReminder : IReminder
        {
            public int ID { get; set; }
            public string UserEmail { get; set; }
            public string Title { get; set; }
            public string Summary { get; set; }
            public string Description { get; set; }
            public DateTime StartDate { get; set; }
            public DateTime EndDate { get; set; }
            public TimeSpan StartTime { get; set; }
            public TimeSpan EndTime { get; set; }
        }
    

        public interface IReminderFactory
        {
            IReminder CreateMeetingReminder();
            IReminder CreateTaskReminder();
        }

        public class TaskReminderFactory : IReminderFactory
        {
            public IReminder CreateMeetingReminder()
            {
                // This factory does not create Meeting Reminders.
                throw new NotImplementedException();
            }

            public IReminder CreateTaskReminder()
            {
                return new TaskReminder();
            }
        }

        public class MeetingReminderFactory : IReminderFactory
        {
            public IReminder CreateMeetingReminder()
            {
                return new MeetingReminder();
            }

            public IReminder CreateTaskReminder()
            {
                // This factory does not create Task Reminders.
                return new TaskReminder();
            }
        }


        public IReminder CreateMeetingReminder()
        {
            return new MeetingReminder();
        }

        public IReminder CreateTaskReminder()
        {
            // This factory does not create Task Reminders.
            return new TaskReminder();
        }
    








        public Form1()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }


        private void button2_Click(object sender, EventArgs e)
        {
            
        }

        
    }
}