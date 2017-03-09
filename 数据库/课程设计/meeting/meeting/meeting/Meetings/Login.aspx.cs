using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.OleDb;
using System.Data;
using MeetingModel;
using MeetingBLL;
using MeetingDAL;
using System.Data.SqlClient;
using System.Configuration;

namespace Meeting
{

    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!this.IsPostBack)
            {
            }
        }
        protected void RadioButtonList_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        protected void RadioButtonList_TextChanged(object sender, EventArgs e)
        {

        }

        protected void btnSure_Click(object sender, EventArgs e)
        {
            if (this.RadioButtonList.SelectedValue.Equals("0") && CheckValue())
            {
                string strConnection = @"Data Source=LENOVO-PC;Database=meeting;Trusted_Connection=true;Persist Security Info=True";
                SqlConnection objConnection = new SqlConnection(strConnection);
                objConnection.Open();
                SqlCommand cmd = new SqlCommand("select * from Supadmin where id=" + txtUserid.Text.Trim() + "", objConnection);
                string sql = "select * from Supadmin where id=" + txtUserid.Text + "and psw='" + txtPsw.Text + "'";
                cmd.CommandText = sql;
                /*   
                 ***********************************************************************************************   
                 *判断是否有此ID,ExecuteScalar() return the first column of the first row in the result set.   
                 */
                if (cmd.ExecuteScalar() == null)//无此用户     
                {
                    Response.Write("<script>alert('账号或密码错误')</script>");
                }
                else
                {

                    Response.Write("<script>alert('登录成功')</script>");
                    Response.Redirect("superadmin.aspx");
                }
            }
            if (this.RadioButtonList.SelectedValue.Equals("1") && CheckValue())
            {
                string strConnection = @"Data Source=LENOVO-PC;Database=meeting;Trusted_Connection=true;Persist Security Info=True";
                SqlConnection objConnection = new SqlConnection(strConnection);
                objConnection.Open();
                SqlCommand cmd = new SqlCommand("select * from Admin where id=" + txtUserid.Text.Trim() + "", objConnection);
                string sql = "select * from Admin where id=" + txtUserid.Text + "and psw='" + txtPsw.Text + "'";
                cmd.CommandText = sql;
                /*   
                 ***********************************************************************************************   
                 *判断是否有此ID,ExecuteScalar() return the first column of the first row in the result set.   
                 */
                if (cmd.ExecuteScalar() == null)//无此用户     
                {
                    Response.Write("<script>alert('账号或密码错误')</script>");
                }
                else
                {
                    Response.Write("<script>alert('登录成功')</script>");
                    //Response.Redirect("admin.aspx");
                    Response.Redirect("MeetingList2.aspx?&&USERId=" + int.Parse(txtUserid.Text.Trim()));
                }
            }
            if (this.RadioButtonList.SelectedValue.Equals("2") && CheckValue())
            {
                string strConnection = @"Data Source=LENOVO-PC;Database=meeting;Trusted_Connection=true;Persist Security Info=True";
                SqlConnection objConnection = new SqlConnection(strConnection);
                objConnection.Open();
                SqlCommand cmd = new SqlCommand("select * from Orduser where id=" + txtUserid.Text.Trim() + "", objConnection);
                string sql = "select * from Orduser where id=" + txtUserid.Text + "and e_mail='" + txtPsw.Text + "'";
                cmd.CommandText = sql;
                /*   
                 ***********************************************************************************************   
                 *判断是否有此ID,ExecuteScalar() return the first column of the first row in the result set.   
                 */
                if (cmd.ExecuteScalar() == null)//无此用户     
                {
                    Response.Write("<script>alert('账号或密码错误')</script>");
                }
                else
                {
                    Response.Write("<script>alert('登录成功')</script>");
                    Response.Redirect("OrduserAdd3.aspx?Opera=Edit&&OId=" + int.Parse(txtUserid.Text.Trim()));
                }
            }
        }
        

        private bool CheckValue()
        {
            if (string.IsNullOrEmpty(txtUserid.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('请输入账号');", true);
                txtUserid.Focus();
                return false;
            }
            if (string.IsNullOrEmpty(txtPsw.Text))
            {
                ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('请输入密码');", true);
                txtPsw.Focus();
                return false;
            }

            String tempUserid = txtUserid.Text;
            for (int i = 0; i < tempUserid.Length; i++) {
                if (tempUserid[i] > '9' || tempUserid[i] < '0') {
                    ClientScript.RegisterStartupScript(this.GetType(), "alert", "alert('账号只包含数字，请重新输入');", true);
                    txtUserid.Text = "";
                    txtUserid.Focus();
                    return false;
                }
            }
                
            return true;
        }
        protected void btnReset_Click(object sender, EventArgs e)
        {
            txtUserid.Text = "";
            txtPsw.Text = "";
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string strConnection = @"Data Source=LENOVO-PC;Database=meeting;Trusted_Connection=true;Persist Security Info=True";
            SqlConnection objConnection = new SqlConnection(strConnection);
            objConnection.Open();
            if (this.RadioButtonList.SelectedValue.Equals("2") && CheckValue())
            {
                SqlCommand cmd = new SqlCommand("insert into Orduser (id,gender,e_mail) values (" + int.Parse(txtUserid.Text.Trim()) + ",'m','" + txtPsw.Text + "')", objConnection);
                int i = cmd.ExecuteNonQuery();
                Response.Write("<script>alert('注册成功')</script>");
            }
            else
            {
                Response.Write("<script>alert('注册失败')</script>");
            }
            objConnection.Close();
            if (this.RadioButtonList.SelectedValue.Equals("0") || this.RadioButtonList.SelectedValue.Equals("1"))
            {
                Response.Write("<script>alert('只能普通用户进行注册')</script>");
            }
        }
    }
}


