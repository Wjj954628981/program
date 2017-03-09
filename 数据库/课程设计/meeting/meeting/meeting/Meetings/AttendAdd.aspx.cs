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
    public partial class AttendAdd : System.Web.UI.Page
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
                    int PARTICIPATORId = int.Parse(Request.QueryString["PARTICIPATORId"]);
                    int MId = int.Parse(Request.QueryString["MId"]);
                    MeetingModel.attend attend = meetingbll.GetAttendInfo(PARTICIPATORId,MId);
                    TxtID.Text = attend.participator_id.ToString();
                    //TxtNumber.Text =attend.m_id.ToString();
                    TxtArriveTime.Text = Convert.ToDateTime(attend.arrive_date).ToString("yyyy-MM-dd HH:MM:ss");
                    TxtArriveWay.Text = attend.arrive_way;
                    TxtLeaveTime.Text = Convert.ToDateTime(attend.leave_date).ToString("yyyy-MM-dd HH:MM:ss");
                    TxtLeaveWay.Text = attend.leave_way;
                    TxtHotelName.Text = attend.h_name;
                    TxtRoomNumber.Text = attend.room_number.ToString();
                }
            }
        }
        protected void btnSave_Click2(object sender, EventArgs e)
        {
            MeetingsBLL meetingbll = new MeetingsBLL();
            string Opera = Request.QueryString["Opera"];
            if (CheckValue())
            {
                if (Opera == "Add")
                {
                    //新增与会人员
                    MeetingModel.attend attend = new MeetingModel.attend();
                    //int PARTICIPATORId = int.Parse(Request.QueryString["PARTICIPATORId"]);
                    int MId = int.Parse(Request.QueryString["MId"]);
                    //meeting.m_id = meetingbll.GetMeetingCount();
                    //meeting.m_id = meetingbll.max(m_id);
                    attend.m_id = MId;
                    attend.participator_id = int.Parse(TxtID.Text);
                    //attend.m_id=int.Parse(TxtNumber.Text);
                    attend.arrive_date=DateTime.Parse(TxtArriveTime.Text);
                    attend.arrive_way=TxtArriveWay.Text;
                    attend.leave_date=DateTime.Parse(TxtLeaveTime.Text);
                    attend.leave_way=TxtLeaveWay.Text;
                    attend.h_name=TxtHotelName.Text;
                    attend.room_number=int.Parse(TxtRoomNumber.Text);

                    if (meetingbll.AddAttend(attend) > 0)
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
                    //更改与会人员信息
                    int PARTICIPATORId = int.Parse(Request.QueryString["PARTICIPATORId"]);
                    int MId = int.Parse(Request.QueryString["MId"]);
                    MeetingModel.attend attend = meetingbll.GetAttendInfo(PARTICIPATORId,MId);

                    //attend.participator_id = int.Parse(TxtID.Text);
                    //attend.m_id=int.Parse(TxtNumber.Text);
                    attend.arrive_date=DateTime.Parse(TxtArriveTime.Text);
                    attend.arrive_way=TxtArriveWay.Text;
                    attend.leave_date=DateTime.Parse(TxtLeaveTime.Text);
                    attend.leave_way=TxtLeaveWay.Text;
                    attend.h_name=TxtHotelName.Text;
                    attend.room_number=int.Parse(TxtRoomNumber.Text);
                    if (meetingbll.UpdateAttend(attend) > 0)
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
            /*if (string.IsNullOrEmpty(TxtID.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('身份证不能为空！');", true);
                TxtID.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtNumber.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('会议编号不能为空！');", true);
                TxtNumber.Focus();
                return false;
            }*/
            if (string.IsNullOrEmpty(TxtArriveTime.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('到达时间不能为空！');", true);
                TxtArriveTime.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtArriveWay.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('到达方式不能为空！');", true);
                TxtArriveWay.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtLeaveTime.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('离开时间不能为空！');", true);
                TxtLeaveTime.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(TxtLeaveWay.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('离开方式不能为空！');", true);
                TxtLeaveWay.Focus();
                return false;
            }
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
        protected void btnCancel_Click2(object sender, EventArgs e)
        {
            //Response.Redirect("AttendList.aspx");
            Response.Redirect(ViewState["retu"].ToString()); 
        }
    }
}