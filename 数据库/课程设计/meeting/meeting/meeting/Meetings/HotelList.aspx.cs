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

    public partial class HotelList : System.Web.UI.Page
    {
        public int number;
        MeetingsBLL mbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            number = 1;
            if (!IsPostBack)
            {
                HotelRepeater.DataSource = mbll.GetAllHotelList();
                HotelRepeater.DataBind();
            }
        }
        protected void HotelRepeater_ItemCommand(object source, RepeaterCommandEventArgs e)
        {
            switch (e.CommandName)
            {
                case "Modify":
                    Response.Redirect("HotelAdd.aspx?Opera=Edit&&HId=" + int.Parse(e.CommandArgument.ToString()));
                    break;
                case "Delete":
                    string h_id = e.CommandArgument.ToString();
                    mbll.DeleteHotel(h_id);
                    Response.Redirect("HotelList.aspx");
                    break;
            }
        }
        protected void HotelRepeater_DataBound(object sender, RepeaterItemEventArgs e)
        {
            if (e.Item.ItemType == ListItemType.Item || e.Item.ItemType == ListItemType.AlternatingItem)
            {
                ((Button)e.Item.FindControl("btnDelete")).Attributes.Add("onclick", "return confirm('该操作永久删除，确定操作？')");
            }
        }
        protected void HotelAdd_Click(object sender, EventArgs e)
        {
            Response.Redirect("HotelAdd.aspx?Opera=Add");
        }
    }
}