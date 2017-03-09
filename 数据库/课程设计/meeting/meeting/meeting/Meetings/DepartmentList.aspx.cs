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
    public partial class DepartmentList : System.Web.UI.Page
    {
        public int number;
        MeetingsBLL mbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            number = 1;
            if (!IsPostBack)
            {
                DepartmentRepeater.DataSource = mbll.GetAllDepartmentList();
                DepartmentRepeater.DataBind();
            }
        }
        protected void DepartmentRepeater_ItemCommand(object source, RepeaterCommandEventArgs e)
        {
            switch (e.CommandName)
            {
                case "Modify":
                    Response.Redirect("DepartmentAdd.aspx?Opera=Edit&&DId=" + e.CommandArgument.ToString());
                    break;
                case "Delete":
                    string dept_id = e.CommandArgument.ToString();
                    mbll.DeleteDepartment(dept_id);
                    Response.Redirect("DepartmentList.aspx");
                    break;
                case "Check":
                    Response.Redirect("MeetingList.aspx?Opera=Check&&DId=" + e.CommandArgument.ToString());
                    break;
            }
        }
        protected void DepartmentRepeater_DataBound(object sender, RepeaterItemEventArgs e)
        {
            if (e.Item.ItemType == ListItemType.Item || e.Item.ItemType == ListItemType.AlternatingItem)
            {
                ((Button)e.Item.FindControl("btnDelete")).Attributes.Add("onclick", "return confirm('该操作永久删除部门，确定操作？')");
            }
        }
        protected void DepartmentAdd_Click(object sender, EventArgs e)
        {
            Response.Redirect("DepartmentAdd.aspx?Opera=Add");
        }
    }
}