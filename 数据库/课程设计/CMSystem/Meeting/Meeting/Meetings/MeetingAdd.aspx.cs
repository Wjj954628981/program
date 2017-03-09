using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using MeetingModel;
using MeetingBLL;
using System.Data;

namespace Meeting.Meeting
{
    public partial class MeetingAdd : System.Web.UI.Page
    {
        MeetingsBLL meetingbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        { 
            if(!IsPostBack)
            {
                string Opera = Request.QueryString["Oprea"];

                if(Opera=="Edit")
                {
                    string MId = Request.QueryString["MId"];
                    Meetings meeting = meetingbll.GetMeetingInfo(MId);
                    txtrank.Text = meeting.m_id.ToString();
                    txtTitle.Text = meeting.m_name;
                    txtpnum.Text = meeting.pre_num.ToString();
                    txtmnum.Text = meeting.max_num.ToString();
                    txttheme.Text = meeting.theme;
                    txtbd.Text = meeting.begin_date.ToString("yyyy-MM-dd");
                    txted.Text = meeting.end_date.ToString();
                    txtcity.Text = meeting.m_city;
                    txtaddress.Text = meeting.m_address;
                    txthotel.Text = meeting.h_name; 
                }
            }
        }
        protected void btnSave_Click(object sender,EventArgs e)
        {
            MeetingsBLL meetingbll=new MeetingsBLL();
            string Opera=Request.QueryString["Opera"];
            if (CheckValue())
            {
                if (Opera == "Edit")
                {
                    string MId = Request.QueryString["MId"];
                    Meetings meeting = meetingbll.GetMeetingInfo(MId);
                    meeting.m_id = txtrank.Text;
                    meeting.m_name = txtTitle.Text;
                    meeting.pre_num = int.Parse(txtpnum.Text);
                    meeting.max_num = int.Parse(txtmnum.Text);
                    meeting.theme = txttheme.Text;
                    meeting.begin_date = DateTime.Parse(txtbd.Text);
                    meeting.end_date = DateTime.Parse(txted.Text);
                    meeting.m_city = txtcity.Text;
                    meeting.m_address = txtaddress.Text;
                    meeting.h_name = txthotel.Text;

                    if (meetingbll.UpdateMeeting(meeting) > 0)
                    {
                        Response.Write("<script>alert('修改成功!')</script>");
                    }
                    else
                    {
                        Response.Write("<script>alert('修改失败！')</script>");
                    }
                }
                else
                {
                    Meetings meeting = new Meetings();
                    meeting.m_id = txtrank.Text;
                    meeting.m_name = txtTitle.Text;
                    meeting.pre_num = int.Parse(txtpnum.Text);
                    meeting.max_num = int.Parse(txtmnum.Text);
                    meeting.theme = txttheme.Text;
                    meeting.begin_date = DateTime.Parse(txtbd.Text);
                    meeting.end_date = DateTime.Parse(txted.Text);
                    meeting.m_city = txtcity.Text;
                    meeting.m_address = txtaddress.Text;
                    meeting.h_name = txthotel.Text;

                    if (meetingbll.AddMeeting(meeting) > 0)
                    {
                        Response.Write("<script>alert('增加成功!')</script>");
                    }
                    else
                    {
                        Response.Write("<script>alert('增加失败！')</script>");
                    }
                }
            }
        }
        /*protected void Page_load(object sender,EventArgs e)
        {
            if(!IsPostBack)
            {
                ViewState["BackUrl"] = Request.UrlReferrer.ToString();
            }
        }*/
        protected void btnCancel_Click(object sender,EventArgs e)
        {
            Response.Redirect("MeetingList.aspx");
        }
        private bool CheckValue()
        {
            if(string.IsNullOrEmpty(txtrank.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(),"alert","alert('会议排序不能为空！');",true);
                txtrank.Focus();
                return false;
            }if(string.IsNullOrEmpty(txtTitle.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(),"alert","alert('会议名称不能为空！');",true);
                txtTitle.Focus();
                return false;
            }
            if(string.IsNullOrEmpty(txtpnum.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(),"alert","alert('会议参加人数不能为空！');",true);
                txtpnum.Focus();
                return false;
            }
            if(string.IsNullOrEmpty(txtmnum.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(),"alert","alert('会议最多人数不能为空！');",true);
                txtmnum.Focus();
                return false;
            }
            if(string.IsNullOrEmpty(txttheme.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(),"alert","alert('会议主题不能为空！');",true);
                txttheme.Focus();
                return false;
            }
            if(string.IsNullOrEmpty(txtbd.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(),"alert","alert('会议开始日期不能为空！');",true);
                txtbd.Focus();
                return false;
            }
            if(string.IsNullOrEmpty(txted.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(),"alert","alert('会议结束日期不能为空！');",true);
                txted.Focus();
                return false;
            }
            if(string.IsNullOrEmpty(txtcity.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(),"alert","alert('会议城市不能为空！');",true);
                txtcity.Focus();
                return false;
            }
            if(string.IsNullOrEmpty(txtaddress.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(),"alert","alert('会议地址不能为空！');",true);
                txtaddress.Focus();
                return false;
            }
            if(string.IsNullOrEmpty(txthotel.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(),"alert","alert('会议预订宾馆不能为空！');",true);
                txthotel.Focus();
                return false;
            }
            return true;
        }
    }
}