﻿using System;
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
    public partial class MeeingList2 : System.Web.UI.Page
    {
        MeetingsBLL mbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                int USERId = int.Parse(Request.QueryString["USERId"]);
                string DId = mbll.GetDeptIDfromAdminID(USERId);
                MeetingRepeater.DataSource = mbll.GetDept_MeetingInfo(DId);
                MeetingRepeater.DataBind();
                //MeetingRepeater.DataSource = mbll.GetAllMeetingList();
                //MeetingRepeater.DataBind();
            }
        }
        protected void MeetingRepeater_ItemCommand(object source, RepeaterCommandEventArgs e)
        {
            switch (e.CommandName)
            {
                case "Modify":
                    Response.Redirect("MeetingAdd2.aspx?Opera=Edit&&MId=" + int.Parse(e.CommandArgument.ToString()));
                    break;
                case "Delete":
                    int m_id = int.Parse(e.CommandArgument.ToString());
                    mbll.DeleteMeeting(m_id);
                    Response.Redirect("MeetingList2.aspx");
                    break;
                case "Check":
                    Response.Redirect("AttendList2.aspx?Opera=Check&&MId=" + int.Parse(e.CommandArgument.ToString()));
                    break;
                case "Agenda":
                    Response.Redirect("Agenda2.aspx?MId=" + int.Parse(e.CommandArgument.ToString()));
                    break;
            }
        }
        protected void MeetingRepeater_DataBound(object sender, RepeaterItemEventArgs e)
        {
            if (e.Item.ItemType == ListItemType.Item || e.Item.ItemType == ListItemType.AlternatingItem)
            {
                ((Button)e.Item.FindControl("btnDelete")).Attributes.Add("onclick", "return confirm('该操作永久删除，确定操作？')");
            }
        }
        protected void MeetingAdd_Click(object sender, EventArgs e)
        {
            Response.Redirect("MeetingAdd2.aspx?Opera=Add");
        }

    }
}