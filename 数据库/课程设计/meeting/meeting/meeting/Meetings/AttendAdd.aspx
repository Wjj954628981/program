<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="AttendAdd.aspx.cs" Inherits="meeting.Meetings.AttendAdd" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>AttendAdd</title>
    <script src="js/jQuery.js"></script>
    <script src="js/bootstrap.js"></script>
    <link href="css/bootstrap.css" rel="stylesheet"/>
    <style type="text/css">
        .auto-style1 {
            height: 23px;
        }
        .auto-style2 {
            width: 75%;
            height: 23px;
        }
    </style>
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
    <h1 style="text-align:center">与会人员信息</h1>
        <table style="width:78%; padding:0;border-spacing:0; margin-left: 104px;">
        <tr>
            <td>
                <div style="padding:10px">
                    <table style="width:100%;padding:0;border-spacing:0">

                        
                         <tr>
                            <td class="auto-style1";style="width:25%">
                                &nbsp;&nbsp;&nbsp;
                                身份证
                            </td>
                            <td class="auto-style2">
                                <asp:TextBox ID="TxtID" runat="server" width="70%"></asp:TextBox>
                            </td>
                            <td class="auto-style1"><%# Eval("participator_id") %></td>
                        </tr>
                        <!--<tr>
                            <td class="auto-style1";style="width:25%">
                                &nbsp;&nbsp;
                                会议编号
                            </td>
                            <td class="auto-style2">
                                <asp:TextBox ID="TxtNumber" runat="server" width="70%"></asp:TextBox>
                            </td>
                        </tr>
                        <tr>
                            <td class="td_right";style="width:25%">
                                &nbsp;&nbsp;&nbsp;&nbsp;
                                开始日期
                            </td>
                            <td style="width:75%">
                                <asp:TextBox ID="TxtStartDate" runat="server" width="70%"></asp:TextBox>
                            </td>
                        </tr>-->
                        <tr>
                            <td class="auto-style1";style="width:25%">
                                &nbsp;&nbsp;
                                到达时间
                            </td>
                            <td class="auto-style2">
                                <asp:TextBox ID="TxtArriveTime" runat="server" width="70%"></asp:TextBox>
                            </td>
                        </tr>
                       <!-- <tr>
                            <td class="td_right";style="width:25%">
                                &nbsp;&nbsp;&nbsp;&nbsp;
                                结束日期
                            </td>
                            <td style="width:75%">
                                <asp:TextBox ID="TxtEndDate" runat="server" width="70%"></asp:TextBox>
                            </td>
                        </tr>-->
                        <tr>
                            <td class="td_right";style="width:25%">
                                &nbsp;&nbsp;
                                到达方式
                            </td>
                            <td style="width:75%">
                                <asp:TextBox ID="TxtArriveWay" runat="server" width="70%"></asp:TextBox>
                            </td>
                        </tr>
                        <tr>
                            <td class="auto-style1";style="width:25%">
                                &nbsp;&nbsp;
                                离开时间
                            </td>
                            <td class="auto-style2">
                                <asp:TextBox ID="TxtLeaveTime" runat="server" width="70%"></asp:TextBox>
                            </td>
                        </tr>
                        <tr>
                            <td class="auto-style1";style="width:25%">
                                &nbsp;&nbsp;
                                离开方式
                            </td>
                            <td class="auto-style2">
                                <asp:TextBox ID="TxtLeaveWay" runat="server" width="70%"></asp:TextBox>
                            </td>
                        </tr>
                        <tr>
                            <td class="td_right";style="width:25%">
                                &nbsp;&nbsp;
                                宾馆名称
                            </td>
                            <td style="width:75%">
                                <asp:TextBox ID="TxtHotelName" runat="server" width="70%" Height="16px"></asp:TextBox>
                            </td>
                        </tr>
                        <tr>
                            <td class="td_right";style="width:25%">
                                &nbsp;&nbsp;&nbsp;
                                房间号
                            </td>
                            <td style="width:75%">
                                <asp:TextBox ID="TxtRoomNumber" runat="server" width="70%"></asp:TextBox>
                            </td>
                        </tr>
                    </table>
                </div>
                <div style="padding:0px 10px 10px 400px">
                    <asp:Button ID="btnSave2" runat="server" TEXT="保存" OnClick="btnSave_Click2" style="margin:0px 10px" BorderColor="#FFFFCC" BorderStyle="Outset"/>
                    <asp:Button ID="btnCancel2" runat="server" TEXT="返回" OnClick="btnCancel_Click2" style="margin:0px 10px" BorderColor="#FFFFCC" BorderStyle="Outset"/>
                </div>
            </td>
        </tr>
        </table>
    </div>
    </form>

                   </div>

              </div>

         </div>

     </div>

</body>
</html>