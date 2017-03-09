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
    public partial class HotelAdd : System.Web.UI.Page
    {
        MeetingsBLL meetingbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                string Opera = Request.QueryString["Opera"];
                if (Opera == "Edit")
                {
                    String HId = Request.QueryString["HId"];
                    MeetingModel.Hotel hotel = meetingbll.GetHotelInfo(HId);
                    Txth_name.Text = hotel.h_name;
                    Txtstreet.Text = hotel.h_street;
                    Txtphone_number.Text = hotel.phone_number;
                }

            }
        }
        protected void btnSave_Click(object sender, EventArgs e)
        {
            MeetingsBLL meetingbll = new MeetingsBLL();
            string Opera = Request.QueryString["Opera"];
            if (CheckValue())
            {
                if (Opera == "Add")
                {
                    //新增宾馆
                    MeetingModel.Hotel hotel = new MeetingModel.Hotel();
                    hotel.h_name = Txth_name.Text;
                    hotel.h_street = Txtstreet.Text;
                    hotel.phone_number = Txtphone_number.Text;
                    if (meetingbll.AddHotel(hotel) > 0)
                    {
                        Response.Write("<script>alert('添加成功')</script>");
                    }
                    else
                    {
                        Response.Write("<script>alert('添加失败')</script>");
                    }
                }
                else
                {
                    //更改宾馆信息
                    string HId = Request.QueryString["HId"];
                    MeetingModel.Hotel hotel = meetingbll.GetHotelInfo(HId);
                    
                    hotel.h_name = Txth_name.Text;
                    hotel.h_street = Txtstreet.Text;
                    hotel.phone_number = Txtphone_number.Text;
                    if (meetingbll.UpdateHotel(hotel) > 0)
                    {
                        Response.Write("<script>alert('修改成功')</script>");
                    }
                    else
                    {
                        Response.Write("<script>alert('修改失败')</script>");
                    }
                }
            }
        }

        private bool CheckValue()
        {
            if (string.IsNullOrEmpty(Txth_name.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('宾馆名称不能为空！');", true);
                Txth_name.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(Txtstreet.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('宾馆地址不能为空！');", true);
                Txtstreet.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(Txtphone_number.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('宾馆电话不能为空！');", true);
                Txtphone_number.Focus();
                return false;
            }

            return true;
        }
        protected void btnCancel_Click(object sender, EventArgs e)
        {
            Response.Redirect("HotelList.aspx");
        }
    }
}