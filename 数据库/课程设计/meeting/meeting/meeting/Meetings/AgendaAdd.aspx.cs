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

namespace Meeting.Meetings
{
    public partial class AgendaAdd : System.Web.UI.Page
    {
        AgendaBLL agendabll = new AgendaBLL();
        public int MID3;
        public void Page_Load(object sender, EventArgs e)
        {
            //MID3 = int.Parse(Request.QueryString["MID2"]);
            if (!IsPostBack)
            {
                string Opera = Request.QueryString["Opera"];
                if (Opera == "Edit")
                {
                    int agendanumber = int.Parse(Request.QueryString["agendanumber"]);
                    MID3 = int.Parse(Request.QueryString["MID2"]);
                    MeetingModel.agenda agenda = agendabll.GetAgendaInfo(agendanumber);
                    //MID3 = agenda.m_id;
                    txtStarttime.Text = Convert.ToDateTime(agenda.starttime).ToString("yyyy-MM-dd HH:MM:ss");
                    txtEndtime.Text = Convert.ToDateTime(agenda.endtime).ToString("yyyy-MM-dd HH:MM:ss");
                    txtDetail.Text = agenda.detail; ;
                }
                else
                {
                    MID3 = int.Parse(Request.QueryString["MID2"]);
                }
            }
        }

        protected void btnSave_Click(object sender, EventArgs e)
        {
            AgendaBLL agendabll = new AgendaBLL();
            string Opera = Request.QueryString["Opera"];
            if (CheckValue())
            {
                if (Opera == "Add")
                {
                    //新增日程
                    MeetingModel.agenda agenda = new MeetingModel.agenda();
                    MID3 = int.Parse(Request.QueryString["MID2"]);
                    agenda.m_id = MID3;
                    agenda.starttime = DateTime.Parse(txtStarttime.Text);
                    agenda.endtime = DateTime.Parse(txtEndtime.Text);
                    agenda.detail = txtDetail.Text;
                    if (agendabll.AddAgenda(agenda) > 0)
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
                    //更改日程信息
                    int agendanumber = int.Parse(Request.QueryString["agendanumber"]);
                    MeetingModel.agenda agenda = agendabll.GetAgendaInfo(agendanumber);
                    //MID3 = int.Parse(Request.QueryString["MID2"]);
                    //agenda.m_id = MID3;
                    agenda.starttime = DateTime.Parse(txtStarttime.Text);
                    agenda.endtime = DateTime.Parse(txtEndtime.Text);
                    agenda.detail = txtDetail.Text;
                    if (agendabll.UpdateAgenda(agenda) > 0)
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
            if (string.IsNullOrEmpty(txtStarttime.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('开始时间不能为空！');", true);
                txtStarttime.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(txtEndtime.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('结束时间不能为空！');", true);
                txtEndtime.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(txtDetail.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('具体细节不能为空！');", true);
                txtDetail.Focus();
                return false;
            }
            return true;
        }
        protected void btnCancel_Click(object sender, EventArgs e)
        {
            MID3 = int.Parse(Request.QueryString["MID2"]);
            Response.Redirect("Agenda.aspx?MId="+MID3);
        }
    }
}