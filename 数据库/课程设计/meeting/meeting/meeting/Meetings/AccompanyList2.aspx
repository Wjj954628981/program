<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="AccompanyList2.aspx.cs" Inherits="meeting.Meetings.AccompanyList2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>AccompanyList</title>
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
    <h1 style="text-align:center">陪同人员列表</h1>
        <p style="text-align:center">&nbsp;</p>
        <asp:Repeater ID="AccompanyRepeater" runat="server" OnItemCommand="AccompanyRepeater_ItemCommand" OnItemDataBound="AccompanyRepeater_DataBound">
            <HeaderTemplate>
                <table style= "margin-left:80px;left:100px;height:200px;width:85%;border-collapse: collapse"border="1px">
                    <tr>
                        <th>与会人员身份证</th>
                        <th>会议编号</th>
                        <th>本人身份证</th>
                        <th>宾馆名称</th>
                        <th>房间号</th>
                        <th>操作</th>
                    </tr>
            </HeaderTemplate>
            <ItemTemplate>
                <tr>
                    <td style="text-align:center"><%# Eval("participator_id")%></td>
                    <td style="text-align:center"><%# Eval("m_id") %></td>
                    <td style="text-align:center"><%# Eval("re_id") %></td>
                    <td style="text-align:center"><%# Eval("h_name") %></td>
                    <td style="text-align:center"><%# Eval("roomnumber") %></td>
                    <td style="text-align:center">
                        <asp:Button ID="btnModify3" runat="server" CommandArgument='<%# Eval("participator_id")+","+ Eval("m_id")+","+Eval("re_id") %>' CommandName="Modify3" TEXT="修改"/>
                        <asp:Button ID="btnDelete3" runat="server" CommandArgument='<%# Eval("participator_id")+","+ Eval("m_id")+","+Eval("re_id") %>' CommandName="Delete3" TEXT="删除"/>
                    </td>
                </tr>
            </ItemTemplate>
            <FooterTemplate>
                <tr id="noData2" runat="server" visible="<%#AccompanyRepeater.Items.Count==0 %>">
                    <td colspan="8">没有相关数据</td>
                </tr> 
               </table>
            </FooterTemplate>
        </asp:Repeater>
        <div>
            <asp:Button ID="btnAdd3" runat="server" TEXT="新增陪同人员" OnClick="AccompanyAdd_Click3" style="margin:10px 10px 0px 385px; text-align:center" Height="26px" Width="76px" BorderColor="#FFFFCC"/>
            <asp:Button ID="btnReturn3" runat="server" TEXT="返回" OnClick="Return_Click3" style="margin:10px 10px 0px 385px; text-align:center" Height="26px" Width="76px" BorderColor="#FFFFCC"/>
        </div>
    </div>
    </form>

                   </div>

              </div>

         </div>

     </div>
</body>
</html>
