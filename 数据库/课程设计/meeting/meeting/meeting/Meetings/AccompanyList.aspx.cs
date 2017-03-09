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
    public partial class AccompanyList : System.Web.UI.Page
    {
        MeetingsBLL mbll = new MeetingsBLL();

        //pid=int.Parse(Request.QueryString["PARTICIPATORId"]);
        //mid=int.Parse(Request.QueryString["MId"]);
        protected void Page_Load(object sender, EventArgs e)
        {
            if(!IsPostBack)
            {
                string Opera = Request.QueryString["Opera"];
                if (Opera == "Check")
                {
                    int MId = int.Parse(Request.QueryString["MId"]);
                    int PARTICIPATORId = int.Parse(Request.QueryString["PARTICIPATORId"]);
                    AccompanyRepeater.DataSource = mbll.GetAccompanyList(MId, PARTICIPATORId);
                    AccompanyRepeater.DataBind();
                }
            }
        }
        protected void AccompanyRepeater_ItemCommand(object source, RepeaterCommandEventArgs e)
        {
            switch (e.CommandName)
            {
                case "Modify3":
                    string[] arg1 = e.CommandArgument.ToString().Split(',');
                    Response.Redirect("AccompanyAdd.aspx?Opera=Edit&&PARTICIPATORId=" + int.Parse(arg1[0]) + "&&MId=" + int.Parse(arg1[1]) + "&&REId=" + int.Parse(arg1[2]));
                    break;
                case "Delete3":
                    string[] arg2 = e.CommandArgument.ToString().Split(',');
                    int participator_id = int.Parse(arg2[0]);
                    int m_id = int.Parse(arg2[1]);
                    int re_id = int.Parse(arg2[2]);
                    mbll.DeleteAccompany(participator_id, m_id,re_id);

                    int PARTICIPATORId = int.Parse(Request.QueryString["PARTICIPATORId"]);
                    int MId = int.Parse(Request.QueryString["MId"]);
                    Response.Redirect("AccompanyList.aspx?Opera=Check&&MId=" + MId + "&&PARTICIPATORId=" + PARTICIPATORId);
                    break;
            }
        }
        protected void AccompanyRepeater_DataBound(object sender, RepeaterItemEventArgs e)
        {
            if (e.Item.ItemType == ListItemType.Item || e.Item.ItemType == ListItemType.AlternatingItem)
            {
                ((Button)e.Item.FindControl("btnDelete3")).Attributes.Add("onclick", "return confirm('该操作永久删除，确定操作？')");
            }
        }
        protected void AccompanyAdd_Click3(object sender, EventArgs e)
        {
            int PARTICIPATORId = int.Parse(Request.QueryString["PARTICIPATORId"]);
            int MId = int.Parse(Request.QueryString["MId"]);
            Response.Redirect("AccompanyAdd.aspx?Opera=Add&&MId=" + MId + "&&PARTICIPATORId=" + PARTICIPATORId);
        }

        protected void Return_Click3(object sender, EventArgs e)
        {
            int MId = int.Parse(Request.QueryString["MId"]);
            Response.Redirect("AttendList.aspx?Opera=Check&&MId="+MId);
        }
    }
}