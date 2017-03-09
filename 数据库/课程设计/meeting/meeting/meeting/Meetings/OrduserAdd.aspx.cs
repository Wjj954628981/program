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
    public partial class OrduserAdd1 : System.Web.UI.Page
    {
        MeetingsBLL meetingbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                string Opera = Request.QueryString["Opera"];
                if (Opera == "Edit")
                {
                    int OId = int.Parse(Request.QueryString["OId"]);
                    MeetingModel.Orduser ord = meetingbll.GetOrduserInfo(OId);
                    Txtid.Text = ord.id.ToString();
                    Txtpsw.Text = ord.e_mail;
                    Txtgender.Text = ord.gender;
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
                    //新增子管理员
                    MeetingModel.Orduser ord = new MeetingModel.Orduser();
                    ord.id = int.Parse(Txtid.Text);
                    ord.e_mail = Txtpsw.Text;
                    ord.gender = Txtgender.Text;
                    if (meetingbll.AddOrduser(ord) > 0)
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
                    //更改子管理员信息
                    int OId = int.Parse(Request.QueryString["OId"]);
                    MeetingModel.Orduser ord = meetingbll.GetOrduserInfo(OId);
                    ord.id = int.Parse(Txtid.Text);
                    ord.e_mail = Txtpsw.Text;
                    ord.gender = Txtgender.Text;
                    if (meetingbll.UpdateOrduser(ord) > 0)
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
            if (string.IsNullOrEmpty(Txtid.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('普通用户账号不能为空！');", true);
                Txtid.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(Txtpsw.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('密码不能为空！');", true);
                Txtpsw.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(Txtgender.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('性别不能为空！');", true);
                Txtgender.Focus();
                return false;
            }

            return true;
        }
        protected void btnCancel_Click(object sender, EventArgs e)
        {
            Response.Redirect("OrduserList.aspx");
        }
    }
}