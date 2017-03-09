<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="MeetingAdd.aspx.cs" Inherits="Meeting.Meeting.MeetingAdd" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h1>会议详情</h1>
        <table style="height:200px;width:100%" border="0" class="list_table3">
            <tr>
                <td>
                    <div style="padding:10px">
                        <table style="height:200px;width:100%" border="0" class="list_table2">
                            <tr>
                                <td class="td_right" style="width:25%">
                                    会议编号
                                </td>
                                <td style="width:75%">
                                    <asp:TextBox ID="txtrank" runat="server" Width="90%"></asp:TextBox>
                                </td>
                            </tr>
                            <tr>
                                <td class="td_right" style="width:25%">
                                    会议名称
                                </td>
                                <td style="width:75%">
                                    <asp:TextBox ID="txtTitle" runat="server" Width="90%"></asp:TextBox>
                                </td>
                            </tr>
                            <tr>
                                <td class="td_right" style="width:25%">
                                    会议参加人数
                                </td>
                                <td style="width:75%">
                                    <asp:TextBox ID="txtpnum" runat="server" Width="90%"></asp:TextBox>
                                </td>
                            </tr>
                            <tr>
                                <td class="td_right" style="width:25%">
                                    会议最多人数
                                </td>
                                <td style="width:75%">
                                    <asp:TextBox ID="txtmnum" runat="server" Width="90%"></asp:TextBox>
                                </td>
                            </tr>
                            <tr>
                                <td class="td_right" style="width:25%">
                                    会议主题
                                </td>
                                <td style="width:75%">
                                    <asp:TextBox ID="txttheme" runat="server" Width="90%"></asp:TextBox>
                                </td>
                            </tr>
                            <tr>
                                <td class="td_right" style="width:25%">
                                    会议开始日期
                                </td>
                                <td style="width:75%">
                                    <asp:TextBox ID="txtbd" runat="server" Width="90%"></asp:TextBox>
                                </td>
                            </tr>
                            <tr>
                                <td class="td_right" style="width:25%">
                                    会议结束日期
                                </td>
                                <td style="width:75%">
                                    <asp:TextBox ID="txted" runat="server" Width="90%"></asp:TextBox>
                                </td>
                            </tr>
                            <tr>
                                <td class="td_right" style="width:25%">
                                    会议城市
                                </td>
                                <td style="width:75%">
                                    <asp:TextBox ID="txtcity" runat="server" Width="90%"></asp:TextBox>
                                </td>
                            </tr>
                            <tr>
                                <td class="td_right" style="width:25%">
                                    会议地址
                                </td>
                                <td style="width:75%">
                                    <asp:TextBox ID="txtaddress" runat="server" Width="90%"></asp:TextBox>
                                </td>
                            </tr>
                            <tr>
                                <td class="td_right" style="width:25%">
                                    会议预定宾馆
                                </td>
                                <td style="width:75%">
                                    <asp:TextBox ID="txthotel" runat="server" Width="90%"></asp:TextBox>
                                </td>
                            </tr>
                        </table>
                    </div>
                    <div style="padding:0px 10px 10px;text-align:center">
                        <asp:Button ID="btnSave" runat="server" Text="保存" OnClick="btnSave_Click" Style="margin: 0 10px;" />
                        <asp:Button ID="btnCancel" runat="server" Text="返回" OnClick="btnCancel_Click" Style="margin: 0 10px;" />
                    </div>
                </td>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>
