<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Agenda2.aspx.cs" Inherits="Meeting.Meetings.MeeingtAgendas2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Agenda</title>
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

                            <li><a href="MeetingList2.aspx">会议</a></li>

                            <li><a href="HotelList2.aspx">宾馆</a></li>

                            <li><a href="Login.aspx">退出登录</a></li>

                       </ul>

                   </div>

              </div>

              <div class="span10">

                   <div class="hero-unit">

                       <form id="form1" runat="server">
    <div>
    <h1 style="text-align:center">日程</h1>
        <asp:Repeater ID="AgendaRepeater" runat="server" OnItemCommand="AgendaRepeater_ItemCommand" OnItemDataBound="AgendaRepeater_DataBound">
           <HeaderTemplate>
               <table style= "margin-left:80px;left:100px;height:200px;width:85%;border-collapse: collapse"border="1px">
                    <tr>
                        <th>开始时间</th>
                        <th>结束时间</th>
                        <th>具体事项</th>
                        <th>操作</th>
                   </tr>
            </HeaderTemplate>
            <ItemTemplate>
                <tr>
                    <td style="text-align:center"><%# DateTime.Parse(Eval("starttime").ToString()).ToString("yyyy-MM-dd HH:MM:ss") %></td>
                    <td style="text-align:center"><%# DateTime.Parse(Eval("endtime").ToString()).ToString("yyyy-MM-dd HH:MM:ss") %></td>
                    <td style="text-align:center"><%# Eval("detail") %></td>
                    <td style="text-align:center">
                        <asp:Button ID="btnModify" runat="server" CommandArgument='<%# Eval("agenda_number") %>' CommandName="Modify" TEXT="修改"/>
                        <asp:Button ID="btnDelete" runat="server" CommandArgument='<%# Eval("agenda_number") %>' CommandName="Delete" TEXT="删除"/>
                        
                    </td>
                </tr>
            </ItemTemplate>
            <FooterTemplate>
                <tr id="noData" runat="server" visible="<%#AgendaRepeater.Items.Count==0 %>">
                    <td colspan="8">没有相关数据</td>
                </tr> 
               </table>
            </FooterTemplate>
        </asp:Repeater>
        <asp:Button ID="btnAdd" runat="server" TEXT="新增日程" OnClick="Add_Click" style="margin:10px 10px 0px 385px; text-align:center" Height="26px" Width="76px" BorderColor="#FFFFCC"/>
            <asp:Button ID="btnBack" runat="server" TEXT="返回" OnClick="Back_Click" style="margin:10px 10px 0px 385px; text-align:center" Height="26px" Width="76px" BorderColor="#FFFFCC"/>
    </div>
    </form>

                   </div>

              </div>

         </div>

     </div>

</body>
</html>
