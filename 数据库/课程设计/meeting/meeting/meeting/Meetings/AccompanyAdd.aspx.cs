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
    public partial class AccompanyAdd : System.Web.UI.Page
    {
        MeetingsBLL meetingbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            if(!IsPostBack)
            {
                ViewState["retu"] = Request.UrlReferrer.ToString();
                string Opera = Request.QueryString["Opera"];
                if (Opera == "Edit")
                {
                    int MId = int.Parse(Request.QueryString["MId"]);
                    int REId = int.Parse(Request.QueryString["REId"]);
                    int PARTICIPATORId = int.Parse(Request.QueryString["PARTICIPATORId"]);
                    
                    MeetingModel.accompany accompany = meetingbll.GetAccompanyInfo(PARTICIPATORId, MId,REId);
                    //TxtID1.Text = accompany.participator_id.ToString();
                    //TxtNumber.Text = accompany.m_id.ToString();
                    TxtID2.Text = accompany.re_id.ToString();
                    TxtHotelName.Text = accompany.h_name;
                    TxtRoomNumber.Text = accompany.roomnumber.ToString();
                }
            }
        }
        protected void btnSave_Click3(object sender, EventArgs e)
        {
            MeetingsBLL meetingbll = new MeetingsBLL();
            string Opera = Request.QueryString["Opera"];
            if (CheckValue())
            {
                if (Opera == "Add")
                {
                    //新增陪同人员
                    MeetingModel.accompany accompany = new MeetingModel.accompany();
                    int MId = int.Parse(Request.QueryString["MId"]);
                    int PARTICIPATORId = int.Parse(Request.QueryString["PARTICIPATORId"]);
                    //int MId = 6; ;
                   // int PARTICIPATORId = 1414;
                    //int REId = int.Parse(Request.QueryString["REId"]);
                    //meeting.m_id = meetingbll.GetMeetingCount();
                    //meeting.m_id = meetingbll.max(m_id);
                    accompany.participator_id = PARTICIPATORId;
                    accompany.m_id = MId;
                    accompany.re_id = int.Parse(TxtID2.Text);
                    accompany.h_name = TxtHotelName.Text;
                    accompany.roomnumber = int.Parse(TxtRoomNumber.Text);

                    if (meetingbll.AddAccompany(accompany) > 0)
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
                    //更改陪同人员信息
                    int PARTICIPATORId = int.Parse(Request.QueryString["PARTICIPATORId"]);
                    int MId = int.Parse(Request.QueryString["MId"]);
                    int REId = int.Parse(Request.QueryString["REId"]);
                    MeetingModel.accompany accompany = meetingbll.GetAccompanyInfo(PARTICIPATORId, MId,REId);

                    //accompany.participator_id = int.Parse(TxtID1.Text);
                    //accompany.m_id = int.Parse(TxtNumber.Text);
                    //accompany.re_id = int.Parse(TxtID2.Text);
                    accompany.h_name = TxtHotelName.Text;
                    accompany.roomnumber = int.Parse(TxtRoomNumber.Text);
                    if (meetingbll.UpdateAccompany(accompany) > 0)
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
            /*if (string.IsNullOrEmpty(TxtID1.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('与会人员身份证不能为空！');", true);
                TxtID1.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtNumber.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('会议编号不能为空！');", true);
                TxtNumber.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtID2.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('陪同人员身份证不能为空！');", true);
                TxtID2.Focus();
                return false;
            }*/
            if (string.IsNullOrEmpty(TxtHotelName.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('宾馆名称不能为空！');", true);
                TxtHotelName.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtRoomNumber.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('房间号不能为空！');", true);
                TxtRoomNumber.Focus();
                return false;
            }
            return true;
        }
        protected void btnCancel_Click3(object sender, EventArgs e)
        {
            //Response.Redirect("AttendList.aspx");
            Response.Redirect(ViewState["retu"].ToString());
        }
    }
}