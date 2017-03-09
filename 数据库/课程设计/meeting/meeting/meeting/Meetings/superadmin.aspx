<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="superadmin.aspx.cs" Inherits="meeting.Meetings.superadmin" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>superadmin</title>
    <!--<script src="js/jQuery.js"></script>
    <script src="js/jQuery.js"></script>
    <script src="js/bootstrap.js"></script>-->
    <link href="css/bootstrap.css" rel="stylesheet"/>
    <!--<script>
        function clientSideInclude(id, url) {
            var req = false;

            // Safari, Firefox, 及其他非微软浏览器
            if (window.XMLHttpRequest) {
                try {
                    req = new XMLHttpRequest();
                } catch (e) {
                    req = false;
                }
            } else if (window.ActiveXObject) {

                // For Internet Explorer on Windows
                try {
                    req = new ActiveXObject("Msxml2.XMLHTTP");
                } catch (e) {
                    try {
                        req = new ActiveXObject("Microsoft.XMLHTTP");
                    } catch (e) {
                        req = false;
                    }
                }
            }
            var element = document.getElementById(id);
            if (!element) {
                alert("函数clientSideInclude无法找到id " + id + "。" +
                "你的网页中必须有一个含有这个id的div 或 span 标签。");
                return;
            }
            if (req) {
                // 同步请求，等待收到全部内容
                req.open('GET', url, false);
                req.send(null);
                element.innerHTML = req.responseText;
            } else {
                element.innerHTML =
                "对不起，你的浏览器不支持" +
                "XMLHTTPRequest 对象。这个网页的显示要求" +
                "Internet Explorer 5 以上版本, " +
                "或 Firefox 或 Safari 浏览器，也可能会有其他可兼容的浏览器存在。";
            }
        }
    </script>-->
    
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

                       <h1>欢迎进入会议管理系统</h1>

                   </div>

              </div>

         </div>

     </div>

</body>
</html>
