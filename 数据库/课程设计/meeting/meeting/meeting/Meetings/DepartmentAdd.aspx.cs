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
    public partial class DepartmentAdd : System.Web.UI.Page
    {
        MeetingsBLL meetingbll = new MeetingsBLL();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                string Opera = Request.QueryString["Opera"];
                if (Opera == "Edit")
                {
                    string DId = Request.QueryString["DId"];
                    MeetingModel.Department dept = meetingbll.GetDepartmentInfo(DId);
                    Txtdept_id.Text = dept.dept_id;
                    Txtdept_name.Text = dept.dept_name;
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
                    MeetingModel.Department dept = new MeetingModel.Department();
                    dept.dept_id = Txtdept_id.Text;
                    dept.dept_name = Txtdept_name.Text;
                    
                    if (meetingbll.AddDepartment(dept) > 0)
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
                    string DId = Request.QueryString["DId"];
                    MeetingModel.Department dept = meetingbll.GetDepartmentInfo(DId);
                    dept.dept_id = Txtdept_id.Text;
                    dept.dept_name = Txtdept_name.Text;

                    if (meetingbll.UpdateDepartment(dept) > 0)
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
            if (string.IsNullOrEmpty(Txtdept_id.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('部门编号不能为空！');", true);
                Txtdept_id.Focus();
                return false;
            }
            //if (string.IsNullOrEmpty(Txtdept_name.Text))
            //{
            //    ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('部门名称不能为空！');", true);
            //    Txtdept_name.Focus();
            //    return false;
            //}


            return true;
        }
        protected void btnCancel_Click(object sender, EventArgs e)
        {
            Response.Redirect("DepartmentList.aspx");
        }
        
    }
}