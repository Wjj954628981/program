using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using MeetingModel;
using MeetingBLL;
using MeetingDAL;

namespace Meeting.Meeting
{
    public partial class MeetingAdd : System.Web.UI.Page
    {
        MeetingsBLL meetingbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                string Opera = Request.QueryString["Opera"];
                if (Opera == "Edit")
                {
                    int MId = int.Parse(Request.QueryString["MId"]);
                    MeetingModel.Meeting meeting = meetingbll.GetMeetingInfo(MId);
                    TxtName.Text = meeting.m_name;
                    TxtTheme.Text = meeting.theme;
                    TxtStartTime.Text = meeting.begin_time.ToString("yyyy-MM-dd HH:MM:ss");
                    TxtEndTime.Text = Convert.ToDateTime(meeting.end_time).ToString("yyyy-MM-dd HH:MM:ss");
                    TxtCity.Text = meeting.m_city;
                    TxtStreet.Text = meeting.m_street;
                    TxtNumber.Text = meeting.m_number.ToString();
                    TxtDept.Text = meeting.dept_id;
                }

            }
        }
        protected void btnSave_Click(object sender, EventArgs e)
        {
            MeetingsBLL meetingbll = new MeetingsBLL();
            string Opera = Request.QueryString["Opera"];
            if (CheckValue())
            {
                if (Opera == "Add")
                {
                    //新增会议
                    MeetingModel.Meeting meeting = new MeetingModel.Meeting();
                    //meeting.m_id = meetingbll.GetMeetingCount();
                    //meeting.m_id = meetingbll.max(m_id);
                    meeting.m_name = TxtName.Text;
                    meeting.theme = TxtTheme.Text;
                    meeting.begin_time = DateTime.Parse(TxtStartTime.Text);
                    meeting.end_time = DateTime.Parse(TxtEndTime.Text);
                    meeting.m_city = TxtCity.Text;
                    meeting.m_street = TxtStreet.Text;
                    meeting.m_number = int.Parse(TxtNumber.Text);
                    meeting.dept_id = TxtDept.Text;
                    if (meetingbll.AddMeeting(meeting) > 0)
                    {
                        Response.Write("<script>alert('添加成功')</script>");
                    }
                    else
                    {
                        Response.Write("<script>alert('添加失败')</script>");
                    }
                }
                else
                {
                    //更改会议信息
                    int MId = int.Parse(Request.QueryString["MId"]);
                    MeetingModel.Meeting meeting = meetingbll.GetMeetingInfo(MId);

                    meeting.m_name = TxtName.Text;
                    meeting.theme = TxtTheme.Text;
                    meeting.begin_time = DateTime.Parse(TxtStartTime.Text);
                    meeting.end_time = DateTime.Parse(TxtEndTime.Text);
                    meeting.m_city = TxtCity.Text;
                    meeting.m_street = TxtStreet.Text;
                    meeting.m_number = int.Parse(TxtNumber.Text);
                    meeting.dept_id = TxtDept.Text;
                    if (meetingbll.UpdateMeeting(meeting) > 0)
                    {
                        Response.Write("<script>alert('修改成功')</script>");
                    }
                    else
                    {
                        Response.Write("<script>alert('修改失败')</script>");
                    }
                }
            }
        }
        private bool CheckValue()
        {
            if (string.IsNullOrEmpty(TxtName.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('会议名称不能为空！');", true);
                TxtName.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtTheme.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('主题不能为空！');", true);
                TxtTheme.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtStartTime.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('开始时间不能为空！');", true);
                TxtStartTime.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtEndTime.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('结束时间不能为空！');", true);
                TxtEndTime.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtCity.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('所在城市不能为空！');", true);
                TxtCity.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtStreet.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('街道不能为空！');", true);
                TxtStreet.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtNumber.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('门牌号不能为空！');", true);
                TxtNumber.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtDept.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('所属部门不能为空！');", true);
                TxtDept.Focus();
                return false;
            }
            return true;
        }
        protected void btnCancel_Click(object sender, EventArgs e)
        {
            Response.Redirect("MeetingList.aspx");
        }
    }
}