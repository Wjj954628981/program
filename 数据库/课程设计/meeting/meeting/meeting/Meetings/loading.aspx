<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="loading.aspx.cs" Inherits="meeting.Meetings.loading" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
  <meta charset="utf-8"/>
  <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1"/>
  <title>Loading</title>
  <link rel="stylesheet" href="css/progressbar.css"/>
</head>
<body>
  <section class="container">
    <div class="progress">
      <span class="blue" style="width:0%;"><span>0%</span></span>
    </div>
  </section>
  <script type="text/javascript" src="js/jquery.min.js"></script>
  <script type='text/javascript'>
      function loading(percent) {
          $('.progress span').animate({ width: percent }, 1000, function () {
              $(this).children().html(percent);
              if (percent == '100%') {
                  $(this).children().html('加载完成,正在转向登陆界面...&nbsp;&nbsp;&nbsp;&nbsp;');
                  setTimeout(function () {
                      $('.container').fadeOut();
                      location.href = "login.aspx";
                  }, 1000);
              }
          })
      }
  </script>
<!--[if lt IE 9]><script src="//html5shim.googlecode.com/svn/trunk/html5.js"></script><![endif]-->
<script type="text/javascript">loading('5%');</script>
<script type="text/javascript" src="js/jquery-ui.min.js"></script>
<script type="text/javascript">loading('20%');</script>
<script type="text/javascript" src="js/CFInstall.min.js"></script>
<script type="text/javascript">loading('40%');</script>
<script type="text/javascript" src="js/ext-core.js"></script>
<script type="text/javascript">loading('70%');</script>
<script type="text/javascript" src="js/mootools-yui-compressed.js"></script>
<script type="text/javascript">loading('100%');</script>
<script type="text/javascript" src="js/dojo.xd.js"></script>
<div style="text-align:center;clear:both">
</div>
</body>

</html>
