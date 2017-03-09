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
    public partial class MeeingtAgendas2 : System.Web.UI.Page
    {
        public int number1;
        AgendaBLL agendabll = new AgendaBLL();
        public int MID1;
        protected void Page_Load(object sender, EventArgs e)
        {
            number1 = 1;
            if (!IsPostBack)
            {
                 MID1 = int.Parse(Request.QueryString["MId"]);
                 AgendaRepeater.DataSource = agendabll.GetAgendaList(MID1);
                 AgendaRepeater.DataBind();
            }
        }
        protected void AgendaRepeater_ItemCommand(object source, RepeaterCommandEventArgs e)
        {
            switch (e.CommandName)
            {
                case "Modify":
                    MID1 = int.Parse(Request.QueryString["MId"]);
                    Response.Redirect("AgendaAdd2.aspx?Opera=Edit&&agendanumber=" + int.Parse(e.CommandArgument.ToString())+"&MID2="+MID1);
                    break;
                case "Delete":
                    int agendanumber = int.Parse(e.CommandArgument.ToString());
                    agendabll.DeleteAgenda(agendanumber);
                    MID1 = int.Parse(Request.QueryString["MId"]);
                    Response.Redirect("Agenda2.aspx?MId="+MID1);
                    break;
                //case "Add":
                //    Response.Redirect("AgendaAdd.aspx?Opera=Add&&MID="+ int.Parse(e.CommandArgument.ToString()));
                //    break;
            }
        }
        protected void AgendaRepeater_DataBound(object sender, RepeaterItemEventArgs e)
        {
            if (e.Item.ItemType == ListItemType.Item || e.Item.ItemType == ListItemType.AlternatingItem)
            {
                ((Button)e.Item.FindControl("btnDelete")).Attributes.Add("onclick", "return confirm('该操作永久删除，确定操作？')");
            }
        }
        protected void Add_Click(object sender, EventArgs e)
        {
            MID1 = int.Parse(Request.QueryString["MId"]);
            Response.Redirect("AgendaAdd2.aspx?Opera=Add&&MID2="+MID1);
        }
        protected void Back_Click(object sender, EventArgs e)
        {
            Response.Redirect("MeetingList2.aspx");
        }
    }
}