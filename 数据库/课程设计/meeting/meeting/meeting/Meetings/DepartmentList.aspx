<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="DepartmentList.aspx.cs" Inherits="Meeting.Meetings.DepartmentList" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>DepartmentList</title>
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
        <h1 style="text-align:center">部门列表</h1>
        <asp:Repeater ID="DepartmentRepeater" runat="server" OnItemCommand="DepartmentRepeater_ItemCommand" OnItemDataBound="DepartmentRepeater_DataBound">
           <HeaderTemplate>
               <table style= "margin-left:80px;left:100px;height:200px;width:85%;border-collapse: collapse"border="1px">
                    <tr>
                        <th>序号</th>
                        <th>部门编号</th>
                        <th>部门名称</th>
                        <th>操作</th>
                   </tr>
            </HeaderTemplate>
            <ItemTemplate>
                <tr>
                    <td style="text-align:center">
                        <%=number %>
                        <%number++; %>
                    </td>
                    <td style="text-align:center"><%# Eval("dept_id") %></td>
                    <td style="text-align:center"><%# Eval("dept_name") %></td>
                    <td style="text-align:center">
                        <asp:Button ID="btnModify" runat="server" CommandArgument='<%# Eval("dept_id") %>' CommandName="Modify" TEXT="修改"/>
                        <asp:Button ID="btnDelete" runat="server" CommandArgument='<%# Eval("dept_id") %>' CommandName="Delete" TEXT="删除"/>
                        <asp:Button ID="btnCheckMeeting" runat="server" CommandArgument='<%# Eval("dept_id") %>' CommandName="Check" TEXT="查看会议"/>
                    </td>
                </tr>
            </ItemTemplate>
            <FooterTemplate>
                <tr id="noData" runat="server" visible="<%#DepartmentRepeater.Items.Count==0 %>">
                    <td colspan="8">没有相关数据</td>
                </tr> 
               </table>
            </FooterTemplate>
        </asp:Repeater>
        <asp:Button ID="btnAdd" runat="server" TEXT="新增部门" OnClick="DepartmentAdd_Click" style="margin:10px 10px 0px 626px; text-align:center" Height="26px" Width="76px" BorderColor="#FFFFCC"/>

    </div>
    </form>

                   </div>

              </div>

         </div>

     </div>

</body>
</html>
