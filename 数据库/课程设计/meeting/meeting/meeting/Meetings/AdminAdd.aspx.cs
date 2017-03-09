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

    public partial class OrduserAdd : System.Web.UI.Page
    {
        MeetingsBLL meetingbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                string Opera = Request.QueryString["Opera"];
                if (Opera == "Edit")
                {
                    int AId = int.Parse(Request.QueryString["AId"]);
                    MeetingModel.Admin admin = meetingbll.GetAdminInfo(AId);
                    Txtid.Text = admin.id.ToString();
                    Txtpsw.Text = admin.psw;
                    Txtdept_id.Text = admin.dept_id;
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
                    MeetingModel.Admin admin = new MeetingModel.Admin();
                    admin.id = int.Parse(Txtid.Text);
                    admin.psw = Txtpsw.Text;
                    admin.dept_id = Txtdept_id.Text;
                    if (meetingbll.AddAdmin(admin) > 0)
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
                    int AId = int.Parse(Request.QueryString["AId"]);
                    MeetingModel.Admin admin = meetingbll.GetAdminInfo(AId);
                    admin.id = int.Parse(Txtid.Text);
                    admin.psw = Txtpsw.Text;
                    admin.dept_id = Txtdept_id.Text;
                    if (meetingbll.UpdateAdmin(admin) > 0)
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
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('子管理员账号不能为空！');", true);
                Txtid.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(Txtpsw.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('密码不能为空！');", true);
                Txtpsw.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(Txtdept_id.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('所属部门不能为空！');", true);
                Txtdept_id.Focus();
                return false;
            }

            return true;
        }
        protected void btnCancel_Click(object sender, EventArgs e)
        {
            Response.Redirect("AdminList.aspx");
        }
    }
}


    