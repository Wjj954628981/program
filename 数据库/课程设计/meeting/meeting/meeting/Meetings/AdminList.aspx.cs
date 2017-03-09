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
    public partial class Orduser : System.Web.UI.Page
    {
        public int number;
        MeetingsBLL mbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            number = 1;
            if (!IsPostBack)
            {
                AdminRepeater.DataSource = mbll.GetAllAdminList();
                AdminRepeater.DataBind();
            }
        }

        protected void AdminRepeater_ItemCommand(object source, RepeaterCommandEventArgs e)
        {
            switch (e.CommandName)
            {
                case "Modify":
                    Response.Redirect("AdminAdd.aspx?Opera=Edit&&AId=" + int.Parse(e.CommandArgument.ToString()));
                    break;
                case "Delete":
                    int id = int.Parse(e.CommandArgument.ToString());
                    mbll.DeleteAdmin(id);
                    Response.Redirect("AdminList.aspx");
                    break;
            }
        }
        protected void AdminRepeater_DataBound(object sender, RepeaterItemEventArgs e)
        {
            if (e.Item.ItemType == ListItemType.Item || e.Item.ItemType == ListItemType.AlternatingItem)
            {
                ((Button)e.Item.FindControl("btnDelete")).Attributes.Add("onclick", "return confirm('该操作永久删除子管理员，确定操作？')");
            }
        }
        protected void AdminAdd_Click(object sender, EventArgs e)
        {
            Response.Redirect("AdminAdd.aspx?Opera=Add");
        }
    }
}