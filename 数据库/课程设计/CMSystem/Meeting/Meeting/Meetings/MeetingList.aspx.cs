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
    public partial class MeetingList : System.Web.UI.Page
    {
        //public int number;
        MeetingsBLL mbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            //number = 1;
            if(!IsPostBack)
            {
                MeetingRepeater.DataSource = mbll.GetAllMeetingList();
                MeetingRepeater.DataBind();
            }
        }
        protected void MeetingRepeater_ItemCommand(Object source,RepeaterCommandEventArgs e)
        {
            switch(e.CommandName)
            {
                case "Modify":
                    Response.Redirect("MeetingAdd.aspx?Opera=Edit&&MId=" + e.CommandArgument.ToString());
                    break;
                case "Delete":
                    string MId = e.CommandArgument.ToString();
                    mbll.DeleteMeeting(MId);
                    Response.Redirect("MeetingList.aspx");
                    break;

            }
        }
        protected void MeetingRepeater_DataBound(Object sender,RepeaterItemEventArgs e)
        {
            if(e.Item.ItemType==ListItemType.Item||e.Item.ItemType==ListItemType.AlternatingItem)
            {
                ((Button)e.Item.FindControl("btnDelete")).Attributes.Add
                    ("onclick", "return confirm('该操作将永久删除，确定删除？')");
            }
        }
        protected void MeetingAdd_Click(Object sender,EventArgs e)
        {
            Response.Redirect("MeetingAdd.aspx?Opera=Add");
        }
    }
}