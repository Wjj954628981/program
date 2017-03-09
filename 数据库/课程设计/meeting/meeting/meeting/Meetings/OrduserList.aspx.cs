using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using MeetingModel;
using MeetingDAL;
using MeetingBLL;


namespace Meeting.Meetings
{
    public partial class OrduserList : System.Web.UI.Page
    {
        public int number;
        MeetingsBLL mbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            number = 1;
            if (!IsPostBack)
            {
                OrduserRepeater.DataSource = mbll.GetAllOrduserList();
                OrduserRepeater.DataBind();
            }
        }

        protected void OrduserRepeater_ItemCommand(object source, RepeaterCommandEventArgs e)
        {
            switch (e.CommandName)
            {
                case "Modify":
                    Response.Redirect("OrduserAdd.aspx?Opera=Edit&&OId=" + int.Parse(e.CommandArgument.ToString()));
                    break;
                case "Delete":
                    int id = int.Parse(e.CommandArgument.ToString());
                    mbll.DeleteOrduser(id);
                    Response.Redirect("OrduserList.aspx");
                    break;
            }
        }
        protected void OrduserRepeater_DataBound(object sender, RepeaterItemEventArgs e)
        {
            if (e.Item.ItemType == ListItemType.Item || e.Item.ItemType == ListItemType.AlternatingItem)
            {
                ((Button)e.Item.FindControl("btnDelete")).Attributes.Add("onclick", "return confirm('该操作永久删除普通用户，确定操作？')");
            }
        }
        protected void AdminAdd_Click(object sender, EventArgs e)
        {
            Response.Redirect("OrduserAdd.aspx?Opera=Add");
        }
    }
}