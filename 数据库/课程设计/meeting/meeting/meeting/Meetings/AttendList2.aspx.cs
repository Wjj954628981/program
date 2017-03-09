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

namespace meeting.Meetings
{
    public partial class AttendList2 : System.Web.UI.Page
    {
        MeetingsBLL mbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            //ViewState["retu"] = Request.UrlReferrer.ToString();
            string Opera = Request.QueryString["Opera"];
            if(!IsPostBack)
            {
                if(Opera=="Check")
                {
                    int MId = int.Parse(Request.QueryString["MId"]);
                    AttendRepeater.DataSource = mbll.GetAttendList(MId);
                    AttendRepeater.DataBind();
                }
            }
        }
        protected void AttendRepeater_ItemCommand(object source, RepeaterCommandEventArgs e)
        {
            switch (e.CommandName)
            {
                case "Modify2":
                    string[] arg1 = e.CommandArgument.ToString().Split(',');
                    Response.Redirect("AttendAdd2.aspx?Opera=Edit&&PARTICIPATORId="+int.Parse(arg1[0])+"&&MId="+int.Parse(arg1[1]));
                    break;
                case "Delete2":
                    string[] arg2 = e.CommandArgument.ToString().Split(',');
                    int participator_id = int.Parse(arg2[0]);
                    int m_id = int.Parse(arg2[1]);
                    mbll.DeleteAttend(participator_id,m_id);
                    Response.Redirect("AttendList2.aspx");
                    break;
                case "Check2":
                    string[] arg3 = e.CommandArgument.ToString().Split(',');
                    Response.Redirect("AccompanyList2.aspx?Opera=Check&&PARTICIPATORId=" + int.Parse(arg3[0]) + "&&MId=" + int.Parse(arg3[1]));
                    break;
            }
        }
        protected void AttendRepeater_DataBound(object sender, RepeaterItemEventArgs e)
        {
            if (e.Item.ItemType == ListItemType.Item || e.Item.ItemType == ListItemType.AlternatingItem)
            {
                ((Button)e.Item.FindControl("btnDelete2")).Attributes.Add("onclick", "return confirm('该操作永久删除，确定操作？')");
            }
        }
        protected void AttendAdd_Click2(object sender, EventArgs e)
        {
            int MId = int.Parse(Request.QueryString["MId"]);
            Response.Redirect("AttendAdd2.aspx?Opera=Add&&MID="+MId);
        }
        protected void Return_Click2(object sender, EventArgs e)
        {
            Response.Redirect("MeetingList2.aspx");
            //Response.Redirect(ViewState["retu"].ToString()); 
        }
    }
}