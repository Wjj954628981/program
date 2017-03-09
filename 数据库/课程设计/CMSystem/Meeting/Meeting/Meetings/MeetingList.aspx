<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="MeetingList.aspx.cs" Inherits="Meeting.Meeting.MeetingList" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <h1>会议列表</h1>
        <asp:Repeater ID="MeetingRepeater" runat="server" OnItemCommand="MeetingRepeater_ItemCommand" OnItemDataBound="MeetingRepeater_DataBound">
            <HeaderTemplate>
                <table style="height:200px;width:100%">
                    <tr>
                        <th>会议编号</th>
                        <th>会议名称</th>
                        <th>会议参加人数</th>
                        <th>会议最多人数</th>
                        <th>会议主题</th>
                        <th>会议开始日期</th>
                        <th>会议结束日期</th>
                        <th>会议城市</th>
                        <th>会议地址</th>
                        <th>会议预定宾馆</th>
                        <th>操作</th>
                    </tr>
            </HeaderTemplate>
            <ItemTemplate>
                <tr>
                    <td><%# Eval("m_id") %></td>
                    <td><%# Eval("m_name") %></td>
                    <td><%# Eval("pre_num") %></td>
                    <td><%# Eval("max_num") %></td>
                    <td><%# Eval("theme") %></td>
                    <td><%# Eval("begin_date") %></td>
                    <td><%# Eval("end_date") %></td>
                    <td><%# Eval("m_city") %></td>
                    <td><%# Eval("m_address") %></td>
                    <td><%# Eval("h_name") %></td>
                    <td>
                        <asp:Button ID="btnModify" runat="server" CommandArgument='<%# Eval("m_id") %>' CommandName="Modify" Text="修改" />
                        <asp:Button ID="btnDelete" runat="server" CommandArgument='<%# Eval("m_id") %>' CommandName="Delete" Text="删除" />
                    </td>
                </tr>
            </ItemTemplate>
            <FooterTemplate>
                <tr id="noData" runat="server" visible="<%#MeetingRepeater.Items.Count==0%>">
                    <td colspan="8">没有相关数据</td>
                </tr>
                </table>
            </FooterTemplate>
        </asp:Repeater>
        <asp:Button ID="btnAdd" runat="server" Text="新增会议" OnClick="MeetingAdd_Click" Style="margin:20px; padding:6px;"/>
    </div>
    </form>
</body>
</html>
