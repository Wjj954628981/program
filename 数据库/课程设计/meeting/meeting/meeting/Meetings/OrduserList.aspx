<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="OrduserList.aspx.cs" Inherits="Meeting.Meetings.OrduserList" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>OrduserList</title>
    <script src="js/jQuery.js"></script>
    <script src="js/bootstrap.js"></script>
    <link href="css/bootstrap.css" rel="stylesheet"/>
</head>
<body background="Images/10.jpg">

     <div class="container-fluid">

         <div class="row-fluid">

              <div class="span2">

                   <div class="well sidebar-nav">

                       <ul>

                            <li><a href="MeetingList.aspx">会议</a></li>

                            <li><a href="DepartmentList.aspx">部门</a></li>

                            <li><a href="AdminList.aspx">子管理员</a></li>

                            <li><a href="OrduserList.aspx">普通人员</a></li>

                           <li><a href="HotelList.aspx">宾馆</a></li>

                            <li><a href="Login.aspx">退出登录</a></li>

                       </ul>

                   </div>

              </div>

              <div class="span10">

                   <div class="hero-unit">

                       <form id="form1" runat="server">
   <div>
        <h1 style="text-align:center">普通用户列表</h1>
        <asp:Repeater ID="OrduserRepeater" runat="server" OnItemCommand="OrduserRepeater_ItemCommand" OnItemDataBound="OrduserRepeater_DataBound">
           <HeaderTemplate>
               <table style= "margin-left:80px;left:100px;height:200px;width:85%;border-collapse: collapse"border="1px">
                    <tr>
                        <th>序号</th>
                        <th>普通用户账号</th>
                        <th>密码</th>
                        <th>性别</th>
                        <th>操作</th>
                   </tr>
            </HeaderTemplate>
            <ItemTemplate>
                <tr>
                    <td style="text-align:center">
                        <%=number %>
                        <%number++; %>
                    </td>
                    <td style="text-align:center"><%# Eval("id") %></td>
                    <td style="text-align:center"><%# Eval("e_mail") %></td>
                    <td style="text-align:center"><%# Eval("gender") %></td>
                    <td style="text-align:center">
                        <asp:Button ID="btnModify" runat="server" CommandArgument='<%# Eval("id") %>' CommandName="Modify" TEXT="修改"/>
                        <asp:Button ID="btnDelete" runat="server" CommandArgument='<%# Eval("id") %>' CommandName="Delete" TEXT="删除"/>
                    </td>
                </tr>
            </ItemTemplate>
            <FooterTemplate>
                <tr id="noData" runat="server" visible="<%#OrduserRepeater.Items.Count==0 %>">
                    <td colspan="8">没有相关数据</td>
                </tr> 
               </table>
            </FooterTemplate>
        </asp:Repeater>
        <asp:Button ID="btnAdd" runat="server" TEXT="新增用户" OnClick="AdminAdd_Click" style="margin:10px 10px 0px 626px; text-align:center" Height="26px" Width="76px" BorderColor="#FFFFCC"/>

    </form>

                   </div>

              </div>

         </div>

     </div>

</body>
</html>
