<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="AttendList.aspx.cs" Inherits="meeting.Meetings.AttendList" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>AttendList</title>
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
    <h1 style="text-align:center">与会人员列表</h1>
        <p style="text-align:center">&nbsp;</p>
        <asp:Repeater ID="AttendRepeater" runat="server" OnItemCommand="AttendRepeater_ItemCommand" OnItemDataBound="AttendRepeater_DataBound">
            <HeaderTemplate>
                <table style= "margin-left:80px;left:100px;height:200px;width:85%;border-collapse: collapse"border="1px">
                    <tr>
                        <th>身份证</th>
                        <th>会议编号</th>
                        <th>到达时间</th>
                        <th>到达方式</th>
                        <th>离开时间</th>
                        <th>离开方式</th>
                        <th>宾馆名称</th>
                        <th>房间号</th>
                        <th>操作</th>
                        <td>查看</td>
                    </tr>
            </HeaderTemplate>
            <ItemTemplate>
                <tr>
                    <td style="text-align:center"><%# Eval("participator_id")%></td>
                    <td style="text-align:center"><%# Eval("m_id") %></td>
                    <td style="text-align:center"><%# DateTime.Parse(Eval("arrive_date").ToString()).ToString("yyyy-MM-dd HH:MM:ss") %></td>
                    <td style="text-align:center"><%# Eval("arrive_way") %></td>
                    <td style="text-align:center"><%# DateTime.Parse(Eval("leave_date").ToString()).ToString("yyyy-MM-dd HH:MM:ss") %></td>
                    <td style="text-align:center"><%# Eval("leave_way") %></td>
                    <td style="text-align:center"><%# Eval("h_name") %></td>
                    <td style="text-align:center"><%# Eval("room_number") %></td>
                    <td style="text-align:center">
                        <asp:Button ID="btnModify2" runat="server" CommandArgument='<%# Eval("participator_id")+","+Eval("m_id") %>' CommandName="Modify2" TEXT="修改"/>
                        <asp:Button ID="btnDelete2" runat="server" CommandArgument='<%# Eval("participator_id")+","+Eval("m_id") %>' CommandName="Delete2" TEXT="删除"/>
                    </td>
                    <td style="text-align:center">
                        <asp:Button ID="btnPerson2" runat="server" CommandArgument='<%# Eval("participator_id")+","+Eval("m_id") %>' CommandName="Check2" TEXT="陪同人员"/>
                    </td>
                </tr>
            </ItemTemplate>
            <FooterTemplate>
                <tr id="noData2" runat="server" visible="<%#AttendRepeater.Items.Count==0 %>">
                    <td colspan="8">没有相关数据</td>
                </tr> 
               </table>
            </FooterTemplate>
        </asp:Repeater>
        <div>
            <asp:Button ID="btnAdd2" runat="server" TEXT="新增与会人员" OnClick="AttendAdd_Click2" style="margin:10px 10px 0px 385px; text-align:center" Height="26px" Width="76px" BorderColor="#FFFFCC"/>
            <asp:Button ID="btnReturn2" runat="server" TEXT="返回" OnClick="Return_Click2" style="margin:10px 10px 0px 385px; text-align:center" Height="26px" Width="76px" BorderColor="#FFFFCC"/>
        </div>
    </div>
    </form>

                   </div>

              </div>

         </div>

     </div>

</body>
</html>