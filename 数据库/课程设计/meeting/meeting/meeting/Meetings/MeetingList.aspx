<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="MeetingList.aspx.cs" Inherits="Meeting.Meeting.MeeingList" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>MeetingList</title>
    <script src="js/jQuery.js"></script>
    <script src="js/bootstrap.js"></script>
    <link href="css/bootstrap.css" rel="stylesheet"/>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
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
    <h1 style="text-align:center">会议列表</h1>
        <p style="text-align:center">&nbsp;</p>

        <asp:Repeater ID="MeetingRepeater" runat="server" OnItemCommand="MeetingRepeater_ItemCommand" OnItemDataBound="MeetingRepeater_DataBound">
           <HeaderTemplate>
               <table style= "margin-left:80px;left:100px;height:200px;width:85%;border-collapse: collapse"border="1px">
                    <tr>
                        <th>序号</th>
                        <th>会议名称</th>
                        <th>主题</th>
                        <th>开始时间</th>
                        <th>结束时间</th>
                        <th>所在城市</th>
                        <th>所在街道</th>
                        <th>门牌号</th>
                        <th>所属部门</th>
                        <th>操作</th>
                        <th>查看</th>
                   </tr>
            </HeaderTemplate>
            <ItemTemplate>
                <tr>
                    <td style="text-align:center"><%# Eval("m_id")%></td>
                    <td style="text-align:center"><%# Eval("m_name") %></td>
                    <td style="text-align:center"><%# Eval("theme") %></td>
                    <td style="text-align:center"><%# DateTime.Parse(Eval("begin_time").ToString()).ToString("yyyy-MM-dd HH:MM:ss") %></td>
                    <td style="text-align:center"><%# DateTime.Parse(Eval("end_time").ToString()).ToString("yyyy-MM-dd HH:MM:ss") %></td>
                    <td style="text-align:center"><%# Eval("m_city") %></td>
                    <td style="text-align:center"><%# Eval("m_street") %></td>
                    <td style="text-align:center"><%# Eval("m_number") %></td>
                    <td style="text-align:center"><%# Eval("dept_id") %></td>
                    <td style="text-align:center">
                        <asp:Button ID="btnModify" runat="server" CommandArgument='<%# Eval("m_id") %>' CommandName="Modify" TEXT="修改"/>
                        <asp:Button ID="btnDelete" runat="server" CommandArgument='<%# Eval("m_id") %>' CommandName="Delete" TEXT="删除"/>
                    </td>
                    <td style="text-align:center">
                        <asp:Button ID="btnCheck" runat="server" CommandArgument='<%# Eval("m_id") %>' CommandName="Check" TEXT="查看与会人员"/>
                        <asp:Button ID="btnAgenda" runat="server" CommandArgument='<%# Eval("m_id") %>' CommandName="Agenda" TEXT="查看会议日程"/>
                    </td>
                </tr>
            </ItemTemplate>
            <FooterTemplate>
                <tr id="noData" runat="server" visible="<%#MeetingRepeater.Items.Count==0 %>">
                    <td colspan="8">没有相关数据</td>
                </tr> 
               </table>
            </FooterTemplate>
        </asp:Repeater>
        <div>
            <asp:Button ID="btnAdd" runat="server" TEXT="新增会议" OnClick="MeetingAdd_Click" style="margin:10px 10px 0px 626px; text-align:center" Height="26px" Width="76px" BorderColor="#FFFFCC"/>
        </div>
    </div>
    </form>

                   </div>

              </div>

         </div>

     </div>

</body>
</html>