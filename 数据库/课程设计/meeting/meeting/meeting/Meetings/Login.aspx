<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Login.aspx.cs" Inherits="Meeting.Login" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Login</title>

        <!--<link rel="shortcut icon" type="image/x-icon" href="/favicon.ico" /> 
        <link rel="stylesheet" type="text/css" href="http://www.cssmoban.com/statics/css/code-demo.css" />
		<link rel="stylesheet" type="text/css" href="css/demo.css" />-->

        <style type="text/css">
            body 
            {
	            background:url(Images/10.jpg);
	            margin-left: 460px;
	            margin-top: 200px;
	            margin-right: 306px;
	            margin-bottom: 200px;
            }
            .auto-style1 {
                height: 50px;
            }
            .auto-style2 {
                height: 81px;
                width: 205px;
            }
            .auto-style3 {
                height: 81px;
                width: 133px;
            }
        </style>
</head>
<body>
    <form id="form1" runat="server">
       <div>
    <table width="411" border="0" cellpadding="0" cellspacing="0" style="height: 307px; margin-left: 0px;">
  <tr>
    <td colspan="3"  style="FILTER: dropshadow(color=#B4BBCF,offx=6,offy=6,positive=1)" align="center" class="auto-style1"><font face="楷体" color="#22DDDD" size="8"><b><i>会议系统</i></b></font>
    </td>
  </tr>
  <tr>
    <td height="50" colspan="3"  style="text-align: center">
        
        <asp:RadioButtonList ID="RadioButtonList" runat="server" RepeatDirection="Horizontal" Width="610px" OnSelectedIndexChanged="RadioButtonList_SelectedIndexChanged" OnTextChanged="RadioButtonList_TextChanged">
            <asp:ListItem style="FILTER: dropshadow(color=#B4BBCF,offx=6,offy=6,positive=1)" Value="0" Selected="True"><font face="楷体" color="#22DDDD" size="5"><b><i>超级管理员</i></b></font></asp:ListItem>
            <asp:ListItem style="FILTER: dropshadow(color=#B4BBCF,offx=6,offy=6,positive=1)" Value="1"><font face="楷体" color="#22DDDD" size="5"><b><i>子管理员</i></b></font></asp:ListItem>
            <asp:ListItem style="FILTER: dropshadow(color=#B4BBCF,offx=6,offy=6,positive=1)" Value="2"><font face="楷体" color="#22DDDD" size="5"><b><i>普通用户</i></b></font></asp:ListItem>
        </asp:RadioButtonList>
        
      </td>
  </tr>
  <tr>
    <td  class="auto-style3"></td>
    <td valign="top"  class="auto-style2">
        <table border="0" cellpadding="0" cellspacing="0" 
            style="height: 103px; width: 197px; margin-left: 13px;">
  <!--DWLayoutTable-->
            <tr>
                <td style="FILTER: dropshadow(color=#B4BBCF,offx=6,offy=6,positive=1)" align="left" height="27" valign="middle" width="80">
                    <font face="楷体" color="##22DDDD" size="4"><b><i>账&nbsp;&nbsp;号：</i></b></font>
                </td>
                <td align="left" colspan="2" valign="middle">
                    <asp:TextBox ID="txtUserid" runat="server" Width="100px"></asp:TextBox>
                    <asp:Label ID="lblVolidateUserName" runat="server" ForeColor="Red" Text="*" 
                        Visible="False"></asp:Label>
                </td>
            </tr>
            <tr>
                <td style="FILTER: dropshadow(color=#B4BBCF,offx=6,offy=6,positive=1)" align="left" height="27" valign="middle">
                    <font face="楷体" color="#22DDDD" size="4"><b><i>密&nbsp;&nbsp;码：</i></b></font>
                </td>
                <td align="left" colspan="2" valign="middle">
                    <asp:TextBox ID="txtPsw" runat="server" Width="100px" TextMode="Password"></asp:TextBox>
                    <asp:Label ID="lblVolidateUserPwd" runat="server" ForeColor="Red" Text="*" 
                        Visible="False"></asp:Label>
                </td>
            </tr>
            <tr>
                <td align="center" colspan="3" height="38" valign="middle">
                    <asp:Button ID="btnSure" runat="server" Text="确定" style="height: 26px" BackColor="#E0FFFF" OnClick="btnSure_Click"/>
                    <asp:Button ID="btnReset" runat="server" Text="重置" OnClick="btnReset_Click" BackColor="#E0FFFF" style="height: 26px" />
                    <asp:Button ID="btnRe" runat="server" Text="注册" OnClick="Button1_Click" BackColor="#E0FFFF" style="height: 26px" />
                    <!--<a class="large button blue" runat="server">Blue Button</a>-->
                </td>
            </tr>

        </table>
      </td>
    <td width="54"  class="style2"></td>
  </tr>
    </table>
    </form>
</body>
</html>


