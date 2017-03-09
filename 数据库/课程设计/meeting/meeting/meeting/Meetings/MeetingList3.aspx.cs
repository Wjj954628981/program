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
    public partial class MeeingList3 : System.Web.UI.Page
    {
        MeetingsBLL mbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                if (!IsPostBack)
                {
                    string Opera = Request.QueryString["Opera"];
                    if (Opera == "Check")
                    {
                        string DId = Request.QueryString["DId"];
                        MeetingRepeater.DataSource = mbll.GetDept_MeetingInfo(DId);
                        MeetingRepeater.DataBind();
                    }
                    else
                    {
                        MeetingRepeater.DataSource = mbll.GetAllMeetingList();
                        MeetingRepeater.DataBind();
                    }

                }
                //MeetingRepeater.DataSource = mbll.GetAllMeetingList();
                //MeetingRepeater.DataBind();
            }
        }
        protected void MeetingRepeater_ItemCommand(object source, RepeaterCommandEventArgs e)
        {
           
        }
        protected void MeetingRepeater_DataBound(object sender, RepeaterItemEventArgs e)
        {

        }
        protected void MeetingAdd_Click(object sender, EventArgs e)
        {
           // Response.Redirect("MeetingAdd.aspx?Opera=Add");
        }

    }
}